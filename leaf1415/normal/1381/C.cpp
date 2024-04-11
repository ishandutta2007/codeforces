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
#define llint long long
#define inf 1e18
#define rep(x, s, t) for(llint (x) = (s); (x) < (t); (x)++)
#define Rep(x, s, t) for(llint (x) = (s); (x) <= (t); (x)++)
#define chmin(x, y) (x) = min((x), (y))
#define chmax(x, y) (x) = max((x), (y))

using namespace std;
typedef pair<llint, llint> P;
typedef pair<P, llint> E;

llint T;
llint n, x, y;
llint b[100005];
llint cnt[100005];
vector<P> vec;
vector<E> pvec;
llint pos[100005];
map<llint, llint> mp;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> T;
	for(int z = 0; z < T; z++){
		cin >> n >> x >> y;
		for(int i = 1; i <= n; i++) cin >> b[i];
		
		vec.clear();
		for(int i = 1; i <= n+1; i++) cnt[i] = 0;
		for(int i = 1; i <= n; i++){
			vec.push_back(P(cnt[b[i]], i));
			cnt[b[i]]++;
		}
		sort(vec.begin(), vec.end());
		
		llint c;
		for(int i = 1; i <= n+1; i++){
			if(cnt[i] == 0){
				c = i;
				break;
			}
		}
		
		pvec.clear(); mp.clear();
		for(int i = 0; i < y-x; i++){
			pvec.push_back(E(P(b[vec[i].second], 0), vec[i].second));
		}
		for(int i = 0; i < pvec.size(); i++) mp[pvec[i].first.first]++;
		
		llint shift = 0;
		for(auto it = mp.begin(); it != mp.end(); it++) shift = max(shift, it->second);
		
		for(int i = y-x; i < n-x; i++){
			pvec.push_back(E(P(b[vec[i].second], 1), vec[i].second));
		}
		for(int i = 0; i < pvec.size(); i++) mp[pvec[i].first.first]++;
		
		llint mx = 0;
		for(auto it = mp.begin(); it != mp.end(); it++) mx = max(mx, it->second);
		if(mx > n-x){
			cout << "NO" << endl;
			continue;
		}
		
		//for(int i = 0; i < pvec.size(); i++) cout << pvec[i].first.first << " " << pvec[i].first.second << " " << pvec[i].second << endl;
		
		sort(pvec.begin(), pvec.end());
		for(int i = 0; i < pvec.size(); i++){
			if(pvec[i].first.second == 1) b[pvec[i].second] = c;
		}
		
		for(int i = 1; i <= n; i++) pos[i] = -1;
		for(int i = 0; i < pvec.size(); i++){
			pos[pvec[i].second] = pvec[(i+shift)%(n-x)].second;
		}
		
		cout << "YES" << endl;
		for(int i = 1; i <= n; i++){
			if(pos[i] == -1) cout << b[i] << " ";
			else cout << b[pos[i]] << " ";
		}
		cout << endl;
	}
	
	return 0;
}