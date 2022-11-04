#include <bits/stdc++.h>
 
#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define FOR(i,n) for (int i = 0; i < n; i++)
#define ALL(v) v.begin(), v.end()

using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int, ll> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef vector<vii> vvii;

struct Trie {
    Trie *sig[2];
    int cn;

    Trie () {
        sig[0] = sig[1] = 0;
        cn = 0;
    }

    void update (int i, int x, int k) {
        cn += k;
        if (i < 0)
            return;

        int s = bool(x & (1 << i));
        if (!sig[s])
            sig[s] = new Trie();
        sig[s]->update(i-1, x, k);
    }

    int query (int i, int p, int l) {
        if (i < 0)
            return 0;

        int x = bool(p & (1 << i)), y = bool(l & (1 << i)), res = 0;

        if (y) {
            if (sig[x])
                res += sig[x]->cn;
            if (sig[1-x])
                res += sig[1-x]->query(i-1, p, l);
        } else {
            if (sig[x])
                res += sig[x]->query(i-1, p, l);
        }

        return res;
    }
};

int q, p, l, op;
Trie *t = new Trie();

int main () {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> q;
    while (q--) {
        cin >> op >> p;

        if (op == 1)
            t->update(26, p, 1);
        else if (op == 2)
            t->update(26, p, -1);
        else {
            cin >> l;
            cout << t->query(26, p, l) << endl;
        }
    }

    return 0;
}