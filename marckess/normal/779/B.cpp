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
	string s; int k;
	cin >> s >> k;

	int res = 0, c = 0;
	for(int i = s.size() - 1; i >= 0; i-- ){
		if ( s[i] == '0' )
			c++;
		else if ( c < k )
			res ++;
	}

	if ( c < k )
		cout << s.size() - 1;
	else 
		cout << res;

	return 0;
}