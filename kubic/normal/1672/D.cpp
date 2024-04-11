#include <bits/stdc++.h>
using namespace std;
#define N 200005
#define ll long long
#define pb push_back
int T,n,a[N],b[N],nw[N];
void slv()
{
	scanf("%d",&n);a[n+1]=b[n+1]=0;
	for(int i=1;i<=n;++i) nw[i]=0;
	for(int i=1;i<=n;++i) scanf("%d",&a[i]);
	for(int i=1;i<=n;++i) scanf("%d",&b[i]);
	for(int i=n,t=n;i;--i)
	{
		while(t && a[i+1]==b[t]) ++nw[b[t--]];
		if(t && a[i]==b[t]) {--t;continue;}
		if(!nw[a[i]]) {puts("No");return;}--nw[a[i]];
	}puts("Yes");
}
int main()
{
	scanf("%d",&T);
	while(T--) slv();return 0;
}