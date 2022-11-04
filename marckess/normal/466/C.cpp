#include <bits/stdc++.h>
#define ll long long
#define vi vector<int>

using namespace std;

int main(){
	int n;
	ll x;
	cin >> n;
	vector<ll> v(n,0);
	cin >> v[0];

	for(int i = 1; i < n; i++ ){
		cin >> x;
		v[i] = v[i-1] + x;
	}

	ll sum = v[n-1];
	if ( sum % 3 != 0 ){
		cout << 0;
		return 0;
	}

	ll part = sum / 3;
	ll cp = 0;
	for ( int i = 0; i < n - 1; i++ ){
		if ( v[i] == part * 2 )
			cp++;
	} 

	ll ways = 0;
	for( int i = 0; i < n - 1; i++){
		if ( v[i] == part * 2 )
			cp--;
		if ( v[i] == part )
			ways += cp;
	}

	cout << ways;

	return 0;
}