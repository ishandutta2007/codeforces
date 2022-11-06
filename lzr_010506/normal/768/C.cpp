#include <bits/stdc++.h>
using namespace std;
int cnt[2][1025];
int now;
inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}
void upd(int x)
{
	int pre = now;
	now ^= 1;
	int par = 0;
	for(int i = 0; i < 1024; i ++) cnt[now][i]=0;
	for(int i = 0; i < 1024; i ++)
	{
		if(cnt[pre][i] == 0) continue;
		int v = cnt[pre][i];
		if(v & 1)
		{
			if(!par)
			{
				cnt[now][(i ^ x)] += (v + 1) / 2;
				cnt[now][i] += (v - 1) / 2;
			}
			else
			{
				cnt[now][(i ^ x)] += (v - 1) / 2;
				cnt[now][i] += (v + 1) / 2;
			}
			par ^= 1;
		}
		else
		{
			cnt[now][(i ^ x)] += v / 2;
			cnt[now][i] += v / 2;
		}
	}
}

int main()
{
	int n;
	n = read();
	int k, x;
	k = read();
	x = read();
	now = 0;
	for(int i = 0; i < n; i ++)
	{
		int z = read();
		cnt[now][z] ++;
	}
	for(int i = 0; i < k; i ++) upd(x);
	for(int i = 1023; i >= 0; i --)
		if(cnt[now][i] > 0)
		{
			cout << i;
			break;
		}
	cout << " ";
	for(int i = 0; i <= 1023; i ++)
		if(cnt[now][i] > 0)
		{
			cout << i;
			break;
		}
	return 0;
}