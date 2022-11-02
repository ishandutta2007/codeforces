//
//
#include<bits/stdc++.h>
using namespace std;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	if(f) x=-x;
}
int n,qwq[25],cnt[15];
inline void add(int x,int qwq)
{
	if(x==1) return;
	if(x==2||x==3||x==5||x==7) return(void)(cnt[x]+=qwq);
	if(x==4) return(void)(cnt[2]+=2*qwq);else if(x==9) return(void)(cnt[3]+=2*qwq);
	if(x==6) return(void)(cnt[2]+=qwq,cnt[3]+=qwq);else if(x==8) cnt[2]+=3*qwq;
}
inline void P() {for(int i=1;i<=9;i++) printf("%d%c",cnt[i],i==9?'\n':' ');}
int main()
{
	read(n);
	for(int i=1,x;i<=n;i++) {scanf("%1d",&x);for(int i=2;i<=x;i++) add(i,1);}
	for(int i=9;i>=1;i--) while(cnt[i]>0) {putchar(i^48);for(int j=i;j>=2;j--) add(j,-1);}
	return putchar('\n'),0;
}