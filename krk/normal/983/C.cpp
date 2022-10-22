#include <bits/stdc++.h>
using namespace std;

const int Maxn = 2005;
const int Maxd = 4;
const int Maxm = 720;
const int Maxf = 10;
const int Inf = 1000000000;

struct pos {
	int peop[Maxd];
	pos() { fill(peop, peop + Maxd, 0); }
	bool operator <(const pos &p) const {
		for (int i = 0; i < Maxd; i++)
			if (peop[i] != p.peop[i]) return peop[i] < p.peop[i];
		return false;
	}
};

struct triple {
	int ind, fl, p;
	triple(int ind = 0, int fl = 0, int p = 0): ind(ind), fl(fl), p(p) {}
	bool operator <(const triple &t) const {
		if (ind != t.ind) return ind < t.ind;
		if (fl != t.fl) return fl < t.fl;
		return p < t.p;
	}
};

int n;
int A[Maxn], B[Maxn];
map <pos, int> M;
pos wh[Maxm];
int whlen;
int dist[Maxn][Maxf][Maxm];
bool vis[Maxn][Maxf][Maxm];

int getId(const pos &p)
{
	map <pos, int>::iterator it = M.find(p);
	if (it == M.end()) {
		M.insert(make_pair(p, whlen));
		wh[whlen++] = p;
		return whlen - 1;
	}
	return it->second;
}

int Leave(int id, int floor)
{
	pos p = wh[id];
	for (int i = 0; i < Maxd; i++)
		if (p.peop[i] == floor) p.peop[i] = 0;
	sort(p.peop, p.peop + Maxd);
	return getId(p);
}

bool couldEnter(int id)
{
	return wh[id].peop[0] == 0;
}

int Enter(int id, int floor)
{
	pos p = wh[id];
	p.peop[0] = floor;
	sort(p.peop, p.peop + Maxd);
	return getId(p);
}

void Gen(int lvl, int from, pos &p)
{
	if (lvl >= Maxd) getId(p);
	else for (int i = from; i < Maxf; i++) {
		p.peop[lvl] = i;
		Gen(lvl + 1, i, p);
	}
}

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d %d", &A[i], &B[i]);
	pos p; Gen(0, 0, p);
	fill((int*)dist, (int*)dist + Maxn * Maxf * Maxm, Inf); dist[0][1][0] = 0;
	deque <triple> Q; Q.push_back(triple(0, 1, 0));
	while (!Q.empty()) {
		triple v = Q.front(); Q.pop_front();
		if (vis[v.ind][v.fl][v.p]) continue;
		vis[v.ind][v.fl][v.p];
		int d = dist[v.ind][v.fl][v.p];
		if (v.fl > 1) {
			triple u = triple(v.ind, v.fl - 1, v.p);
			if (d + 1 < dist[u.ind][u.fl][u.p]) {
				dist[u.ind][u.fl][u.p] = d + 1;
				Q.push_back(u);
			}
		}
		if (v.fl + 1 < Maxf) {
			triple u = triple(v.ind, v.fl + 1, v.p);
			if (d + 1 < dist[u.ind][u.fl][u.p]) {
				dist[u.ind][u.fl][u.p] = d + 1;
				Q.push_back(u);
			}
		}
		triple u = triple(v.ind, v.fl, v.p);
		u.p = Leave(u.p, u.fl);
		while (u.ind < n && A[u.ind] == u.fl && couldEnter(u.p)) {
			u.p = Enter(u.p, B[u.ind]); u.ind++;
		}
		if (d < dist[u.ind][u.fl][u.p]) {
			dist[u.ind][u.fl][u.p] = d;
			Q.push_front(u);
		}
	}
	int res = Inf;
	for (int i = 1; i < Maxf; i++)
		res = min(res, dist[n][i][0]);
	res += 2 * n;
	printf("%d\n", res);
	return 0;
}