#include <cstdio>
#include <set>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 300005;

int n, m;
char str[Maxn];
int res;

int main()
{
	scanf("%d %d", &n, &m);
	scanf("%s", str + 1);
	str[0] = 'a'; str[n + 1] = 'a';
	for (int i = 1; i <= n; i++)
		res += str[i] == '.' && str[i + 1] == '.';
	while (m--) {
		int x; char ch; scanf("%d %c", &x, &ch);
		if (ch == '.' && str[x] != '.') {
			str[x] = '.';
			if (str[x - 1] == '.') res++;
			if (str[x + 1] == '.') res++;
		}
		if (ch != '.' && str[x] == '.') {
			str[x] = ch;
			if (str[x - 1] == '.') res--;
			if (str[x + 1] == '.') res--;
		}
		printf("%d\n", res);
	}
	return 0;
}