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
#define pb push_back
#define szz(x) (int)x.size()
#define rep(i,n) for(int i=0;i<n;i++)
#define all(x) x.begin(),x.end()
typedef tuple<int, int, int> t3;

int m, n;
int hp[1000010];
int idx[2000020];

int main() {
	scanf("%d%d", &n, &m);
	for(int i=1;i<=m;i++) scanf("%d", hp + i);
	int sum_hp = 0;
	for(int i=1;i<=m;i++) sum_hp += hp[i];
	if(sum_hp % n != 0) {
		hp[1] += (n - sum_hp % n);
		sum_hp += (n - sum_hp % n);
	}
	int C = sum_hp / n;
	vector <int> w;
	for(int i=1, s=0;i<=m;i++) {
		s += hp[i];
		w.pb(s % n);
	}
	sort(all(w));
	w.pb(n);
	printf("%d\n", C);
	for(int i=1;i<szz(w);i++) printf("%d ", w[i] - w[i-1]); puts("");
	int ns = 0;
	for(int i=0, j=1;i<C;i++) {
		for(int k=0;k<m;k++) {
			printf("%d ", j);
			int v = w[k+1] - w[k];
			ns += v;
			if(ns == hp[j]) {
				ns = 0; ++j;
			}
		} puts("");
	}
	
	return 0;
}