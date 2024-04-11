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
	//ios_base::sync_with_stdio(0); cin.tie(0);
	ll n, res = 0, x; cin >> n;
	int i = 1, j = n;
	n++;
	bool f = true;
	while( i < j ){
		res +=(i+j) % n;
		if ( f )
			i++;
		else
			j--;
		f = !f;
	}

	cout << res;

	return 0;
}