#include <bits/stdc++.h>
using namespace std;

using ll=long long;
#define int ll

#define rng(i,a,b) for(int i=int(a);i<int(b);i++)
#define rep(i,b) rng(i,0,b)
#define gnr(i,a,b) for(int i=int(b)-1;i>=a;i--)
#define per(i,b) gnr(i,0,b)
#define pb push_back
#define eb emplace_back
#define a first
#define b second
#define bg begin()
#define ed end()
#define all(x) x.bg,x.ed
#ifdef LOCAL
#define dmp(x) cerr<<__LINE__<<" "<<#x<<" "<<x<<endl
#else
#define dmp(x) void(0)
#endif

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

template<class t> using vc=vector<t>;
template<class t> using vvc=vc<vc<t>>;

using pi=pair<int,int>;
using vi=vc<int>;

template<class t,class u>
ostream& operator<<(ostream& os,const pair<t,u>& p){
	return os<<"{"<<p.a<<","<<p.b<<"}";
}

template<class t> ostream& operator<<(ostream& os,const vc<t>& v){
	os<<"{";
	for(auto e:v)os<<e<<",";
	return os<<"}";
}

using uint=unsigned;
using ull=unsigned long long;

const uint mod=998244353;
//const uint mod=1000000007;
struct mint{
	uint v;
	mint(ll vv=0){s(vv%mod+mod);}
	mint& s(uint vv){
		v=vv<mod?vv:vv-mod;
		return *this;
	}
	mint operator-()const{return mint()-*this;}
	mint& operator+=(const mint&rhs){return s(v+rhs.v);}
	mint&operator-=(const mint&rhs){return s(v+mod-rhs.v);}
	mint&operator*=(const mint&rhs){
		v=ull(v)*rhs.v%mod;
		return *this;
	}
	mint&operator/=(const mint&rhs){return *this*=rhs.inv();}
	mint operator+(const mint&rhs)const{return mint(*this)+=rhs;}
	mint operator-(const mint&rhs)const{return mint(*this)-=rhs;}
	mint operator*(const mint&rhs)const{return mint(*this)*=rhs;}
	mint operator/(const mint&rhs)const{return mint(*this)/=rhs;}
	mint pow(int n)const{
		mint res(1),x(*this);
		while(n){
			if(n&1)res*=x;
			x*=x;
			n>>=1;
		}
		return res;
	}
	mint inv()const{return pow(mod-2);}
	/*mint inv()const{
		int x,y;
		int g=extgcd(v,mod,x,y);
		assert(g==1);
		if(x<0)x+=mod;
		return mint(x);
	}*/
	friend ostream& operator<<(ostream&os,const mint&m){
		return os<<m.v;
	}
	bool operator<(const mint&r)const{return v<r.v;}
};

const int Vmax=(1<<21)+10;
mint fact[Vmax],finv[Vmax],inv[Vmax];
void initfact(){
	fact[0]=1;
	rng(i,1,Vmax){
		fact[i]=fact[i-1]*i;
	}
	finv[Vmax-1]=fact[Vmax-1].inv();
	for(int i=Vmax-2;i>=0;i--){
		finv[i]=finv[i+1]*(i+1);
	}
	for(int i=Vmax-1;i>=1;i--){
		inv[i]=finv[i]*fact[i-1];
	}
}
mint choose(int n,int k){
	return fact[n]*finv[n-k]*finv[k];
}
mint binom(int a,int b){
	return fact[a+b]*finv[a]*finv[b];
}
mint catalan(int n){
	return binom(n,n)-(n-1>=0?binom(n-1,n+1):0);
}

int topbit(signed t){
	return t==0?-1:31-__builtin_clz(t);
}
int topbit(ll t){
	return t==0?-1:63-__builtin_clzll(t);
}

struct BIT{
	vi buf;
	int s;
	BIT(int n=0){init(n);}
	void init(int n){buf.assign(s=n,0);}
	void add(int i,int v){
		for(;i<s;i+=(i+1)&(-i-1))
			buf[i]+=v;
	}
	int get(int i){
		int res=0;
		for(;i>=0;i-=(i+1)&(-i-1))
			res+=buf[i];
		return res;
	}
	int sum(int b,int e){
		return get(e-1)-get(b-1);
	}
	int kth(int k){
		int res=0;
		for(int i=topbit(s);i>=0;i--){
			int w=res+(1<<i);
			if(w<=s&&buf[w-1]<=k){
				k-=buf[w-1];
				res=w;
			}
		}
		return res;
	}
};

signed main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	cout<<fixed<<setprecision(20);
	
	initfact();
	
	int n;cin>>n;
	auto rv=[&](){
		vi res(n);
		rep(i,n){
			cin>>res[i];
			res[i]--;
		}
		return res;
	};
	
	vvc<mint> dp(n+1,vc<mint>(n+1));
	rep(i,n+1)
		dp[0][i]=fact[i];
	rng(i,1,n+1)rep(j,n-i+1){
		if(i>=2)dp[i][j]+=dp[i-2][j+1]*(i-1);
		dp[i][j]+=dp[i-1][j]*j;
	}
	
	mint ans=0;
	
	vi pre;
	rep(_,n){
		vi cur=rv();
		mint idx=0;
		if(_==0){
			BIT bit(n);
			rep(i,n){
				int cnt=cur[i]-bit.get(cur[i]);
				idx+=fact[n-1-i]*cnt;
				bit.add(cur[i],1);
			}
		}else{
			BIT a(n),b(n);
			rep(i,n)a.add(i,1);
			vi st(n);
			int ac=n,bc=0;
			rep(i,n){
				int c=a.get(cur[i]-1);
				int d=b.get(cur[i]-1);
				if(st[pre[i]]==0){
					if(pre[i]<cur[i])c--;
					if(c)idx+=dp[ac-2][bc+1]*c;
					if(d)idx+=dp[ac-1][bc]*d;
				}else{
					if(c)idx+=dp[ac-1][bc]*c;
					if(d)idx+=dp[ac][bc-1]*d;
				}
				if(st[cur[i]]==0){
					a.add(cur[i],-1);
					ac--;
				}else{
					b.add(cur[i],-1);
					bc--;
				}
				st[cur[i]]=2;
				if(st[pre[i]]==0){
					a.add(pre[i],-1);
					ac--;
					b.add(pre[i],1);
					bc++;
					st[pre[i]]=1;
				}
			}
		}
		dmp(idx);
		ans+=idx*dp[n][0].pow(n-1-_);
		pre=cur;
	}
	
	cout<<ans<<endl;
}