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
#define sz(x) (int)x.size()
#define rep(i,n) for(int i=0;i<n;i++)
#define all(x) x.begin(),x.end()
typedef tuple<int, int, int> t3;

int q;

int main() {
	scanf("%d", &q);
	while(q-- ){
		int x; scanf("%d", &x);
		int f = -1;
		for(int i=25;i>=0;i--) if(1<<i & x) { f = i; break; }
		int r = (1<<(f+1)) - 1;
		if(r == x) {
			int ans = -1;
			for(int a=2;a*a<=x;a++) if(x % a == 0) {
				ans = x / a;
				break;
			}
			if(ans == -1) ans = 1;
			printf("%d\n", ans);
		}
		else printf("%d\n", r);
	}
	return 0;
}