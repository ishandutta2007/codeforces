#include <bits/stdc++.h>
using namespace std;
#define N 100005
#define ll long long
int T,n,m,p[4],ans[4],cnt[N],s[N],st[4][N];ll mx;char a[N];
void slv1()
{
	ll res=0;for(int i=1;i<=n;++i) cnt[i]=0;
	for(int i=0;i<4;++i)
	{
		for(int j=n;j;--j) s[j]=s[j+1]+cnt[j];
		for(int j=1;j<=st[p[i]][0];++j)
			res+=s[st[p[i]][j]],++cnt[st[p[i]][j]]; 
	}if(res>mx) {mx=res;for(int i=0;i<4;++i) ans[i]=p[i];}
}
void slv()
{
	scanf("%s",a+1);n=strlen(a+1);mx=-1;
	for(int i=0;i<4;++i) st[i][0]=0,p[i]=i;
	for(int i=1,t;i<=n;++i)
	{
		if(a[i]=='A') t=0;if(a[i]=='N') t=1;
		if(a[i]=='T') t=2;if(a[i]=='O') t=3;
		st[t][++st[t][0]]=i;
	}while(1) {slv1();if(!next_permutation(p,p+4)) break;}
	for(int i=0;i<4;++i) for(int j=1;j<=st[ans[i]][0];++j)
		putchar(a[st[ans[i]][1]]);puts("");
}
int main() {scanf("%d",&T);while(T--) slv();return 0;}