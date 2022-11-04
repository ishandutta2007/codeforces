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
typedef pair<ll, ll> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

int n, a[111], res = 0;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];

    a[0] = 0, a[n+1] = 1001;

    n++;
    for (int i = 0; i <= n; i++)
        for (int j = i + 1; j <= n; j++)
            if (a[j] - a[i] == j - i)
                res = max(res, j - i - 1);
    cout << min(res,n-2) << endl;

	return 0;
}