//Coded by leapfrog on 2021.11.05 {{{
//
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
const int N=100005,P=1019260817;char s[N],t[N*10];int n,m;
struct Hash
{
	int has;inline int pls(int x,int y) {return (x+=y)>=P?x-=P:x;}
	inline int mns(int x,int y) {return y?pls(x,P-y):x;}
	inline bool operator<(const Hash &b) {return has<b.has;}
	inline bool operator==(const Hash &b) {return has==b.has;}
	inline bool operator!=(const Hash &b) {return has!=b.has;}
	inline Hash operator+(const Hash &b) {return(Hash){pls(has,b.has)};}
	inline Hash operator-(const Hash &b) {return(Hash){mns(has,b.has)};}
	inline Hash operator*(const Hash &b) {return(Hash){int(1ll*has*b.has%P)};}
	inline Hash operator+(const int &x) {return(Hash){pls(has,x)};}
	inline Hash operator*(const int &x) {return(Hash){int(1ll*has*x%P)};}
}B=(Hash){137},pw[N*10],hs[N*10];
inline Hash geths(int l,int r) {return hs[r]-hs[l-1]*pw[r-l+1];}
int main()
{
	scanf("%s%s",s+1,t+1),n=strlen(s+1),m=strlen(t+1);
	int rs=0;for(int i=n;i>=1;i--) s[i]^=s[1];
	pw[0]=(Hash){1};for(int i=1;i<=m;i++) pw[i]=pw[i-1]*B,hs[i]=hs[i-1]*B+t[i];
	int c0=0,c1=0;for(int i=1;i<=n;i++) c0+=!s[i],c1+=s[i];
	for(int l0=1;l0<m;l0++)
	{
		if(m-c0*l0<0) break;else if((m-c0*l0)%c1) continue;
		int l1=(m-c0*l0)/c1,L0=-1,R0,L1=-1,R1;char fg=0;if(l1==0) continue;
		for(int i=1,nw=1;i<=n&&!fg;i++)
		{
			if(s[i]) if(L1==-1) L1=nw,R1=(nw+=l1)-1;else fg|=geths(L1,R1)!=geths(nw,nw+l1-1),nw+=l1;
			else if(L0==-1) L0=nw,R0=(nw+=l0)-1;else fg|=geths(L0,R0)!=geths(nw,nw+l0-1),nw+=l0;
		}rs+=!fg&&(geths(L0,R0)!=geths(L1,R1));
	}return printf("%d\n",rs),0;
}