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
ll n;
ll a[200005];
ll l[200005], r[200005];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> T;
	while(T--){
		cin >> n;
		rep(i, 1, n) cin >> a[i];
		
		rep(i, 0, n+2) l[i] = r[i] = 0;
		rep(i, 1, n){
			l[i] = a[i] - l[i-1];
			if(l[i] < 0) l[i] = inf;
		}
		for(int i = n; i >= 1; i--){
			r[i] = a[i] - r[i+1];
			if(r[i] < 0) r[i] = inf;
		}
		if(l[n] == 0){
			cout << "YES" << endl;
			continue;
		}
		
		rep(i, 1, n-1){
			ll L = a[i+1] - l[i-1], R = a[i] - r[i+2];
			if(L >= 0 && R >= 0 && L == R){
				cout << "YES" << endl;
				goto end;
			}
		}
		cout << "NO" << endl;
		end:;
	}
	
	return 0;
}