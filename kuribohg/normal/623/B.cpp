#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
typedef long long LL;
const int MAXN=1000010;
const LL INF=1000000000000000000LL;
int n,a[MAXN];
LL A,B;
vector<int> v;
void fact(int n)
{
	int nn=n;
	for(int i=2;i*i<=nn;i++)
		if(n%i==0)
		{
			n/=i,v.push_back(i);
			while(n%i==0) n/=i;
		}
	if(n>1) v.push_back(n);
}
LL ans=INF;
LL f[MAXN][3],c[MAXN];
LL solve(int x)
{
	for(int i=1;i<=n;i++)
		for(int j=0;j<3;j++)
			f[i][j]=INF;
	for(int i=1;i<=n;i++)
	{
		if(a[i]%x==0) f[i][0]=f[i-1][0],f[i][2]=f[i-1][2];
		if(a[i]%x==1||a[i]%x==x-1) f[i][0]=f[i-1][0]+B,f[i][2]=f[i-1][2]+B;
		f[i][1]=min(f[i-1][1],f[i-1][0])+A;
		f[i][2]=min(f[i][2],f[i][1]);
	}
	return min(f[n][0],f[n][2]);
}
int main()
{
	scanf("%d%I64d%I64d",&n,&A,&B);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	fact(a[1]);
	fact(a[1]+1);
	fact(a[1]-1);
	fact(a[n]);
	fact(a[n]+1);
	fact(a[n]-1);
	v.erase(unique(v.begin(),v.end()),v.end());
	for(int i=0;i<v.size();i++)
		ans=min(ans,solve(v[i]));
	printf("%I64d\n",ans);
	return 0;
}