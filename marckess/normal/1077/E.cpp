#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb(x) push_back(x)

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

int n, x;
map<int, int> mp;
vi st;

int main () {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> n;
    while (n--) {
        cin >> x;
        mp[x]++;
    }

    for (auto it : mp)
        st.pb(it.se);

    sort(all(st));

    int res = 0;
    for (int i = 1; i <= 2e5; i++) {
        int it = 0, acu = 0, k = i;
        
        while (1) {
            int j = lower_bound(st.begin()+it, st.end(), k) - st.begin();
            if (j == st.size()) break;

            acu += k;
            it = j + 1;
            k *= 2;
        }

        res = max(res, acu);
    }

    cout << res << endl;

    return 0;
}