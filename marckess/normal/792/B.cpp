#include <bits/stdc++.h>
#define ll long long
#define vi vector<bool>

using namespace std;

int main(){
	int n, k, l = 0;
	cin >> n >> k;
	ll x;
	vector<bool> v( n, true );
	int i = n;
	while(k--){
		cin >> x;

		int p = l % n;
		x %= i;
		while(x){
			p = (p+1)%n;
			if ( v[p] )
				x--;
		}
		v[p] = false;
		cout << p + 1 << " ";
		l = (p + 1) % n;
		while ( !v[l] ){
			l++;
			l %= n;
		}
		i--;
	}

	return 0;
}