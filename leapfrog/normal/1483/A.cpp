//
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<48||c>57;c=getchar()) if(!(c^45)) f=1;
	for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	f?x=-x:0;
}
int T,n,m,cn[100005],a[100005][2],Cn[100005];
map<int,char>mp[100005];int fs[100005];
inline void solve()
{
	read(n),read(m);for(int i=1;i<=n;i++) cn[i]=Cn[i]=0;
	for(int i=1;i<=m;i++) mp[i].clear(),fs[i]=0;
	for(int i=1,k;i<=m;i++)
	{
		read(k);int w;
		for(int j=1;j<=k;j++)
		{
			read(w),(j==1?a[i][0]=w:0),(j==2?a[i][1]=w:0);
			mp[i][w]=1,Cn[w]++;if(k==1) cn[w]++,fs[i]=w;
		}
	}
	char tag=0;int mx=0,wh;
	for(int i=1;i<=n;i++) if(cn[i]>((m+1)>>1)) tag=1;
	if(tag) return puts("NO"),void();else puts("YES");
	for(int i=1;i<=n;i++) if(Cn[i]>mx) mx=Cn[i],wh=i;
	int tim=cn[wh];for(int i=1;i<=m;i++) if(fs[i]^wh) fs[i]=0;
	for(int i=1;i<=m;i++)
	{
		if(fs[i]) printf("%d ",wh);
		else if(mp[i][wh]&&tim<(m>>1)+(m&1)) printf("%d ",wh),tim++;
		else printf("%d ",a[i][0]^wh?a[i][0]:a[i][1]);
	}
	putchar('\n');
}
int main() {for(read(T);T--;) solve();return 0;}