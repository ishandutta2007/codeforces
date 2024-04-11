#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define FOR(i,n) for (int i = 0; i < n; i++)
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<ii> vii;
typedef vector<vii> vvii;

const int MX = 100005;
bitset<MX> bs;
int q, t, u, x, k, s, v;
set<int> st[MX];

int main () {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> q;

    while (q--) {
        cin >> t;

        if (t == 1) {
            cin >> u;
            if (bs[u])
                continue;
            bs[u] = 1;

            for (int i = 1; ll(i) * i <= u; i++) {
                if (u % i == 0) {
                    st[i].insert(u);
                    st[u/i].insert(u);
                }
            }
        } else {
            cin >> x >> k >> s;
            if (x % k) {
                cout << -1 << endl;
                continue;
            }

            v = 0;

            for (int i = 16, j = (1 << i), mk = j - 1; i >= 0; i--, j >>= 1, mk = j - 1) {
                int low = v | (j ^ (j & x));

                if (low <= s - x && st[k].lower_bound(low) != st[k].upper_bound(min(s - x, low | mk)))
                    v = low;
                else
                    v |= (j ^ (j & ~x));
            }

            if (x + v <= s && st[k].find(v) != st[k].end())
                cout << v << endl;
            else
                cout << -1 << endl;
        }
    }

    return 0;
}