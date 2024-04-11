#include <cstdio>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

const int Maxn = 200005;

int n, a, b, k;
char str[Maxn];
vector <int> res;

int main()
{
	scanf("%d %d %d %d", &n, &a, &b, &k);
	scanf("%s", str + 1);
	int tot = 0;
	for (int i = 1; i <= n; i++)
		if (str[i] == '0') {
			int r = i;
			while (r <= n && str[r] == '0') r++;
			tot += (r - i) / b;
			i = r;
		}
	int nd = tot - (a - 1);
	printf("%d\n", nd);
	for (int i = 1; i <= n; i++)
		if (str[i] == '0') {
			int r = i;
			while (r <= n && str[r] == '0') r++;
			for (int j = i + b - 1; j < r && nd > 0; j += b) {
				res.push_back(j); nd--;
			}
			i = r;
		}
	for (int i = 0; i < res.size(); i++)
		printf("%d%c", res[i], i + 1 < res.size()? ' ': '\n');
	return 0;
}