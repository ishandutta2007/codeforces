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

using namespace std;
typedef long long ll;
#define Fi first
#define Se second
#define pb(x) push_back(x)
#define sz(x) (int)x.size()
#define rep(i, n) for(int i=0;i<n;i++)
#define all(x) x.begin(), x.end()
typedef pair<int, int> pii;
typedef tuple<int, int, int> t3;
typedef pair<ll, ll> pll;

const int MOD = 1e9 + 7;
int P[1000010];
char S[1000010];

void solve(){
	scanf("%s", S+1);
	int n = (int)strlen(S+1);
	ll ans = 0, now = 0;
	for(int i=n;i;i--){
		if(S[i] == 'b'){
			now = (now + 1) % MOD;
		}
		else{
			ans = (ans + now) % MOD;
			now = now * 2 % MOD;
		}
	}
	printf("%lld\n", ans);
}

int main(){
	int Tc = 1; //scanf("%d", &Tc);
	for(int tc=1; tc<=Tc; tc++){
		solve();
	}
	return 0;
}