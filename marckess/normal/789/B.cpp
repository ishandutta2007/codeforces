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
	ll b, q, l, m, res = 0, a, x; set<ll> s;
	cin >> b >> q >> l >> m;
	while(m--){
		cin >> x;
		s.insert(x);
	}

	if ( abs(b) > l ){
		res = 0;
	}else if ( b == 0 ){
		if ( !s.count(0) )
			res = -1;
	}else if ( q == 0 ){
		if ( !s.count(0) )
			res = -1;
		else if ( !s.count(b) )
			res++;
	}else if ( q == 1 ){
		if ( !s.count(b) )
			res = -1;
	}else if ( q == -1 ){
		if ( !s.count(b) || !s.count(-b) )
			res = -1;
	}else{
		while ( abs(b) <= l ){
			if ( !s.count(b) )
				res++;
			b *= q;
		}
	}  


	if ( res == -1 )
		cout << "inf";
	else
		cout << res;

	return 0;
}