#include <iostream>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <cassert>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <bitset>
#include <string>
#include <algorithm>
#include <utility>
#include <complex>
#define rep(x, s, t) for(llint (x) = (s); (x) <= (t); (x)++)
#define chmin(x, y) (x) = min((x), (y))
#define chmax(x, y) (x) = max((x), (y))
#define all(x) (x).begin(),(x).end()
#define inf 1e18

using namespace std;

typedef long long llint;
typedef long long ll;
typedef pair<llint, llint> P;

ll T;
ll n, m;
ll a[1000005][3];
ll ans[1005][1005];
string s;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> T;
	while(T--){
		cin >> n >> m;
		ll b;
		rep(i, 0, n-1) rep(j, 0, n-1){
			cin >> b;
			b--;
			a[i*n+j][0] = j, a[i*n+j][1] = i, a[i*n+j][2] = b;
		}
		cin >> s;
		
		ll x = 0, y = 1, z = 2, p[3] = {};
		for(auto c : s){
			if(c == 'I') swap(x, z);
			if(c == 'C') swap(y, z);
			if(c == 'L') p[x] = (p[x]+1)%n;
			if(c == 'R') p[x] = (p[x]+n-1)%n;
			if(c == 'U') p[y] = (p[y]+1)%n;
			if(c == 'D') p[y] = (p[y]+n-1)%n;
		};
		
		rep(i, 0, n*n-1){
			ans[(a[i][y]-p[y]+n)%n][(a[i][x]-p[x]+n)%n] = (a[i][z]-p[z]+n)%n;
		}
		
		rep(i, 0, n-1){
			rep(j, 0, n-1){
				cout << ans[i][j]+1 << " ";
			}
			cout << "\n";
		}
		cout << "\n";
	}
	flush(cout);
	
	return 0;
}