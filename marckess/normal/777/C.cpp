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
	int n, m;
	cin >> n >> m;

	vector<vi> v(n+2,vi(m+2, 0));
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			cin >> v[i][j];

	vi mx(100005, 0);
	for( int j = 0; j < m; j++ ){
		int aux = 0;
		for(int i = n - 1; i >= 0; i-- ){
			if ( v[i][j] <= v[i+1][j] )
				aux ++;
			else
				aux = 0;
			mx[i] = max ( aux, mx[i] );
		}
	}

	int q, a, b;
	cin >> q;

	while(q--){
		cin >> a >> b;
		if ( mx[a-1] >= b - a )
			cout << "Yes\n";
		else
			cout << "No\n";
	}

	return 0;
}