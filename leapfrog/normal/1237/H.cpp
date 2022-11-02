//{{{
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<48||c>57;c=getchar()) if(!(c^45)) f=1;
	for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	f?x=-x:x;
}
template<typename T,typename...L>inline void read(T &x,L&...l) {read(x),read(l...);}//}}}
int n,tn[4005],tt,a[4005],b[4005];char s[4005],t[4005];vector<int>rs;
inline void rev(int r)
{
	for(int i=1;i<=r;i++) if(a[i]==1||a[i]==2) a[i]^=3;
	reverse(a+1,a+r+1),rs.push_back(r<<1);
}
inline void solve()
{
	rs.clear(),scanf("%s%s",s+1,t+1),tn[0]=tn[1]=tn[2]=0,n=strlen(s+1);
	for(int i=1;i<=n;i+=2) a[(i+1)>>1]=(s[i]^48)<<1|(s[i+1]^48);
	for(int i=1;i<=n;i+=2) b[(i+1)>>1]=(t[i]^48)<<1|(t[i+1]^48);
	for(int i=1;i<=n/2;i++) tn[(a[i]>>1)+(a[i]&1)]++,tn[(b[i]>>1)+(b[i]&1)]--;
	if(tn[0]||tn[1]||tn[2]) return puts("-1"),void();
	for(int i=n/2;i>=1;i--)
	{
		if(a[i]==b[i]) continue;
		if(a[1]==b[i]&&(!a[1]||a[1]==3)) {rev(i);continue;}
		if((a[1]^b[i])==3&&a[1]&&a[1]!=3) {rev(i);continue;}
		int wh=0;for(int j=i;j>=1;j--) if(a[j]==b[i]) {wh=j;break;}
		if(wh) {rev(wh),rev(i);continue;}
		tt=0;for(int j=i;j>=1;j--) if((a[j]^b[i])==3) tn[++tt]=j;
		wh=tn[rand()%tt+1],rev(wh),rev(1),rev(i);
	}printf("%d\n",(int)rs.size());
	for(auto x:rs) printf("%d ",x);
	putchar('\n');
}
int main() {int Ca;for(srand(19260817),read(Ca);Ca--;) solve();return 0;}