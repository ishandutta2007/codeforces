#include <bits/stdc++.h>
using namespace std;
#define N 200005
int T,n,cnt,nw1,nw2,nw;char a[N],z1[N],z2[N];
void slv()
{
	scanf("%d %s",&n,a+1);cnt=nw1=nw2=nw=0;
	for(int i=1;i<=n;++i) if(a[i]=='1') ++cnt;
	for(int i=1;i<=n;++i)
	{
		if(a[i]=='1')
		{
			++nw;
			if(nw<=cnt/2) ++nw1,++nw2,z1[i]=z2[i]='(';
			else --nw1,--nw2,z1[i]=z2[i]=')';
		}
		else
		{
			if(nw1<nw2) ++nw1,--nw2,z1[i]='(',z2[i]=')';
			else --nw1,++nw2,z1[i]=')',z2[i]='(';
		}if(nw1<0 || nw2<0) {puts("NO");return;}
	}if(nw1 || nw2) {puts("NO");return;}puts("YES");
	for(int i=1;i<=n;++i) putchar(z1[i]);puts("");
	for(int i=1;i<=n;++i) putchar(z2[i]);puts("");
}
int main()
{
	scanf("%d",&T);while(T--) slv();
	return 0;
}