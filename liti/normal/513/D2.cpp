/* In the name of Allah */
#include <bits/stdc++.h>

using namespace std;

#define sz(x) (((int) x.size()))
typedef long long ll;

const int maxN = 1000*1000 + 10;

set<int> curr;
int mx[maxN][2];
int mn[maxN][2];

vector<int> ans;
int n,c;

void doJob( int s , int e = -1 ) { 
//	cout << s << ' ' << e << endl;
	curr.erase(s);
	if( e != -1 && e < s ) {
		cout << "IMPOSSIBLE" << endl;
		exit(0);
	}
	if( mx[s][0] > s ) 
		doJob( s + 1 , mx[s][0] );
	ans.push_back( s ) ;
	if( mx[s][1] > s && (curr.size() == 0 || ( mn[s][1] != n + 1 && mn[s][1] < *curr.begin()) ) ) { 
		cout << "IMPOSSIBLE" << endl;
		exit(0);
	}
	if( mx[s][1] > s || (curr.size() && *curr.begin() - 1 < e )  ) 
		doJob( *curr.begin() , max( e ,mx[s][1] ) );
	if( curr.size() && *curr.begin() <= e ) {
		cout << "IMPOSSIBLE" << endl;
		exit(0);
	}
}

int main() { 
	cin >> n >> c;

	for( int i = 1 ; i <= n ; i++ ) {
		mx[i][0] = mx[i][1] = i;
		mn[i][0] = mn[i][1] = n + 1;
		curr.insert(i);
	}
	for( int i =0 ; i < c ; i++ ) {
		int a,b; string x;
		cin >> a >>b >> x;
		if( b <= a ) { 
			cout << "IMPOSSIBLE" << endl;
			return 0;
		}
		mx[a][(x=="RIGHT")] = max(mx[a][(x=="RIGHT")],b) ;
		mn[a][(x=="RIGHT")] = min(mn[a][(x=="RIGHT")],b) ;
	}

	doJob( 1, n ) ; 

	for( int i =0 ; i < sz(ans) ; i++ ) 
		cout << ans[i] << ' ' ;
	cout << endl;
}