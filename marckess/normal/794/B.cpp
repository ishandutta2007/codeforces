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

#define ld long double

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	ld h;
	int n;
	cin >> n >> h;
	for(int i = 1; i < n; i++){
		ld res = h / sqrt( (ld)n / (ld)i );
		printf("%.7lf ", (double)res );
	}

	return 0;
}