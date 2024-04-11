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

int mat[12][12];
int V[12];
const int mod = 1e6 + 3;

int pw(int x, int y = mod - 2) {
	int res = 1;
	while(y) {
		if(y & 1) res = (ll) res * x % mod;
		x = (ll) x * x % mod;
		y >>= 1;
	}
	return res;
}

int main() {
	rep(i, 11) {
		int v = 1;
		rep(j, 11) {
			mat[i][j] = v;
			v = (ll) v * i % mod;
		}
	}
	
	
	for(int i=0;i<11;i++) {
		printf("? %d\n", i);
		fflush(stdout);
		int v; scanf("%d", &v);
		V[i] = v;
	}
	
	
	for(int i=0, a=0;i<11;i++) {
		int f = -1;
		for(int j=a;j<11;j++) if(mat[j][i] != 0) { f = j; break; }
		if(f == -1) puts("?");
		for(int j=i;j<11;j++) swap(mat[i][j], mat[f][j]);
		swap(V[i], V[f]);
		int val = pw(mat[f][i]);
		for(int j=i;j<11;j++) mat[f][j] = (ll)mat[f][j] * val % mod;
		V[f] = (ll) V[f] * val % mod;
		
		for(int j=f+1;j<11;j++) {
			val = mat[j][i];
			for(int k=i;k<11;k++) mat[j][k] = (mat[j][k] - (ll)val * mat[f][k] % mod + mod) % mod;
			V[j] = (V[j] - (ll)val * V[f] % mod + mod) % mod;
		}
		++a;
	}
	
	for(int i=10;i>=0;i--) {
		for(int j=i+1;j<11;j++) V[i] = (V[i] - (ll)mat[i][j] * V[j] % mod + mod) % mod;
	}
	int ans = -1;
	for(int i=0;i<mod;i++) {
		int r = 0;
		for(int j=10;j>=0;j--) {
			r = ((ll)r * i + V[j]) % mod;
		}
		if(r == 0) {
			ans = i; break;
		}
	}
	printf("! %d\n", ans);
	fflush(stdout);
	
	return 0;
}