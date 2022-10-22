#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 1000005;

int T;
int n;
char str[Maxn];
map <ii, int> M;

int gcd(int a, int b) { return a? gcd(b % a, a): b; }

ii Fix(ii p)
{
	int g = gcd(p.first, p.second);
	return ii(p.first / g, p.second / g);
}

int main()
{
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		scanf("%s", str);
		M.clear();
		ii p = ii(0, 0);
		for (int i = 0; i < n; i++) {
			if (str[i] == 'D') p.first++;
			else p.second++;
			printf("%d%c", ++M[Fix(p)], i + 1 < n? ' ': '\n');
		}
	}
    return 0;
}