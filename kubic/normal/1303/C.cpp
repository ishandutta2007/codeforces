#include <bits/stdc++.h>
using namespace std;
#define N 205
#define M 105
#define set(a,v) memset(a,v,sizeof(a))
int T,n,ans[M];bool vs[M];char a[N];
void slv()
{
	int u=50;set(vs,0);set(ans,0);
	for(int i=1,t;i<=n;++i)
	{
		t=a[i]-'a'+1;
		if(vs[t])
		{
			if(ans[u+1]==t) ++u;
			else if(ans[u-1]==t) --u;
			else {puts("NO");return;}
		}
		else
		{
			if(!ans[u+1]) ans[++u]=t;
			else if(!ans[u-1]) ans[--u]=t;
			else {puts("NO");return;}vs[t]=1;
		}
	}puts("YES");
	for(int i=0;i<=100;++i) if(ans[i]) putchar(ans[i]+'a'-1);
	for(int i=1;i<=26;++i) if(!vs[i]) putchar(i+'a'-1);puts("");
} 
int main()
{
	scanf("%d",&T);
	while(T--) scanf("%s",a+1),n=strlen(a+1),slv();return 0;
}