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
int n;char s[1000005],t[1000005];
int main()
{
	read(n),scanf("%s%s",s+1,t+1);if(n==1) return putchar(t[1]),putchar('\n'),0;
	if(s[1]!=t[1]) {for(int i=1;i<=n;i++) putchar('1');return putchar('\n'),0;}
	if(t[n]=='1') return printf("%s\n",t+1),0;else s[n-1]++;
	for(int i=n-1;i>=1;i--) if(s[i]>'1') s[i-1]++,s[i]='0';
	char fg=1;for(int i=0;i<=n;i++) if(s[i]^t[i]) {fg=s[i]<t[i];break;}
	return t[n]=fg+'0',printf("%s\n",t+1),0;
}