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
string s;
ll f[1<<20];

void FWT(llint f[], int n)
{
	int N = 1 << n;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < N; j++){
			if(j & (1<<i)) continue;
			llint x = f[j], y = f[j|(1<<i)];
			f[j] = (x + y*2) % mod, f[j|(1<<i)] = (2*x + y) % mod;
		}
	}
}


int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> s;
	ll N = s.size();
	
	rep(i, 0, N-1) f[i] = s[i]%2;
	FWT(f, n);
	
	ll ans = 0;
	rep(i, 0, N-1) if(s[i] == '0') ans += f[i], ans %= mod;
	ans *= 3, ans %= mod;
	cout << ans << endl;
	
	
	return 0;
}