#include<cstdio>
typedef long long ll;
const int K=1e5+5,mod=1e9+9;
inline int qpow(int a,int p)
{
	int res=1;
	for(;p;a=(ll)a*a%mod,p>>=1)
		if(p&1)
			res=(ll)res*a%mod;
	return res;
}
int n,a,b,k,g,sg,ans;
int A[3][3],res[3][3],th[3][3];
char s[K];
inline void matrix_qpow(int n,int p)
{
	register int i,j,k;
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			res[i][j]=(i==j);
	for(;p;p>>=1)
	{
		if(p&1)
		{
			for(i=1;i<=n;i++)
				for(j=1;j<=n;j++)
					th[i][j]=0;
			for(k=1;k<=n;k++)
				for(i=1;i<=n;i++)
					for(j=1;j<=n;j++)
					{
						th[i][j]+=(ll)res[i][k]*A[k][j]%mod;
						if(th[i][j]>=mod)
							th[i][j]-=mod;
					}
			for(i=1;i<=n;i++)
				for(j=1;j<=n;j++)
					res[i][j]=th[i][j];
		}
		for(i=1;i<=n;i++)
			for(j=1;j<=n;j++)
				th[i][j]=0;
		for(k=1;k<=n;k++)
			for(i=1;i<=n;i++)
				for(j=1;j<=n;j++)
				{
					th[i][j]+=(ll)A[i][k]*A[k][j]%mod;
					if(th[i][j]>=mod)
						th[i][j]-=mod;
				}
		for(i=1;i<=n;i++)
			for(j=1;j<=n;j++)
				A[i][j]=th[i][j];
	}
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			A[i][j]=res[i][j];
	return;
}
signed main()
{
	register int i;
	scanf("%d%d%d%d",&n,&a,&b,&k);
	scanf("%s",s);
	g=(ll)qpow(qpow(a,k),mod-2)*qpow(b,k)%mod;
	A[1][1]=A[2][1]=g;A[1][2]=0;A[2][2]=1;
	matrix_qpow(2,(n+1)/k-1);
	sg=(A[2][1]+A[2][2])%mod;
	for(i=0;i<k;i++)
	{
		ans+=(ll)(s[i]=='+'?1:mod-1)*qpow(a,n-i)%mod*qpow(b,i)%mod*sg%mod;
		if(ans>=mod)
			ans-=mod;
	}
	printf("%d\n",ans);
	return 0;
}