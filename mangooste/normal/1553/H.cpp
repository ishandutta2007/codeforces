#pragma GCC optimize("O3")

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

#define all(a) begin(a), end(a)
#define rall(a) rbegin(a), rend(a)
#define len(a) ((int)((a).size()))

template<typename A, typename B>
ostream& operator<<(ostream &out, pair<A, B> p) { return out << '(' << p.first << ", " << p.second << ')'; }

template<typename A, typename B = typename enable_if<!is_same<A, string>::value, typename A::value_type>::type>
ostream& operator<<(ostream &out, A vec) { out << '{'; string sep; for (B x : vec) out << sep << x, sep = ", "; return out << '}'; }

void dbg_print() { cerr << endl; }
template<typename A, typename... B> void dbg_print(A a, B... b) { cerr << ' ' << a; dbg_print(b...); }

#ifdef LOCAL
    #define dbg(...) cerr << '#' << __LINE__ << " [" << #__VA_ARGS__ << "]:", dbg_print(__VA_ARGS__)
#else
    #define dbg(...)
#endif

struct node {
    array<int, 2> sons;
    int mn, mx, answer;

    node() : sons({-1, -1}), mn(INT_MAX), mx(INT_MIN), answer(INT_MAX) {}
};

int n, k;
vector<node> trie;
int root;
vector<set<int>> layers;

int new_node() {
    trie.push_back(node());
    return len(trie) - 1;
}

void relax(int v, int level) {
    trie[v].mn = INT_MAX;
    trie[v].mx = INT_MIN;
    trie[v].answer = INT_MAX;

    for (int i : {0, 1})
        if (trie[v].sons[i] != -1) {
            trie[v].mn = min(trie[v].mn, trie[trie[v].sons[i]].mn ^ (i << level));
            trie[v].mx = max(trie[v].mx, trie[trie[v].sons[i]].mx ^ (i << level));
            trie[v].answer = min(trie[v].answer, trie[trie[v].sons[i]].answer);
        }

    if (trie[v].sons[0] != -1 && trie[v].sons[1] != -1)
        trie[v].answer = min(trie[v].answer, (trie[trie[v].sons[1]].mn ^ (1 << level)) - trie[trie[v].sons[0]].mx);
}

void add(int v, int x, int level) {
    if (level == -1) {
        trie[v].mn = trie[v].mx = 0;
        return;
    }

    layers[level].insert(v);
    int bit = (x >> level) & 1;
    if (trie[v].sons[bit] == -1)
        trie[v].sons[bit] = new_node();

    add(trie[v].sons[bit], x, level - 1);
    relax(v, level);
}

void resolve(int v, int level, int limit) {
    if (level <= limit)
        return;

    for (int i : {0, 1})
        if (trie[v].sons[i] != -1)
            resolve(trie[v].sons[i], level - 1, limit);

    relax(v, level);
}

vector<int> answer;

void solve(int value, int level) {
    if (level == k) {
        answer[value] = trie[root].answer;
        return;
    }
    solve(value, level + 1);

    auto flip = [&]() {
        for (int v : layers[level])
            swap(trie[v].sons[0], trie[v].sons[1]);

        resolve(root, k - 1, level - 1);
    };

    flip();
    solve(value ^ (1 << level), level + 1);
    flip();
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    cin >> n >> k;
    root = new_node();
    layers.resize(k);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        add(root, x, k - 1);
    }

    answer.resize(1 << k);
    solve(0, 0);
    for (auto x : answer)
        cout << x << ' ';

    cout << '\n';
}