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
	int n;
	string s;
	char c;
	vi cub(10,0);

	cin >> n >> s;
	for(int i = 0; i < n; i++){
		cin >> c;
		cub[c-'0']++;
	}

	vi aux = cub;
	int res = n;
	for(int i = 0; i < n; i++){
		int j;
		for( j = s[i]-'0'; cub[j] == 0; j = (j+1)%10 );
		if ( j >= s[i]-'0' ){
			res--;
		}
		cub[j]--;
	}
	cout << res << endl;

	cub = aux;
	res = 0;
	for(int i = 0; i < n; i++){
		int j;
		for( j = (s[i]-'0'+1)%10; cub[j] == 0; j = (j+1)%10 );
		if ( j > s[i]-'0' ){
			res++;
		}
		cub[j]--;
	}
	cout << res << endl;

	return 0;
}