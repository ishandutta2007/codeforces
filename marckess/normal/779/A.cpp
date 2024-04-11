#include <bits/stdc++.h>

#define ll long long
#define vi vector<int>
#define vb vector<bool>
#define ii pair<int, int>
#define vii vector<ii>
#define fi first
#define se second
#define endl '\n'

#define isOn(S, j) (S & (1 << j) )
#define setBit(S, j) (S |= (1 << j ) )

using namespace std;

int main(){
	int n, x;
	cin >> n;
	vi a(6,0), b(6,0), t(6,0);
	for(int i = 0; i < n; i++){
		cin >> x;
		a[x]++;
		t[x]++;
	}
	for(int i = 0; i < n; i++){
		cin >> x;
		b[x]++;
		t[x]++;
	}

	int res = 0;
	for(int i = 1; i < 6; i++){
		if ( t[i] % 2 ){
			cout << -1;
			return 0;
		}

		res += abs( a[i] - t[i]/2 ) + abs( b[i] - t[i]/2);
	}

	if ( res % 4 )
		cout << -1;
	else
		cout << res / 4;

	return 0;
}