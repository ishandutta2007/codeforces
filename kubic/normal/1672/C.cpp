#include <bits/stdc++.h>
using namespace std;
#define N 200005
#define ll long long
#define pb push_back
int T,n,ans,cnt,a[N],b[N];
void slv()
{
	scanf("%d",&n);cnt=ans=b[n]=0;
	for(int i=1;i<=n;++i) scanf("%d",&a[i]);
	for(int i=1;i<n;++i) b[i]=a[i]==a[i+1],cnt+=b[i];
	for(int i=1;i<n;++i) if(b[i-1])
	{
		if(cnt<2) break;
		++ans;cnt-=b[i+1]+1;cnt+=!b[i];
		b[i-1]=0;b[i]=1;b[i+1]=0;
	}printf("%d\n",ans);
}
int main()
{
	scanf("%d",&T);
	while(T--) slv();return 0;
}