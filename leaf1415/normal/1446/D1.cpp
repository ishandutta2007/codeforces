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
#define rep(x, s, t) for(llint (x) = (s); (x) <= (t); (x)++)
#define chmin(x, y) (x) = min((x), (y))
#define chmax(x, y) (x) = max((x), (y))
#define all(x) (x).begin(),(x).end()
#define inf 1e9

using namespace std;

typedef long long llint;
typedef long long ll;
typedef pair<llint, llint> P;

int n;
int a[200005];
int sum[105][200005];
int dif[200005];
int lb[105][400005];
const int zero = 200002;

int calc(int l, int r)
{
	int mx = -1, mx_i, cnt = 0;
	rep(i, 1, 100){
		int x = sum[i][r] - sum[i][l-1];
		if(x > mx) mx = x, cnt = 1, mx_i = i;
		else if(x == mx) cnt++;
	}
	if(cnt == 1) return mx_i;
	return -1;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	rep(i, 1, n) cin >> a[i];

	rep(i, 1, n){
		rep(j, 1, 100) sum[j][i] = sum[j][i-1];
		sum[a[i]][i]++;
	}

	int f = calc(1, n);
	if(f < 0){
		cout << n << endl;
		return 0;
	}

	rep(i, 1, 100){
		rep(j, 1, n){
			dif[j] = dif[j-1];
			if(a[j] == f) dif[j]++;
			if(a[j] == i) dif[j]--;
		}
		dif[n+1] = inf;
		for(int j = n; j >= 1; j--){
			dif[j] = min(dif[j], dif[j+1]);
		}
		rep(j, -n, n) lb[i][zero+j] = inf;
		rep(j, 1, n) lb[i][zero+dif[j]] = j;
	}

	ll ans = 0;
	rep(i, 1, n){
		int mx = 0;
		rep(j, 1, 100){
			if(f == j) continue;
			int d = sum[f][i-1] - sum[j][i-1];
			int p = lb[j][zero+d];
			if(p >= i && p <= n) chmax(mx, p);
		}
		chmax(ans, mx-i+1);
		//cout << i << " " << mx << endl;
	}
	cout << ans << endl;

	return 0;
}