#include<bits/stdc++.h>
#define For(i,a,b) for(int i=(a);i<=(b);++i)
#define Rep(i,a,b) for(int i=(a);i>=(b);--i)
#define int long long 
using namespace std;
inline int read()
{
    char c=getchar();int x=0;bool f=0;
    for(;!isdigit(c);c=getchar())f^=!(c^45);
    for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
    if(f)x=-x;return x;
}

// modint
#define mod 998244353
struct modint{
	int x;
	modint(int o=0){x=o;}
	modint &operator = (int o){return x=o,*this;}
	modint &operator +=(modint o){return x=x+o.x>=mod?x+o.x-mod:x+o.x,*this;}
	modint &operator -=(modint o){return x=x-o.x<0?x-o.x+mod:x-o.x,*this;}
	modint &operator *=(modint o){return x=1ll*x*o.x%mod,*this;}
	modint &operator ^=(int b){
		modint a=*this,c=1;
		for(;b;b>>=1,a*=a)if(b&1)c*=a;
		return x=c.x,*this;
	}
	modint &operator /=(modint o){return *this *=o^=mod-2;}
	modint &operator +=(int o){return x=x+o>=mod?x+o-mod:x+o,*this;}
	modint &operator -=(int o){return x=x-o<0?x-o+mod:x-o,*this;}
	modint &operator *=(int o){return x=1ll*x*o%mod,*this;}
	modint &operator /=(int o){return *this *= ((modint(o))^=mod-2);}
	template<class I>friend modint operator +(modint a,I b){return a+=b;}
	template<class I>friend modint operator -(modint a,I b){return a-=b;}
	template<class I>friend modint operator *(modint a,I b){return a*=b;}
	template<class I>friend modint operator /(modint a,I b){return a/=b;}
	friend modint operator ^(modint a,int b){return a^=b;}
	friend bool operator ==(modint a,int b){return a.x==b;}
	friend bool operator !=(modint a,int b){return a.x!=b;}
	bool operator ! () {return !x;}
	modint operator - () {return x?mod-x:0;}
	bool operator <(const modint&b)const{return x<b.x;}
};
inline modint qpow(modint x,int y){return x^y;}

vector<modint> fac,ifac,iv;
inline void initC(int n)
{
	if(iv.empty())fac=ifac=iv=vector<modint>(2,1);
	int m=iv.size(); ++n;
	if(m>=n)return;
	iv.resize(n),fac.resize(n),ifac.resize(n);
	For(i,m,n-1){
		iv[i]=iv[mod%i]*(mod-mod/i);
		fac[i]=fac[i-1]*i,ifac[i]=ifac[i-1]*iv[i];
	}
}
inline modint C(int n,int m){
	if(m<0||n<m)return 0;
	return initC(n),fac[n]*ifac[m]*ifac[n-m];
}
inline modint sign(int n){return (n&1)?(mod-1):(1);}

#define fi first
#define se second
#define pb push_back
#define mkp make_pair
typedef pair<int,int>pii;
typedef vector<int>vi;
  
#define maxn 400005
#define inf 0x3f3f3f3f3f3f3f3f

int n,c[205][205],sum[205][205],f[205][205],p[205][205]; bool vis[205][205];
inline int S(int x,int y,int xx,int yy){
	return sum[xx][yy]-sum[x-1][yy]-sum[xx][y-1]+sum[x-1][y-1];
}
int cal(int l,int r){
	// [l,r]  
	return sum[r][n]-sum[l-1][n]-S(l,l,r,r);
}

int F(int l,int r)
{
	if(l>r)return 0;
	if(vis[l][r])return f[l][r];
	vis[l][r]=1;
	int pos=-1;
	For(k,l,r){
		int tmp=F(l,k-1)+F(k+1,r)+cal(l,k-1)+cal(k+1,r);
		if(tmp<f[l][r]) f[l][r]=tmp,pos=k;
	}
	p[l][r]=pos;
	return f[l][r];
}

int fa[205];
int dfs(int l,int r){
	if(l>r)return 0;
	int k=p[l][r];
	fa[dfs(l,k-1)]=fa[dfs(k+1,r)]=k;
	return k;
}

signed main()
{
	n=read();
	For(i,1,n)For(j,1,n)c[i][j]=read();
	For(i,1,n)
		For(j,1,n) sum[i][j]=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+c[i][j];
	memset(f,63,sizeof f);
	F(1,n);
	dfs(1,n);
	For(i,1,n)cout<<fa[i]<<" ";
	return 0;
}
/* 
f[i][j] = f[i][k-1] + f[k+1][j] + sum([i,k-1],[k+1,j])
*/