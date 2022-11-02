#include<bits/stdc++.h>
using namespace std;typedef vector<int>zk;const int P=998244353;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<'0'||c>'9';c=getchar()) if(!(c^45)) f=1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	if(f) x=-x;
}
namespace NTT
{
	int r[5000005],g[25][2];
	inline int ksm(int x,int q=P-2) {int r=1;for(;q;q>>=1,x=1ll*x*x%P) if(q&1) r=1ll*r*x%P;return r;}
	inline void Ainit()
	{
		g[23][0]=ksm(3,119),g[23][1]=ksm(332748118,119);
		for(int i=22;i;i--) g[i][0]=1ll*g[i+1][0]*g[i+1][0]%P,g[i][1]=1ll*g[i+1][1]*g[i+1][1]%P;
	}
	inline void init(int T) {for(int i=0;i<T;i++) r[i]=(r[i>>1]>>1)|((i&1)?(T>>1):0);}
	inline void NTT(int n,int *a,int fg)
	{
		for(int i=0;i<n;i++) if(r[i]<i) swap(a[i],a[r[i]]);
		for(int d=1,rp=1;d<n;d<<=1,rp++)
			for(int i=0,wn=g[rp][fg];i<n;i+=(d<<1))
				for(int k=0,w=1;k<d;k++,w=1ll*w*wn%P)
					{int x=a[i+k],y=1ll*a[i+k+d]*w%P;a[i+k]=(x+y)%P,a[i+k+d]=(x-y+P)%P;}
		if(fg) {int iv=ksm(n);for(int i=0;i<n;i++) a[i]=1ll*a[i]*iv%P;}
	}
}
zk dw,gg;int n,k,A[5000005],B[5000005],C[5000005];
inline zk AKIOI(zk a,zk b)
{
	int l=a.size()+b.size()-1,T=1;zk c;while(T<=l) T<<=1;NTT::init(T);
	memset(A,0,sizeof(A));for(int i=0;i<(int)a.size();i++) A[i]=a[i];NTT::NTT(T,A,0);
	memset(B,0,sizeof(B));for(int i=0;i<(int)b.size();i++) B[i]=b[i];NTT::NTT(T,B,0);
	memset(C,0,sizeof(C));for(int i=0;i<T;i++) C[i]=1ll*A[i]*B[i]%P;
	NTT::NTT(T,C,1);for(int i=0;i<=l;i++) c.push_back(C[i]);return c;
}
inline zk AKZJOI(zk a,int q) {zk R=dw;for(;q;q>>=1,a=AKIOI(a,a)) if(q&1) R=AKIOI(a,R);return R;}
int main()
{
	read(n),read(k),dw.resize(1),dw[0]=1,gg.resize(10),NTT::Ainit();
	for(int i=1,x;i<=k;i++) read(x),gg[x]=1;
	gg=AKZJOI(gg,n>>1);int res=0;
	for(int i=0;i<(int)gg.size();i++) (res+=1ll*gg[i]*gg[i]%P)%=P;
	return printf("%d\n",res),0;
}