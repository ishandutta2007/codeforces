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

llint n, Q;
llint p[100005];
multiset<llint> S, T;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> Q;
	for(int i = 1; i <= n; i++){
		cin >> p[i];
		S.insert(p[i]);
	}
	sort(p+1, p+n+1);
	for(int i = 1; i < n; i++) T.insert(p[i+1]-p[i]);
	
	if(S.size() <= 2) cout << 0 << "\n";
	else cout << *S.rbegin() - *S.begin() - *T.rbegin() << "\n";
	
	llint t, x;
	for(int i = 1; i <= Q; i++){
		cin >> t >> x;
		if(t == 0){
			auto it = S.lower_bound(x);
			auto nit = it; nit++;
			if(nit != S.end()){
				T.erase(T.lower_bound(*nit-*it));
			}
			if(it != S.begin()){
				auto pit = it; pit--;
				T.erase(T.lower_bound(*it-*pit));
				if(nit != S.end()) T.insert(*nit-*pit);
			}
			S.erase(it);
		}
		else{
			S.insert(x);
			auto it = S.lower_bound(x);
			auto nit = it; nit++;
			if(nit != S.end()){
				T.insert(*nit-*it);
			}
			if(it != S.begin()){
				auto pit = it; pit--;
				T.insert(*it-*pit);
				if(nit != S.end()) T.erase(T.lower_bound(*nit-*pit));
			}
		}
		
		if(S.size() <= 2) cout << 0 << "\n";
		else cout << *S.rbegin() - *S.begin() - *T.rbegin() << "\n";
	}
	flush(cout);
	
	return 0;
}