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
ll n;
set<ll> S;
vector<ll> vec;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> T;
	while(T--){
		cin >> n;
		
		vec.clear();
		ll p;
		rep(i, 1, n){
			cin >> p;
			vec.push_back(p);
		}
		
		S.clear();
		rep(i, 1, n) S.insert(i);
		
		vector<ll> ans;
		for(int i = n-1; i >= 0; i--){
			if(vec[i] == *S.rbegin()){
				ans.insert(ans.end(), vec.begin()+i, vec.end());
				vec.erase(vec.begin()+i, vec.end());
			}
			S.erase(vec[i]);
		}
		for(auto x : ans) cout << x << " "; cout << endl;
	}
	
	return 0;
}