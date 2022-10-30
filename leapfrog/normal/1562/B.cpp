#include<bits/stdc++.h>//{{{
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
    x=0;char c=getchar(),f=0;
    for(;c<48||c>57;c=getchar()) if(!(c^45)) f=1;
    for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
    f?x=-x:x;
}
template<typename T,typename...L>inline void read(T &x,L&...l) {read(x),read(l...);}/*}}}*/
int n;char ch[100005],fg[15];
inline void solve()
{
	read(n),scanf("%s",ch+1),fg[2]=fg[3]=fg[5]=fg[7]=fg[0]=1;
	int cn[15];memset(cn,0,sizeof(cn));
	for(int i=1;i<=n;i++) if(!fg[ch[i]-'0']) return printf("1\n%c\n",ch[i]),void();
	for(int i=1;i<=n;i++) cn[ch[i]-'0']++;
	for(int i=1;i<10;i++) if(cn[i]>1) return printf("2\n%d%d\n",i,i),void();
	for(int i=1;i<(1<<n);i++)
	{
		int vl=0;for(int j=0;j<n;j++) if((i>>j)&1) vl=vl*10+ch[j+1]-'0';
		char fg=0;for(int j=2;j<vl;j++) if(vl%j==0) {fg=1;break;}
		int cnt=0;for(int j=0;j<n;j++) cnt+=(i>>j)&1;
		if(fg) return printf("%d\n%d\n",cnt,vl),void();
	}
}
int main() {int Ca;for(read(Ca);Ca--;) solve();return 0;}