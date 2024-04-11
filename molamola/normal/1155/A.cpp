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

char S[300030];

int main() {
	int n;
	scanf("%d%s", &n, S + 1);
	if(is_sorted(S+1, S+1+n)) puts("NO");
	else {
		for(int i=2;i<=n;i++) if(S[i-1] > S[i]) {
			printf("YES\n%d %d\n", i-1, i);
			return 0;
		}
	}
	return 0;
}