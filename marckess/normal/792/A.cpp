#include <bits/stdc++.h>
#define ll long long
#define vi vector<bool>

using namespace std;

int main(){
	int n, count = 0;
	ll x, ma = 2e9 + 10;
	vector<ll> v;

	cin >> n;
	while( n-- ){
		cin >> x;
		v.push_back(x);
	}

	sort(v.begin(), v.end());

	for(int i = 0; i < v.size() - 1; i++){
		ll dif = v[i+1] - v[i];
		if ( dif < ma ){
			ma = dif;
			count = 0;
		}
		if ( dif == ma )
			count ++;
	}

	cout << ma << " " << count;

	return 0;
}