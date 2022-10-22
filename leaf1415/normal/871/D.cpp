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
#define mod 1000000007

using namespace std;

typedef long long llint;
typedef long long ll;
typedef pair<llint, llint> P;

ll n;
const int M = 10000000;
ll prime[M+5];
ll pcnt[M+5], psum[M+5];
ll euler[M+5];


int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	
	rep(i, 2, M){
		if(prime[i]) continue;
		for(int j = 2*i; j <= M; j+=i) if(prime[j] == 0) prime[j] = i;
	}
	rep(i, 0, M) euler[i] = i;
	rep(i, 2, M){
		if(euler[i] == i){
			for(int j = i; j <= M; j+=i) euler[j] = euler[j] / i * (i-1);
		}
	}
	
	ll cnt = 0, ans = 0;
	rep(i, 2, n){
		if(prime[i] || i*2 <= n){
			ans -= (i-1) - euler[i];
			cnt++;
			if(prime[i] == 0) pcnt[i]++;
			else pcnt[prime[i]]++;
		}
	}
	//cout << ans << " " << cnt << endl;
	ans += cnt * (cnt-1) / 2 * 3;
	
	//cout << ans << endl;
	rep(i, 2, n){
		if(prime[i] == 0) ans -= pcnt[i] * (pcnt[i] - 1) / 2;
		else{
			ll p = prime[i], q = i / p;
			if(prime[q] == 0 && p != q) ans -= pcnt[p] * pcnt[q];
		}
		//cout << i << " " << pcnt[i] << " " << ans << endl;
	}
	cout << ans << endl;
	
	return 0;
}