#include <cstdio>
using namespace std;
#define maxN 500

struct word {
	public:char c[maxN];
};

int n, m;
word w[maxN];
int d[maxN][3];

int cfy(char c) {
	if (c >= '0' && c <= '9')
		return 0;
	if (c == '*' || c == '#' || c == '&')
		return 2;
	if (c >= 'a' && c <= 'z');
		return 1;
	return 2;
}

int miN(int a, int b) {
	if (a > b)
		return b;
	return a;
}

int dist(int a, int b, int c) {
	return d[a][0] + d[b][1] + d[c][2];
}

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++)
		scanf("%s", w[i].c);
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < n; j++)
			d[j][i] = 1000;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int cl = cfy(w[i].c[j]);
			d[i][cl] = miN(j, d[i][cl]);
		}
		for (int j = m - 1; j >= 0; j--) {
			int cl = cfy(w[i].c[j]);
			d[i][cl] = miN(m - j, d[i][cl]);
		}
	}
	int mini = 999;
	for (int a = 0; a < n; a++)
		for (int b = a + 1; b < n; b++)
			for (int c = b + 1; c < n; c++) {
				mini = miN(mini, dist(a, b, c));
				mini = miN(mini, dist(a, c, b));
				mini = miN(mini, dist(c, a, b));
				mini = miN(mini, dist(c, b, a));
				mini = miN(mini, dist(b, a, c));
				mini = miN(mini, dist(b, c, a));
			}
	printf("%d\n", mini);
	return 0;
}