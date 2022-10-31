#include <iostream>
#include <set>
#include <vector>
using namespace std;

const int maxN = 100000 + 100 ; 
const long long INF = 1e17 ; 
long long d1[maxN], d2[maxN];
vector< pair<int,long long> > c[maxN];

vector< long long > train[maxN];
set<pair<long long, int> > curr;

int ans;
int n,m,k;

void update( int node ) { 
	vector< pair<int,long long> >& x = c[node];

	for(int i= 0 ; i < x.size() ; i++ ) { 
		if( d1[node] + x[i].second <= d1[x[i].first] ) {
			curr.erase( make_pair( d1[x[i].first] , x[i].first ) ) ; 
			d1[x[i].first] = d1[node] + x[i].second;
			d2[x[i].first] = node;
			curr.insert( make_pair( d1[x[i].first] , x[i].first ) ) ; 
		}
	}
}

void dij() { 
	for(int i = 1 ; i < n ; i++ ) { 
		d1[i] = INF;
		d2[i] = -1;
	}


	int s = 0 ;

	for(int i = 0 ; i < n ; i++ ) 
		for(int j = 0 ; j < train[i].size() ; j++ ) 
			d1[i] = min( d1[i] , train[i][j] ) ; 

	for(int i = 1 ; i < n ; i++ ) 
		curr.insert( make_pair( d1[i], i ) ) ;

	update(s); 

	while( !curr.empty() ) {
		s = curr.begin()->second;
		curr.erase( make_pair( d1[s], s ) ) ;
	//	cout << s << ' ' << d1[s] << ' ' << ans << endl;
		int counter = 0 ; 
		for(int i = 0 ; i < train[s].size() ; i++ ) 
			if( train[s][i] > d1[s]  ) 
				ans++;
			else if ( train[s][i] == d1[s] ) 
				counter++;

	//	cout << "SALAM " << ans << ' ' << counter << ' ' << d2[s] << endl;
		ans += max(counter-1,0);
		if( counter != 0 && d2[s] != -1 ) 
			ans++;
		update(s); 
	}
}


int main() { 
	cin>> n >> m >> k;

	for(int i = 0 ; i < m ; i++ ) { 
		int x,y,z;
		cin >> x >> y >> z; x-- ; y--; 
		c[x].push_back( make_pair( y , z ) ) ; 
		c[y].push_back( make_pair( x, z ) ) ; 
	}

	for(int i = 0 ; i < k ; i++ ) { 
		int num , val ;
		cin >> num >> val;
		train[num-1].push_back( val ) ; 
	}

	dij();

	cout << ans << endl;
}