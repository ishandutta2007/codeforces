#include<bits/stdc++.h>
using namespace std;
const int mod=8244353;
int n,pig;
char s[55];
int f[55][55],pa[55],ans,id[55],cnt;
vector<int> v[55],ok;
int msk[55],a[11111111],b[11111111];
void FWT_or(int a[],int flg)
{
	for (int i=2;i<=(1<<cnt);i<<=1)
	{
		for (int p=i>>1,j=0;j<(1<<cnt);j+=i)
		{
			for (int k=j;k<j+p;k++)
			{
				a[k+p]+=a[k]*flg;
			}
		}
	}
}
int root(int x)
{
	if (pa[x]!=x) pa[x]=root(pa[x]);
	return pa[x];
}
void Union(int x,int y)
{
	int rx=root(x),ry=root(y);
	if (rx==ry) return;
	pa[rx]=ry;
}
int IFWT(int msk,int i)
{
	if (!i) return a[msk];
	int p=(1<<(i-1));
	if ((msk%(1<<i))>=p) return (IFWT(msk,i-1)-IFWT(msk-p,i-1)+mod)%mod;
	return IFWT(msk,i-1);
}
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		scanf("%s",s);
		for (int j=1;j<=n;j++)
		{
			if (s[j-1]=='A') f[i][j]=0;
			else if (s[j-1]=='O') f[i][j]=1;
			else f[i][j]=2;
		}
	}
	for (int i=1;i<=n;i++)
	{
		pa[i]=i;
	}
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=n;j++)
		{
			if (!f[i][j]) Union(i,j);
		}
	}
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=n;j++)
		{
			if (i==j) continue;
			if (f[i][j]==2)
			{
				if (root(i)==root(j))
				{
					printf("-1\n");
					return 0;
				}
			}
		}
	}
	for (int i=1;i<=n;i++)
	{
		v[root(i)].push_back(i);
	}
	for (int i=1;i<=n;i++)
	{
		if (v[i].size()==0);
		else if (v[i].size()==1) ans++;
		else 
		{
			ans+=(v[i].size()+1);
			id[cnt++]=i;
		}
	}
	ans--;
	for (int i=0;i<cnt;i++)
	{
		for (int j=i+1;j<cnt;j++)
		{
			pig=1;
			for (int k=0;k<v[id[i]].size();k++)
			{
				for (int h=0;h<v[id[j]].size();h++)
				{
					if (f[v[id[i]][k]][v[id[j]][h]]==2) pig=0;
				}
			}
			if (pig) 
			{
				msk[i]|=(1<<j);
				msk[j]|=(1<<i);
			}
		}
	}
	a[0]=1;
	for (int i=1;i<(1<<cnt);i++)
	{
		for (int j=0;j<cnt;j++)
		{
			if (i&(1<<j))
			{
				if (a[i^(1<<j)] && (msk[j]&(i^(1<<j)))==(i^(1<<j))) a[i]=1;
			}
		}
	}
	for (int i=0;i<(1<<cnt);i++)
	{
		if (a[i]) ok.push_back(i); 
	}
	//for (int i=0;i<(1<<cnt);i++) c[i]=a[i];
	//cnt=23;ans=0;a[0]=1;
	//for (int i=1;i<=11;i++) a[(1<<(2*i-2))|(1<<(2*i-1))]=1;
	//a[1<<22]=1;
	FWT_or(a,1);
	for (int i=0;i<(1<<cnt);i++) b[i]=a[i];
	for (int i=1;i<=cnt;i++)
	{
		if (IFWT((1<<cnt)-1,cnt)) 
		{
			printf("%d\n",ans-cnt+i);
			return 0;
		}
		for (int j=0;j<(1<<cnt);j++) a[j]=1ll*a[j]*b[j]%mod;
	}
	printf("%d\n",ans);
	return 0;
}