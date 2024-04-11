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

int N, A[300030];
ll ans;

int main() {
	scanf("%d", &N);
	for(int i=1;i<=N;i++) {
		scanf("%d", A+i);
	}
	ll p = 0;
	for(int i=1;i<=N;i++) {
		ll x = A[i];
		if(2 * p >= x) {
			ll t = x / 2;
			ans += t;
			x -= 2 * t; p -= t;
			p += x;
		}
		else {
			ans += p;
			x -= 2 * p;
			ans += x / 3;
			x %= 3;
			p = x;
		}
	}
	printf("%lld\n", ans);
	return 0;
}