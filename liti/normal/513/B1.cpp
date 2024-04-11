/* In the name of Allah */
#include <bits/stdc++.h>

using namespace std;

#define sz(x) (((int) x.size()))
typedef long long ll;
deque<int> ans;

int n,m;
deque<int> doJob( int x , int y ) { 
	if( x == n ) return deque<int>(1,n);
//	cout << x << ' ' << y << endl;
	int p = n - x -1;
	int st = (1<<p);
	deque<int> ret;
	if( st >= y ) {
		ret = doJob(x+1,y);
		ret.push_front(x);
	} else { 
		ret = doJob(x+1,y-st);
		ret.push_back(x);
	}
	return ret;
}

int main() {
	cin >> n >> m;
	deque<int> ans = doJob(1,m);
	for( int i = 0 ; i < n ; i++ ) 
		cout << ans[i] << ' ';
	cout << endl;
}