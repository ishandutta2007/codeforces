#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long LL;
const int MAXN=300010;
const LL INF=1000000000000000000LL;
int n,k,A,B,Len;
LL a[MAXN],f[5010][5010],ans;
LL getf(int i,int j)
{
	if(f[i][j]!=-1) return f[i][j];
	if(i==0&&j==0) return 0;
	f[i][j]=INF;
	if(i>=1) f[i][j]=min(f[i][j],getf(i-1,j)+a[i*Len+j*(Len+1)]-a[(i-1)*Len+j*(Len+1)+1]);
	if(j>=1) f[i][j]=min(f[i][j],getf(i,j-1)+a[i*Len+j*(Len+1)]-a[i*Len+(j-1)*(Len+1)+1]);
	return f[i][j];
}
int main()
{
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	Len=n/k,B=n%k,A=k-B;
	memset(f,-1,sizeof(f));
	ans=getf(A,B);
	printf("%I64d\n",ans);
	return 0;
}