#include <bits/stdc++.h>
#define ll long long
#define vi vector<int>

using namespace std;

int main(){
	int n;
	ll x;
	cin >> n;
	vector <ll> a(n+5);
	for( int i = 1; i <= n; i++ )
		cin >> a[i];
	vector <ll> acu(n+1);
	for( int i = 1; i < n; i++){
		acu[i] = abs(a[i] - a[i+1]);
		if ( i % 2 == 0 )
			acu[i] *= -1;
	}

	ll mx = -1, s=0;
	for(int i = 1; i < n; i++ ){
		s = max(acu[i],s+acu[i]);
		mx = max(mx,s);
	}

	s=0;
	for(int i = 2; i < n; i++ ){
		s = max(-acu[i],s-acu[i]);
		mx = max(mx,s);
	}

	cout << mx;

	return 0;
}