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
#define pb(x) push_back(x)
#define szz(x) (int)x.size()
#define rep(i,n) for(int i=0;i<n;i++)
#define all(x) x.begin(),x.end()
typedef tuple<int, int, int> t3;

int chk[2000020], mk;

int main() {
	int T; scanf("%d", &T);
	rep(t, T) {
		int n, a[110];
		scanf("%d", &n);
		for(int i=1;i<=n;i++) scanf("%d", a + i);
		memset(chk, 0, sizeof chk);
		puts("YES");
		int b[110];
		++mk;
		for(int i=1;i<=n;i++) {
			int x = 1;
			if(i > 1) x = b[i-1] + 1;
			while(1) {
				int ok = 1;
				for(int j=1;j<=n;j++) if(chk[x+a[j]] == mk) { ok = 0; break; }
				if(ok) {
					b[i] = x;
					for(int j=1;j<=n;j++) chk[x+a[j]] = mk;
					break;
				}
				++x;
			}
		}
		for(int i=1;i<=n;i++) printf("%d ", b[i]); puts("");
	}
	return 0;
}