#include <cstdio>
#include <vector>

using namespace std;

vector <int> x, y;
bool f[50000][200];
int g[50000][200];
long long n;

long long grade(int a, int b){
	long long res = 1, mul = a;
	while (b != 0){
		if (b % 2)
			res *= mul;
		mul *= mul;
		b /= 2;
	}
	return res;
}

void tryGo(int xCur, int yCur){
	if (f[xCur][yCur])
		return ;
	long long res = grade(xCur, yCur);
	if (xCur == 40000){
		if ((n - xCur) % 2 == 1)
			g[xCur][yCur] = -1;
		else
			g[xCur][yCur] = 1;
		f[xCur][yCur] = true;
		return ;
	}
	if (res >= n){
		g[xCur][yCur] = 1;
		f[xCur][yCur] = true;
		return ;
	}
	f[xCur][yCur] = true;
	x.push_back(xCur);
	y.push_back(yCur);
}

void bfs(int xs, int ys){
	int xCur, yCur, i;
	x.push_back(xs); y.push_back(ys);
	int cur = 0;
	while (cur < x.size()){
		xCur = x[cur]; yCur = y[cur];
		tryGo(xCur + 1, yCur);
		if (yCur < 50)
			tryGo(xCur, yCur + 1);
		cur++;
	}
	for (i = x.size() - 1;i > -1;i--){
		if (g[x[i]][y[i]] == 0){
			if (g[x[i] + 1][y[i]] == -1 || g[x[i]][y[i] + 1] == -1)
				g[x[i]][y[i]] = 1;
			else
			{
				if (g[x[i] + 1][y[i]] == 0 || g[x[i]][y[i] + 1] == 0)
					g[x[i]][y[i]] = 0;
				else
					g[x[i]][y[i]] = -1;
			}
		}
	}
	if (g[xs][ys] == 1){
		printf("Masha");
		return ;
	}
	if (g[xs][ys] == 0)
		printf("Missing");
	else
		printf("Stas");
}

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int xs, ys;
	scanf("%d%d%I64d", &xs, &ys, &n);
	bfs(xs, ys);
	return 0;
}