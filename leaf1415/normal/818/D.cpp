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

ll n, A;
ll c[100005];
bool used[1000005];
ll cnt[1000005];
set<P> S;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> A;
	rep(i, 1, n) cin >> c[i];
	
	rep(i, 1, 1000000){
		if(i != A) S.insert(P(0, i));
	}
	
	ll x = 0;
	rep(i, 1, n){
		if(c[i] != A){
			if(used[c[i]]) continue;
			S.erase(P(cnt[c[i]], c[i]));
			cnt[c[i]]++;
			S.insert(P(cnt[c[i]], c[i]));
		}
		else{
			x++;
			while(S.size() && S.begin()->first < x){
				used[S.begin()->second] = true;
				S.erase(S.begin());
			}
		}
	}
	if(S.size()) cout << S.begin()->second << endl;
	else cout << -1 << endl;
	
	return 0;
}