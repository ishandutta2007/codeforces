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
typedef vector<vvi> vvvi;
typedef vector<ii> vii;
typedef vector<vii> vvii;

ll a, b, res = 0;

int main () {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
  	cin >> a >> b;
	
	while (a && b) {
		if (a < b)
			swap(a, b);
		res += a / b;
		a %= b;
	}

	cout << res << endl;

    return 0;
}