#include <bits/stdc++.h>
using namespace std;

const int Maxb = 22;
const int Maxm = 1 << 21;

int n;
int addp[Maxb];
int sump[Maxb][Maxm];
int addn[Maxb];
int sumn[Maxb][Maxm];
int res = 100;
int apos, aneg;

void Gen(int lvl, int candp, int candn, int cur)
{
	bool has = addp[lvl] + sump[lvl][candn] + addn[lvl] + sumn[lvl][candp] > 0;
	if (lvl >= Maxb - 1) {
		if (!has)
			if (cur < res) { res = cur; apos = candp; aneg = candn; }
	} else if (!has) Gen(lvl + 1, candp, candn, cur);
	else {
		Gen(lvl + 1, candp, candn | 1 << lvl, cur + 1);
		Gen(lvl + 1, candp | 1 << lvl, candn, cur + 1);
	}
}

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int mask; scanf("%d", &mask);
		if (mask >= 0) {
			int cur = 0;
			for (int j = 0; j < Maxb; j++)
				if (mask & 1 << j) {
					addp[j]++;
					if (cur > 0) sump[j][(1 << j) - cur]--;
					cur |= 1 << j;
				} else if (cur > 0) sump[j][(1 << j) - cur]++;
		} else {
			mask = -mask;
			int cur = 0;
			for (int j = 0; j < Maxb; j++)
				if (mask & 1 << j) {
					addn[j]++;
					if (cur > 0) sumn[j][(1 << j) - cur]--;
					cur |= 1 << j;
				} else if (cur > 0) sumn[j][(1 << j) - cur]++;
		}
	}
	for (int i = 0; i < Maxb; i++)
		for (int j = 1; j < 1 << i; j++) {
			sump[i][j] += sump[i][j - 1];
			sumn[i][j] += sumn[i][j - 1];
		}
	Gen(0, 0, 0, 0);
	vector <int> seq;
	for (int i = 0; i < Maxb; i++) {
		if (apos & 1 << i) seq.push_back(1 << i);
		if (aneg & 1 << i) seq.push_back(-(1 << i));
	}
	printf("%d\n", int(seq.size()));
	for (int i = 0; i < seq.size(); i++)
		printf("%d%c", seq[i], i + 1 < seq.size()? ' ': '\n');
    return 0;
}