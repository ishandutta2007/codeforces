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

ll A[100010];
int n;
ll k;

void solve(){
	scanf("%d%lld", &n, &k);
	for(int i=1;i<=n;i++)scanf("%lld", A+i);
	vector <ll> v;
	if(k == 1)v.pb(1);
	else if(k == -1)v.pb(-1), v.pb(1);
	else{
		v.pb(1);
		ll t = k;
		while(abs(t) < 1e15){
			v.pb(t);
			t = t * k;
		}
	}
	ll S[100010] = {};
	for(int i=1;i<=n;i++)S[i] = S[i-1] + A[i];
	ll ans = 0;
	for(auto e : v){
		map <ll, int> M;
		M[0]++;
		for(int i=1;i<=n;i++){
			ans += M[S[i] - e];
			M[S[i]]++;
		}
	}
	printf("%lld\n", ans);
}

int main(){
	int Tc = 1; //scanf("%d", &Tc);
	for(int tc=1;tc<=Tc;tc++){
		//printf("Case #%d: ", tc);
		solve();
	}
	return 0;
}