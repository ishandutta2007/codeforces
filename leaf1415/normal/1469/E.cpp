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

ll Q;
ll n, k;
string s;
ll z[1000005];
bool used[1<<20];
vector<ll> vec;

ll get(ll l, ll len)
{
	ll ret = 0;
	rep(i, 0, len-1) ret *= 2, ret += s[l+i] % 2;
	return ret;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	srand(time(NULL));
	
	cin >> Q;
	while(Q--){
		cin >> n >> k;
		cin >> s;
		rep(i, 0, n-1){
			if(s[i] == '0') s[i] = '1';
			else s[i] = '0';
		}
		
		ll cnt = 0;
		for(int i = n-1; i >= 0; i--){
			if(s[i] == '0') cnt++;
			else cnt = 0;
			z[i] = cnt;
		}
		
		if(k <= 20){
			rep(i, 0, n-1){
				if(i+k-1 >= n) break;
				ll x = get(i, k);
				used[x] = true;
				vec.push_back(x);
			}
		}
		else{
			rep(i, 0, n-1){
				if(i+k-1 >= n) break;
				if(z[i] < k-20) continue;
				ll x = get(i+k-20, 20);
				used[x] = true;
				vec.push_back(x);
			}
		}
		
		ll x = -1;
		for(int i = 0; i < (1<<min(20LL, k)); i++){
			if(!used[i]){
				x = i;
				break;
			}
		}
		for(auto x : vec) used[x] = false;
		vec.clear();
		
		if(x == -1){
			cout << "NO" << endl;
			continue;
		}
		cout << "YES" << endl;
		
		string ans;
		rep(i, 1, max(0LL, k-20)) ans += '0';
		for(int i = min(19LL, k-1); i >= 0; i--) ans += ((x>>i)&1) + '0';
		cout << ans << "\n";
	}
	flush(cout);
	
	return 0;
}