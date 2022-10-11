#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

#define vec vector
#define ar array

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

const int MAX_LEFT = 15;

void change(int &mask, int pos) {
    int bit = (mask >> pos) % 2;
    mask ^= (bit << pos);
    mask ^= ((bit ^ 1) << pos);
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int n;
    cin >> n;
    vec<int> a(n);
    for (auto &x : a)
        cin >> x;

    vec<ar<int, 3>> ops;

    auto reverse = [&](int i, int j) {
        a[i] ^= 1;
        a[j] ^= 1;
        a[2 * j - i] ^= 1;
        ops.push_back({i, j, 2 * j - i});
    };

    int st = 0;
    for (; n - st > MAX_LEFT; st += 3) {
        vec<int> ones;
        for (int i = st; i < st + 3; i++)
            if (a[i])
                ones.push_back(i);

        if (len(ones) == 0)
            continue;

        if (len(ones) == 1) {
            reverse(ones[0], st + 3);
            continue;
        }

        if (len(ones) == 3) {
            reverse(st, st + 1);
            continue;
        }

        if (ones[0] != st || ones[1] != st + 1) {
            reverse(ones[0], ones[1]);
            continue;
        }

        vec<int> after;
        for (int i = st + 3; i < st + 6; i++)
            if (a[i])
                after.push_back(i);

        if (len(after) == 0) {
            reverse(st, st + 3);
            reverse(st + 1, st + 3);
            continue;
        }

        if (len(after) == 1) {
            reverse(st, after[0]);
            reverse(st + 1, st + 6);
            continue;
        }

        if (len(after) == 2) {
            reverse(st, after[0]);
            reverse(st + 1, after[1]);
            continue;
        }

        reverse(st + 1, st + 3);
        reverse(st, st + 4);
    }

    assert(st != n);

    int left = n - st;
    const int MASK = (1 << left);

    vec<int> dist(MASK, -1);
    dist[0] = 0;
    vec<ar<int, 3>> par(MASK);

    vec<int> que{0};
    for (int st = 0; st < len(que); st++) {
        int mask = que[st];
        for (int i = 0; i < left; i++)
            for (int j = i + 1; j < left; j++) {
                int k = 2 * j - i;
                if (k >= left)
                    continue;

                int cur_mask = mask;
                change(cur_mask, i);
                change(cur_mask, j);
                change(cur_mask, k);

                if (dist[cur_mask] == -1) {
                    dist[cur_mask] = dist[mask] + 1;
                    par[cur_mask] = {i, j, k};
                    que.push_back(cur_mask);
                }
            }
    }

    int mask = 0;
    for (int i = 0; i < left; i++)
        mask ^= (a[st + i] << i);

    if (dist[mask] == -1) {
        cout << "NO\n";
        return 0;
    }

    while (mask != 0) {
        ops.push_back(par[mask]);
        for (auto &x : ops.back()) {
            change(mask, x);
            x += st;
        }
    }

    cout << "YES\n";
    cout << len(ops) << '\n';
    for (auto [i, j, k] : ops)
        cout << i + 1 << ' ' << j + 1 << ' ' << k + 1 << '\n';
}