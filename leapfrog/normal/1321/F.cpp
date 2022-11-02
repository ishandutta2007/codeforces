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
const int N=200005,P=1019260817;int n,Q,s[N];char ch[N];
struct Hash/*{{{*/
{
	int a;inline int pls(int x,int y) {return (x+=y)>=P?x-P:x;}
	inline Hash operator+(int x) {return(Hash){pls(a,x)};}
	inline Hash operator-(int x) {return(Hash){pls(a,x?P-x:0)};}
	inline Hash operator*(int x) {return(Hash){int(1ll*a*x%P)};}
	inline Hash operator+(Hash x) {return(Hash){pls(a,x.a)};}
	inline Hash operator-(Hash x) {return(Hash){pls(a,x.a?P-x.a:0)};}
	inline Hash operator*(Hash x) {return(Hash){int(1ll*a*x.a%P)};}
	inline char operator==(Hash x) {return a==x.a;}
	inline char operator!=(Hash x) {return a!=x.a;}
}bs,bp[N],hs[2][N];/*}}}*/
inline Hash get(Hash *h,int l,int r) {return h[r]-h[l-1]*bp[s[r]-s[l-1]];}
int main()
{
	read(n),scanf("%s",ch+1),read(Q);for(int i=1;i<=n;i++) s[i]=s[i-1]+!(ch[i]&1);
	bs.a=114,bp[0].a=1;for(int i=1;i<=n;i++) bp[i]=bp[i-1]*bs;
	for(int i=1;i<=n;i++) if(ch[i]&1) hs[0][i]=hs[0][i-1],hs[1][i]=hs[1][i-1];
	else hs[0][i]=hs[0][i-1]*bs+1+(i&1),hs[1][i]=hs[1][i-1]*bs+1+!(i&1);
	//for(int i=1;i<=n;i++) printf("%d %d\n",hs[0][i].a,hs[1][i].a);
	for(int a,b,x;Q--;) read(a,b,x),puts(get(hs[a&1],a,a+x-1)==get(hs[b&1],b,b+x-1)?"Yes":"No");
	return 0;
}