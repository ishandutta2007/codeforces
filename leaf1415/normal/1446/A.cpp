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

typedef long long llint;
typedef pair<llint, llint> P;

llint T;
llint n, W;
P p[200005];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> T;
	while(T--){
		cin >> n >> W;
		rep(i, 1, n) cin >> p[i].first, p[i].second = i;
		
		llint sum = 0; vector<llint> vec;
		rep(i, 1, n){
			if(p[i].first >= (W+1)/2 && p[i].first <= W){
				cout << 1 << endl;
				cout << i << endl;
				goto end;
			}
		}
		sort(p+1, p+n+1);
		
		rep(i, 1, n){
			if(sum + p[i].first > W) break;
			vec.push_back(p[i].second);
			sum += p[i].first;
		}
		if(sum >= (W+1)/2 && sum <= W){
			cout << vec.size()  << endl;
			for(auto x : vec) cout << x << " ";
			cout << endl;
		}
		else cout << -1 << endl;
		
		end:;
	}
	
	return 0;
}