#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mp make_pair
#define pb push_back
#define fi first
#define se second
void read(int &digit)
{
	digit=0;
	char c;
	for (c=getchar();(c<'0' || c>'9') && c!='-';c=getchar());
	bool type=false;
	if (c=='-')
		type=true,c=getchar();
	for (;c>='0' && c<='9';digit=digit*10+c-'0',c=getchar());
	if (type==true)
		digit=-digit;
}
#define maxn 1010
typedef long double db;
db f[maxn];
db g[maxn];
double b[maxn][maxn];
int n;
int que[maxn],r;
int pos[maxn];
bool vis[maxn];

void add(int t)
{
	r++;
	que[r]=t;
	pos[t]=r;
	int now=r;
	while (now>1)
	{
		if (f[que[now]]<f[que[now/2]])	swap(que[now],que[now/2]),swap(pos[que[now]],pos[que[now/2]]);
		else break;
		now/=2;
	}
}
void change(int t)
{
	int now=t;
	while (now>1)
	{
		if (f[que[now]]<f[que[now/2]])	swap(que[now],que[now/2]),swap(pos[que[now]],pos[que[now/2]]);
		else break;
		now/=2;
	}
}
void del()
{
	pos[que[1]]=-1;
	if (r==1)	return;
	pos[que[r]]=1;
	que[1]=que[r];
	que[r--]=0;
	int now=1;
	while (2*now<=r)
	{
		int son=now*2;
		if (son+1<=r)
		if (f[que[son+1]]<f[que[son]])	son=son+1;
		if (f[que[son]]<f[que[now]])	swap(que[now],que[son]),swap(pos[que[now]],pos[que[son]]),now=son;
		else break;
	}
}
const double eps=1e-9; 
int main()
{
	read(n);
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
		{
			int x;
			read(x);
			b[i][j]=x/100.0;
		}
	for (int i=1;i<n;i++)	f[i]=1e9,g[i]=1;
	for (int i=1;i<=n;i++)	add(i);
	for (int i=1;i<=n;i++)
	{
		int u=que[1];
		vis[u]=true;
		del();
		for (int j=1;j<=n;j++)
		if (!vis[j])
		{
			db A=f[j]*(1.0-g[j]);
			if (g[j]==1)	A=1;
			db B=g[j]*b[j][u]*f[u];
			g[j]=g[j]*(1.0-b[j][u]);
			if (fabs(1-g[j])<eps)	f[j]=1e9;else f[j]=(A+B)/(1.0-g[j]);
			change(pos[j]);
		}
	}
	printf("%.8lf\n",(double)f[1]);
	return 0;
}