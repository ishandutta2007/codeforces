//In the name of Allah    
#include <bits/stdc++.h>    
using namespace std;    

#define __sz(x) ((int)(x).size())    
typedef long long ll;    

const int maxN = 4 * 1000*100 + 20; 
const int K = 2 * 1000*100 + 1;

vector<pair<int,int>> c[maxN];
int ptr[maxN];
int mark[maxN];

void dfs( int s, int co = 1 ) { 
	for( int& i = ptr[s] ; i < __sz(c[s]) ; i++ ) { 
		if( mark[c[s][i].second] ) continue;
		mark[c[s][i].second] = co;
		dfs( c[s][i].first , 3 - co ); 
	}
}

int main() { 
	int n; 
	cin >> n; 
	for( int i= 0 ; i< n ; i++ ) {
		int x,y; cin>> x >> y; 
		c[x].push_back( { y+K , i } ) ; 
		c[y+K].push_back( { x , i } ) ; 
	}
	int m = n;
	for( int i = 0 ; i < 2*K ; i++ ) 
		if( __sz(c[i]) % 2 == 1 ) {
			c[i].push_back( { 2*K + (i>=K) , m } ) ; 
			c[2*K+(i>=K)].push_back( { i , m++ } ) ; 
		}
	if( __sz(c[2*K]) % 2 == 1 ) {
		c[2*K].push_back( {2*K+1,m} ) ;
		c[2*K+1].push_back( {2*K,m++} ) ;
	}

	for( int i = 0 ; i < maxN ; i++ ) 
		if( ptr[i] != __sz(c[i]) ) 
			dfs( i ) ; 
	for( int i = 0 ; i < n ; i++ ) 
		cout << (mark[i]==1?"b":"r"); 
	cout << endl;
}