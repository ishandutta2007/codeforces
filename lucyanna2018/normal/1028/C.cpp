#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<cctype>
#include<iostream>
#include<string>
#include<sstream>
#include<set>
#include<map>
#include<vector>
#include<algorithm>
#include<queue>
#include<utility>
using namespace std;

#define ran 133333
const int inf = (int)(2e9);
int n, lx[ran],ly[ran],rx[ran],ry[ran];
int pref_maxlx[ran], pref_maxly[ran], pref_minrx[ran], pref_minry[ran];
int suff_maxlx[ran], suff_maxly[ran], suff_minrx[ran], suff_minry[ran];
void Max(int*pos, int dir, int w) {
	(*pos) = max((*(pos + dir)), w);
}
void Min(int*pos, int dir, int w) {
	(*pos) = min((*(pos + dir)), w);
}
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d%d%d%d", &lx[i], &ly[i], &rx[i], &ry[i]);
	pref_maxlx[0] = suff_maxlx[n + 1] = -inf;
	pref_maxly[0] = suff_maxly[n + 1] = -inf;
	pref_minrx[0] = suff_minrx[n + 1] = inf;
	pref_minry[0] = suff_minry[n + 1] = inf;
	for (int i = 1; i <= n; i++) {
		Max(pref_maxlx+i,-1,lx[i]);
		Max(pref_maxly+i,-1,ly[i]);
		Min(pref_minrx+i,-1,rx[i]);
		Min(pref_minry+i,-1,ry[i]);
	}
	for (int i = n; i >= 1; i--) {
		Max(suff_maxlx+i,1, lx[i]);
		Max(suff_maxly+i,1, ly[i]);
		Min(suff_minrx+i,1, rx[i]);
		Min(suff_minry+i,1, ry[i]);
	}
	for (int i = 1; i <= n; i++) {
		int LX = max(pref_maxlx[i - 1], suff_maxlx[i + 1]);
		int LY = max(pref_maxly[i - 1], suff_maxly[i + 1]);
		int RX = min(pref_minrx[i - 1], suff_minrx[i + 1]);
		int RY = min(pref_minry[i - 1], suff_minry[i + 1]);
		if (LX <= RX && LY <= RY) {
			printf("%d %d\n", LX, LY);
			return 0;
		}
	}
	return 0;
}