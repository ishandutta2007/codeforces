#include<bits/stdc++.h>
using namespace std;
const int N=705,mod=1e9+7;
char s[N];
int n,ans,memo[N][N][3][3];
void f(int l,int r)
{
	int tmp=1,i,j1,j2,k1,k2;
	if(l+1==r)
	{
		for(j1=0;j1<3;j1++)
			for(j2=0;j2<3;j2++)
				if((j1==2&&j2<=1)||(j1<=1&&j2==2))
					memo[l][r][j1][j2]=1;
		return;
	}
	for(i=l+1;i<r;i++)
		if((tmp+=(s[i]=='('?1:-1))==0)
		{
			f(l,i);f(i+1,r);
			for(j1=0;j1<3;j1++)
				for(j2=0;j2<3;j2++)
					for(k1=0;k1<3;k1++)
						for(k2=0;k2<3;k2++)
							if(!((j2==0&&k1==0)||(j2==1&&k1==1)))
								(memo[l][r][j1][k2]+=(long long)memo[l][i][j1][j2]*memo[i+1][r][k1][k2]%mod)%=mod;
			return;
		}
	f(l+1,r-1);
	for(j1=0;j1<3;j1++)
		for(j2=0;j2<3;j2++)
			for(k1=0;k1<3;k1++)
				for(k2=0;k2<3;k2++)
					if(((j1==2&&j2<=1)||(j1<=1&&j2==2))&&!((j1==0&&k1==0)||(j1==1&&k1==1))&&!((j2==0&&k2==0)||(j2==1&&k2==1)))
						(memo[l][r][j1][j2]+=memo[l+1][r-1][k1][k2])%=mod;
}
signed main()
{
	register int i,j;
	scanf("%s",s+1);
	n=strlen(s+1);
	f(1,n);
	for(i=0;i<=2;i++)
		for(j=0;j<=2;j++)
			(ans+=memo[1][n][i][j])%=mod;
	printf("%d\n",ans);
	return 0;
}