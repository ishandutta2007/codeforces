#include <bits/stdc++.h>
using namespace std;
const int maxn=1000;
char buffer[maxn],*S,*T;
inline char Get_Char()
{
    if(S==T)
    {
        T=(S=buffer)+fread(buffer,1,maxn,stdin);
        if(S==T) return EOF;
    }
    return *S++;
}
long long read()
{
    char c;
    long long re=0;
	int f=0;
    for(c=Get_Char();c<'0'||c>'9';c=Get_Char())
    {
    	if (c=='-') f=1;
	}
    while(c>='0'&&c<='9')
           re=re*10+(c&15),c=Get_Char();
    if (f) return -re;
    return re;
}
int n, cnt, pa[2222];
long long f[2222], x;
pair<long long, pair<int, int> > arr[4444444];
int root(int x)
{
	if (pa[x] != x) pa[x] = root(pa[x]);
	return pa[x];
}
bool Union(int x, int y)
{
	int rx = root(x), ry = root(y);
	if (rx == ry) return 0;
	pa[rx] = ry;
	return 1;
}
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			if (i == j) f[i] = read();
			else
			{
				x = read();
				arr[++cnt] = make_pair(x, make_pair(i, j));
			}
		}
	}
	sort(arr + 1, arr + cnt + 1);
	reverse(arr + 1, arr + cnt + 1);
	for (int i = 1; i <= n; i++) pa[i] = i;
	for (int i = 1; i <= cnt; i++)
	{
		if (Union(arr[i].second.first, arr[i].second.second))
		{
			printf("%d %d %d\n", arr[i].second.first, arr[i].second.second, (f[arr[i].second.first] + f[arr[i].second.second] - (arr[i].first << 1)) / n);
		}
	}
	return 0;
}