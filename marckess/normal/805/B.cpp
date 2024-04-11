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
	int n; cin >> n;
	for(int i = 0; i < n; i++){
		if ( i % 4 == 0 )
			cout << 'a';
		if ( i % 4 == 1 )
			cout << 'a';
		if ( i % 4 == 2 )
			cout << 'b';
		if ( i % 4 == 3 )
			cout << 'b';
	}
	return 0;
}