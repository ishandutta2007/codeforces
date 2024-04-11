/* In the name of Allah */
#include <bits/stdc++.h>

using namespace std;

const int maxN = 100*100*100 + 10;
int f[maxN]; 
int p[maxN];
int c[maxN]; //childs!

int main() { 
	ios::sync_with_stdio(false);
	string s;
	cin >> s;

	int ind = 0 ;
	for( int i = 1 ; i < (int)s.size() ; i++ ) { 
		while( ind != 0 && s[ind] != s[i] ) 
			ind = f[ind-1]; 
		if( s[ind] == s[i] ) 
			f[i] = ++ind;
		else 
			f[i] = ind;
		p[i] = ind;
		c[ind]++;
	}

	int x = f[s.size()-1];
	if( x != 0 && c[x] > 1 ) 
		cout << s.substr( 0 , x ) << endl;
	else if( x != 0 && p[x-1] != 0 ) 
		cout << s.substr( 0 , p[x-1] ) << endl;
	else
		cout << "Just a legend" << endl;
}