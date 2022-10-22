#include<cstdio>
#include<algorithm>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=1e6+5;
template<typename T>void readmain(T &x)
{
	bool neg=false;
	unsigned char c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
template<typename T>T& read(T &x){readmain(x);return x;}
template<typename T,typename ...Tr>void read(T &x,Tr&... r){readmain(x);read(r...);}
int tt,n,a[N],b[N],aa[N],bb[N],aw,bw,q[N],qf,qr,al[N],bl[N];
bool vis[N];
int main()
{
	read(tt);
	while(tt--)
	{
		read(n);
		F(i,0,n)aa[i]=read(a[i]);
		F(i,0,n)bb[i]=read(b[i]);
		sort(aa,aa+n);
		sort(bb,bb+n);
		F(i,0,n)al[a[i]=n-1-(lower_bound(aa,aa+n,a[i])-aa)]=i;
		F(i,0,n)bl[b[i]=n-1-(lower_bound(bb,bb+n,b[i])-bb)]=i;
		aw=bw=1;
		F(i,0,n)vis[i]=false;
		qf=qr=0;
		vis[q[qr++]=al[0]]=true;
		if(!vis[bl[0]])vis[q[qr++]=bl[0]]=true;
		while(qf<qr)
		{
			int u=q[qf++];
			while(aw<a[u])
			{
				if(!vis[al[aw]])
				{
					vis[q[qr++]=al[aw]]=true;
				}
				++aw;
			}
			while(bw<b[u])
			{
				if(!vis[bl[bw]])
				{
					vis[q[qr++]=bl[bw]]=true;
				}
				++bw;
			}
		}
		F(i,0,n)if(vis[i])putchar('1');else putchar('0');
		puts("");
	}
	return 0;
}