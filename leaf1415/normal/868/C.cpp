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

ll n, k;
ll a[100005][4];
ll cnt[16];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> k;
	rep(i, 1, n) rep(j, 0, k-1) cin >> a[i][j];
	rep(i, 1, n){
		ll b = 0;
		rep(j, 0, k-1) b |= a[i][j] << j;
		cnt[b]++;
	}
	if(cnt[0]){
		cout << "YES" << endl;
		return 0;
	}
	
	ll K = 1<<k;
	rep(i, 0, K-1){
		rep(j, 0, K-1){
			if(i&j) continue;
			if(cnt[i]*cnt[j] == 0) continue;
			cout << "YES" << endl;
			return 0;
		}
	}
	cout << "NO" << endl;
	
	return 0;
}