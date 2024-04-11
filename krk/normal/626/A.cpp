#include <cstdio>
#include <cstring>
using namespace std;

const int Maxn = 205;

int n;
char str[Maxn];
int res;

int main()
{
	scanf("%d", &n); scanf("%s", str);
	for (int i = 0; i < n; i++) {
		int r = 0, c = 0;
		for (int j = i; j < n; j++) {
			if (str[j] == 'U') r--;
			else if (str[j] == 'R') c++;
			else if (str[j] == 'D') r++;
			else if (str[j] == 'L') c--;
			if (r == 0 && c == 0) res++;
		}
	}
	printf("%d\n", res);
	return 0;
}