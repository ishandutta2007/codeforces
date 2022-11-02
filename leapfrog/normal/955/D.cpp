//{{{
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<48||c>57;c=getchar()) if(!(c^45)) f=1;
	for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	f?x=-x:x;
}/*}}}*/
const int P=1019260817;int tag;int n,m,K;
struct Hs
{
	int a;inline int pls(int x,int y) {return (x+=y)>=P?x-P:x;}
	inline char operator==(Hs x) {return a==x.a;}
	inline char operator!=(Hs x) {return a!=x.a;}
	inline Hs operator+(int x) {return(Hs){pls(a,x)};}
	inline Hs operator+(Hs x) {return(Hs){pls(a,x.a)};}
	inline Hs operator-(Hs x) {return(Hs){pls(a,x.a?P-x.a:0)};}
	inline Hs operator*(int x) {return(Hs){(int)(1ll*a*x%P)};}
	inline Hs operator*(Hs x) {return(Hs){(int)(1ll*a*x.a%P)};}
}pw[500005],bs=(Hs){114514};
struct Hash
{
	Hs h[500005];
	inline void init(int n,char *ch) {for(int i=1;i<=n;i++) h[i]=h[i-1]*bs+ch[i];}
	inline Hs get(int l,int r) {return h[r]-h[l-1]*pw[r-l+1];}
}S,T;char s[500005],t[500005];int L[500005],R[500005];
int main()
{
	pw[0]=(Hs){1};for(int i=1;i<=500000;i++) pw[i]=pw[i-1]*bs;
	read(n),read(m),read(K),scanf("%s%s",s+1,t+1),S.init(n,s),T.init(m,t);
	for(int i=1,r=K;i<=K&&i<=m;L[i]=r,i++)
	{
		Hs gg=T.get(1,i);while(r<=n&&S.get(r-i+1,r)!=gg) r++;
		if(S.get(K-i+1,K)==gg) r=K;
	}
	for(int i=1,r=n-K+1;i<=K&&i<=m;R[i]=r,i++)
	{
		//if(n==500000&&m==400000&&K==200000) printf("%d,",r);
		Hs gg=T.get(m-i+1,m);while(r&&S.get(r,r+i-1)!=gg) r--;
		//if(n==500000&&m==400000&&K==200000) printf("%d\n",r);
		if(S.get(n-K+1,n-K+i)==gg) r=n-K+1;
	}
	if(m<=K) for(int i=1;i+m-1<=n;i++) if(S.get(i,i+m-1)==T.get(1,m))
	{
		if(i<=K&&i+m-1>=n-K+1) continue;else puts("Yes");
		//if(n==500000&&m==11550&&K==9611) puts("nmsl");
		return printf("%d %d\n",min(max(1,i-K+1),n-K+1-K),max(K+1,min(n-K+1,i))),0;
	}
	//for(int i=1;i<=K&&i<=m;i++) printf("%d%c",L[i],i==min(K,m)?'\n':' ');
	//for(int i=1;i<=K&&i<=m;i++) printf("%d%c",R[i],i==min(K,m)?'\n':' ');
	for(int i=1;i<m&&i<=K;i++) if(L[i]<=n&&R[m-i]>=1)
		if(L[i]<R[m-i]) return printf("Yes\n%d %d\n",L[i]-K+1,R[m-i]),0;
	return puts("No"),0;
}