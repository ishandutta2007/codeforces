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
 
const int MX = 200005;
int fin[MX], n, k, a, m, x, acu = 0;
set<int> st;

void insert (int l, int r) {
    if (l <= r && (r - l + 2) / (a + 1)) {
        st.insert(l);
        fin[l] = r;
        acu += (r - l + 2) / (a + 1);
    }
}

void erase (int x) {
    auto it = st.upper_bound(x);
    if (it == st.begin())
        return;

    it--;
    if (*it <= x && x <= fin[*it]) {
        int l = *it, r = fin[*it];
        st.erase(it);

        acu -= (r - l + 2) / (a + 1);
        insert(l, x-1);
        insert(x+1, r);
    }
}

int main () {
    ios_base::sync_with_stdio(0); cin.tie(0);
    assert(st.begin() == st.end());

    cin >> n >> k >> a >> m;

    insert(1, n);

    for (int i = 1; i <= m; i++) {
        cin >> x;
        erase(x);

        if (acu < k) {
            cout << i << endl;
            return 0;
        }
    }

    cout << -1 << endl;

    return 0;
}