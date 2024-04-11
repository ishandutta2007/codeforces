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

typedef long long ll;
typedef long long llint;
typedef pair<llint, llint> P;

ll n;
set<ll> S;
map<string, vector<ll> > mp[1000005];
char ans[2000005];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	string s; ll k, x;
	rep(i, 1, n){
		cin >> s;
		vector<ll> &vec = mp[s.size()][s];
		cin >> k;
		rep(j, 1, k){
			cin >> x;
			vec.push_back(x);
		}
	}
	rep(i, 1, 2000005) S.insert(i);

	ll len = 0;
	for(int i = 1000000; i >= 1; i--){
		for(auto p : mp[i]){
			string s = p.first; vector<ll> &vec = p.second;
			for(auto x : vec){
				auto it = S.lower_bound(x);
				ll p = *it - x;
				rep(j, p, (int)s.size()-1){
					if(S.count(x+j) == 0) break;
					ans[x+j] = s[j];
					chmax(len, x+j);
					S.erase(x+j);
				}
			}
		}
	}

	rep(i, 1, len){
		if(ans[i] == 0) ans[i] = 'a';
		cout << ans[i];
	}
	cout << endl;

	return 0;
}