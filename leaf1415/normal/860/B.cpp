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
string s[70005];
map<string, ll> mp;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	rep(i, 1, n) cin >> s[i];
	rep(i, 1, n){
		set<string> S;
		rep(j, 0, 9) rep(k, 0, 9){
			if(j > k) continue;
			S.insert(s[i].substr(j, k-j+1));
		}
		for(auto s : S) mp[s]++;
	}
	
	rep(i, 1, n){
		rep(len, 1, 10){
			rep(l, 0, 9){
				if(l+len-1 >= 10) continue;
				string t = s[i].substr(l, len);
				if(mp[t] == 1){
					cout << t << endl;
					goto end;
				}
			}
		}
		end:;
	}
	
	return 0;
}