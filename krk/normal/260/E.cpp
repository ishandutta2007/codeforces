#include <cstdio>
#include <algorithm>
using namespace std;

typedef pair <int, int> ii;

const int Inf = 2000000000;
const int Maxn = 100005;
const int Maxm = 9;
const int Maxg = 3;
const double eps = 1e-5;

int n;
ii byx[Maxn], byy[Maxn];
int a[Maxm], tsum;
bool taken[Maxm];
int seq[Maxm];
int tmp[Maxn], len;
ii sx[Maxm][Maxm][Maxm], sly[Maxm][Maxm][Maxm], sry[Maxm][Maxm][Maxm];
bool slost[Maxm][Maxm][Maxm];
ii ex[Maxm][Maxm][Maxm], ely[Maxm][Maxm][Maxm], ery[Maxm][Maxm][Maxm];
bool elost[Maxm][Maxm][Maxm];
bool res;

void GetX(int lose, ii &res) { res = ii(byx[lose - 1].first, byx[lose].first); }

void GetY(int lose, ii &res) { res = ii(byy[lose - 1].first, byy[lose].first); }

void GetcY(int l, int r, int lose1, ii &res1, int lose2, ii &res2)
{
	len = 0;
	for (int i = 0; i < n; i++)
		if (l <= byy[i].second && byy[i].second <= r)
			tmp[len++] = byy[i].first;
	res1 = ii(tmp[lose1 - 1], tmp[lose1]); res2 = ii(tmp[lose2 - 1], tmp[lose2]);
}

bool Eq(const ii &cand) { return cand.first == cand.second; }

void genS(int v)
{
	if (v == Maxg) {
		GetX(a[seq[0]] + a[seq[1]] + a[seq[2]], sx[seq[0]][seq[1]][seq[2]]);
		GetcY(-Inf, sx[seq[0]][seq[1]][seq[2]].first, a[seq[2]], sly[seq[0]][seq[1]][seq[2]], a[seq[1]] + a[seq[2]], sry[seq[0]][seq[1]][seq[2]]);
		slost[seq[0]][seq[1]][seq[2]] = Eq(sx[seq[0]][seq[1]][seq[2]]) || Eq(sly[seq[0]][seq[1]][seq[2]]) || Eq(sry[seq[0]][seq[1]][seq[2]]);
	} else for (int i = 0; i < Maxm; i++) if (!taken[i]) {
			taken[i] = true; seq[v] = i;
			genS(v + 1);
			taken[i] = false;
		}
}

void genE(int v)
{
	if (v == Maxg) {
		GetX(tsum - a[seq[0]] - a[seq[1]] - a[seq[2]], ex[seq[0]][seq[1]][seq[2]]);
		GetcY(ex[seq[0]][seq[1]][seq[2]].second, Inf, a[seq[2]], ely[seq[0]][seq[1]][seq[2]], a[seq[1]] + a[seq[2]], ery[seq[0]][seq[1]][seq[2]]);
		elost[seq[0]][seq[1]][seq[2]] = Eq(ex[seq[0]][seq[1]][seq[2]]) || Eq(ely[seq[0]][seq[1]][seq[2]]) || Eq(ery[seq[0]][seq[1]][seq[2]]);
	} else for (int i = 0; i < Maxm; i++) if (!taken[i]) {
			taken[i] = true; seq[v] = i;
			genE(v + 1);
			taken[i] = false;
		}
}

void printRes(double x1, double x2, double y1, double y2)
{
	printf("%.10lf %.10lf\n", x1, x2);
	printf("%.10lf %.10lf\n", y1, y2);
	res = true;
}

void Solve(int v)
{
	if (v == Maxm) {
		if (slost[seq[0]][seq[3]][seq[6]] || elost[seq[2]][seq[5]][seq[8]]) return;
		int l1 = max(sly[seq[0]][seq[3]][seq[6]].first, ely[seq[2]][seq[5]][seq[8]].first);
		int l2 = min(sly[seq[0]][seq[3]][seq[6]].second, ely[seq[2]][seq[5]][seq[8]].second);
		if (l1 >= l2) return;
		int r1 = max(sry[seq[0]][seq[3]][seq[6]].first, ery[seq[2]][seq[5]][seq[8]].first);
		int r2 = min(sry[seq[0]][seq[3]][seq[6]].second, ery[seq[2]][seq[5]][seq[8]].second);
		if (r1 >= r2) return;
		ii L; GetY(a[seq[6]] + a[seq[7]] + a[seq[8]], L);
		if (Eq(L) || L.first < l1 || L.first >= l2) return;
		ii R; GetY(a[seq[3]] + a[seq[4]] + a[seq[5]] + a[seq[6]] + a[seq[7]] + a[seq[8]], R);
		if (Eq(R) || R.first < r1 || R.first >= r2) return;
		printRes(sx[seq[0]][seq[3]][seq[6]].first + 0.5, ex[seq[2]][seq[5]][seq[8]].first + 0.5, L.first + 0.5, R.first + 0.5);
	} else for (int i = 0; i < Maxm && !res; i++) if (!taken[i]) {
			taken[i] = true; seq[v] = i;
			Solve(v + 1);
			taken[i] = false;
		}
}

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &byx[i].first, &byx[i].second); byy[i] = ii(byx[i].second, byx[i].first);
	}
	sort(byx, byx + n); sort(byy, byy + n);
	for (int i = 0; i < Maxm; i++) {
		scanf("%d", &a[i]); tsum += a[i];
	}
	genS(0); genE(0);
	Solve(0);
	if (!res) printf("-1\n");
	return 0;
}