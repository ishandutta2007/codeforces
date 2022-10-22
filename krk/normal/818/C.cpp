#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <string>
#include <cstring>
#include <sstream>
#include <algorithm>
using namespace std;

const int Maxn = 100005;

int d;
int n, m;
int X1[Maxn], Y1[Maxn], X2[Maxn], Y2[Maxn];
vector <int> mX, MX, mY, MY;
int cntl, cntr, cntt, cntb;

int main()
{
	scanf("%d", &d);
	scanf("%d %d", &n, &m);
	for (int i = 0; i < d; i++) {
		scanf("%d %d %d %d", &X1[i], &Y1[i], &X2[i], &Y2[i]);
		if (X1[i] > X2[i]) swap(X1[i], X2[i]);
		if (Y1[i] > Y2[i]) swap(Y1[i], Y2[i]);
		mX.push_back(X1[i]); MX.push_back(X2[i]);
		mY.push_back(Y1[i]); MY.push_back(Y2[i]);
	}
	sort(mX.begin(), mX.end());
	sort(MX.begin(), MX.end());
	sort(mY.begin(), mY.end());
	sort(MY.begin(), MY.end());
	scanf("%d %d %d %d", &cntl, &cntr, &cntt, &cntb);
	for (int i = 0; i < d; i++) {
		int l = lower_bound(mX.begin(), mX.end(), X2[i]) - mX.begin() - (X1[i] != X2[i]);
		int r = MX.end() - upper_bound(MX.begin(), MX.end(), X1[i]) - (X1[i] != X2[i]);
		int t = lower_bound(mY.begin(), mY.end(), Y2[i]) - mY.begin() - (Y1[i] != Y2[i]);
		int b = MY.end() - upper_bound(MY.begin(), MY.end(), Y1[i]) - (Y1[i] != Y2[i]);
		if (cntl == l && cntr == r && cntt == t && cntb == b) { printf("%d\n", i + 1); return 0; }
	}
	printf("-1\n");
	return 0;
}