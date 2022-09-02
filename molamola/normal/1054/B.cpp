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
#define szz(x) ((int)(x).size())
#define rep(i, n) for(int i=0;i<n;i++)
#define all(x) (x).begin(), (x).end()
typedef tuple<int, int, int> t3;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef long double ldouble;

int main() {
	int n, A[100010];
	scanf("%d", &n);
	for(int i=1;i<=n;i++) {
		scanf("%d", A+i);
	}
	if(A[1] != 0) { puts("1"); return 0; }
	int mx = A[1];
	for(int i=2;i<=n;i++) {
		if(A[i] > mx + 1) {
			printf("%d\n", i);
			return 0;
		}
		mx = max(mx, A[i]);
	}
	puts("-1");
	return 0;
}