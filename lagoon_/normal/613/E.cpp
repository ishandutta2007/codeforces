#include<bits/stdc++.h>
#define re register
const int mod=1e9+7;
char ss[2][2010],s1[2010];
int hsa[3][2010],hsb[3][2010],ex[2010],f[2][2010],n,k,md;
bool che(re int no,re int l1,re int l2,re int len,re bool lr)
{
	re int x1,y1;
	y1=(hsa[2][l2+len-1]-1ll*hsa[2][l2-1]*ex[len]%md+md)%md;
	if(!lr)
	{
		x1=(hsa[no][l1+len-1]-1ll*hsa[no][l1-1]*ex[len]%md+md)%md;
	}
	else
	{
		x1=(hsb[no][l1-len+1]-1ll*hsb[no][l1+1]*ex[len]%md+md)%md;
	}//printf("***%d %d %d\n",x1,y1,l1);
	return x1==y1;
}
int main()
{
	srand(time(0));
	scanf("%s%s%s",ss[0]+1,ss[1]+1,s1+1);
	n=strlen(ss[0]+1);k=strlen(s1+1);
	re int ans=0;
	md=rand()%(int)1e9+1e9;
	for(re bool bo=1;bo;md++)
	{
		bo=0;
		for(re long long i=2;i*i<=md;i++)if(!(md%i)){bo=1;break;}
	}md--;
	ex[0]=1;
	for(re int i=1;i<=std::max(n,k);i++)
	{
		hsa[0][i]=(hsa[0][i-1]*29ll+ss[0][i]-'a')%md;
		hsa[1][i]=(hsa[1][i-1]*29ll+ss[1][i]-'a')%md;
		hsa[2][i]=(hsa[2][i-1]*29ll+s1[i]-'a')%md;
		ex[i]=ex[i-1]*29ll%md;
	}
	for(re int i=n;i;i--)
	{
		hsb[0][i]=(hsb[0][i+1]*29ll+ss[0][i]-'a')%md;
		hsb[1][i]=(hsb[1][i+1]*29ll+ss[1][i]-'a')%md;
		hsb[2][i]=(hsb[2][i+1]*29ll+s1[i]-'a')%md;
	}
	f[0][0]=f[1][0]=1;
	
	/*if(!(k&1))
	{
		re int x1=k/2;
		if(x1>1&&x1<=n)
		{
			if(che(0,1,1,x1,0)&&che(1,x1,x1+1,x1,1))ans++;
			if(che(1,1,1,x1,0)&&che(0,x1,x1+1,x1,1))ans++;
			if(che(0,n,1,x1,1)&&che(1,n-x1+1,x1+1,x1,0))ans++;
			if(che(1,n,1,x1,1)&&che(0,n-x1+1,x1+1,x1,0))ans++;//printf("***%d\n",ans);
		}
	}*/
	for(re int i=1;i<=n;i++)
	{
		for(re int j=k;j;j--)
		{
			if(ss[0][i]==s1[j])f[0][j]=f[0][j-1];else f[0][j]=0;
			if(ss[1][i]==s1[j])f[1][j]=f[1][j-1];else f[1][j]=0;
			if(j<k)
			{
				if(ss[0][i]==s1[j+1])f[0][j+1]=(f[0][j+1]+f[1][j])%mod;
				if(ss[1][i]==s1[j+1])f[1][j+1]=(f[1][j+1]+f[0][j])%mod;
			}
		}
		for(re int j=2;j<=i&&2*j<=k;j++)
		{//printf("*l*%d\n",j);
			if(che(0,i,1,j,1)&&che(1,i-j+1,j+1,j,0))f[1][2*j]=(f[1][2*j]+1)%mod;
			if(che(1,i,1,j,1)&&che(0,i-j+1,j+1,j,0))f[0][2*j]=(f[0][2*j]+1)%mod;
		}
		for(re int j=1+(!(k&1));j<=k;j+=2)
		{
			re int x1=(k-j)/2;
			if(x1<=1||i+x1>n)continue;
			if(che(0,i+1,j+1,x1,0)&&che(1,i+x1,j+x1+1,x1,1))ans=(ans+f[0][j])%mod;
			if(che(1,i+1,j+1,x1,0)&&che(0,i+x1,j+x1+1,x1,1))ans=(ans+f[1][j])%mod;
		}
		ans=(1ll*ans+f[0][k]+f[1][k])%mod;
		//printf("**%d %d %d %d %d %d %d %d\n",f[0][1],f[0][2],f[0][3],f[0][4],f[1][1],f[1][2],f[1][3],f[1][4]);
	}//printf("***%d\n",ans);
	memset(f,0,sizeof(f));
	f[0][0]=f[1][0]=1;
	for(re int i=n;i;i--)
	{
		for(re int j=k;j;j--)
		{
			if(ss[0][i]==s1[j])f[0][j]=f[0][j-1];else f[0][j]=0;
			if(ss[1][i]==s1[j])f[1][j]=f[1][j-1];else f[1][j]=0;
			if(j<k)
			{
				if(ss[0][i]==s1[j+1])f[0][j+1]=(f[0][j+1]+f[1][j])%mod;
				if(ss[1][i]==s1[j+1])f[1][j+1]=(f[1][j+1]+f[0][j])%mod;
			}
		}
		for(re int j=2;j<=n-i+1&&2*j<=k;j++)
		{
			if(che(0,i,1,j,0)&&che(1,i+j-1,j+1,j,1))f[1][2*j]=(f[1][2*j]+1)%mod;
			if(che(1,i,1,j,0)&&che(0,i+j-1,j+1,j,1))f[0][2*j]=(f[0][2*j]+1)%mod;
		}
		for(re int j=1+(!(k&1));j<=k;j+=2)
		{
			re int x1=(k-j)/2;
			if(x1<=1||i<=x1)continue;
			if(che(0,i-1,j+1,x1,1)&&che(1,i-x1,j+x1+1,x1,0))ans=(ans+f[0][j])%mod;
			if(che(1,i-1,j+1,x1,1)&&che(0,i-x1,j+x1+1,x1,0))ans=(ans+f[1][j])%mod;
		}
		ans=(1ll*ans+f[0][k]+f[1][k])%mod;//printf("**%d %d\n",i,ans);
		if(k==1)ans=(ans-(ss[0][i]==s1[1])-(ss[1][i]==s1[1])+mod)%mod;
		else if(k==2)ans=(ans-(ss[0][i]==s1[1]&&ss[1][i]==s1[2])-(ss[0][i]==s1[2]&&ss[1][i]==s1[1])+mod)%mod;
	}
	printf("%d\n",ans);
}