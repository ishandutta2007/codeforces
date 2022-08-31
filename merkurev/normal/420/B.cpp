#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

const int maxn = 1e5 + 100;


char s[3];
bool used[maxn];
bool bad[maxn];

bool isNow[maxn];

pair <char, int> a[maxn];
int only = -1;


void updOnly()
{
	if (only == -2)
		return;
	if (only != -1 && !isNow[only] )
	{
		only = -2;
		return;
	}
	for (int i = 0; ; i++)
		if (isNow[i] )
		{
			only = i;
			break;
		}
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++)
	{
		int id;
		scanf("%s %d", s, &id);
		id--;
		used[id] = true;
		a[i] = make_pair(s[0], id);
	}
	for (int i = m - 1; i >= 0; i--)
	{
		int id = a[i].second;
		if (a[i].first == '+')
			isNow[id] = false;
		else
			isNow[id] = true;
	}
	int cnt = 0;
	for (int i = 0; i < n; i++)
		if (isNow[i] )
			cnt++;
	for (int i = 0; i < m; i++)
	{
		int id = a[i].second;
		char t = a[i].first;

		if (cnt == 1)
		{
			updOnly();
		}

		if (t == '+')
		{
			if (cnt != 0)
				bad[id] = true;
			cnt++;
			isNow[id] = true;
		}
		else
		{
			cnt--;
			isNow[id] = false;
			if (cnt != 0)
				bad[id] = true;
		}
	}
	if (cnt == 1)
		updOnly();
	if (only >= 0 && !bad[only] )
	{
		used[only] = false;
	}
	cnt = 0;
	for (int i = 0; i < n; i++)
		if (!used[i] )
			cnt++;
	printf("%d\n", cnt);
	for (int i = 0; i < n; i++)
		if (!used[i] )
			printf("%d ", i + 1);

	return 0;
}