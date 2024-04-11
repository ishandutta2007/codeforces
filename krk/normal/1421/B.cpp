#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 205;

int T;
int n;
char B[Maxn][Maxn];

vector <ii> Inv(char a, char b)
{
	vector <ii> res;
	if (B[1][2] != a) res.push_back(ii(1, 2));
	if (B[2][1] != a) res.push_back(ii(2, 1));
	if (B[1][3] != b) res.push_back(ii(1, 3));
	if (B[2][2] != b) res.push_back(ii(2, 2));
	if (B[3][1] != b) res.push_back(ii(3, 1));
	return res;
}

int main()
{
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)
			scanf("%s", B[i] + 1);
		auto res = Inv('0', '1');
		if (res.size() > 2)
			res = Inv('1', '0');
		printf("%d\n", int(res.size()));
		for (int i = 0; i < res.size(); i++)
			printf("%d %d\n", res[i].first, res[i].second);
	}
    return 0;
}