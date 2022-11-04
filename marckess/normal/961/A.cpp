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

int n, m, a[1005] = {0}, x, res = 0;
	
int main () {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> n >> m;
    while (m--) {
    	cin >> x;
    	a[x-1]++;

    	int d = *min_element(a, a+n);
    	res += d;
    	for (int i = 0; i < n; i++)
    		a[i] -= d;
    }

    cout << res << endl;

    return 0;
}