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

char A[] = "What are you doing at the end of the world? Are you busy? Will you save us?";
char B[] = "What are you doing while sending \"";
char C[] = "\"? Are you busy? Will you send \"";
char D[] = "\"?";
ll L[100010] = {};
int lb, lc, ld;

char Do(int n, ll K) {
	if(n == 0) {
		if(K <= (int)strlen(A)) return A[K-1];
		return '.';
	}
	else if(K <= lb) return B[K-1];
	else if(L[n-1] + lb >= K) return Do(n-1, K - lb);
	else if(lb + L[n-1] + lc >= K) return C[K - lb - L[n-1] - 1];
	else if(lb + L[n-1] + lc + L[n-1] >= K) return Do(n-1, K - lb - L[n-1] - lc);
	else if(lb + L[n-1] + lc + L[n-1] + ld >= K) return D[K - lb - L[n-1] - lc - L[n-1] - 1];
	return '.';
}

void solve() {
	int n; ll k; scanf("%d%lld", &n, &k);
	printf("%c", Do(n, k));
}

int main() {
	L[0] = (int)strlen(A);
	lb = (int)strlen(B);
	lc = (int)strlen(C);
	ld = (int)strlen(D);
	for(int i=1;i<100010;i++) {
		L[i] = 2 * L[i-1] + (int)strlen(B) + (int)strlen(C) + (int)strlen(D);
		if(L[i] > 2e18) L[i] = 2e18;
	}
	int Tc = 1; scanf("%d", &Tc);
	while(Tc--) {
		solve();
	} puts("");
	return 0;
}