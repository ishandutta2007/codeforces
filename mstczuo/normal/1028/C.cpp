# include <bits/stdc++.h>
using namespace std;

const int maxn = 132674 + 10;
#define y1 __mstczuo__y1 
#define y2 __mstczuo__y2 

int n;
int x1[maxn], x2[maxn], y1[maxn], y2[maxn];
int fx1[maxn], fx2[maxn], fy1[maxn], fy2[maxn];
int gx1[maxn], gx2[maxn], gy1[maxn], gy2[maxn];
int main() {
	scanf("%d", &n);
	for(int i = 0; i < n; ++i) {
		scanf("%d%d%d%d", &x1[i], &y1[i], &x2[i], &y2[i]);
	}
	fx1[0] = x1[0];
	fx2[0] = x2[0];
	fy1[0] = y1[0];
	fy2[0] = y2[0];
	for(int i = 1; i < n; ++i) {
		fx1[i] = max(fx1[i-1], x1[i]);
		fx2[i] = min(fx2[i-1], x2[i]);
		fy1[i] = max(fy1[i-1], y1[i]);
		fy2[i] = min(fy2[i-1], y2[i]);
	}
	gx1[n-1] = x1[n-1];
	gx2[n-1] = x2[n-1];
	gy1[n-1] = y1[n-1];
	gy2[n-1] = y2[n-1];
	for(int i = n - 2; i >= 0; --i) {
		gx1[i] = max(gx1[i+1], x1[i]);
		gx2[i] = min(gx2[i+1], x2[i]);
		gy1[i] = max(gy1[i+1], y1[i]);
		gy2[i] = min(gy2[i+1], y2[i]);
	}
	if(gx1[1] <= gx2[1] && gy1[1] <= gy2[1]) {
		printf("%d %d\n", gx1[1], gy1[1]);
		return 0;
	}
	if(fx1[n-2] <= fx2[n-2] && fy1[n-2] <= fy2[n-2]) {
		printf("%d %d\n", fx1[n-2], fy1[n-2]);
		return 0;
	}
	for(int i = 1; i < n - 1; ++i) {
		int lx = max(fx1[i-1], gx1[i+1]);
		int rx = min(fx2[i-1], gx2[i+1]);
		int ly = max(fy1[i-1], gy1[i+1]);
		int ry = min(fy2[i-1], gy2[i+1]);
		if(lx <= rx && ly <= ry) {
			printf("%d %d\n", lx, ly);
			return 0;
		}
	}
	return 0;
}