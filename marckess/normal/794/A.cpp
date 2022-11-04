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
#define LSB(S) (S & (-S))

using namespace std;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	ll a, b, c, n, x, res = 0;
	cin >> a >> b >> c >> n;
	while(n--){
		cin >> x;
		if ( x > b && x < c )
			res++;
	}

	cout << res << endl;

	return 0;
}