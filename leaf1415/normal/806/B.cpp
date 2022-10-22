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
#define reps(x, s) for(llint (x) = 0; (x) < (llint)(s).size(); (x)++)
#define chmin(x, y) (x) = min((x), (y))
#define chmax(x, y) (x) = max((x), (y))
#define ceildiv(x, y) (((x)+(y)-1) / (y))
#define all(x) (x).begin(),(x).end()
#define outl(x) cout << x << endl
#define SP << " " << 
#define inf 1e18

using namespace std;

typedef long long llint;
typedef long long ll;
typedef pair<llint, llint> P;
bool exceed(ll x, ll y, ll m){return x >= m / y + 1;} 

ll n;
ll a[150][5];
ll cnt[5], cls[5];

vector<ll> vec;
bool dfs(int p, int m, ll s)
{
	if(p == 5){
		//cout << m << " " << s << endl;
		//for(auto x : vec) cout << x << " "; cout << endl;
		return s > 0;
	}
	rep(i, 1, 6){
		if(i > cls[p] && (1<<(i-1)) * cnt[p] > n + m) continue;
		if(i < cls[p] && (a[1][p] == 250 || (1<<i) * (cnt[p]+m) <= n + m)) continue;
		//vec.push_back(i);
		if(dfs(p+1, m, s + (i * 2) * (250 - a[1][p]) - (i * 2) * (250 - a[2][p]))) return true;
		//vec.pop_back();
	}
	return false;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	rep(i, 1, n) rep(j, 0, 4) cin >> a[i][j];
	rep(i, 1, n) rep(j, 0, 4){
		if(a[i][j] != -1) cnt[j]++;
		else a[i][j] = 250;
	}
	
	
	rep(i, 0, 100*n){
		rep(j, 0, 4){
			cls[j] = 6;
			rep(k, 1, 5){
				if((1<<k)*cnt[j] > n+i){
					cls[j] = k;
					break;
				}
			}
		}
		if(dfs(0, i, 0)){
			cout << i << endl;
			return 0;
		}
	}
	cout << -1 << endl;
	
	return 0;
}