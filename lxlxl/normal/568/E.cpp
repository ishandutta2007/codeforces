#include<set>
#include<map>
#include<deque>
#include<queue>
#include<stack>
#include<cmath>
#include<ctime>
#include<bitset>
#include<string>
#include<vector>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<climits>
#include<complex>
#include<iostream>
#include<algorithm>
#define ll long long
#define inf 1e9
using namespace std;

const int maxn = 110000;

int n,m;
int a[maxn],b[maxn],al[maxn];
bool v[maxn];
int w[maxn],f[maxn],s[maxn];

int cal(int x,int y)
{
	return al[y]-al[x]-(b[al[y]]==a[y]?1:0);
}
int cal2(int x,int y)
{
	return s[y]-s[x];
}

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++) 
	{
		scanf("%d",&a[i]); s[i]=s[i-1];
		if(a[i]==-1) ++s[i];
	}
	scanf("%d",&m); for(int i=1;i<=m;i++) scanf("%d",&b[i]);
	sort(b+1,b+m+1); int L=unique(b+1,b+m+1)-(b+1); 
	
	int tp; w[tp=0]=0;
	for(int i=1;i<=n;i++)
	{
		if(a[i]!=-1)
		{
			int l=0,r=tp;
			while(l<=r)
			{
				int mid=l+r>>1;
				if(w[mid]<a[i]) l=mid+1;
				else r=mid-1;
			}int j=l;
			w[j]=a[i]; f[i]=j;
			if(w[tp+1]) tp++;
		}
		else
		{
			int pos=tp+1;
			for(int j=L;j>=1;j--)
			{
				while(pos&&w[pos-1]>=b[j]) pos--;
				w[pos]=b[j];
			}
			f[i]=pos;
			if(w[tp+1]) tp++;
		}
	}
	int now=n+1; a[now]=inf+1; s[now]=s[n]; f[now]=tp+1;
	for(int i=1;i<=n+1;i++) if(a[i]!=-1)
	{
		int l=1,r=L;
		while(l<=r)
		{
			int mid=l+r>>1;
			if(b[mid]<=a[i]) l=mid+1;
			else r=mid-1;
		}al[i]=l-1;
	}
	while(f[now])
	{
		int nex=now-1;
		for(;a[nex]==-1||a[nex]>=a[now]||f[now]-f[nex]-1>min(cal(nex,now),cal2(nex,now));nex--);
		int pos=al[now]; if(b[pos]==a[now]) pos--;
		for(int j=now-1;j>nex;j--) if(a[j]==-1)
		{
			while(v[pos]) pos--;
			if(pos<=al[nex]) break;
			a[j]=b[pos]; v[pos--]=true;
		}
		now=nex;
	}
	int j=1;
	for(int i=1;i<=n;i++) if(a[i]==-1)
	{
		while(v[j]) j++;
		a[i]=b[j]; v[j++]=true;
	}
	for(int i=1;i<=n;i++) printf("%d ",a[i]);
	
	return 0;
}