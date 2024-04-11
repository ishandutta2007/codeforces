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

struct segtree {
    struct node {
        int answer;
        int balance;
        int max_balance;
        int min_balance;
        int max_delta_right;
        int max_delta_left;

        node() {}
        node(char c) {
            answer = balance = max_balance = min_balance = c == '(' ? 1 : -1;
            answer = max(answer, 0);
            max_delta_left = max_delta_right = -balance;
        }
    };

    node merge(const node &left, const node &right) const {
        node res;
        res.balance = left.balance + right.balance;
        res.max_balance = max(left.max_balance, right.max_balance + left.balance);
        res.min_balance = min(left.min_balance, right.min_balance + left.balance);

        res.max_delta_right = max({
            left.max_delta_right,
            right.max_delta_right - left.balance,
            left.max_balance - 2 * (right.min_balance + left.balance)
        });

        res.max_delta_left = max({
            left.max_delta_left,
            right.max_delta_left - left.balance,
            (right.max_balance + left.balance) - 2 * left.min_balance
        });

        res.answer = max({
            left.answer,
            right.answer,
            left.max_delta_right + (right.max_balance + left.balance),
            (right.max_delta_left - left.balance) + left.max_balance
        });

        return res;
    }

    int n;
    vector<node> tree;

    segtree(const string &s) : n(len(s)), tree(4 * n) {
        build(1, 0, n, s);
    }

    void build(int v, int vl, int vr, const string &s) {
        if (vr - vl == 1) {
            tree[v] = node(s[vl]);
            return;
        }

        int vm = (vl + vr) >> 1;
        build(v << 1, vl, vm, s);
        build(v << 1 | 1, vm, vr, s);
        tree[v] = merge(tree[v << 1], tree[v << 1 | 1]);
    }

    void set_value(int pos, char c) {
        set_value(1, 0, n, pos, c);
    }

    void set_value(int v, int vl, int vr, int pos, char c) {
        if (vr - vl == 1) {
            tree[v] = node(c);
            return;
        }

        int vm = (vl + vr) >> 1;
        pos < vm ? set_value(v << 1, vl, vm, pos, c) : set_value(v << 1 | 1, vm, vr, pos, c);
        tree[v] = merge(tree[v << 1], tree[v << 1 | 1]);
    }

    int get() const {
        return tree[1].answer;
    }
};

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int n, q;
    string s;
    cin >> n >> q >> s;

    segtree tree(s);
    cout << tree.get() << '\n';

    while (q--) {
        int pos1, pos2;
        cin >> pos1 >> pos2;
        pos1--, pos2--;

        tree.set_value(pos1, s[pos2]);
        tree.set_value(pos2, s[pos1]);
        swap(s[pos1], s[pos2]);

        cout << tree.get() << '\n';
    }
}