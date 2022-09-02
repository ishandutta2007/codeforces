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

int n;
char S[100010];

int main() {
	scanf("%d", &n);
	scanf("%s", S + 1);
	int t = (n - 11) / 2;
	string res;
	for(int i=1;i<=n;i++) {
		if(S[i] != '8') {
			if(t) --t;
			else res.pb(S[i]);
		}
		else res.pb(S[i]);
	}
	for(int i=0;i<(n - 11) / 2+1;i++) if(res[i] != '8') {
		puts("NO");
		return 0;
	}
	puts("YES");
	return 0;
}