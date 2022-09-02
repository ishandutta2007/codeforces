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

int n, c[2];

int main() {
	scanf("%d", &n);
	rep(i, n) {
		int x; scanf("%d", &x); --x;
		c[x]++;
	}
	if(c[0] == n) { rep(i, n) printf("1 "); puts(""); }
	else if(c[1] == n) { rep(i, n) printf("2 "); puts(""); }
	else {
		printf("2 1 ");
		rep(i, c[1] - 1) printf("2 ");
		rep(i, c[0] - 1) printf("1 ");
		puts("");
	}
	return 0;
}