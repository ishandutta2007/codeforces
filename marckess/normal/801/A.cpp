#include <bits/stdc++.h>

//#define ll long long
#define vi vector<int>
#define vb vector<bool>
#define ii pair<int, int>
#define vii vector<ii>

#define isOn(S, j) (S & (1 << j) )
#define setBit(S, j) (S |= (1 << j ) )

using namespace std;

int main(){
	int c = 0, k = 0;
	string s;
	cin >> s;
	while ( s.find("VK") != string::npos ){
		c++;
		s.replace( s.find("VK", k), 2, ".." );
	}

	if( s.find("VV") != string::npos || s.find("KK") != string::npos )
		c++;

	cout << c;

	return 0;
}