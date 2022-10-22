#include <cstdio>
#include <algorithm>
using namespace std;

const int Maxn = 32;
const int Maxz = 15;
const int Maxp = 28;
const int Maxe = 7;

int id[Maxe][Maxe];
int n, m;
char B[Maxn][Maxn];
int z, sr[Maxz], sc[Maxz];
int col[Maxn][Maxn];
int seq[Maxz];
int tp[Maxp];
int ways;
bool was;
char cur[Maxn][Maxn], res[Maxn][Maxn];

int getId(int a, int b) { return id[min(a, b)][max(a, b)]; }

bool Check()
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (B[i][j] != '.')
				if (j + 1 < m && B[i][j] == B[i][j + 1]) {
					int id = getId(cur[i][j] - '0', cur[i][j + 1] - '0');
					if (++tp[id] > 1) return false;
				} else if (i + 1 < n && B[i][j] == B[i + 1][j]) {
					int id = getId(cur[i][j] - '0', cur[i + 1][j] - '0');
					if (++tp[id] > 1) return false;
				}
	return true;
}

void Gen(int v)
{
	if (v == Maxe) {
		for (int i = 1; i < Maxz; i++) {
			int r = sr[i], c = sc[i];
			cur[r][c] = cur[r][c + 1] = cur[r + 1][c] = cur[r + 1][c + 1] = seq[i] + '0';
		}
		fill(tp, tp + Maxp, 0);
		if (Check()) {
			ways += 5040;
			if (!was) {
				for (int i = 0; i < n; i++)
					for (int j = 0; j < m; j++)
						res[i][j] = cur[i][j];
				was = true;
			}
		}
	} else {
		int i = 1;
		while (seq[i] != -1) i++;
		seq[i] = v;
		for (int j = i + 1; j < Maxz; j++) if (seq[j] == -1) {
			seq[j] = v;
			Gen(v + 1);
			seq[j] = -1;
		}
		seq[i] = -1;
	}
}

int main()
{
	int lst = 0;
	for (int i = 0; i < Maxe; i++)
		for (int j = i; j < Maxe; j++)
			id[i][j] = lst++;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			scanf(" %c", &B[i][j]);
			if (B[i][j] != '.' && col[i][j] == 0) {
				z++; col[i][j] = col[i][j + 1] = col[i + 1][j] = col[i + 1][j + 1] = z;
				sr[z] = i; sc[z] = j;
			}
		}
	fill(seq, seq + Maxz, -1);
	Gen(0);
	printf("%d\n", ways);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			printf("%c", B[i][j] == '.'? '.': res[i][j]);
		printf("\n");
	}
	return 0;
}