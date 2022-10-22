#include <bits/stdc++.h>
using namespace std;
#define N 100005
int T,n,m,lim,cnt[3],a[N];
void slv()
{
	bool fl=0;cnt[0]=cnt[1]=cnt[2]=0;scanf("%d %d",&n,&m);lim=n+1>>1;
	for(int i=1;i<=n;++i)
		scanf("%d",&a[i]),cnt[0]+=a[i]<m,cnt[1]+=a[i]==m,cnt[2]+=a[i]>m;
	if(!cnt[1]) puts("no");
	else if(cnt[0]<lim && cnt[0]+cnt[1]>=lim) puts("yes");
	else if(cnt[0]>=lim)
	{
		for(int i=1;i<n;++i) if(a[i]>=m && a[i+1]>=m) fl=1;
		for(int i=1;i<n-1;++i) if(a[i]>=m && a[i+2]>=m) fl=1;
		puts(fl?"yes":"no");
	}else puts(cnt[0] || cnt[1]?"yes":"no");
}
int main() {scanf("%d",&T);while(T--) slv();return 0;}