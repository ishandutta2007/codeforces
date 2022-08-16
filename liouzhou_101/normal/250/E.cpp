#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;

const int MaxN=110;
const int MaxM=10010;

int n,m;
char s[MaxN][MaxM];

int flag;
long long ans;

int u[MaxM];
int pL[MaxM],pR[MaxM];
int L[MaxM],R[MaxM];

int getL(int x)
{
	return (L[x]==x)?x:L[x]=getL(L[x]);
}

int getR(int x)
{
	return (R[x]==x)?x:R[x]=getR(R[x]);
}

void work(int x,int y,int c)
{
	if (x==n) return;
	if (s[x+1][y]=='.')
	{
		++ans;
		work(x+1,y,c);
		return;
	}
	if (!u[x])
	{
		pL[0]=0;
		for (int i=1;i<=m;++i)
			pL[i]=(s[x+1][i]=='.')?i:pL[i-1];
		pR[m+1]=m+1;
		for (int i=m;i>=1;--i)
			pR[i]=(s[x+1][i]=='.')?i:pR[i+1];
		L[0]=0;
		for (int i=1;i<=m;++i)
			L[i]=(s[x][i]=='.')?L[i-1]:i;
		R[m+1]=m+1;
		for (int i=m;i>=1;--i)
			R[i]=(s[x][i]=='.')?R[i+1]:i;
	}
	u[x]++;
	if (u[x]>m*2)
	{
		flag=1;
		return;
	}
	if (c==1)
	{
		int t=getR(y);
		if (pR[y]<t)
		{
			ans+=pR[y]-y;
			work(x,pR[y],c);
			return;
		}
		ans+=t-y;
		if (s[x][t]=='+')
		{
			s[x][t]='.';
			L[t]=getL(t-1);
			R[t]=getR(t+1);
			work(x,t-1,-c);
			return;
		}
		else
			work(x,t-1,-c);
	}
	else
	{
		int t=getL(y);
		if (t<pL[y])
		{
			ans+=y-pL[y];
			work(x,pL[y],c);
			return;
		}
		ans+=y-t;
		if (s[x][t]=='+')
		{
			s[x][t]='.';
			L[t]=getL(t-1);
			R[t]=getR(t+1);
			work(x,t+1,-c);
			return;
		}
		else
			work(x,t+1,-c);
	}
}

int main()
{
	cin>>n>>m;
	for (int i=1;i<=n;++i)
	{
		scanf("%s",s[i]+1);
		s[i][0]=s[i][m+1]='#';
	}
	work(1,1,1);
	if (flag)
		puts("Never");
	else
		cout<<ans<<endl;
	return 0;
}