#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

typedef pair <int, int> ii;

const int Maxp = 4;
const int Inf = 1000000000;

int t;
int x[Maxp], y[Maxp];
vector <int> X, Y;
vector <int> myX, myY;
int res;
vector <ii> best;
int D;

void solveStandard()
{
	if (myX[1] - myX[0] != myY[1] - myY[0]) return;
	int dp[1 << Maxp], par[1 << Maxp];
	fill(dp, dp + (1 << Maxp), Inf); dp[0] = 0;
	for (int i = 0; i + 1 < 1 << Maxp; i++) {
		int ind = __builtin_popcount(i);
		for (int j = 0; j < Maxp; j++) if (!(i & 1 << j))
			if (myX[j / 2] == x[ind] || myY[j % 2] == y[ind]) {
				int cand = max(dp[i], abs(myX[j / 2] - x[ind]) + abs(myY[j % 2] - y[ind]));
				if (cand < dp[i | 1 << j]) {
					dp[i | 1 << j] = cand; par[i | 1 << j] = j;
				}
			}
	}
	if (dp[(1 << Maxp) - 1] == Inf) return;
	if (dp[(1 << Maxp) - 1] < res) {
		res = dp[(1 << Maxp) - 1];
		int cur = (1 << Maxp) - 1;
		best.resize(Maxp);
		for (int i = Maxp - 1; i >= 0; i--) {
			int p = par[cur];
			best[i] = ii(myX[p / 2], myY[p % 2]);
			cur ^= 1 << p;
		}
	}
}

ii Min(ii a, ii b)
{
	return a.second < b.second? a: b;
}

ii F(vector <ii> V[], int D, int x)
{
	int res = max(abs(V[0][0].second - x), abs(V[0][1].second - x - D));
	int res2 = max(abs(V[1][0].second - x), abs(V[1][1].second - x - D));
	return ii(x, max(res, res2));
}

ii Get(int l, int r, vector <ii> V[], int D)
{
	if (l == r) return F(V, D, l);
	if (l + 1 == r) return Min(F(V, D, l), F(V, D, l + 1));
	if (l + 2 == r) return Min(Min(F(V, D, l), F(V, D, l + 1)), F(V, D, l + 2));
	int q1 = (2 * l + r) / 3, q2 = (l + 2 * r) / 3;
	ii a = F(V, D, q1), b = F(V, D, q2);
	if (Min(F(V, D, q1), F(V, D, q2)) == F(V, D, q1))
		return Get(l, q2, V, D);
	else return Get(q1, r, V, D);
}

void solveHorizontal()
{
	vector <ii> V[2];
	for (int i = 0; i < Maxp; i++)
		if (myY[0] == y[i]) V[0].push_back(ii(i, x[i]));
		else V[1].push_back(ii(i, x[i]));
	if (V[0].size() != V[1].size()) return;
	if (V[0][1].second < V[0][0].second) swap(V[0][1], V[0][0]);
	if (V[1][1].second < V[1][0].second) swap(V[1][1], V[1][0]);
	D = myY[1] - myY[0];
	ii got = Get(-200000000, 200000000, V, D);
	if (got.second < res) {
		res = got.second;
		best.resize(Maxp);
		best[V[0][0].first] = ii(got.first, myY[0]);
		best[V[0][1].first] = ii(got.first + D, myY[0]);
		best[V[1][0].first] = ii(got.first, myY[1]);
		best[V[1][1].first] = ii(got.first + D, myY[1]);
	}
}

void solveVertical()
{
	vector <ii> V[2];
	for (int i = 0; i < Maxp; i++)
		if (myX[0] == x[i]) V[0].push_back(ii(i, y[i]));
		else V[1].push_back(ii(i, y[i]));
	if (V[0].size() != V[1].size()) return;
	if (V[0][1].second < V[0][0].second) swap(V[0][1], V[0][0]);
	if (V[1][1].second < V[1][0].second) swap(V[1][1], V[1][0]);
	D = myX[1] - myX[0];
	ii got = Get(-200000000, 200000000, V, D);
	if (got.second < res) {
		res = got.second;
		best.resize(Maxp);
		best[V[0][0].first] = ii(myX[0], got.first);
		best[V[0][1].first] = ii(myX[0], got.first + D);
		best[V[1][0].first] = ii(myX[1], got.first);
		best[V[1][1].first] = ii(myX[1], got.first + D);
	}
}

void Solve()
{
	myX = X, myY = Y;
	sort(myX.begin(), myX.end()); myX.erase(unique(myX.begin(), myX.end()), myX.end());
	sort(myY.begin(), myY.end()); myY.erase(unique(myY.begin(), myY.end()), myY.end());
	if (myX.size() <= 1 && myY.size() <= 1) return;
	if (myX.size() > 2 || myY.size() > 2) return;
	if (myX.size() == 0) solveHorizontal();
	else if (myX.size() == 1) {
		int d = myY[1] - myY[0];
		myX.push_back(myX[0] + d);
		solveStandard();
		myX.pop_back();
		myX.push_back(myX[0] - d);
		sort(myX.begin(), myX.end());
		solveStandard();
	} else if (myY.size() == 0) solveVertical();
		   else if (myY.size() == 1) {
		   		int d = myX[1] - myX[0];
		   		myY.push_back(myY[0] + d);
		   		solveStandard();
		   		myY.pop_back();
		   		myY.push_back(myY[0] - d);
		   		sort(myY.begin(), myY.end());
		   		solveStandard();
		   } else solveStandard();
}

void Gen(int lvl)
{
	if (lvl == Maxp) Solve();
	else {
		Y.push_back(y[lvl]);
		Gen(lvl + 1);
		Y.pop_back();
		X.push_back(x[lvl]);
		Gen(lvl + 1);
		Y.push_back(x[lvl]);
		Gen(lvl + 1);
		Y.pop_back();
		X.pop_back();
	}
}

int main()
{
	scanf("%d", &t);
	while (t--) {
		for (int i = 0; i < Maxp; i++)
			scanf("%d %d", &x[i], &y[i]);
		res = Inf;
		Gen(0);
		if (res == Inf) printf("-1\n");
		else {
			printf("%d\n", res);
			for (int i = 0; i < Maxp; i++)
				printf("%d %d\n", best[i].first, best[i].second);
		}
	}
	return 0;
}