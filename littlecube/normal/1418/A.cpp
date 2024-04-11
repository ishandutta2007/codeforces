#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
	ll t, x, y, k;
	cin >> t;
	while(t--){
		cin >> x >> y >> k;
		cout << (ll)(((ll)(y * k + k + x - 3)/(x - 1)) + k) << '\n';
	}



	return 0;
}