#include <bits/stdc++.h>
#define ll long long
#define vi vector<int>

using namespace std;

int main(){
	ll n, k, w, res = 0;
	cin >> n >> k;

	while ( n-- ){
		cin >> w;
		res += w / k;
		if ( w % k )
			res ++;
	}

	if ( res % 2 )
		cout << res / 2 + 1;
	else
		cout << res / 2;

	return 0;
}