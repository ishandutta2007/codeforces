#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>
#include <math.h>
#include <assert.h>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <string>
#include <algorithm>
#include <iostream>
#include <functional>
#include <unordered_set>
#include <bitset>
#include <time.h>
#include <limits.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define Fi first
#define Se second
#define pb(x) push_back(x)
#define szz(x) (int)x.size()
#define sz(x) (int)x.size()
#define rep(i,n) for(int i=0;i<n;i++)
#define all(x) x.begin(),x.end()
typedef tuple<int, int, int> t3;

int n, c[100010], t[100010];

int main() {
	scanf("%d", &n);
	for(int i=1;i<=n;i++) scanf("%d", c+i);
	vector <int> w, v;
	for(int i=1;i<=n;i++) scanf("%d", t+i);
	if(c[1] != t[1]) {
		puts("No");
		return 0;
	}
	for(int i=2;i<=n;i++) w.pb(c[i] - c[i-1]);
	for(int i=2;i<=n;i++) v.pb(t[i] - t[i-1]);
	sort(all(w));
	sort(all(v));
	rep(i, szz(w)) if(v[i] != w[i]) {
		puts("No");
		return 0;
	}
	
	puts("Yes");
	return 0;
}