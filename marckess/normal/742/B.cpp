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

const int MX = 100000;
int n, x, a[MX+5], y;
ll res = 0;

int main () {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> n >> x;
    for (int i = 0; i < n; i++) {
    	cin >> y;
    	a[y]++;
    }

    for (int i = 1; i <= MX; i++) {
    	if ((i ^ x) < i)
    		res += a[i] * (ll)a[i^x];
    	if ((i ^ x) == i)
    		res += a[i] * ll(a[i] - 1) / 2;
    }

    cout << res << endl;

    return 0;
}