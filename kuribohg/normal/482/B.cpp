#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN=100010;
int n,m,L[MAXN],R[MAXN],W[MAXN],d[MAXN],a[MAXN],s[MAXN],ans[MAXN];
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++) scanf("%d%d%d",&L[i],&R[i],&W[i]);
	for(int Bit=0;Bit<30;Bit++)
	{
		for(int i=1;i<=n+1;i++) d[i]=0;
		for(int i=1;i<=m;i++)
			if(W[i]&(1<<Bit))
				d[L[i]]++,d[R[i]+1]--;
		for(int i=1;i<=n;i++) a[i]=a[i-1]+d[i];
		for(int i=1;i<=n;i++) if(a[i]) a[i]=1;
		for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
		for(int i=1;i<=m;i++)
		{
			if(W[i]&(1<<Bit)) continue;
			if(s[R[i]]-s[L[i]-1]==R[i]-L[i]+1) {puts("NO");return 0;}
		}
		for(int i=1;i<=n;i++) if(a[i]) ans[i]|=(1<<Bit);
	}
	puts("YES");
	for(int i=1;i<=n;i++) printf("%d ",ans[i]);
	puts("");
	return 0;
}