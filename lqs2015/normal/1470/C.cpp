#include <bits/stdc++.h>
using namespace std;
mt19937 rnd(time(0));
int n, k, y, cur;
int ask(int x)
{
	printf("? %d\n", x);
	fflush(stdout);
	scanf("%d", &y);
	return y;
}
int confirm(int x)
{
	printf("! %d\n", x);
	fflush(stdout);
	exit(0);
}
int Get()
{
	return rnd() % n + 1;
}
int main()
{
	scanf("%d%d", &n, &k);
	while(1)
	{
		cur = Get();
		y = ask(cur);
		if (y != k) break;
	}
	if (y < k)
	{
		cur = cur % n + 1;
		while(ask(cur) != k) cur = cur % n + 1;
		confirm(cur);
	}
	else
	{
		cur = (cur + n - 2) % n + 1;
		while(ask(cur) != k) cur = (cur + n - 2) % n + 1;
		confirm(cur);
	}
	return 0;
}