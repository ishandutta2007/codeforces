#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

const int Maxl = 5000005;
const int Inf = 1000000000;

struct node {
	int M, D;
	int h, m, s;
	node() {}
	node(char lin[]) {
		M = (lin[5] - '0') * 10 + (lin[6] - '0');
		D = (lin[8] - '0') * 10 + (lin[9] - '0');
		h = (lin[11] - '0') * 10 + (lin[12] - '0');
		m = (lin[14] - '0') * 10 + (lin[15] - '0');
		s = (lin[17] - '0') * 10 + (lin[18] - '0');
	}
};

int n, m;
char s[Maxl];
vector <node> M;
vector <int> srt;
int Q[Maxl], l, r;

bool Less(const int &a, const int &b)
{
	if (M[a].M != M[b].M) return M[a].M < M[b].M;
	if (M[a].D != M[b].D) return M[a].D < M[b].D;
	if (M[a].h != M[b].h) return M[a].h < M[b].h;
	if (M[a].m != M[b].m) return M[a].m < M[b].m;
	return M[a].s < M[b].s;
}

int hasDays(int mon)
{
	if (mon == 2) return 29;
	if (mon == 4 || mon == 6 || mon == 9 || mon == 11) return 30;
	return 31;
}

int nxtDay(int aM, int aD, int bM, int bD)
{
	if (aD < hasDays(aM)) aD++;
	else { aM++; aD = 1; }
	return aM == bM && aD == bD;
}

int Dif(const node &a, const node &b)
{
	if (a.M == b.M && a.D == b.D) return b.h * 3600 + b.m * 60 + b.s - a.h * 3600 - a.m * 60 - a.s;
	if (nxtDay(a.M, a.D, b.M, b.D)) return b.h * 3600 + b.m * 60 + b.s + 24 * 3600 - a.h * 3600 - a.m * 60 - a.s;
	return Inf;
}

int getError()
{
	for (int i = 0; i < srt.size(); i++) {
		Q[r++] = srt[i];
		while (Dif(M[Q[l]], M[Q[r - 1]]) >= n) l++;
		if (r - l >= m) return Q[r - 1];
	}
	return -1;
}

int main()
{
	scanf("%d %d", &n, &m); cin.getline(s, Maxl);
	while (cin.getline(s, Maxl)) {
		M.push_back(node(s)); srt.push_back(M.size() - 1);
	}
	sort(srt.begin(), srt.end(), Less);
	int ind = getError();
	if (ind == -1) printf("-1\n");
	else printf("2012-%d%d-%d%d %d%d:%d%d:%d%d\n", 
			M[ind].M / 10, M[ind].M % 10, M[ind].D / 10, M[ind].D % 10, 
			M[ind].h / 10, M[ind].h % 10, M[ind].m / 10, M[ind].m % 10, M[ind].s / 10, M[ind].s % 10);
	return 0;
}