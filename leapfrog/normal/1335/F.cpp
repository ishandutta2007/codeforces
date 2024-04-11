#include<bits/stdc++.h>
using namespace std;
int q,n,m,r,r1,r2,to[1000005][25],hav[1000005][2];char c[1000005],s[1000005],t[1000005];
int main()
{
	for(scanf("%d",&q);q--;)
	{
		scanf("%d%d",&n,&m),r1=r2=0,r=n*m;
		for(int i=1;i<=r;i++) hav[i][0]=hav[i][1]=0;
		for(int i=1,cnt=0;i<=n;i++) {scanf("%s",t+1);for(int j=1;j<=m;j++) c[++cnt]=t[j];}
		for(int i=1,cnt=0;i<=n;i++) {scanf("%s",t+1);for(int j=1;j<=m;j++) s[++cnt]=t[j];}
		for(int i=1;i<=r;i++)
			if(s[i]=='U') to[i][0]=i-m;
			else if(s[i]=='D') to[i][0]=i+m;
			else if(s[i]=='L') to[i][0]=i-1;
			else to[i][0]=i+1;
		for(int i=1;i<=20;i++) for(int j=1;j<=r;j++) to[j][i]=to[to[j][i-1]][i-1];
		for(int i=1,p=i;i<=r;i++,p=i)
		{
			for(int j=20;j>=0;j--) if((r>>j)&1) p=to[p][j];
			hav[p][c[i]-'0']=1;
		}
		for(int i=1;i<=r;i++) if(hav[i][0]) r1++,r2++;else if(hav[i][1]) r1++;
		printf("%d %d\n",r1,r2);
	}
	return 0;
}