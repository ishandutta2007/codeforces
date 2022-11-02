//
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<48||c>57;c=getchar()) if(!(c^45)) f=1;
	for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	f?x=-x:0;
}
int n,K,a[200005],T[400010],s[200005];
inline void upd(int x) {x+=200002;for(;x<=400005;x+=x&(-x)) T[x]|=1;}
inline int qry(int x) {x+=200002;for(;x>0;x-=x&(-x)) if(T[x]) return 1;return 0;}
inline char chk(int x)
{
	memset(T,0,sizeof(T));for(int i=1;i<=n;i++) s[i]=s[i-1]+(a[i]<x?-1:1);
	for(int i=K;i<=n;i++) {upd(s[i-K]);if(qry(s[i]-1)) return 1;}
	return 0;
}
int main()
{
	read(n),read(K);for(int i=1;i<=n;i++) read(a[i]);
	int le=1,ri=n,rs=0;while(le<=ri) {int md=(le+ri)>>1;if(chk(md)) rs=md,le=md+1;else ri=md-1;}
	return printf("%d\n",rs),0;
}