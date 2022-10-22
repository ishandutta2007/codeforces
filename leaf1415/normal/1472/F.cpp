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
typedef pair<P, llint> T;

ll Q;
ll n, m;
map<ll, ll> mp;
vector<P> vec;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> Q;
	while(Q--){
		cin >> n >> m;
		
		mp.clear();
		ll x, y;
		rep(i, 1, m){
			cin >> y >> x;
			mp[x] += y;
		}
		mp[n+1] = 3;
		
		vec.clear();
		for(auto p : mp) vec.push_back(P(p.first, p.second));
		sort(all(vec));
		
		ll s = 3, pos = 0;
		for(auto p : vec)
		{
			if(s == 3){
				s = p.second;
				pos = p.first;
				continue;
			}
			if(p.second == 3){
				cout << "NO" << endl;
				goto end;
			}
			if(p.second == s && (p.first - pos) % 2 == 0){
				cout << "NO" << endl;
				goto end;
			}
			if(p.second != s && (p.first - pos) % 2){
				cout << "NO" << endl;
				goto end;
			}
			s = 3;
			pos = p.first;
		}
		cout << "YES" << endl;
		end:;
	}
	
	return 0;
}