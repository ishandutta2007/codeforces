#include <cstdio>
#include <string>
#include <algorithm>
using namespace std;

const int Maxn = 55;

int n, m;
char B[Maxn][Maxn];
int res;

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++)
		scanf("%s", B[i]);
	for (int i = 0; i + 2 <= n; i++)
		for (int j = 0; j + 2 <= m; j++) {
			string s = "";
			for (int ni = 0; ni < 2; ni++)
				for (int nj = 0; nj < 2; nj++)
					s += string(1, B[i + ni][j + nj]);
			sort(s.begin(), s.end());
			res += s == "acef";
		}
	printf("%d\n", res);
	return 0;
}