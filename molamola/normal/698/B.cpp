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

int n, a[200020];
int p[200020];
int Find(int x){return p[x] == x ? x : p[x] = Find(p[x]) ;}

void solve(){
	scanf("%d", &n);
	for(int i=1;i<=n;i++)p[i] = i;
	int t = 0;
	for(int i=1;i<=n;i++){
		scanf("%d", a+i);
		int x = Find(i), y = Find(a[i]);
		if(x != y)p[x] = y;
		if(a[i] == i)t = 1;
	}
	int ans = 0;
	for(int i=1;i<=n;i++)if(p[i] == i)++ans;
	if(t == 0){
		vector <int> v;
		for(int i=1;i<=n;i++)if(p[i] == i)v.pb(i);
		for(int i=0;i<sz(v);i++)a[v[i]] = v[0];
		printf("%d\n", ans);
		for(int i=1;i<=n;i++)printf("%d ", a[i]); puts("");
	}
	else{
		vector <int> v;
		int pp = -1;
		for(int i=1;i<=n;i++)if(p[i] == i){
			if(a[i] == i && pp == -1)pp = i;
			else v.pb(i);
		}
		for(int e : v)a[e] = pp;
		printf("%d\n", ans - 1);
		for(int i=1;i<=n;i++)printf("%d ", a[i]); puts("");
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