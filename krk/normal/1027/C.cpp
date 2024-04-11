#include <bits/stdc++.h>
using namespace std;

typedef long double ld;

const int Maxn = 1000005;
const int Maxm = 10005;

int t;
int n;
int a[Maxn];
int has[Maxm];
int seq[Maxn], slen;

int main()
{
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			scanf("%d", &a[i]);
			if (has[a[i]]++ == 0) seq[slen++] = a[i];
		}
		sort(seq, seq + slen);
		ld best = 1e30l;
		int bi = -1, bj = -1;
		int cur = 0, nxt = 0;
		for (int i = 0; i < slen; i++) {
			int a = seq[i];
			if (has[a] < 2) continue;
			if (has[a] >= 4)
				if (2 < best) { best = 2; bi = a; bj = a; }
			if (cur <= i) cur = i + 1;
			while (cur < slen && has[seq[cur]] < 2) cur++;
			if (cur >= slen) break;
			ld my = ld(a) / ld(seq[cur]) + ld(seq[cur]) / ld(a);
			nxt = max(nxt, cur + 1);
			while (nxt < slen)
				if (has[seq[nxt]] < 2) nxt++;
				else {
					ld cand = ld(a) / ld(seq[nxt]) + ld(seq[nxt]) / ld(a);
					if (cand < my) { my = cand; cur = nxt; nxt++; }
					else break;
				}
			if (my < best) { best = my; bi = a; bj = seq[cur]; }
		}
		printf("%d %d %d %d\n", bi, bi, bj, bj);
		for (int i = 0; i < slen; i++)
			has[seq[i]] = 0;
		slen = 0;
	}
	return 0;
}