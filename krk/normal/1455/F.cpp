#include <bits/stdc++.h>
using namespace std;
 
typedef pair <int, int> ii;
 
const int Maxl = 26;
const int Maxn = 505;
 
int T;
int n, k;
char str[Maxn];
bool dp[2][Maxl][Maxl][2];
int cur;
char res[Maxn];
bool hasa[Maxl], hasmid;

void Prec()
{
	fill(hasa, hasa + Maxl, false);
	hasmid = false;
	for (int a = 0; a < Maxl; a++)
		for (int b = 0; b < Maxl; b++)
			for (int mid = 0; mid < 2; mid++) if (dp[cur][a][b][mid]) {
				hasa[a] = true;
				if (mid) hasmid = true;
			}
}
 
bool Pos(int ind, int let, int nd)
{
	return hasa[nd] || hasmid && let == nd;
}
 
int Prv(int let) { return (let - 1 + k) % k; }
 
int Nxt(int let) { return (let + 1) % k; }
 
void Change(int ind, int let, int nd)
{
	for (int a = 0; a < Maxl; a++)
		for (int b = 0; b < Maxl; b++)
			for (int mid = 0; mid < 2; mid++) if (dp[cur][a][b][mid]) {
				dp[cur][a][b][mid] = false;
				if (mid == 0)
					if (a != nd) continue;
					else {
						dp[!cur][let][b][0] = true;
						if (ind + 1 < n)
							dp[!cur][b][let][1] = true;
						dp[!cur][b][let][0] = dp[!cur][b][Prv(let)][0] = dp[!cur][b][Nxt(let)][0] = true;
					}
				else {
					if (ind > 0 && let == nd)
						dp[!cur][a][b][0] = true;
					if (a == nd) {
						dp[!cur][b][let][0] = true;
						dp[!cur][let][b][0] = dp[!cur][Prv(let)][b][0] = dp[!cur][Nxt(let)][b][0] = true;
					}
				}
			}
}
 
int main()
{
	scanf("%d", &T);
	while (T--) {
		scanf("%d %d", &n, &k);
		scanf("%s", str);
		int let = str[0] - 'a';
		if (n > 1)
			dp[cur][0][let][1] = true;
		dp[cur][0][let][0] = dp[cur][0][Prv(let)][0] = dp[cur][0][Nxt(let)][0] = true;
		for (int i = 1; i < n; i++) {
			Prec();
			int let = str[i] - 'a';
			int j = 0;
			while (!Pos(i, let, j)) j++;
			res[i - 1] = 'a' + j;
			Change(i, let, j);
			cur = !cur;
		}
		ii mn = ii(Maxl, Maxl);
		for (int a = 0; a < Maxl; a++)
			for (int b = 0; b < Maxl; b++)
				for (int mid = 0; mid < 2; mid++) if (dp[cur][a][b][mid]) {
					dp[cur][a][b][mid] = false;
					mn = min(mn, ii(a, b));
				}
		res[n - 1] = mn.first + 'a';
		res[n] = mn.second + 'a';
		res[n + 1] = '\0';
		printf("%s\n", res + 1);
	}
    return 0;
}