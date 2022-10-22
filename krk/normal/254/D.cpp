#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;

typedef pair <int, int> ii;

const int Inf = 1000000000;
const int Maxn = 1005;
const int Maxm = Maxn * Maxn;
const int Maxd = 4;
const int dy[Maxd] = {-1, 0, 1, 0};
const int dx[Maxd] = {0, -1, 0, 1};

int n, m, d;
char B[Maxn][Maxn];
vector <ii> rats;
vector <ii> fre;
int tk1[Maxn][Maxn], tk2[Maxn][Maxn], tk3[Maxn][Maxn], tk4[Maxn][Maxn];
ii seq1[Maxm], seq2[Maxm], seq3[Maxm], seq4[Maxm];
int len1, len2, len3, len4;
bool res;

void Print(ii a, ii b)
{
	printf("%d %d %d %d\n", a.first + 1, a.second + 1, b.first + 1, b.second + 1);
	res = true;
}

void BFS(ii v, int dist[][Maxn], ii seq[], int &len)
{
	for (int i = 0; i < len; i++) dist[seq[i].first][seq[i].second] = Inf;
	len = 0;
	dist[v.first][v.second] = 0; seq[len++] = v;
	queue <ii> Q; Q.push(v);
	while (!Q.empty()) {
		v = Q.front(); int curd = dist[v.first][v.second]; Q.pop();
		if (curd == d) continue;
		for (int i = 0; i < Maxd; i++) {
			ii u = ii(v.first + dy[i], v.second + dx[i]);
			if (0 <= u.first && u.first < n && 0 <= u.second && u.second < m && B[u.first][u.second] != 'X' && curd + 1 < dist[u.first][u.second]) {
				dist[u.first][u.second] = curd + 1; seq[len++] = u; Q.push(u);
			}
		}
	}
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	scanf("%d %d %d", &n, &m, &d);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			scanf(" %c", &B[i][j]);
			if (B[i][j] == 'R') rats.push_back(ii(i, j));
			if (fre.size() < 2 && (B[i][j] == 'R' || B[i][j] == '.')) fre.push_back(ii(i, j));
		}
	if (rats.size() > 2 + 4 * d * (d + 1)) { printf("-1\n"); return 0; }
	if (rats.size() == 0) { printf("%d %d %d %d\n", fre[0].first + 1, fre[0].second + 1, fre[1].first + 1, fre[1].second + 1); return 0; }
	fill((int*)tk1, (int*)tk1 + Maxn * Maxn, Inf); fill((int*)tk2, (int*)tk2 + Maxn * Maxn, Inf); 
	fill((int*)tk3, (int*)tk3 + Maxn * Maxn, Inf); fill((int*)tk4, (int*)tk4 + Maxn * Maxn, Inf);
	BFS(rats[0], tk1, seq1, len1);
	for (int i = 0; i < len1 && !res; i++) {
		BFS(seq1[i], tk2, seq2, len2);
		int j = 0;
		while (j < rats.size() && tk2[rats[j].first][rats[j].second] < Inf) j++;
		if (j == rats.size()) {
			ii oth = fre[0];
			if (seq1[i] == oth) oth = fre[1];
			Print(seq1[i], oth); break;
		}
		BFS(rats[j], tk3, seq3, len3);
		for (int k = 0; k < len3 && !res; k++) if (seq1[i] != seq3[k]) {
			BFS(seq3[k], tk4, seq4, len4);
			int l = j;
			while (l < rats.size() && (tk2[rats[l].first][rats[l].second] < Inf || tk4[rats[l].first][rats[l].second] < Inf)) l++;
			if (l == rats.size()) { Print(seq1[i], seq3[k]); break; }
		}
	}
	if (!res) printf("-1\n");
	return 0;
}