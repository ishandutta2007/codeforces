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
#include <list>

using namespace std;
typedef pair<int, int> Pi;
typedef long long ll;
#define Fi first
#define Se second
#define pb(x) push_back(x)
#define sz(x) (int)x.size()
#define rep(i, n) for(int i=0;i<n;i++)
#define all(x) x.begin(), x.end()

char c[130];

void solve(){
	c['f'] = 1;
	c['e'] = 2;
	c['d'] = 3;
	c['a'] = 4;
	c['b'] = 5;
	c['c'] = 6;
	char S[130];
	scanf("%s", S);
	int n = (int)strlen(S);
	ll ans = c[S[n-1]]; S[n-1] = 0;
	ll X = atoll(S);
	ll Y = (X - 1) / 4;
	ans += Y * 16;
	if(X % 4 == 2 || X % 4 == 0)ans += 7;
	printf("%lld", ans);
}

int main(){
	int Tc = 1; //scanf("%d", &Tc);
	for(int tc=1;tc<=Tc;tc++){
		solve();
	}
	return 0;
}