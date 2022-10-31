/* In the name of Allah */
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

const int maxN = 100*1000 + 10; 
const int maxQ = 3*maxN ; 

map<int,long long> ans;

int a[maxN]; 
vector<pair<int,int>> b;

int main() { 
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	for( int i = 0 ; i < n; i++ ) 
		cin >> a[i];

	ans[a[0]]++;
	b.push_back({a[0],0}) ; 
	vector<pair<int,int>> c;
	for( int i = 1 ; i < n ; i++ ) { 
		if( b.size() > 40 ) { 
			cout << "BUMP" << endl;
			for( auto x : b ) 
				cout << x.first <<  ' ';
			cout << endl;
			return 0;
		}
		c.clear();
		int curr = 1;
		//cerr << "new " << i << endl;
		for( int j = 0 ; j < (int)b.size() ; j++ ) { 
			curr *= b[j].first;
			if( a[i] % curr != 0 ) {
				int x = __gcd(a[i], curr);
		//		cout << curr << ' ' << x << endl;
				b[j].first /= curr / x; 
				curr = x;
				if( j == 0 || b[j].first != 1  ) 
					c.push_back(b[j]);
			} else 
				c.push_back(b[j]);
			ans[curr] += (j == (int)b.size() - 1 ? i : b[j+1].second ) - b[j].second;
		//	cerr << "B " << curr << ' ' << (j == (int)b.size() - 1 ? i : b[j+1].second ) - b[j].second << endl;
		}
		if( a[i] / curr != 1 ) 
			c.push_back({a[i] / curr,i});
		b.swap(c);

		ans[a[i]]++;
	}

	int q;
	cin >> q;
	for( int i = 0 ; i < q ; i++ ) {
		int num;
		cin >> num;
		cout << ans[num] << endl;
	}
}