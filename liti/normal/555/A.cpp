//In the name of Allah
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define __sz(x) ((int)(x).size())

const int maxN = 1000*100 + 100;
int a[maxN];
int main() { 
	int n,m; 
	cin >> n >> m;
	int cnt = 0; 
	int ans = 0;
	for( int i = 0 ; i < m ;i++ ) { 
		int k; cin >> k;
		int last; cin >> last;
		cnt++; 
		bool ch = false;
		int f = last;
		for( int j =1 ; j < k ; j++ ) { 
			int x; cin >> x; 
			if( !ch && (x > last + 1 || f != 1) ) { 
				ans += k - j; 
				cnt += k - j;
				ch = true;
			}
			last = x; 
		}
	}
	cout << ans + cnt - 1 << endl;
}