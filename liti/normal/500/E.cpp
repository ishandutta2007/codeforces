/* In the name of Allah */
#include <bits/stdc++.h>

using namespace std;

#define sz(x) (((int) x.size()))
typedef long long ll;

const int maxN = 200*1000 + 10; 
const int maxL = 22;
int l[maxN] , x[maxN];
int rmq[maxN][maxL];
int prq[maxN][maxL];
int brq[maxN][maxL];
deque<pair<int,int>> curr;

int main() { 
	int n;
	cin >> n;

	for( int i = 0 ; i < n ; i++ ) 
		cin >> x[i] >> l[i];

	for( int i = 0 ; i < maxL ; i++ ) {
		rmq[n][i] = rmq[n-1][i] = n;
		brq[n][i] = brq[n-1][i] = 2e9;
	}

	for( int i = n - 2 ; i >= 0 ; i-- ) { 
		int best = upper_bound( x + i , x + n , x[i] + l[i] ) - x;
		int tmp = lower_bound( curr.begin() , curr.end() , 
				make_pair(best,0) ) - curr.begin();
		brq[i][0] = x[i] + l[i];
		if( tmp != 0 ) {
			best = max( best , curr[tmp-1].second ) ; 
			brq[i][0] = max( brq[i][0] , brq[curr[tmp-1].first][0] ) ;
		}
		while( curr.size() && curr[0].second <= best ) 
			curr.pop_front();
		curr.push_front( {i,best} ) ; 

//		cerr << i << ' ' << best << endl;

		rmq[i][0] = best;
		prq[i][0] = max(0,x[best] - brq[i][0]);
		for( int j = 1 ; j < maxL ; j++ ) { 
			rmq[i][j] = rmq[rmq[i][j-1]][j-1];
			prq[i][j] = prq[i][j-1] +  prq[rmq[i][j-1]][j-1];
//			cout << i << ' ' << (1<<j) << ' ' << rmq[i][j] << ' ' << prq[i][j] <<
//				' ' << brq[i][j] << endl;
		}
	}
	int q;
	cin >> q;

	for( int i = 0 ; i < q ; i++ ) { 
		int x,y;
		cin >> x >> y; x--;y--;
		int sum = 0;
//		[ x , rmq[x][j] ) = prq[x][j];
		for( int j = maxL - 1 ; j >= 0 ; j-- ) { 
			if( rmq[x][j] <= y ) {
				sum += prq[x][j];
				x = rmq[x][j];
			}
		}
		cout << sum << endl;
	}
}