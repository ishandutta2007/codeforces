#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 100005;

int n;
bool tk[Maxn];
vector <int> res;

int gcd(int x, int y) { return x? gcd(y % x, x): y; }

int main()
{
	scanf("%d", &n);
	int cur = 1;
	for (int i = 1; i < n; i++)
		if (gcd(i, n) == 1) {
			tk[i] = true;
			cur = ll(cur) * i % n;
		}
	if (cur > 1) tk[cur] = false;
	for (int i = 1; i < n; i++)
		if (tk[i]) res.push_back(i);
	printf("%d\n", int(res.size()));
	for (int i = 0; i < res.size(); i++)
		printf("%d%c", res[i], i + 1 < res.size()? ' ': '\n');
    return 0;
}