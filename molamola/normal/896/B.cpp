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

int n, m, c;
int A[1010];
int chk() {
	for(int i=1;i<=n;i++) if(A[i] == -1) return 0;
	for(int i=1;i<n;i++) if(A[i] > A[i+1]) return 0;
	return 1;
}

void solve() {
	memset(A, -1, sizeof A);
	scanf("%d%d%d", &n, &m, &c);
	int h = (c + 1) / 2;
	while(1) {
		int x;
		scanf("%d", &x);
		if(x <= h) {
			for(int i=1;i<=n;i++) if(A[i] > x || A[i] == -1) { A[i] = x; printf("%d\n", i); fflush(stdout); break; }
		}
		else {
			for(int i=n;i;i--) if(A[i] < x || A[i] == -1) { A[i] = x; printf("%d\n", i); fflush(stdout); break; }
		}
		if(chk()) break;
	}
	
}

int main() {
	solve();
	return 0;
}