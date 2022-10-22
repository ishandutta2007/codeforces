#include<bits/stdc++.h>
#define For(i,a,b) for(int i=(a),i##END=(b);i<=i##END;i++)
#define Rof(i,b,a) for(int i=(b),i##END=(a);i>=i##END;i--)
#define go(u) for(int i=head[u];i;i=nxt[i])
#define int long long
using namespace std;
inline int read(){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
    return x*f;
}
const int N=2e5+10,p=1e9+7,iv2=(p+1)/2;
int fac[N],ifac[N],a[N];
inline int inv(int a,int b=p-2){
	int x=1;while(b){
		if(b&1)(x*=a)%=p;
		(a*=a)%=p,b>>=1;
	}return x;
}
void init(int n=N-10){
	fac[0]=1;For(i,1,n)fac[i]=fac[i-1]*i%p;
	ifac[n]=inv(fac[n]);Rof(i,n-1,0)ifac[i]=ifac[i+1]*(i+1)%p;
}
int C(int n,int m){return n<m||m<0?0:fac[n]*ifac[m]%p*ifac[n-m]%p;}
int n,q,f[N][48];
template<const int K> struct H{
	int val[N],A[K+1],D[K+1];
	void init(){For(i,1,n)val[i]=inv(a[i],K)+val[i-1];}
	bool check(int l,int r,int a,int d){
		A[0]=D[0]=1;For(i,1,K)A[i]=A[i-1]*a%p,D[i]=D[i-1]*d%p;
		int val1=(val[r]-val[l-1]+p)%p,val2=0,len=r-l+1;
		For(j,0,K)(val2+=C(K,j)*A[K-j]%p*D[j]%p*f[len-1][j]%p)%=p;
//		cout<<K<<" "<<val1<<" "<<val2<<endl;
		return val1==val2;
	}
};
H<3> h1;H<1> h2;H<37> h3;H<47> h4;H<31> h5;
signed main(){
	init(),n=read(),q=read();
	For(i,0,n)For(j,0,47)f[i][j]=((i?f[i-1][j]:0)+inv(i,j))%p;
	For(i,1,n)a[i]=(read()+114514123)%p;h1.init(),h2.init(),h3.init(),h4.init(),h5.init();
	For(i,1,n)(a[i]+=a[i-1])%=p;while(q--){
		int l=read(),r=read(),d=read(),len=r-l+1;
		int A=((a[r]-a[l-1]+p)%p+(p-d*len%p*(len-1)%p*iv2%p))%p*inv(len)%p;
		puts(h1.check(l,r,A,d)&&h2.check(l,r,A,d)&&h3.check(l,r,A,d)&&h4.check(l,r,A,d)&&h5.check(l,r,A,d)?"Yes":"No");
	}
	return 0;
}