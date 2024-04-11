//{{{
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),bz=0;
	for(;c<48||c>57;c=getchar()) if(!(c^45)) bz=1;
	for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	bz?x=-x:x;
}/*}}}*/
struct ${int v,id;char operator<($ b) const {return v^b.v?v>b.v:id<b.id;}}a[514];
set<$>s;int n,K;typedef set<$>::iterator IT;
inline IT add(IT x,int k) {$ r=*x;return s.erase(x),r.v+=k,s.insert(r).first;}
int main()
{
	read(n),read(K);if((n&1)&&!(K&1)) return puts("-1"),0;
	int sc=n;for(int i=1;i<=n;i++) s.insert(($){1,i});
	while(sc%K||s.begin()->v>sc/K) sc+=2,add(--s.end(),2);//sc%K==0,mxc<=sc/K
	//for(auto x:s) printf("<%d,%d>",x.id,x.v);putchar('\n');
	int rs=0;for(int i=1;i<=sc/K;i++)
	{
		putchar('?');int vl,k=K,tt=0;
		for(IT i=s.begin();i!=s.end()&&k;i++,k--) printf(" %d",i->id);
		k=K;for(IT i=s.begin(),j;i!=s.end()&&k;k--) a[++tt]=*i,j=i,++i,s.erase(j);
		for(IT i=s.begin();i!=s.end()&&tt;tt--) a[tt].v--,s.insert(a[tt]);
		putchar('\n'),fflush(stdout),read(vl),rs^=vl;
	}
	return printf("! %d\n",rs),0;
}