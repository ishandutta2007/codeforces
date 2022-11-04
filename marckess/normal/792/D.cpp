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

ll n, q, act;

void up(){
	if ( act == (n + 1) >> 1 )
		return;
	act |= LSB(act) << 1;
	act -= LSB(act);
}

void right(){
	if ( act & 1 )
		return;
	act += LSB(act) >> 1;
}

void left(){
	if ( act & 1 )
		return;
	act += (LSB(act) >> 1) - LSB(act) ;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> q;
	string s;

	while( q-- ){
		cin >> act >> s;
		for(int i = 0; i < s.size(); i++){
			switch ( s[i] ){
				case 'U':
					up();
					break;
				case 'L':
					left();
					break;
				case 'R':
					right();
					break;
			}
		}
		cout << act << endl;
	}

	return 0;
}