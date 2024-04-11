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
ll h, w;
char c[105][105];
vector< vector<P> > ans;

void change(ll x, ll y)
{
	if(c[x][y] == '0') c[x][y] = '1';
	else c[x][y] = '0';
}

void solve()
{
	ll b = 0;
	if(c[1][1]%2) b |= 1;
	if(c[2][1]%2) b |= 2;
	if(c[1][2]%2) b |= 4;
	if(c[2][2]%2) b |= 8;
	
	ll m[4] = {14, 13, 11, 7};
	
	ll ret = -1;
	rep(i, 0, 15){
		ll sum = 0;
		rep(j, 0, 3){
			if(i & (1<<j)) sum ^= m[j];
		}
		if(sum == b) ret = i;
	}
	assert(ret >= 0);
	
	if(ret & (1<<0)){
		vector<P> tmp;
		tmp.push_back(P(2, 1));
		tmp.push_back(P(1, 2));
		tmp.push_back(P(2, 2));
		ans.push_back(tmp);
	}
	if(ret & (1<<1)){
		vector<P> tmp;
		tmp.push_back(P(1, 1));
		tmp.push_back(P(1, 2));
		tmp.push_back(P(2, 2));
		ans.push_back(tmp);
	}
	if(ret & (1<<2)){
		vector<P> tmp;
		tmp.push_back(P(1, 1));
		tmp.push_back(P(2, 1));
		tmp.push_back(P(2, 2));
		ans.push_back(tmp);
	}
	if(ret & (1<<3)){
		vector<P> tmp;
		tmp.push_back(P(1, 1));
		tmp.push_back(P(2, 1));
		tmp.push_back(P(1, 2));
		ans.push_back(tmp);
	}
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> T;
	while(T--){
		cin >> h >> w;
		rep(y, 1, h)rep(x, 1, w) cin >> c[x][y];
		
		ans.clear();
		for(int y = h; y > 2; y--){
			rep(x, 1, w-1){
				if(c[x][y] == '1'){
					vector<P> tmp;
					tmp.push_back(P(x, y)), change(x, y);
					tmp.push_back(P(x, y-1)), change(x, y-1);
					tmp.push_back(P(x+1, y-1)), change(x+1, y-1);
					ans.push_back(tmp);
				}
			}
			if(c[w][y] == '1'){
				vector<P> tmp;
				tmp.push_back(P(w, y)), change(w, y);
				tmp.push_back(P(w, y-1)), change(w, y-1);
				tmp.push_back(P(w-1, y-1)), change(w-1, y-1);
				ans.push_back(tmp);
			}
		}
		
		for(int x = w; x > 2; x--){
			if(c[x][1] == '1'){
				vector<P> tmp;
				tmp.push_back(P(x, 1)), change(x, 1);;
				tmp.push_back(P(x-1, 1)), change(x-1, 1);;
				tmp.push_back(P(x-1, 2)), change(x-1, 2);;
				ans.push_back(tmp);
			}
			if(c[x][2] == '1'){
				vector<P> tmp;
				tmp.push_back(P(x, 2)), change(x, 2);;
				tmp.push_back(P(x-1, 1)), change(x-1, 1);;
				tmp.push_back(P(x-1, 2)), change(x-1, 2);;
				ans.push_back(tmp);
			}
		}
		
		solve();
		
		cout << ans.size() << endl;
		for(auto vec : ans){
			for(auto p : vec) cout << p.second << " " << p.first << " ";
			cout << endl;
		}
	}
	
	return 0;
}