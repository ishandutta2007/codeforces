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

ll pot = 1, ln2 = 0, res = 0;
ll n;

int main () {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> n;

    while (n > 1) {
    	pot = 1, ln2 = 0;

	    while (pot * 2 <= n) {
	    	pot *= 2, ln2++;
	    }

	    res += pot * ln2 / 2;

	    if (n > pot)
	    	res += pot;
		
		n -= pot;
	}

    cout << res << endl;

    return 0;
}