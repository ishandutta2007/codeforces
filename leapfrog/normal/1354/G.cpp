//
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
/*template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<48||c>59;c=getchar()) if(!(c^45)) f=1;
	for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	f?x=-x:0;
}*/
mt19937 rnd(1919810);int T,n,K,zr;
inline char qry(int la,int ra,int lb,int rb)
{
	cout<<"? "<<ra-la+1<<" "<<rb-lb+1<<endl;
	for(int i=la;i<=ra;i++) cout<<i<<(i==ra?'\n':' ');
	for(int i=lb;i<=rb;i++) cout<<i<<(i==rb?'\n':' ');
	fflush(stdout);char c[15];return scanf("%s",c),*c;
}
inline char blck1() {for(int i=2;i<=n;i++) if(qry(1,1,i,i)=='S') return 1;return 0;}
inline char rdck1()
{
	for(int i=1,x=rnd()%(n-1)+2;i<=30;i++,x=rnd()%(n-1)+2) if(qry(1,1,x,x)=='S') return 1;
	return 0;
}
inline void work(int l,int r)
{
	int md=(l+r)>>1;if(l==r) return printf("! %d\n",l),void();
	if(qry(1,md-l+1,l,md)=='E') return work(md+1,r);else return work(l,md);
}
inline void solve()
{
	cin>>n>>K;if((n<=30&&blck1())||(n>30&&rdck1())) return puts("! 1"),void();
	for(int i=1;i<=n;i<<=1) if(qry(1,min(i,n-i),i+1,min(i<<1,n))!='E') return work(i+1,min(i<<1,n));
}
int main() {for(cin>>T;T--;) solve();return 0;}