#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef pair <ll, int> ii;

struct point {
	int c[3];
};

const int Maxd = 8;
const int Maxc = 3;
const int Maxp = 6;
const int perm[Maxp][Maxc] = {{0, 1, 2}, {0, 2, 1}, {1, 0, 2}, {1, 2, 0}, {2, 0, 1}, {2, 1, 0}};

point I[Maxd];
point C[Maxd];
point P[Maxd];
bool taken[Maxd];
ii dist[Maxd];

bool checkAngle(int a, int b, int c)
{
	ll ax = P[b].c[0] - P[a].c[0], ay = P[b].c[1] - P[a].c[1], az = P[b].c[2] - P[a].c[2];
	ll bx = P[c].c[0] - P[a].c[0], by = P[c].c[1] - P[a].c[1], bz = P[c].c[2] - P[a].c[2];
	return ax * bx + ay * by + az * bz == 0;
}

ll Dist(const point &a, const point &b)
{
	ll res = 0;
	for (int i = 0; i < Maxc; i++)
		res += ll(a.c[i] - b.c[i]) * (a.c[i] - b.c[i]);
	return res;
}

bool Solve3(ll d)
{
	return Dist(P[6], P[1]) == d && Dist(P[6], P[3]) == d && Dist(P[6], P[5]) == d &&
		   Dist(P[7], P[2]) == d && Dist(P[7], P[3]) == d && Dist(P[7], P[5]) == d &&
		   checkAngle(6, 1, 3) && checkAngle(6, 1, 5) && checkAngle(6, 3, 5) &&
		   checkAngle(7, 2, 3) && checkAngle(7, 2, 5) && checkAngle(7, 3, 5);
}

bool Solve2(ll d)
{
	int ind[2], ilen = 0;
	for (int i = 1; i < Maxd; i++) if (!taken[i])
		ind[ilen++] = i;
	P[6] = C[ind[0]]; P[7] = C[ind[1]];
	if (Solve3(d)) return true;
	P[6] = C[ind[1]]; P[7] = C[ind[0]];
	if (Solve3(d)) return true;
	return false;
}

bool Solve1(ll d)
{
	for (int i = 1; i <= 2; i++)
		for (int j = i + 1; j <= 3; j++)
			if (!checkAngle(0, i, j)) return false;
	for (int i = 1; i < Maxd; i++) if (!taken[i]) {
		P[4] = C[i];
		if (Dist(P[1], P[4]) != d || Dist(P[2], P[4]) != d || !checkAngle(4, 1, 2)) continue;
		int cnt = 0, lst;
		for (int j = 1; j < Maxd && cnt <= 1; j++) if (!taken[j] && j != i) {
			P[5] = C[j];
			if (Dist(P[4], P[5]) == d && checkAngle(4, 1, 5) && checkAngle(4, 2, 5)) {
				lst = j; cnt++;
			}
		}
		if (cnt == 1) {
			taken[i] = true; P[5] = C[lst]; taken[lst] = true;
			if (Solve2(d)) return true;
			taken[i] = false; taken[lst] = false;
		}
	}
	return false;
}

bool checkCube()
{
	P[0] = C[0]; taken[0] = true; fill(taken + 1, taken + Maxd, false);
	for (int i = 1; i < Maxd; i++)
		dist[i] = ii(Dist(C[0], C[i]), i);
	sort(dist + 1, dist + Maxd);
	int lst = 1;
	for (int i = 2; i <= Maxd; i++)
		if (i == Maxd || dist[i].first != dist[i - 1].first) {
			if (i - lst == 3) {
				int cur = 1;
				for (int j = lst; j < i; j++) {
					P[cur++] = C[dist[j].second]; taken[dist[j].second] = true;
				}
				if (Solve1(dist[lst].first)) return true;
				for (int j = lst; j < i; j++)
					taken[dist[j].second] = false;
			}
			lst = i;
		}
	return false;
}

bool genCube(int lvl)
{
	if (lvl >= Maxd) {
		if (checkCube()) {
			printf("YES\n");
			for (int i = 0; i < Maxd; i++)
				printf("%d %d %d\n", C[i].c[0], C[i].c[1], C[i].c[2]);
			return true;
		}
		return false;
	}
	for (int i = 0; i < Maxp; i++) {
		for (int j = 0; j < Maxc; j++)
			C[lvl].c[j] = I[lvl].c[perm[i][j]];
		if (genCube(lvl + 1)) return true;
	}
	return false;
}

int main()
{
	for (int i = 0; i < Maxd; i++)
		scanf("%d %d %d", &I[i].c[0], &I[i].c[1], &I[i].c[2]);
	if (!genCube(0)) printf("NO\n");
	return 0;
}