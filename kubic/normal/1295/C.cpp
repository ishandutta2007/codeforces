#include <bits/stdc++.h>
using namespace std;
#define N 100005
int T,n,m,ans,nxt[N<<1][26];bool fl;char a[N<<1],b[N];
int main()
{
	scanf("%d",&T); 
	while(T--)
	{
		fl=0;ans=1;
		scanf("%s %s",a+1,b+1);n=strlen(a+1);m=strlen(b+1);
		for(int i=1;i<=n;++i) a[i+n]=a[i];
		for(int i=(n<<1)-1;i>=0;--i)
		{
			for(int j=0;j<26;++j)
				if(a[i+1]==j+'a') nxt[i][j]=i%n+1;
				else nxt[i][j]=nxt[i+1][j];
		}
		for(int i=1,t=0;i<=m;++i)
		{
			if(t>=nxt[t][b[i]-'a']) ++ans;
			t=nxt[t][b[i]-'a'];if(!t) {fl=1;puts("-1");break;} 
		}if(!fl) printf("%d\n",ans);
		for(int i=(n<<1)-1;i>=0;--i) for(int j=0;j<26;++j)
			nxt[i][j]=0;
	}
}