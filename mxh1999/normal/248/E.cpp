#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
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

#define maxn 100010
map<int,double>	f[maxn];
pair<int,double>	qaq[maxn];
int a[maxn];
int n,m;
typedef map<int,double>::iterator zxo;
ll c[100010][6];
double mjy;

int main()
{
	//freopen("248E.in","r",stdin);
	read(n);
	for (int i=1;i<=n;i++)	read(a[i]);
	for (int i=1;i<=n;i++)
	{
		f[i][a[i]]=1;
		if (a[i]==0)	mjy+=1;
	}
	c[0][0]=1;
	for (int i=1;i<=100000;i++)
	{
		c[i][0]=1;
		for (int j=1;j<=i && j<=5;j++)	c[i][j]=c[i-1][j-1]+c[i-1][j];
	}
	read(m);
	while (m--)
	{
		int u,v,k;
		read(u),read(v),read(k);
		int cnt=0;
		mjy-=f[u][0];
		for (zxo it=f[u].begin();it!=f[u].end();it++)
		{
			for (int l=0;l<=k;l++)
			if (it->first>=l && a[u]-(it->first)>=k-l)
			{
				double num=c[it->first][l];
				num*=c[a[u]-it->first][k-l];
				num/=c[a[u]][k];
				num*=it->second;
				qaq[++cnt]=make_pair(it->first-l,num);
			}
		}
		f[u].clear();
		for (int i=1;i<=cnt;i++)	f[u][qaq[i].first]+=qaq[i].second;
		a[u]-=k;
		a[v]+=k;
		mjy+=f[u][0];
		printf("%.10lf\n",mjy);
	}
	return 0;
}