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

int n, m, A[550][550], B[550][550];

int main() {
	scanf("%d%d", &n, &m);
	rep(i, n) rep(j, m) scanf("%d", A[i]+j);
	rep(i, n) rep(j, m) { scanf("%d", B[i]+j); B[i][j] ^= A[i][j]; }
	int xa[550] = {}, xb[550] = {};
	rep(i, n) rep(j, m) xa[i] ^= B[i][j], xb[j] ^= B[i][j];
	rep(i, n) if(xa[i]) { puts("No"); return 0; }
	rep(i, m) if(xb[i]) { puts("No"); return 0; }
	puts("Yes");
	return 0;
}