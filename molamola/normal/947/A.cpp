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
typedef pair<int, int> pii;
typedef long long ll;
#define Fi first
#define Se second
#define pb(x) push_back(x)
#define szz(x) ((int)(x).size())
#define rep(i, n) for(int i=0;i<n;i++)
#define all(x) (x).begin(), (x).end()
typedef tuple<int, int, int> t3;
typedef pair<ll, ll> pll;
typedef long double ldouble;
typedef pair<double, double> pdd;

int D[1000010];
int p[1000010];

void solve(){
	for(int i=2;i<=1000000;i++) p[i] = i;
	for(int i=2;i<=1000000;i++) if(p[i]) {
		D[i] = i;
		for(int j=i+i;j<=1000000;j+=i) p[j] = 0, D[j] = i;
	}
	int x; scanf("%d", &x);
	int ans = 1e9;
	for(int i=x-D[x]+1;i<=x;i++) {
		int val;
		if(D[i] == i) val = i;
		else val = i - D[i] + 1;
		ans = min(ans, val);
	}
	printf("%d\n", ans);
}

int main(){
	int Tc = 1; // scanf("%d\n", &Tc);
	for(int tc=1;tc<=Tc;tc++){
		solve();
	}
	return 0;
}