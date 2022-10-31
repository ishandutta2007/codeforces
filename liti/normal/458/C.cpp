/* In the name of Allah */
#include <bits/stdc++.h>

using namespace std;
const int maxN = 100*1000 + 10; 

int cnt[maxN];
pair<int,int> val[maxN];
vector<int> last[maxN];

set< pair<int,int> > curr;

int main() { 
	int n;
	cin >> n;

	int k = 0 ; 
	int sum = 0;
	for(int i = 0 ; i < n; i++ ) { 
		int a,b;
		cin >> a >> b;
		val[i] = make_pair( b , a ) ; 
		sum += b;
		if( a == 0 ) 
			k++;
	}

	sort( val , val + n , greater<pair<int,int> >() ) ; 

	int ans = sum;
	int ray = n;
	for(int i = n ; i > k ; i-- ) { 
		ray--;
		int j = n - i;


	//	cout << "DD " << sum << endl;
		while( !curr.empty() && curr.rbegin()->first >= ray ) { 
			sum += last[ curr.rbegin()->second ].back();
			cnt[curr.rbegin()->second]--;
			last[ curr.rbegin()->second ].pop_back();

			curr.insert( make_pair( cnt[ curr.rbegin()->second ] , curr.rbegin()->second ) ) ;
			curr.erase( *curr.rbegin() ) ; 
			ray++;
		}
	//	cout << "PP " << sum << endl;

		if( cnt[ val[j].second ] + 1 >= ray ) { 
			ray++;
			continue;
		}

		curr.erase( make_pair( cnt[ val[j].second ] , val[j].second ) ) ;
		cnt[ val[j].second ]++;
		curr.insert( make_pair( cnt[ val[j].second ] , val[j].second ) ) ;

		last[ val[j].second ].push_back( val[j].first ) ; 
		sum -= val[j].first;

//		cout << i << ' ' << ray << ' ' << sum << endl;

		ans = min( ans, sum) ; 
	}
	cout << ans << endl;
}