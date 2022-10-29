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

const int maxn = 3100;
const int maxd = 20;

int n;
struct node{int i,x;}a[maxn];
inline bool cmpi(const node x,const node y){return x.i<y.i;}
inline bool cmpx(const node x,const node y){return x.x<y.x;}

int c[maxn];
int pre[maxn][maxd],suf[maxn][maxd],pw[maxn];

int q(const int l,const int r)
{
	int L=pw[r-l+1];
	return max(suf[l][L],pre[r][L]);
}
int ans1,ans2,ans3,ai,aj;
bool cmp(const int x,const int y,const int z)
{
	if(x>ans1) return true;
	else if(x==ans1)
	{
		if(y>ans2) return true;
		else if(y==ans2)
		{
			if(z>ans3) return true;
		}
	}
	return false;
}
int ki[maxn];

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		a[i].i=i; scanf("%d",&a[i].x);
	}sort(a+1,a+n+1,cmpx);
	
	for(int i=1;i<=n;i++) 
		c[i]=a[i].x-a[i-1].x,
		pre[i][0]=suf[i][0]=c[i];
	for(int i=2;i<=n;i<<=1) pw[i]++;
	for(int i=1;i<=n;i++) pw[i]+=pw[i-1];
	
	for(int d=1;d<maxd;d++) for(int i=1;i<=n;i++)
	{
		if(i-(1<<d-1)>=0) pre[i][d]=max(pre[i][d-1],pre[i-(1<<d-1)][d-1]);
		if(i+(1<<d-1)-1<=n) suf[i][d]=max(suf[i][d-1],suf[i+(1<<d-1)][d-1]);
	}
	
	ans1=ans2=ans3=-inf;
	for(int i=2;i<n;i++) for(int j=i+1;j<=n;j++)
	{
		int x=n-j+1,y=j-i; if(x>y) swap(x,y);
		if(x*2<y) continue;
		int l=(y+1)>>1,r=x<<1;
		l=i-l,r=i-r; swap(l,r);
		if(r<1) continue;
		if(l<1) l=1; if(r<1) r=1;
		int kk=q(l,r);
		if(cmp(c[j],c[i],kk)) ans1=c[j],ans2=c[i],ans3=kk,ai=i,aj=j;
	}
	int x=n-aj+1,y=aj-ai; if(x>y) swap(x,y);
	int l=(y+1)>>1,r=x<<1;
	l=ai-l,r=ai-r; swap(l,r);
	int i;for(i=l;i<=r;i++) if(c[i]==ans3) break;
	for(int j=1;j<i;j++) ki[a[j].i]=-1;
	for(int j=i;j<ai;j++) ki[a[j].i]=3;
	for(int j=ai;j<aj;j++) ki[a[j].i]=2;
	for(int j=aj;j<=n;j++) ki[a[j].i]=1;
	
	for(i=1;i<=n;i++) printf("%d ",ki[i]);
	
	return 0;
}