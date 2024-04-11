/* In the name of Allah */
#include <bits/stdc++.h>

using namespace std;

const int maxN = 300*1000 + 10;
int ans[maxN];
pair< int , pair<int,int> > e[maxN];
int val[maxN];

int main() { 
	int n,m;
	cin >> n >> m;

	for(int i =0 ;  i < m ; i++ ) { 
		cin >> e[i].second.first >> e[i].second.second >> e[i].first ;
		e[i].second.first--;
		e[i].second.second--;
	}

	sort( e, e + m , greater<pair<int,pair<int,int> > >() ) ;

	int best = 0;
	for(int i =0 ; i < m;  i++ ){ 
		if( i == 0 || e[i].first != e[i-1].first ) 
			for(int j = i ; j < m ; j++ ) {
				if( e[j].first != e[i].first ) 
					break;
				val[j] = ans[ e[j].second.second ] + 1; 
			}

		ans[ e[i].second.first ] = max( ans[ e[i].second.first ] , val[i] ) ; 
		best = max( best ,val[i] );
	}

	cout << best << endl;
}