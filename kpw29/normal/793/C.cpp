#include <bits/stdc++.h>

using namespace std;

#define FOE(i, s, t) for (int i = s; i <= t; i++)
#define FOD(i, s, t) for (int i = s; i >= t; i--)
#define FOR(i, s, t) for (int i = s; i < t; i++)
#define mp make_pair
#define pb push_back
#define LL long long

struct event{
	double time;
	int type; // 0: leaving 1: entering
};

#define eps 1e-12

bool cmp (event u, event v){return ((abs(u.time - v.time) < eps && u.type < v.type) || u.time < v.time);}

#define y1 demonic

event A[500001];
int n, x1, y1, x2, y2;
int cnt, h;

double solve1(double ori, double speed, double expe){
	return (expe - ori) / speed;
}

double max(double a, double b){
	if (a > b) return a;
	return b;
}

int main(){	
	scanf("%d%d%d%d%d", &n, &x1, &y1, &x2, &y2);
	FOE(i, 1, n){
		int cx, cy, dx, dy; scanf("%d%d%d%d", &cx, &cy, &dx, &dy);
		if (dx == 0){
			if (x1 < cx && cx < x2){

			} else {puts("-1"); return 0;}
		} else {
			double u1 = solve1(cx, dx, x1); 
			double u2 = solve1(cx, dx, x2);
			if (u1 <= eps && u2 <= eps){puts("-1"); return 0;}
			else {
				u1 = max(u1, 0.0);
				u2 = max(u2, 0.0);
				if (u1 > u2) swap(u1, u2);
				A[++h].time = u1; A[h].type = 1;
				A[++h].time = u2; A[h].type = -1;
			}
		}
		if (dy == 0){
			if (y1 < cy && cy < y2){

			} else {puts("-1"); return 0;}
		} else {
			double u1 = solve1(cy, dy, y1); 
			double u2 = solve1(cy, dy, y2);
			if (u1 < eps && u2 < eps){puts("-1"); return 0;}
			else {
				u1 = max(u1, 0.0);
				u2 = max(u2, 0.0);
				if (u1 > u2) swap(u1, u2);
				A[++h].time = u1; A[h].type = 1;
				A[++h].time = u2; A[h].type = -1;
			}
		}
	}

	sort(A + 1, A + h + 1, cmp);
	FOE(i, 1, h / 2) if (A[i].type == -1) {puts("-1"); return 0;}
	printf("%.9f\n", A[h / 2].time);
	return 0;
}