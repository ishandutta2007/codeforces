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
	int n, k;
	cin >> n >> k;
	n %= 6;
	vi v(3, 0);
	v[k] = 1;
	while(n){
		if ( n % 2 )
			swap(v[0], v[1]);
		else
			swap(v[1], v[2] );
		n--;
	}

	for(int i = 0; i < 3; i++)
		if (v[i])
			cout << i;

	return 0;
}