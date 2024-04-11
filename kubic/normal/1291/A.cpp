#include <bits/stdc++.h>
using namespace std;
#define N 3005
int T,n,cnt;char a[N];
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		cnt=0;scanf("%d %s",&n,a+1);
		for(int i=1;i<=n;++i) if((a[i]&15)&1) ++cnt;
		if(cnt<2) {puts("-1");continue;}cnt=2;
		for(int i=1;i<=n && cnt;++i) if((a[i]&15)&1) putchar(a[i]),--cnt;
		puts("");
	}return 0;
}