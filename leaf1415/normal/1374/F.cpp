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
llint a[505], b[505], c[505];
P p[505];
vector<llint> ans;

void ope(llint p)
{
	ans.push_back(p-2);
	swap(c[p], c[p-1]);
	swap(c[p-1], c[p-2]);
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> T;
	for(int t = 0; t < T; t++){
		cin >> n;
		for(int i = 1; i <= n; i++){
			cin >> a[i];
			p[i] = P(a[i], i);
		}
		sort(p+1, p+n+1);
		
		for(int i = 1; i <= n; i++) b[i] = p[i].second;
		for(int i = 1; i <= n; i++) c[b[i]] = i;
		
		llint cnt = 0, u = 0, v = 0;
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= n; j++){
				if(i >= j) continue;
				if(c[i] > c[j]) cnt++;
				if(a[i] == a[j]) u = i, v = j;
			}
		}
		
		if(cnt % 2){
			if(u == 0){
				cout << -1 << endl;
				continue;
			}
			swap(c[u], c[v]);
		}
		
		//for(int i = 1; i <= n; i++) cout << c[i] << " "; cout << endl;
		
		ans.clear();
		for(int i = n; i >= 3; i--){
			llint pos;
			for(int j = 1; j <= n; j++){
				if(c[j] == i){
					pos = j;
					break;
				}
			}
			for(int j = pos+2; j <= i; j++) ope(j);
			if(c[i] != i) ope(i);
		}
		//for(int i = 1; i <= n; i++) cout << c[i] << " "; cout << endl;
		
		cout << ans.size() << endl;
		for(int i = 0; i < ans.size(); i++) cout << ans[i] << " "; cout << endl;
	}
	
	return 0;
}