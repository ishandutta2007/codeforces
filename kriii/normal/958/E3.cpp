#include <stdio.h>
#include <math.h>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <string>
#include <vector>
#include <set>
#include <map>
using namespace std;

int ax[10101], ay[10101], bx[10101], by[10101], mat[10101];

struct pt {
	int x, y, t, i;

	bool operator <(const pt& t) const{
		return x * t.y < y * t.x;
	}
};

int cnt = 0;

void go(vector<int> &p, vector<int> &q)
{
	if (p.empty() || q.empty()) return;

	if (++cnt == 20) {
		for (int i = 0; i < 10101; i++) {
			swap(ax[i], ay[i]); ay[i] = -ay[i];
			swap(bx[i], by[i]); by[i] = -by[i];
		}
		cnt = 0;
	}
	vector<pt> V;
	for (auto &i : p) V.push_back({ ax[i],ay[i],1,i });
	for (auto &i : q) V.push_back({ bx[i],by[i],-1,i });

	pt pv = V[0];
	for (int i = 1; i < V.size(); i++) {
		if (pv.y > V[i].y || (pv.y == V[i].y && pv.x > V[i].x)) pv = V[i];
	}

	for (auto &p : V) p.x -= pv.x, p.y -= pv.y;
	for (int i = 0; i < V.size(); i++) if (V[i].x == 0 && V[i].y == 0) {
		V.erase(V.begin() + i);
		break;
	}

	int base = pv.t;
	sort(V.begin(), V.end());
	for (int i = 0; i < V.size(); i++) {
		base += V[i].t;
		if (base == 0) {
			p.clear(); q.clear();
			vector<int> ap, aq, bp, bq;
			for (int j = 0; j < i; j++) {
				if (V[j].t == 1) ap.push_back(V[j].i);
				else aq.push_back(V[j].i);
			}
			if (pv.t == 1) mat[pv.i] = V[i].i;
			else mat[V[i].i] = pv.i;
			for (int j = i+1; j < V.size(); j++) {
				if (V[j].t == 1) bp.push_back(V[j].i);
				else bq.push_back(V[j].i);
			}
			go(ap, aq);
			go(bp, bq);
			break;
		}
	}
}

void proc()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d %d", &ax[i], &ay[i]);
	for (int i = 0; i < n; i++) scanf("%d %d", &bx[i], &by[i]);

	vector<int> p(n),q;
	for (int i = 0; i < n; i++) p[i] = i; q = p;
	go(p, q);
	for (int i = 0; i < n; i++) printf("%d\n", mat[i] + 1);
}

int main()
{
#ifdef __LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	proc();
	return 0;
}