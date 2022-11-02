//
#include<bits/stdc++.h>
using namespace std;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<'0'||c>'9';c=getchar()) if(!(c^45)) f=1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	if(f) x=-x;
}
int T,n,c1,c2,s1,s2;
int main()
{
	read(n);char ch;c1=c2=s1=s2=0;
	for(int i=1;(i<<1)<=n;i++) {ch=getchar();if(ch=='?') c1++;else s1+=ch^48;}
	for(int i=1;(i<<1)<=n;i++) {ch=getchar();if(ch=='?') c2++;else s2+=ch^48;}
	if(c1==c2) return puts(s1==s2?"Bicarp":"Monocarp"),0;
	if(c1<c2) swap(c1,c2),swap(s1,s2);
	if((c1-c2)&1) return puts("Monocarp"),0;
	int tmp=((c1-c2)>>1)*9+s1;
	if(tmp!=s2) return puts("Monocarp"),0;
	return puts("Bicarp"),0;
}