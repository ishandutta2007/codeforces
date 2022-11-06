#pragma GCC optimize(3)
#include<cstdio>
#define int long long
const int N(5005),mod(998244353);//,M(64);
int a,b,c,ans;
int hj[N][N];//,HJ[M+5][M+5][M+5];
inline void swap(int &a,int &b)
{
	a=a+b;
	b=a-b;
	a=a-b;
	return;
}
/*inline int huaji(int x,int y,int power)
{
	if(x==1)
		return power;
	if(hj[x][y])
		return power*hj[x][y]%mod;
	int sum(0);
	if(y>1)
		sum+=huaji(x-1,y-1,y-1);
	sum+=huaji(x-1,y,1);
	sum%=mod;
	hj[x][y]=sum;
	return power*sum%mod;
}
inline int HUAJI(int x,int y,int z,int power)
{
	if(z==1)
		return power;
	if(x<=504&&y<=504&&z<=504&&HJ[x][y][z])
		return power*HJ[x][y][z]%mod;
	int sum(0);
	if(x>1&&y>1)
		sum+=HUAJI(x-1,y-1,z-1,(x-1)*(y-1));
	if(x>1)
		sum+=HUAJI(x-1,y,z-1,x-1);
	if(y>1)
		sum+=HUAJI(x,y-1,z-1,y-1);
	sum+=HUAJI(x,y,z-1,1);
	sum%=mod;
	if(x<=504&&y<=504&&z<=504)
		HJ[x][y][z]=sum;
	return power*sum%mod;
}*/
signed main()
{
	int i,j,k;
	scanf("%I64d%I64d%I64d",&a,&b,&c);
	if(a<b)
		swap(a,b);
	if(a<c)
		swap(a,c);
	if(b<c)
		swap(b,c);
	for(i=1;i<=b+1;i++)
		hj[1][i]=1;
	for(i=2;i<=a+1;i++)
		for(j=1;j<=b+1;j++)
			hj[i][j]=((j-1)*hj[i-1][j-1]%mod+hj[i-1][j])%mod;
/*	for(i=1;i<=a+1;i++)
		for(j=1;j<=b+1;j++)
		{
			HJ[i&(M-1)][j&(M-1)][1]=1;
			for(k=2;k<=c+1;k++)
				HJ[i&(M-1)][j&(M-1)][k&(M-1)]=((i-1)*(j-1)%mod*HJ[(i-1)&(M-1)][(j-1)&(M-1)][(k-1)&(M-1)]%mod+(i-1)*HJ[(i-1)&(M-1)][j&(M-1)][(k-1)&(M-1)]%mod+(j-1)*HJ[i&(M-1)][(j-1)&(M-1)][(k-1)&(M-1)]%mod+HJ[i&(M-1)][j&(M-1)][(k-1)&(M-1)]%mod)%mod;
		}*/
	//ans=hj[a+1][b+1]*HJ[(a+1)&(M-1)][(b+1)&(M-1)][(c+1)&(M-1)]%mod;
	ans=hj[a+1][b+1]*hj[b+1][c+1]%mod*hj[a+1][c+1]%mod;
	printf("%I64d\n",ans);
	return 0;
}