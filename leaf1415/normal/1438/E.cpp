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
#define inf 1e18

using namespace std;

typedef long long llint;
typedef pair<llint, llint> P;

llint n;
llint a[200005], s[200005], k[200005];
llint succ[200005][35], smin[200005][35];

llint getketa(llint x)
{
	llint ret = 0;
	for(llint t = x; t; t/=2) ret++;
	ret--;
	return ret;
}

llint calc(bool flag = 0)
{
	rep(i, 1, n){
		s[i] = s[i-1] + a[i];
		k[i] = getketa(a[i]);
	}
	rep(j, 0, 30) succ[n][j] = n+1;
	for(int i = n-1; i >= 1; i--){
		rep(j, 0, 30) succ[i][j] = succ[i+1][j];
		succ[i][k[i+1]] = i+1;
	}
	rep(i, 1, n){
		smin[i][30] = succ[i][30];
		for(int j = 29; j >= 0; j--){
			smin[i][j] = min(smin[i][j+1], succ[i][j]);
		}
	}
	
	llint ret = 0;
	if(flag){
		rep(i, 1, n){
			llint r = succ[i][k[i]];
			if(r <= n){
				if(r >= i+2 && (a[i]^a[r]) == s[r-1]-s[i]) ret++;//, cout << i << " " << r << endl;
			}
		}
	}
	//cout << ret << endl;
	
	rep(i, 1, n){
		llint p = i, d = k[i] + 1;
		while(1){
			if(d > 30 || smin[p][d] > n) break;
			llint np = smin[p][d];
			//cout << i << " " << p << " " << np << " " << d << endl;
			if(np >= i+2){
				if((a[i]^a[np]) == s[np-1]-s[i]) ret++;//, cout << "! " << i << " " << np << endl;
			}
			d = chmax(d, getketa(s[np]-s[i]));
			p = np;
		}
	}
	return ret;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	rep(i, 1, n) cin >> a[i];
	
	/*llint cnt = 0;
	rep(i, 1, n){
		rep(j, 1, n){
			if(i+1 >= j) continue;
			llint sum = 0;
			rep(k, i+1, j-1){
				sum += a[k];
			}
			if(sum == (a[i]^a[j])) cnt++, cout << "# " << i << " " << j << endl;
		}
	}
	cout << "# " << cnt << endl;*/
	
	llint ans = calc(1);
	reverse(a+1, a+n+1);
	//cout << "*" << endl;
	ans += calc(0);
	cout << ans << endl;
	
	return 0;
}