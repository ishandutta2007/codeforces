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
typedef long long ll;
typedef pair<llint, llint> P;
bool exceed(ll x, ll y, ll m){return x >= m / y + 1;} 

ll T;
ll u, v;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> T;
	while(T--){
		cin >> u >> v;
		
		ll p = 0;
		for(int i = 30; i >= 0; i--){
			if(v & (1<<i)){
				p = i;
				break;
			}
		}
		bool flag = true;
		for(int i = 30; i > p; i--){
			if(u & (1<<i)){
				flag = false;
				break;
			}
		}
		if(!flag){
			cout << "NO" << "\n";
			continue;
		}
		
		for(int i = p; i >= 0; i--){
			if((v & (1<<i)) == 0 && (u & (1<<i))){
				flag = false;
				break;
			}
			if((u & (1<<i)) == 0 && (v & (1<<i))) break;
			if(u & (1<<i)) u &= ~(1<<i), v &= ~(1<<i);
		}
		
		set<int> S;
		rep(i, 0, 30) if(u & (1<<i)) S.insert(i);
		rep(i, 0, 30){
			if(v & (1<<i)){
				if(S.size() == 0 || *S.begin() > i){
					flag = false;
					break;
				}
				S.erase(S.begin());
			}
		}
		if(flag) cout << "YES" << "\n";
		else cout << "NO" << "\n";
	}
	flush(cout);
	
	return 0;
}