#include<bits/stdc++.h>
using namespace std;
#define re register
int n,m;
char ss[1001000];
int x[1001000],sq[1001000];
int qw[1001000],qw1[1001000];
int cal(re int*xx,re int a,re int k)
{
	re int i1=a/m,j1=a%m,i2=i1+k,ans=0,j2=j1+k;i1-=k+1,j1-=k+1;
	if(i2>=n)i2=n-1;if(j2>=m)j2=m-1;
	ans=xx[i2*m+j2];
	if(i1>=0)ans-=xx[i1*m+j2];
	if(j1>=0)ans-=xx[i2*m+j1];
	if(i1>=0&&j1>=0)ans+=xx[i1*m+j1];
	return ans;
}
bool check(re int k)
{
	memset(qw,0,sizeof(qw));memset(qw1,0,sizeof(qw1));
	for(re int ii=k;ii<n-k;ii++)
	{
		for(re int j=k;j<m-k;j++)
		{
			re int i=ii*m+j;if(cal(x,i,k)==(2*k+1)*(2*k+1))qw[i]=1;
		
		}
	}for(re int ii=0;ii<n;ii++)for(re int j=0;j<m;j++)qw1[ii*m+j]=qw[ii*m+j]+(ii?qw1[ii*m-m+j]:0)+(j?qw1[ii*m+j-1]:0)-(ii&&j?qw1[ii*m+j-m-1]:0);
	for(re int i=0;i<n*m;i++){if(sq[i]&&cal(qw1,i,k)==0){return 0;}}
	return 1;
}
int main()
{
	scanf("%d%d",&n,&m);
	re int l=0,r=(min(n,m)-1)/2,mid;
	for(re int i=0;i<n;i++)
	{
		scanf("%s",ss);
		for(re int j=0;j<m;j++)sq[i*m+j]=(ss[j]=='X'),x[i*m+j]=(ss[j]=='X')+(i?x[i*m-m+j]:0)+(j?x[i*m+j-1]:0)-(i&&j?x[i*m+j-m-1]:0);
	}
	for(mid=(l+r+1)/2;l<r;mid=(l+r+1)/2)
	{
		if(check(mid))l=mid;
		else r=mid-1;
	}
	check(l);
	printf("%d\n",l);
	for(re int i=0;i<n;i++){
		for(re int j=0;j<m;j++)printf("%c",(qw[i*m+j]?'X':'.'));puts("");}
}