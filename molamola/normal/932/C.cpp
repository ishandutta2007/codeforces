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
typedef tuple<ll, int, int> t3;
typedef pair<ll, ll> pll;
typedef long double ldouble;
typedef pair<ldouble, ldouble> pdd;

int N, A, B;
int ans[1000010];

void solve() {
	scanf("%d%d%d", &N, &A, &B);
	int f1 = -1, f2 = -1;
	for(int i=0;i*A<=N;i++) {
		int v = N - i * A;
		if(v % B == 0) {
			f1 = i, f2 = v / B;
			break;
		}
	}
	if(f1 == -1) {
		puts("-1");
		return;
	}
	for(int i=1;i<=f1;i++) {
		int l = i * A - A + 1;
		int r = i * A;
		ans[r] = l;
		for(int j=l;j<r;j++) {
			ans[j] = j + 1;
		}
	}
	rep(i, f2) {
		int l = i * B + 1 + f1 * A;
		int r = f1 * A + (i + 1) * B;
		ans[r] = l;
		for(int j=l;j<r;j++) ans[j] = j + 1;
	}
	for(int i=1;i<=N;i++) printf("%d ", ans[i]); puts("");
}

int main(){
	int Tc = 1; //scanf("%d\n", &Tc);
	for(int tc=1;tc<=Tc;tc++){
		solve();
	}
	return 0;
}