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
#define reps(x, s) for(llint (x) = 0; (x) < (llint)(s).size(); (x)++)
#define chmin(x, y) (x) = min((x), (y))
#define chmax(x, y) (x) = max((x), (y))
#define ceildiv(x, y) (((x)+(y)-1) / (y))
#define all(x) (x).begin(),(x).end()
#define outl(x) cout << x << endl
#define SP << " " << 
#define inf 1e18

using namespace std;

typedef long long llint;
typedef int ll;
typedef pair<llint, llint> P;
bool exceed(ll x, ll y, ll m){return x >= m / y + 1;} 

ll n, Q;
map<P, char> mp;
map<P, ll> G[200005];
ll acnt, bcnt;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> Q;
	
	char t; ll u, v, x; char c;
	rep(q, 1, Q){
		//cout << acnt << " " << bcnt << endl;
		
		cin >> t;
		if(t == '?'){
			cin >> x;
			if(acnt) cout << "YES" << "\n";
			else{
				if(bcnt && x % 2) cout << "YES" << "\n";
				else cout << "NO" << "\n";
			}
		}
		if(t == '+'){
			cin >> u >> v >> c;
			mp[P(u, v)] = c;
			if(mp.count(P(v, u)) == 0) continue;
			bcnt++;
			
			char d = mp[P(v, u)];
			if(c == d) acnt++;
		}
		if(t == '-'){
			cin >> u >> v;
			char c = mp[P(u, v)];
			mp.erase(P(u, v));
			if(mp.count(P(v, u)) == 0) continue;
			bcnt--;
			
			char d = mp[P(v, u)];
			if(c == d) acnt--;
		}
	}
	flush(cout);
	
	return 0;
}