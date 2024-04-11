/* In the name of Allah */
#include <bits/stdc++.h>

using namespace std;

#define sz(x) (((int) x.size()))
typedef long long ll;

const int maxN = 1000*100 + 100; 
map<int,int> curr;
int a[maxN];

int main() { 
	int n,m,k;
	cin >> n >> m >> k;
	for( int i = 0 ; i < n ; i++ ) { 
		cin >> a[i];
		a[i]--; 
		curr[a[i]] = i;
	}

	ll ans = 0;
	for( int i = 0 ; i < m ; i++ ) { 
		int num; cin >> num;
		num--;
		int ind = curr[num];
		ans += 1 + ind / k;

		if( ind != 0 ) { 
			int x = a[ind-1];
			curr[x] = ind;
			curr[num] = ind - 1 ; 
			swap( a[ind-1], a[ind] ) ; 
		}
	}
	cout << ans << endl;
}