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

int n, a[110], d[110][3];

void solve(){
	scanf("%d", &n);
	for(int i=1;i<=n;i++)scanf("%d", a+i);
	for(int i=1;i<=n;i++){
		d[i][0] = min({d[i-1][0], d[i-1][1], d[i-1][2]}) + 1;
		if(a[i] & 1)d[i][1] = min(d[i-1][0], d[i-1][2]);
		else d[i][1] = 1e9;
		if(a[i] & 2)d[i][2] = min(d[i-1][0], d[i-1][1]);
		else d[i][2] = 1e9;
	}
	printf("%d\n", min({d[n][0], d[n][1], d[n][2]}));
}

int main(){
	int Tc = 1; // scanf("%d\n", &Tc);
	for(int tc=1;tc<=Tc;tc++){
		// printf("Case #%d: ", tc);
		solve();
	}
	return 0;
}