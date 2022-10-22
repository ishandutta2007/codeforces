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

ll n;
ll a[55], b[55];
ll p[55];
map<ll, vector<ll> > mp;
ll dp[55][55][55][55];

bool check(ll x)
{
	mp.clear();
	rep(i, 1, n) p[i] = (x*b[i] - 1000*a[i]);
	rep(i, 1, n) mp[-a[i]].push_back(p[i]);
	
	///rep(i, 1, n) cout << p[i] << " "; cout << endl;
	
	ll m = mp.size(), i = 0;
	for(auto p : mp){
		vector<ll> &vec = p.second; 
		rep(j, 0, (int)vec.size()){
			rep(k, 0, n){
				rep(l, 0, n){
					dp[i][j][k][l] = -inf;
				}
			}
		}
		i++;
	}
	rep(j, 0, n){
		rep(k, 0, n){
			rep(l, 0, n){
				dp[m][j][k][l] = -inf;
			}
		}
	}
	dp[0][0][0][0] = 0;
	
	i = 0;
	for(auto p : mp){
		vector<ll> &vec = p.second; 
		rep(j, 0, (int)vec.size()-1){
			//cout << vec[j] << " ";
			rep(k, 0, n){
				rep(l, 0, n){
					chmax(dp[i][j+1][k][l+1], dp[i][j][k][l] + vec[j]);
					if(k-1 >= 0) chmax(dp[i][j+1][k-1][l], dp[i][j][k][l]);
				}
			}
		}
		rep(k, 0, n){
			rep(l, 0, n){
				if(k+l <= n) chmax(dp[i+1][0][k+l][0], dp[i][(int)vec.size()][k][l]);
			}
		}
		i++;
	}
	
	ll ret = -inf;
	rep(k, 0, n) chmax(ret, dp[m][0][k][0]);
	//cout << x << " " << ret << endl;
	
	return ret >= 0;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	rep(i, 1, n) cin >> a[i];
	rep(i, 1, n) cin >> b[i];
	
	llint ub = 2e11, lb = 0, mid;
	while(ub-lb>1){
		mid = (ub+lb)/2;
		if(check(mid)) ub = mid;
		else lb = mid;
	}
	cout << ub << endl;
	
	return 0;
}