/* In the name of Allah */
#include <bits/stdc++.h>

using namespace std;

#define sz(x) (((int) x.size()))
typedef long long ll;

const int maxN = 3000*100 + 10 ; 
int nex[maxN];

vector<pair<int,string>> c[maxN];
string t; 
ll ans;

void dfs( int s , int curr = 0 ) { 
	for( auto x : c[s] ) { 
		int tmp = curr;
		string s = x.second;
		for( int i = 0 ; i < sz(s) ; i++ ) {
			while( tmp && t[tmp] != s[i] ) 
				tmp = nex[tmp];
			if( t[tmp] == s[i] ) tmp++;
			if( tmp == sz(t) - 1 ) 
				ans++;
		}
		dfs( x.first , tmp );
	}
}

int main() { 
	int n;
	cin >> n;
	for( int i = 1 ; i < n ; i++ ) { 
		int p; string s;
		cin >> p >> s; p--; 
		c[p].emplace_back(i,s);
	}

	cin >> t; 

	for( int i = 1 ; i < sz(t) ; i++ ) { 
		int x = nex[i];
		while( x && t[x] != t[i] ) 
			x = nex[x];
		if( t[x]==t[i] ) x++;
		nex[i+1] = x; 
	}
	t += 'A';

	dfs(0);

	cout << ans << endl;
}