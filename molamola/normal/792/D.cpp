#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>
#include <math.h>
#include <assert.h>
#include <queue>
#include <map>
#include <set>
#include <string>
#include <algorithm>
#include <iostream>
#include <functional>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <bitset>

using namespace std;
typedef pair<int, int> Pi;
typedef long long ll;
#define pii Pi
#define pll PL
#define Fi first
#define Se second
#define pb(x) push_back(x)
#define sz(x) ((int)(x).size())
#define rep(i, n) for(int i=0;i<n;i++)
#define all(x) (x).begin(), (x).end()
typedef tuple<int, int, int> t3;
typedef pair<ll, ll> PL;
typedef long double ldouble;

ll n; int q;
char temp[100010];

ll up(ll x){
	ll t = x & -x;
	ll res = x, y = x;
	x /= t;
	if((x&3) == 1)res += t;
	else res -= t;
	return res < n ? res : y;
}

ll left(ll x){
	if(x & 1)return x;
	ll t = x & -x;
	return x - t / 2;
}

ll right(ll x){
	if(x & 1)return x;
	ll t = x & -x;
	return x + t / 2;
}

void solve(){
	cin >> n >> q;
	rep(i, q){
		ll a;
		scanf("%lld%s", &a, temp);
		for(int i=0;temp[i];i++){
			char c = temp[i];
			if(c == 'U')a = up(a);
			else if(c == 'L')a = left(a);
			else a = right(a);
		}
		printf("%lld\n", a);
	}
}

int main(){
	int Tc = 1; // scanf("%d\n", &Tc);
	for(int tc=1;tc<=Tc;tc++){
		// printf("Case #%d: ", tc);
		solve();
	}
	return 0;
}