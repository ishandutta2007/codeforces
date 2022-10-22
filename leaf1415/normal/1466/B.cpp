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

ll T;
ll n;
ll a[100005], cnt[200005];
set<ll> S;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> T;
	while(T--){
		cin >> n;
		rep(i, 1, n) cin >> a[i];
		
		rep(i, 1, 2*n+3) cnt[i] = 0;
		rep(i, 1, n) cnt[a[i]]++;
		
		S.clear();
		rep(i, 1, 2*n){
			if(cnt[i] == 0) continue;
			if(cnt[i] == 1){
				if(S.count(i)) S.insert(i+1);
				else S.insert(i);
			}
			else{
				S.insert(i+1);
				S.insert(i);
			}
		}
		cout << S.size() << endl;
	}
	return 0;
}