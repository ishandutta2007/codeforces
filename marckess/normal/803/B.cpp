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
	int n; cin >> n;
	vi v (n), cero;

	for(int i = 0; i < n; i++){
		cin >> v[i];
		if ( v[i] == 0 )
			cero.push_back(i);
	}

	int a = -1, b = 0;
	for (int i = 0; i < n; i++){
		if ( v[i] == 0 ){
			a++;
			b++;
			cout << 0 << " ";
		}else{
			int mn = 1e9;
			if ( a > -1 )
				mn =  i - cero[a];
			if ( b < cero.size() )
				mn = min(mn, cero[b] - i);
			cout << mn << " ";
		}
	}

	return 0;
}