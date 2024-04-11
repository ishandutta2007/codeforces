#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <string>
#include <cstring>
#include <sstream>
#include <algorithm>
using namespace std;

typedef pair <int, int> ii;
typedef long double ld;
typedef pair <ld, int> ldi;

const int Maxn = 505;
const int Maxd = 4;
const int dy[Maxd] = {-1, 0, 1, 0};
const int dx[Maxd] = {0, -1, 0, 1};
const int my[Maxd] = {-1, 0, 0, -1};
const int mx[Maxd] = {-1, -1, 0, 0};

int n;
int B[Maxn][Maxn];
vector <ii> seq;
vector <ldi> srt;
vector <ii> V;

int Cross(int ax, int ay, int bx, int by) { return ax * by - ay * bx; }

int main()
{
	while (scanf("%d", &n) == 1 && n) {
		for (int y = n; y > 0; y--)
			for (int x = 1; x <= n; x++) {
				char ch; scanf(" %c", &ch);
				B[x][y] = ch - '0';
			}
		seq.clear(); srt.clear(); V.clear();
		for (int x = 2; x < n; x++)
			for (int y = 2; y < n; y++)
				if (B[x][y] == 1)
					for (int d = 0; d < Maxd; d++) {
						int nd = (d + 1) % Maxd;
						if (B[x + dx[d]][y + dy[d]] > 0 && 
							B[x + dx[d] + dx[nd]][y + dy[d] + dy[nd]] > 0 &&
							B[x + dx[nd]][y + dy[nd]] > 0)
							seq.push_back(ii(x + mx[d], y + my[d]));
					}
		sort(seq.begin(), seq.end()); seq.erase(unique(seq.begin(), seq.end()), seq.end());
		for (int i = 1; i < seq.size(); i++)
			srt.push_back(ldi(atan2(ld(seq[i].second - seq[0].second), ld(seq[i].first - seq[0].first)), i));
		sort(srt.begin(), srt.end());
		V.push_back(seq[0]);
		for (int i = 0; i < srt.size(); i++) {
			int ind = srt[i].second;
			while (V.size() >= 2) {
				int ax = V.back().first - V[V.size() - 2].first, ay = V.back().second - V[V.size() - 2].second;
				int bx = seq[ind].first - V[V.size() - 2].first, by = seq[ind].second - V[V.size() - 2].second;
				if (Cross(ax, ay, bx, by) <= 0) V.pop_back();
				else break;
			}
			V.push_back(seq[ind]);
		}
		while (V.size() >= 3) {
			int ax = V.back().first - V[V.size() - 2].first, ay = V.back().second - V[V.size() - 2].second;
			int bx = V[0].first - V[V.size() - 2].first, by = V[0].second - V[V.size() - 2].second;
			if (Cross(ax, ay, bx, by) <= 0) V.pop_back();
			else break;
		}
		int bi = 0;
		for (int i = 0; i < V.size(); i++)
			if (V[i] < V[bi]) bi = i;
		printf("%d\n", V.size());
		for (int i = 0; i < V.size(); i++) {
			int cur = (bi - i + V.size()) % V.size();
			printf("%d %d\n", V[cur].first, V[cur].second);
		}
	}
	return 0;
}