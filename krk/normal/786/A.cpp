#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <map>
#include <cmath>
#include <string>
#include <cstring>
#include <sstream>
#include <algorithm>
using namespace std;

const int Maxn = 7007;
const int Maxm = 2 * Maxn;

int n;
vector <int> V[2];
int in[Maxm];
int st[Maxm];
queue <int> Q;

void fromLose(int x)
{
	if (x < n) {
		int rl = x;
		for (int i = 0; i < V[1].size(); i++) {
			int nw = (rl - V[1][i] + n) % n + n;
			if (st[nw] != 1) { st[nw] = 1; Q.push(nw); }
		}
	} else {
		int rl = x - n;
		for (int i = 0; i < V[0].size(); i++) {
			int nw = (rl - V[0][i] + n) % n;
			if (st[nw] != 1) { st[nw] = 1; Q.push(nw); }
		}
	}
}

void fromWin(int x)
{
	if (x < n) {
		int rl = x;
		for (int i = 0; i < V[1].size(); i++) {
			int nw = (rl - V[1][i] + n) % n + n;
			if (st[nw] != 1 && --in[nw] == 0) { st[nw] = -1; fromLose(nw); } 
		}
	} else {
		int rl = x - n;
		for (int i = 0; i < V[0].size(); i++) {
			int nw = (rl - V[0][i] + n) % n;
			if (st[nw] != 1 && --in[nw] == 0) { st[nw] = -1; fromLose(nw); }
		}
	}
}

void Print(int st)
{
	if (st == -1) printf("Lose");
	else if (st == 0) printf("Loop");
	else printf("Win");
}

int main()
{
	scanf("%d", &n);
	int c; scanf("%d", &c); V[0].resize(c);
	for (int i = 0; i < c; i++)
		scanf("%d", &V[0][i]);
	scanf("%d", &c); V[1].resize(c);
	for (int i = 0; i < c; i++)
		scanf("%d", &V[1][i]);
	for (int i = 1; i <= n - 1; i++) {
		in[i] = V[0].size();
		in[i + n] = V[1].size();
	}
	st[0] = st[n] = -1; fromLose(0); fromLose(n);
	while (!Q.empty()) {
		int v = Q.front(); Q.pop();
		fromWin(v);
	}
	for (int i = 1; i <= n - 1; i++) {
		Print(st[i]);
		printf("%c", i + 1 <= n - 1? ' ': '\n');
	}
	for (int i = 1; i <= n - 1; i++) {
		Print(st[n + i]);
		printf("%c", i + 1 <= n - 1? ' ': '\n');
	}
	return 0;
}