/* In the name of Allah */
#include <bits/stdc++.h>

using namespace std;

#define sz(x) (((int) x.size()))
typedef long long ll;

const int maxN = 2000*100 + 100; 
vector<int> cnt[maxN];

int main() { 
	int n;
	cin >> n;
	for( int i = 0 ; i < n ; i++ ) { 
		int num; cin >> num; 
		cnt[num].push_back( i ) ; 
	}

	vector<int> ans; 
	int curr = 0;
	for( int i = 0 ; i < n ;i++ ) {
		while( curr >= 0 && cnt[curr].empty() ) 
			curr -= 3;
		if( curr < 0 || cnt[curr].empty() ) break;
		ans.push_back( cnt[curr].back() + 1 ) ; 
		cnt[curr].pop_back();
		curr++;
	}
	if( sz(ans) != n ) 
		cout << "Impossible" << endl;
	else {
		cout << "Possible" << endl;
		copy( ans.begin() , ans.end() , ostream_iterator<int>( cout , " " ) ) ;
	}
}