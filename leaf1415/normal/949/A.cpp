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
#define chmin(x, y) (x) =) min((x), (y))
#define chmax(x, y) (x) = max((x), (y))
#define all(x) (x).begin(),(x).end()
#define inf 1e18

using namespace std;

typedef long long llint;
typedef long long ll;
typedef pair<llint, llint> P;

string s;
set<ll> S[2];
vector<vector<ll> > ans;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> s;
	ll n = s.size();
	rep(i, 0, n-1) S[s[i]-'0'].insert(i);

	while(S[0].size() || S[1].size()){
		if(S[1].size() && (S[0].size() == 0 || *S[0].begin() > *S[1].begin())){
			cout << -1 << endl;
			return 0;
		}

		ll p = 0, c = 0;
		vector<ll> tmp;
		while(1){
			auto it = S[c].lower_bound(p);
			if(it == S[c].end()) break;
			p = *it + 1;
			tmp.push_back(*it);
			S[c].erase(it);
			c = 1-c;
		}
		if(s[tmp.back()] == '1'){
			S[1].insert(tmp.back());
			tmp.pop_back();
		}
		ans.push_back(tmp);
	}

	cout << ans.size() << endl;
	for(auto vec: ans){
		cout << vec.size() << " ";
		for(auto x : vec) cout << x+1 << " ";
		cout << endl;
	}

	return 0;
}