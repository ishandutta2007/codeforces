/* In the name of Allah */
#include <bits/stdc++.h>

using namespace std;

#define sz(x) (((int) x.size()))
typedef long long ll;

const int maxN = 300 + 10;

int a[maxN][maxN];
int p[maxN];

bool ch[maxN];
vector<int> g[maxN];
int num[maxN];
	int n;

void dfs( int s , int c ) { 
	ch[s] = true;
	num[s] = c;
	g[c].push_back( p[s] ) ;
	for( int i = 0 ; i < n ; i++ ) 
		if( a[s][i] && !ch[i] ) 
			dfs( i , c ) ;
}

int main() { 
	cin >> n;

	for( int i = 0 ; i < n ; i++ )
		cin >> p[i];
	for( int i = 0 ; i <n ; i++ ) { 
		string s;
		cin >> s;
		for( int j = 0 ; j < n ;j++ ) 
			a[i][j] = s[j] - '0';
	}

	int cnt = 0;
	for( int i = 0 ; i < n ; i++ ) 
		if( !ch[i] ) 
			dfs( i , cnt++ ) ; 
	for( int i = 0 ; i < cnt ; i++ ) 
		sort( g[i].begin() , g[i].end(), greater<int>() ) ;

	for( int i = 0 ; i < n ; i++ ) { 
		cout << g[num[i]].back() << ' ' ;
		g[num[i]].pop_back();
	}
	cout << endl;
}