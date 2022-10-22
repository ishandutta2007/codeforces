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

llint T;
llint n;
llint a[505], b[505];
multiset<P> S;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> T;
	for(int t = 0; t < T; t++){
		cin >> n;
		for(int i = 1; i <= n; i++) cin >> a[i];
		for(int i = 1; i <= n; i++) cin >> b[i];
		
		if(n%2){
			if(a[n/2+1] != b[n/2+1]){
				cout << "No" << endl;
				continue;
			}
		}
		
		S.clear();
		for(int i = 1; i <= n/2; i++){
			P p = P(a[i], a[n+1-i]);
			if(p.first > p.second) swap(p.first, p.second);
			S.insert(p);
		}
		
		for(int i = 1; i <= n/2; i++){
			P p = P(b[i], b[n+1-i]);
			if(p.first > p.second) swap(p.first, p.second);
			auto it = S.lower_bound(p);
			if(it == S.end() || *it != p){
				cout << "No" << endl;
				goto end;
			}
			S.erase(it);
		}
		cout << "Yes" << endl;
		end:;
	}
	
	return 0;
}