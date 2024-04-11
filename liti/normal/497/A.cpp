/* In the name of Allah */
#include <bits/stdc++.h>

using namespace std;

#define sz(x) (((int) x.size()))
typedef long long ll;

const int maxN = 100 + 10; 

string a[maxN];
int used[maxN];

int main() { 
	int n,m;
	cin >> n >> m;
	for( int i = 0 ; i < n ; i++ ) 
		cin >> a[i];

	int ans = 0;
	for( int j = 0 ; j < m ; j++ ) { 
		bool ret = 0;
		for( int i =0  ; i < n - 1 ; i++ ) 
			if( !used[i] && a[i][j] > a[i+1][j] ) 
				ret = 1;
		ans += ret;
		if( !ret ) 
			for( int i = 0 ; i < n - 1 ; i++ ) 
				if( !used[i] && a[i][j] < a[i+1][j] ) 
					used[i] = true;
	}
	cout << ans << endl;
}