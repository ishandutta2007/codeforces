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

char X[100010];
int LX[1331], TLX[1331];

int trans[10][1331];
int C[1331];

int next_state(int a, int c) {
	int me_l = a / 121, me = (a / 11) % 11, me_r = a % 11;
	
	int my_c = me % 11;
	int nme_r = 0, nme_l = 0;
	for(int a=1;a<=me_r;a++) nme_r += (my_c + a) % 11;
	for(int a=1;a<=me_l;a++) nme_l += (my_c - a + 22) % 11;
	C[a] = my_c;
	if(c >= my_c) {
		return -1;
	}
	nme_r += (my_c - c - 1);
	nme_l += c;
	nme_r %= 11; nme_l %= 11;
	me = (me + me_r + nme_l + 1) % 11;
	me_l = nme_l; me_r = nme_r;
	return (me_l * 121 + me * 11 + me_r);
}

int main() {
	rep(i, 1331) {
		rep(a, 10) {
			trans[a][i] = next_state(i, a);
		}
	}
//	for(int i=1;i<=100;i++) X[i] = i%10+'0';
	scanf("%s", X + 1);
	int L = (int)strlen(X+1);
	ll ans = 0;
	for(int i=1;i<=L;i++) {
		int cc = X[i] - '0';
		rep(a, 1331) if(C[a] <= cc) LX[a] = 0;
		rep(a, 1331) TLX[trans[cc][a]] += LX[a];
		rep(a, 1331) LX[a] = TLX[a], TLX[a] = 0;
		
		if(X[i] != '0') {
			int me = cc;
			int me_r = 9 - cc;
			int me_l = cc - 1;
			LX[me_l*121+me*11+me_r]++;
		}
		rep(a, 1331) ans += LX[a];
	}
	printf("%lld\n", ans);
	return 0;
}