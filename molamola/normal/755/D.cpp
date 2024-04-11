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

int T[1000010];
int read(int x, int y){
	int res = 0;
	for(int i=y+1;i;i-=(i&-i))res += T[i];
	for(int i=x;i;i-=(i&-i))res -= T[i];
	return res;
}

void solve(){
	int n, k; scanf("%d%d", &n, &k);
	k = min(n-k, k);
	ll ans = 1;
	for(int i=0, a=0;i<n;i++){
		int b = (a + k) % n;
		if(a <= b)ans += read(a+1, b-1);
		else{
			ans += read(a+1, n-1);
			ans += read(0, b-1);
		}
		for(int i=a+1;i<=n;i+=(i&-i))T[i]++;
		for(int i=b+1;i<=n;i+=(i&-i))T[i]++;
		a = b;
		ans++;
		printf("%lld ", ans);
	}
}

int main(){
	int Tc = 1; //scanf("%d", &Tc);
	for(int tc=1;tc<=Tc;tc++){
		solve();
	}
	return 0;
}