#include <cstdio>
#include <string>
using namespace std;

const int Maxm = 200;
const int Maxd = 3;
const string abc = "ABC";

int X[Maxd], Y[Maxd];
int ar, n;
char B[Maxm][Maxm];
bool tk[Maxd];
bool ok;

bool Check(int sr, int sc, int dr, int dc)
{
	if (sr + dr > n || sc + dc > n) return false;
	for (int i = 0; i < dr; i++)
		for (int j = 0; j < dc; j++)
			if (B[sr + i][sc + j] != '.') return false;
	return true;
}

void Fill(int sr, int sc, int dr, int dc, int id, bool er = false)
{
	for (int i = 0; i < dr; i++)
		for (int j = 0; j < dc; j++)
			B[sr + i][sc + j] = er? '.': abc[id];
}

void Print()
{
	ok = true;
	printf("%d\n", n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			printf("%c", B[i][j]);
		printf("\n");
	}

}

void Gen(int lvl)
{
	if (lvl == Maxd) Print();
	else {
		bool found = false;
		int mr, mc;
		for (int i = 0; i < n && !found; i++)
			for (int j = 0; j < n && !found; j++)
				if (B[i][j] == '.') { found = true; mr = i; mc = j; }
		for (int i = 0; i < Maxd && !ok; i++) if (!tk[i])
			for (int j = 0; j < 2 && !ok; j++) {
				if (Check(mr, mc, X[i], Y[i])) {
					tk[i] = true;
					Fill(mr, mc, X[i], Y[i], i);
					Gen(lvl + 1);
					Fill(mr, mc, X[i], Y[i], i, true);
					tk[i] = false;
				}
				swap(X[i], Y[i]);
			}
	}
}

int main()
{
	for (int i = 0; i < Maxd; i++) {
		scanf("%d %d", &X[i], &Y[i]);
		ar += X[i] * Y[i];
	}
	n = 1;
	while (n * n < ar) n++;
	if (n * n != ar) { printf("-1\n"); return 0; }
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			B[i][j] = '.';
	Gen(0);
	if (!ok) printf("-1\n");
	return 0;
}