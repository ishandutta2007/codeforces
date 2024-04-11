#include<cstdio>
#include<cstring>
#include<algorithm>
#include<utility>
#include<vector>
#include<queue>
using namespace std;
#define ran 111
int n, m;
int pos[ran], hp[ran];
int ww[ran];
bool safe[ran][ran];
int hero[ran][ran];
pair<int, int> fat[ran][ran];
bool ff[ran];
queue<pair<int, int> > q;
void upd(int L, int R, int H, int L1, int R1) {
	if (hero[L][R] != -1)return;
	hero[L][R] = H;
	fat[L][R] = make_pair(L1, R1);
	q.push(make_pair(L, R));
}
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i++)scanf("%d%d", &pos[i], &hp[i]);
	for (int i = 1; i <= n; i++)
		scanf("%d", &ww[i]);
	memset(safe, 0, sizeof(safe));
	for (int i = 1; i <= m; i++) {
		int cur = hp[i];
		for (int j = pos[i]; j >= 1; j--) {
			cur += ww[j];
			if (cur < 0)break;
			safe[i][j] = true;
		}
		cur = hp[i];
		for (int j = pos[i]; j <= n; j++) {
			cur += ww[j];
			if (cur < 0)break;
			safe[i][j] = true;
		}
	}
	for (int X = 1; X <= n; X++) {
		int L = X, R = X;
		for (int i = 1; i <= m; i++) {
			L = min(L, pos[i]);
			R = max(R, pos[i]);
		}
		memset(hero, -1, sizeof(hero));
		for(int i=1; i<=m; i++)
			if (safe[i][X]) {
				int A = min(X, pos[i]);
				int B = max(X, pos[i]);
				hero[A][B] = i;
				fat[A][B] = make_pair(-1, -1);
				q.push(make_pair(A, B));
			}
		while (!q.empty()) {
			int curL = q.front().first, curR = q.front().second;
			q.pop();
			for (int i = 1; i <= m; i++) {
				if (pos[i] < curL) {
					if (!safe[i][curL - 1])continue;
					upd(pos[i], curR, i, curL, curR);
				}else
				if (pos[i] > curR) {
					if (!safe[i][curR + 1])continue;
					upd(curL, pos[i], i, curL, curR);
				}
			}
		}
		if (hero[L][R] != -1) {
			printf("%d\n", X);
			memset(ff, 0, sizeof(ff));
			vector<int> res;
			int curL = L, curR = R;
			while (!(curL == -1 && curR == -1)) {
				res.push_back(hero[curL][curR]);
				pair<int, int> w = fat[curL][curR];
				curL = w.first;
				curR = w.second;
			}
			reverse(res.begin(), res.end());
			for (int i = 0; i < res.size(); i++) {
				ff[res[i]] = true;
			}
			for (int i = 1; i <= m; i++)if (!ff[i])res.push_back(i);
			for (int i = 0; i < m; i++)printf("%d%c", res[i], i < m - 1 ? ' ' : '\n');
			return 0;
		}
	}
	puts("-1");
	return 0;
}