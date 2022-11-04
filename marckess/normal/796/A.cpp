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
	int n, m, k;
	cin >> n >> m >> k;
	vi v(n+1);
	for(int i = 1; i <= n; i++)
		cin >> v[i];

	int a = 1;
	while(true){
		if ( m + a <= n )
			if( v[m+a] > 0 && v[m+a] <= k )
				break;
		if ( m - a > 0 )
			if ( v[m-a] > 0 && v[m-a] <= k )
				break;
		a++;
	}

	cout << a * 10;

	return 0;
}