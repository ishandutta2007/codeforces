#include <bits/stdc++.h>
using namespace std;
#define N 200005
int T,n,m,x,lim,ans,cnt[N][26];char a[N];
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		ans=0;scanf("%d %d %s",&n,&m,a);x=n/m;lim=m&1?m>>1:(m>>1)-1;
		for(int i=0;i<n;++i) for(int j=0;j<26;++j) cnt[i][j]=0;
		for(int i=0;i<n;++i) ++cnt[i%m][a[i]-'a'];
		for(int i=0,t;i<=lim;++i) if((i<<1|1)==m)
		{
			t=x-cnt[i][0];
			for(int j=1;j<26;++j) t=min(t,x-cnt[i][j]);
			ans+=t; 
		}
		else
		{
			t=(x<<1)-cnt[i][0]-cnt[m-1-i][0];
			for(int j=1;j<26;++j) t=min(t,(x<<1)-cnt[i][j]-cnt[m-1-i][j]);
			ans+=t;
		}printf("%d\n",ans);
	}return 0;}