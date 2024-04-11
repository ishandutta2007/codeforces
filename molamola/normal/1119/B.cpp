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

int n, h;
int A[1010];

int main() {
	scanf("%d%d", &n, &h);
	for(int i=1;i<=n;i++) scanf("%d", A + i);
	int low = 0, high = n, res = -1;
	while(low <= high) {
		int mid = (low + high) >> 1;
		vector <int> w;
		for(int i=1;i<=mid;i++) w.pb(A[i]);
		sort(all(w)); reverse(all(w));
		ll sum = 0;
		for(int i=0;i<szz(w);i+=2) {
			sum += w[i];
		}
		if(sum <= h) res = mid, low = mid + 1;
		else high = mid - 1;
	}
	printf("%d\n", res);
	return 0;
}