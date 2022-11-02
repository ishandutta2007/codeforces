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
const int N=100005;int n,a[N],id[N],rx[N<<1],ry[N<<1],rt,st[N],tp;char fg[N];
inline void add(int y,int x) {++rt,rx[rt]=x,ry[rt]=y;}
inline void flsh() {printf("%d\n",rt);for(int i=1;i<=rt;i++) printf("%d %d\n",rx[i],ry[i]);}
int main()
{
	read(n);for(int i=1;i<=n;i++) read(a[i]);
	int idt=0;for(int i=1;i<=n;i++) if(a[i]) id[++idt]=i;
	int up=n;for(int i=idt;i>=1;i--)
	{
		if(a[id[i]]==1) {st[++tp]=i;continue;}
		if(a[id[i]]==3) {if(i==idt) return puts("-1"),0;else continue;}
		if(!tp) return puts("-1"),0;else add(id[i],up),add(id[st[tp--]],up--);
	}while(tp) fg[st[tp]]=1,add(id[st[tp--]],up--);
	int ls=0;for(int i=idt;i>=1;i--)
	{
		if(!ls&&a[id[i]]==3) return puts("-1"),0;
		if(!ls&&(fg[i]||a[id[i]]==2)) ls=id[i];
		else if(a[id[i]]==3) add(id[i],up),add(ls,up--),ls=id[i];
	}
	return flsh(),0;
}