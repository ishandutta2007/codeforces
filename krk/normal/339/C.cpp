#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

const int Maxm = 1005;
const int Maxw = 11;

string s;
int m;
bool dp[Maxm][Maxw][Maxw];
int par[Maxm][Maxw][Maxw];
vector <int> res;

void Collect(int i, int j, int l)
{
	while (i) {
		res.push_back(l);
		int ni = i - 1, nj = l - j, nl = par[i][j][l];
		i = ni; j = nj; l = nl;
	}
}

void Get()
{
	for (int j = 0; j < Maxw; j++)
		for (int l = 0; l < Maxw; l++) if (dp[m][j][l]) {
			Collect(m, j, l); return;
		}
}

int main()
{
	getline(cin, s);
	scanf("%d", &m);
	dp[0][0][0] = true;
	for (int i = 0; i < m; i++)
		for (int j = 0; j < Maxw; j++)
			for (int l = 0; l < Maxw; l++) if (dp[i][j][l])
				for (int t = 1; t < Maxw; t++) 
					if (s[t - 1] == '1' && t != l && t > j) {
						dp[i + 1][t - j][t] = true; par[i + 1][t - j][t] = l;
					}
	Get();
	if (res.size() < m) printf("NO\n");
	else {
		printf("YES\n");
		for (int i = res.size() - 1; i >= 0; i--)
			printf("%d%c", res[i], i - 1 >= 0? ' ': '\n');
	}
	return 0;
}