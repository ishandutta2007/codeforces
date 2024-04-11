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
typedef long long ll;
#define Fi first
#define Se second
#define pb(x) push_back(x)
#define sz(x) ((int)(x).size())
#define rep(i, n) for(int i=0;i<n;i++)
#define all(x) (x).begin(), (x).end()
typedef tuple<int, int, int> t3;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef long double ldouble;
typedef pair<double, double> pdd;

char A[100010], B[100010];
const int P1 = 1e9 + 7;
const int P2 = 1e9 + 33;
pii operator*(pii a, pii b) { return pii((ll)a.Fi * b.Fi % P1, (ll)a.Se * b.Se % P2); }
pii operator-(pii a, pii b) { return pii(a.Fi - b.Fi < 0 ? a.Fi - b.Fi + P1 : a.Fi - b.Fi, a.Se - b.Se < 0 ? a.Se - b.Se + P2 : a.Se - b.Se); }
pii operator+(pii a, pii b) { return pii((a.Fi + b.Fi >= P1 ? a.Fi + b.Fi - P1 : a.Fi + b.Fi), (a.Se + b.Se >= P2 ? a.Se + b.Se - P2 : a.Se + b.Se)); }

int N, M, x;
int D[32][100010];
pii SA[100010];
pii SB[100010];
const int PP = 31;
pii T[100010];

pii getA(int l, int r) {
	return (SA[r] - SA[l-1]) * T[N-l];
}

pii getB(int l, int r) {
	return (SB[r] - SB[l-1]) * T[N-l];
}

void solve(){
	scanf("%d%s%d%s", &N, A+1, &M, B+1);
	scanf("%d", &x);
	pii t = pii(1, 1); T[0] = t;
	for(int i=1;i<=N;i++) {
		SA[i] = SA[i-1] + t * pii(A[i] - 'a', A[i] - 'a');
		t = t * pii(PP, PP);
		T[i] = t;
	}
	t = pii(1, 1);
	for(int i=1;i<=M;i++) {
		SB[i] = SB[i-1] + t * pii(B[i] - 'a', B[i] - 'a');
		t = t * pii(PP, PP);
	}
	for(int i=1;i<=x;i++) {
		for(int j=1;j<=N;j++) {
			D[i][j] = max(D[i][j], D[i][j-1]);
			int p = D[i-1][j-1];
			int low = 1, high = min(M - p, N - j + 1), res = 0;
			while(low <= high) {
				int mid = (low + high) >> 1;
				if(getA(j, j+mid-1) == getB(p+1, p+mid)) res = mid, low = mid + 1;
				else high = mid - 1;
			}
			D[i][j+res-1] = max(D[i][j+res-1], p + res);
			//printf("%d,%d : %d\n", i, j, D[i][j]);
		}
	}
	if(D[x][N] == M) printf("YES\n");
	else puts("NO");
}

int main(){
	int Tc = 1; // scanf("%d\n", &Tc);
	for(int tc=1;tc<=Tc;tc++){
		// printf("Case #%d\n", tc);
		solve();
	}
	return 0;
};