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

const int MX = 200005;
int n, k, x;
map<int, int> mp;
vii a;
vi res;

bool esPos (int m, int f) {
    int acu = 0;

    for (int i = 0; i < a.size(); i++) {
        int d = m ? a[i].fi / m : k;
        acu += d;

        if (f)
            while (d--)
                res.pb(a[i].se);
    }

    return acu >= k;
}

int main () {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> x;
        mp[x]++;
    }

    for (auto it : mp)
        a.emplace_back(it.se, it.fi);
    sort(all(a), greater<ii>());

    int i = 0, j = n+1, rep = 20;
    while (rep--) {
        int m = (i+j)/2;
        if (esPos(m,0)) i = m;
        else j = m;
    }

    if (esPos(j, 0)) esPos(j, 1);
    else esPos(i, 1);

    assert(res.size() >= k);

    for (int i = 0; i < k; i++)
        cout << res[i] << " ";
    cout << endl;

    return 0;
}