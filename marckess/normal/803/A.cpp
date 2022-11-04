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
	int n, k; cin >> n >> k;
	vector<vi> m(n, vi(n, 0));

	if ( k > n*n ){
		cout << -1;
		return 0;
	}

	for(int i = 0; i < n && k; i++){
		for(int j = i; j < n && k; j++){
			if ( k == 1 ){
				if ( i == j )
					m[i][i] = 1;
				else
					m[i+1][i+1] = 1;
				k--;
			}else{
				m[i][j] = 1;
				k--;
				if ( i != j ){
					m[j][i] = 1;
					k--;
				}
			}
		}
	}

	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++)
			cout << m[i][j] << " ";
		cout << endl;
	}

	return 0;
}