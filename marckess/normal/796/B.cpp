#include <bits/stdc++.h>

#define ll long long
#define vi vector<int>
#define vb vector<bool>
#define ii pair<int, int>
#define vii vector<ii>

#define isOn(S, j) (S & (1 << j) )
#define setBit(S, j) (S |= (1 << j ) )

using namespace std;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n, m, k, a, b;

	cin >> n >> m >> k;

	bitset<(int)1e6 + 10> hole;

	while(m--){
		cin >> a;
		hole[a] = 1;
	}

	int act = 1;
	while(k--){
		if ( hole[act] ){
			cout << act; return 0;
		}
		cin >> a >> b;
		if ( a == act )
			act = b;
		else if ( b == act )
			act = a;
	}
	cout << act;

	return 0;
}