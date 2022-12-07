#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long LL;
const int MAXN=100010;
const int N=100000;
int n,Q,op[MAXN],x[MAXN],c[MAXN];
int a[MAXN],tot,now;
LL pos[MAXN],len,L;
void work(int i)
{
	if(op[i]==1)
	{
		if(len<N) a[++len]=x[i];
		L++;
	}
	else
	{
		L+=(LL)x[i]*c[i];
		if(len>=N) return;
		for(int p=1;p<=c[i];p++)
		{
			for(int j=1;j<=x[i];j++)
				if(len<N) a[++len]=a[j];
				else return;
		}
	}
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&op[i]);
		if(op[i]==1) scanf("%d",&x[i]);
		else scanf("%d%d",&x[i],&c[i]);
	}
	scanf("%d",&Q);
	for(int i=1;i<=Q;i++) scanf("%I64d",&pos[i]);
	sort(pos+1,pos+Q+1);
	for(int i=1;i<=Q;i++)
	{
		while(true)
		{
			now++;
			LL nL=L;
			if(op[now]==1) nL++;
			else nL+=(LL)x[now]*c[now];
			if(nL<pos[i]) work(now);
			else {now--;break;}
		}
		if(op[now+1]==1) printf("%d ",x[now+1]);
		else
		{
			LL d=pos[i]-L;
			d=(d-1)%x[now+1]+1;
			printf("%d ",a[d]);
		}
	}
	return 0;
}