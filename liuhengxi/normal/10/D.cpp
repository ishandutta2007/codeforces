#include<cstdio>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=500;
int n,m,a[N],b[N],f[N][N],s[N][N+1],p[N][N],pi[N][N],pj[N][N],ans,i1,j1,mem[N];
int main()
{
	scanf("%d",&n);F(i,0,n)scanf("%d",&a[i]);
	scanf("%d",&m);F(i,0,m)scanf("%d",&b[i]);
	F(i,0,n)F(j,0,m)
	{
		if(a[i]==b[j])
		{
			F(k,0,i)if(a[k]<a[i]&&s[k][j]>f[i][j])f[i][j]=s[k][j],p[i][j]=k;
			++f[i][j];
		}
		if(f[i][j]>ans)ans=f[i][j],i1=i,j1=j;
		if(f[i][j]>s[i][j])s[i][j+1]=f[i][j],pi[i][j+1]=i,pj[i][j+1]=j;
		else s[i][j+1]=s[i][j],pi[i][j+1]=pi[i][j],pj[i][j+1]=pj[i][j];
	}
	for(int k=ans-1,i=i1,j=j1;~k;--k)
	{
		int l=p[i][j];
		mem[k]=a[i];
		i=pi[l][j];j=pj[l][j];
	}
	printf("%d\n",ans);
	F(i,0,ans)printf("%d ",mem[i]);
	printf("\n");
	return 0;
}