//In the name of Allah
#include <bits/stdc++.h>
using namespace std;

typedef long long ll; 
typedef pair<int,int> pii; 

int n; 
bool valid( int x ) { 
	return x > 0 && x <= n ; 
}

int main() { 
	ios::sync_with_stdio(false); cin.tie(0); //XXX remember scanf
	int a,b,c,d; cin >> n >> a >> b >> c >> d; 

	ll ans = 0; 
	for( int i = 1 ; i <= n ; i++ ) { 
		int sum = a + b + i; 
		if( valid( sum - a - c ) && valid( sum - c - d ) && valid( sum - b - d ) ) 
			ans++;
	}
	cout << ans * 1ll * n << endl;
}