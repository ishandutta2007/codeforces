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
int n,a[1000005];struct node{int a,b;}f[2100005];
inline node operator+(node a,node b) {return a.a>b.a?(node){a.a,max(b.a,a.b)}:(node){b.a,max(b.b,a.a)};}
inline void solve()
{
	for(int k=1;k<(1<<21);k<<=1) for(int i=0;i<(1<<21);i+=(k<<1))
		for(int j=0;j<k;j++) f[i|j]=f[i|j]+f[i|j|k];
}
inline char chk(int x) {for(int i=1;i<=n;i++) if(f[x-(x&a[i])].b>i) return 1;return 0;}
int main()
{
	read(n);int res=0;for(int i=1;i<=n;i++)
		{read(a[i]);if(i>f[a[i]].a) f[a[i]].b=f[a[i]].a,f[a[i]].a=i;else f[a[i]].b=max(f[a[i]].b,i);}
//	for(int i=0;i<8;i++) printf("%d , %d\n",f[i].a,f[i].b);
	solve();for(int i=20;~i;i--) if(chk(res|(1<<i))) res|=1<<i;
	return printf("%d\n",res),0;
}