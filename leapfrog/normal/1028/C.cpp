//Coded by Kamiyama_Shiki on 2021.11.16 {{{
//
#include<bits/stdc++.h>
#define debug(...) fprintf(stderr,__VA_ARGS__)
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<48||c>57;c=getchar()) if(!(c^45)) f=1;
	for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	f?x=-x:x;
}
template<typename T,typename...L>inline void read(T &x,L&...l) {read(x),read(l...);}//}}}
const int N=132675;
struct node
{
	int lx,rx,ly,ry;
	node operator+(node b) {return(node){max(lx,b.lx),min(rx,b.rx),max(ly,b.ly),min(ry,b.ry)};}
	inline void chk() {if(lx<=rx&&ly<=ry) printf("%d %d\n",lx,ly),exit(0);}
}a[N],qz[N],hz[N];int n;
int main()
{
	read(n);for(int i=1;i<=n;i++) read(a[i].lx,a[i].ly,a[i].rx,a[i].ry);
	qz[1]=a[1];for(int i=2;i<=n;i++) qz[i]=qz[i-1]+a[i];
	hz[n]=a[n];for(int i=n-1;i;i--) hz[i]=hz[i+1]+a[i];
	qz[n-1].chk(),hz[2].chk();for(int i=2;i<n;i++) (qz[i-1]+hz[i+1]).chk();
	return 0;
}