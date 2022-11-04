#include <bits/stdc++.h>

#define ll long long
#define vi vector<int>
#define vb vector<bool>
#define ii pair<int, int>
#define vii vector<ii>

#define isOn(S, j) (S & (1 << j) )
#define setBit(S, j) (S |= (1 << j ) )

using namespace std;

ll mcd(ll a, ll b){
	if ( b == 0 )
		return a;
	return mcd(b, a % b);
}

vector<ll> v;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n;
	cin >> n;

	v.assign(n,0);

	for(int i = 0; i < n; i++)
		cin >> v[i];

	ll aux = mcd(v[0], v[1]);
	for(int i = 2; i < n; i++)
		aux = mcd(aux, v[i]);

	if ( aux > 1 ){
		cout << "YES\n0";
		return 0;
	}

	int res = 0;
	for(int i = 1; i < n; i++){
		if ( v[i-1]%2 && v[i]%2 ){
			res++;
			int aux = v[i-1];
			v[i-1] -= v[i];
			v[i] += aux;
		}
	}

	for(int i = 1; i < n; i++){
		if ( v[i-1]%2 xor v[i]%2 ){
			res+=2;
			for(int j = 0; j < 2; j++){
				int aux = v[i-1];
				v[i-1] -= v[i];
				v[i] += aux;
			}
		}
	}

	cout << "YES\n" << res;

	return 0;
}