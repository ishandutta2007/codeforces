/* In the name of Allah */
#include <bits/stdc++.h>

using namespace std;

#define sz(x) (((int) x.size()))
typedef long long ll;

const int maxN = (1<<16) + 10;

int cnt[maxN] , b[maxN];

vector<pair<int,int>> ans;
int main() { 
	int n;
	cin >> n;

	queue<int> bfs;
	for( int i = 0 ; i < n; i++ ) {
		cin >> cnt[i] >> b[i];
		if( cnt[i] == 1 ) 
			bfs.push(i);
	}

	while( bfs.size() ) { 
		int s = bfs.front(); bfs.pop();
		if( cnt[s] == 0  ) continue;
		ans.push_back( { s , b[s] } ) ; 
		cnt[b[s]]--;
		b[b[s]] ^= s;
		if( cnt[b[s]] == 1 ) { 
			bfs.push(b[s]);
		}
	}
	cout << ans.size() << endl;
	for( int i = 0 ; i < ans.size() ; i++ ) 
		cout << ans[i].first << ' ' << ans[i].second << endl;
}