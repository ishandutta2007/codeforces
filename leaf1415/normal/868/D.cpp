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

ll n, Q;
string s[205];
string l[205], r[205];
bool dp[205][10][1<<9];

void check(string &s, ll id)
{
	rep(len, 1, 9){
		rep(j, 0, (int)s.size()-1){
			if(j+len-1 >= s.size()) break;
			ll x = 0;
			rep(k, j, j+len-1) x <<= 1, x += s[k]%2;
			dp[id][len][x] = true;
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	rep(i, 1, n){
		cin >> s[i];
		if(s[i].size() <= 9) l[i] = r[i] = s[i];
		else{
			l[i] = s[i].substr(0, 9);
			r[i] = s[i].substr((int)s[i].size()-9, 9);
		}
		check(s[i], i);
	}
	
	cin >> Q;
	ll a, b, id = n+1;
	rep(q, 1, Q){
		cin >> a >> b;
		string t = r[a] + l[b];
		check(t, id);
		
		rep(i, 1, 9) rep(j, 0, (1<<i)-1){
			dp[id][i][j] |= dp[a][i][j];
			dp[id][i][j] |= dp[b][i][j];
		}
		
		l[id] = l[a] + l[b];
		if(l[id].size() > 9) l[id] = l[id].substr(0, 9);
		r[id] = r[a]+r[b];
		if(r[id].size() > 9) r[id] = r[id].substr((int)r[id].size()-9, 9);
		
		int ans = 0;
		for(int len = 9; len >= 1; len--){
			bool flag = true;
			rep(i, 0, (1<<len)-1) flag &= dp[id][len][i];
			if(flag){
				ans = len;
				break;
			}
		}
		id++;
		
		cout << ans << endl;
	}
	
	return 0;
}