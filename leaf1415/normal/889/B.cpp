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
string s[100005];
set<ll> G[26], revG[26];
bool used[26];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	rep(i, 1, n) cin >> s[i];
	rep(i, 1, n){
		for(auto c : s[i]) used[c-'a'] = true;
		rep(j, 1, (int)s[i].size()-1){
			G[s[i][j-1]-'a'].insert(s[i][j]-'a');
			revG[s[i][j]-'a'].insert(s[i][j-1]-'a');
		}
	}
	rep(i, 0, 25){
		if(G[i].size() >= 2 || revG[i].size() >= 2){
			cout << "NO" << endl;
			return 0;
		}
	}
	
	ll cnt = 0;
	rep(i, 0, 25) if(used[i]) cnt++;
	
	string ans;
	rep(i, 0, 25){
		ll c = i;
		if(revG[c].size() || !used[c]) continue;
		while(1){
			ans += c+'a';
			if(G[c].size() == 0) break;
			c = *G[c].begin();
		}
	}
	if(ans.size() < cnt) cout << "NO" << endl;
	else cout << ans << endl;
	
	return 0;
}