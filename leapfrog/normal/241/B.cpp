#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	if(f) x=-x;
}
template<typename T>inline void write(T x) {if(x>=10) write(x/10);putchar(48|(x%10));}
const int N=750005,P=1e9+7,I=(P+1)>>1;int n,tp,Tp,ls[N],pw[65],rs=0;ll K,a[N];
struct node
{
	int l1,r1,md1,l2,r2,md2;
	node(int l1=0,int r1=0,int l2=0,int r2=0):l1(l1),r1(r1),l2(l2),r2(r2) {}
}ar[N],tmp[N];
inline void Ad(int l1,int r1,int l2,int r2) {if(l1^r1&&l2^r2) tmp[++Tp]=node(l1,r1,l2,r2);}
inline int calc(int l1,int r1,int l2,int r2) {return 1ll*(r1-l1-ls[r1]+ls[l1])*(ls[r2]-ls[l2])%P+1ll*(r2-l2-ls[r2]+ls[l2])*(ls[r1]-ls[l1])%P;}
int main()
{
	read(n),read(K),K<<=1;for(int i=0;i<n;i++) read(a[i]);
	pw[0]=1;for(int i=1;i<=60;i++) pw[i]=(pw[i-1]<<1)%P;
	sort(a,a+n),ar[++tp]=node(0,n,0,n);for(int k=31;~k;k--)
	{
		ll sm=0;for(int i=1;i<=tp;i++)
		{
			ar[i].md1=lower_bound(a+ar[i].l1,a+ar[i].r1,(1ll<<k))-a;
			ar[i].md2=lower_bound(a+ar[i].l2,a+ar[i].r2,(1ll<<k))-a;
			sm+=1ll*(ar[i].md1-ar[i].l1)*(ar[i].r2-ar[i].md2)+1ll*(ar[i].md2-ar[i].l2)*(ar[i].r1-ar[i].md1);
		}
		for(int i=0;i<n;i++) a[i]&=(1ll<<k)-1;
		if(K<=sm)
		{
			rs=(rs+1ll*K*pw[k])%P;
			for(int i=1;i<=tp;i++) Ad(ar[i].l1,ar[i].md1,ar[i].md2,ar[i].r2),Ad(ar[i].md1,ar[i].r1,ar[i].l2,ar[i].md2);
		}else
		{
			K-=sm,rs=(rs+sm*pw[k])%P;for(int b=0;b<k;b++)
			{
				ls[0]=0;for(int i=0;i<n;i++) ls[i+1]=ls[i]+((a[i]>>b)&1);
				for(int i=1;i<=tp;i++)
				{
					rs=(rs+1ll*calc(ar[i].l1,ar[i].md1,ar[i].md2,ar[i].r2)*pw[b])%P;
					rs=(rs+1ll*calc(ar[i].l2,ar[i].md2,ar[i].md1,ar[i].r1)*pw[b])%P;
				}
			}
			for(int i=1;i<=tp;i++) Ad(ar[i].l1,ar[i].md1,ar[i].l2,ar[i].md2),Ad(ar[i].md1,ar[i].r1,ar[i].md2,ar[i].r2);
		}
		if(Tp>n) break;else tp=Tp,Tp=0;
		for(int i=1;i<=tp;i++) ar[i]=tmp[i];
	}
	return write(1ll*rs*I%P),putchar('\n'),0;
}