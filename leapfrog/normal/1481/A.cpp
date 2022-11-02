//
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	if(f) x=-x;
}
int T,n,m,K;char a[100005];
inline void solve()
{
	read(n),read(m),scanf("%s",a+1);int l=strlen(a+1);
	int cnt1=0,cnt2=0,cnt3=0,cnt4=0;
	for(int i=1;i<=l;i++) cnt1+=a[i]=='R',cnt2+=a[i]=='U',cnt3+=a[i]=='L',cnt4+=a[i]=='D';
	if(((n>=0&&cnt1>=n)||(n<=0&&cnt3>=-n))&&((cnt2>=m&&m>=0)||(m<=0&&cnt4>=-m))) puts("YES");else puts("NO");
}
int main() {for(read(T);T--;) solve();return 0;}