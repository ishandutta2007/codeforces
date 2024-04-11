//{{{
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	if(f) x=-x;
}/*}}}*/
int n,mx,p[1005],mn[1005],d[2000005][2],a[1005][1005];
inline int count(int x) {int cnt=0;while(x) cnt++,x/=10;return cnt;}
inline char chk()
{
	for(int i=0;i<(1<<mx);i++)
	{
		int cnp=0,cne=0;for(int j=1;j<=mx;j++) if((i>>(j-1))&1) cnp+=p[j];
		if(!cnp) continue;else for(int j=1;j<=mx;j++) if((i>>(j-1))&1)
			for(int k=1;k<=mx;k++) if((i>>(k-1))&1) cne+=a[j][k];
		if(cne>=cnp) return 0;
	}
	return 1;
}
inline char solve()
{
	for(int i=1;i<=mx;i++) for(int j=1;j<=mx;j++) if(a[i][j])
	{
		if(p[i]>1) {a[i][j]--,p[i]--;if(chk()) return printf("%d %d\n",mn[i]+p[i],mn[j]),1;else a[i][j]++,p[i]++;}
		if(p[j]>1) {a[i][j]--,p[j]--;if(chk()) return printf("%d %d\n",mn[i],mn[j]+p[j]),1;else a[i][j]++,p[j]++;}
	}
	return 0;
}
int main()
{
	read(n),mx=count(n);for(int i=1;i<=n;i++) p[count(i)]++;
	char s[105],t[105];mn[1]=1;for(int i=2;i<=mx;i++) mn[i]=mn[i-1]*10;
	for(int i=1;i<n;i++) scanf("%s%s",s,t),d[i][0]=strlen(s),d[i][1]=strlen(t),a[d[i][0]][d[i][1]]++;
	if(!chk()) return puts("-1"),0;else while(solve());
	for(int i=1;i<=mx;i++) for(int j=1;j<=mx;j++) if(a[i][j]) printf("%d %d\n",mn[i]+p[i]-1,mn[j]+p[j]-1);
	return 0;
}