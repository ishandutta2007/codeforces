#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int X, A;
ll nxt = 1;
vector <ll> res;

int Get(int val)
{
	int cur = 0;
	while ((1 << cur + 1) <= val + 1)
		cur++;
	return cur;
}

int main()
{
	scanf("%d %d", &X, &A);
	while (X > 0) {
		int my = Get(X);
		X -= ((1 << my) - 1);
		while (my--) res.push_back(nxt);
		nxt += A + 1;
	}
	printf("%d\n", int(res.size()));
	for (int i = 0; i < res.size(); i++)
		printf("%lld%c", res[i], i + 1 < res.size()? ' ': '\n');
	return 0;
}