/* In the name of Allah */
#include <iostream>
#include <vector>

using namespace std;

const int maxN = 100*100*10 + 10; 

vector<int> c[maxN];
char a[maxN];

int size[maxN], used[maxN];

int dfs( int s , int p ) { 
	size[s] = 1; 
	
	for( auto x : c[s] ) 
		if( x != p && !used[x] ) 
			size[s] += dfs( x, s ) ; 
	return size[s];
}

void doJob( int s, char ch ) { 
	dfs(s, -1) ; 

	int tmp = s;
	int p = -1 ;
	while( true ) {
		bool f = false;
		for( auto x : c[s] ) 
			if( !used[x] && x != p && size[x] > size[tmp]/2 ) {
				p = s;
				s = x;
				f = true;
				break;
			}
		if( !f )
			break;
	}

	used[s] = true;
	a[s] = ch;

	for( auto x : c[s] ) 
		if( !used[x] ) 
			doJob( x , ch+1 ) ; 
}

int main() { 
	ios::sync_with_stdio(false); int n; cin >> n;

	for(int i = 0 ; i < n - 1 ; i++ ) { 
		int x,y;
		cin >> x >> y;
		x--; y--;
		c[x].push_back(y);
		c[y].push_back(x);
	}

	doJob(0, 'A');

	for(int i = 0 ; i < n ; i++ ) 
		cout << a[i] << ' ' ;
	cout << endl;
}