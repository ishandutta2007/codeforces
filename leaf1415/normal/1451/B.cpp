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
ll n, Q;
string s;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> T;
	while(T--){
		cin >> n >> Q;
		cin >> s;
		
		ll l[2] = {}, r[2] = {};
		l[0] = l[1] = inf, r[0] = r[1] = -inf;
		rep(i, 0, n-1){
			int c = s[i]-'0';
			chmin(l[c], i), chmax(r[c], i);
		}
		
		ll L, R;
		rep(q, 1, Q){
			cin >> L >> R;
			L--, R--;
			if(l[s[L]-'0'] < L || R < r[s[R]-'0']) cout << "YES" << endl;
			else cout << "NO" << endl;
		}
	}
	
	return 0;
}