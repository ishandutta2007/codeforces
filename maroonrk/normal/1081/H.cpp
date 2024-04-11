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

//const uint mod=998244353;
const uint mod=1000000007;
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

ll rand_int(ll l, ll r) { //[l, r]
    static random_device rd;
    static mt19937 gen(rd());
    return uniform_int_distribution<ll>(l, r)(gen);
}

namespace rhash{
	const int k=2;
	vc<mint> a[k],b[k];
	void init(int n){
		rep(i,k){
			a[i].resize(n+1,1);
			a[i][1]=rand_int(1,mod-1);
			b[i].resize(n+1,1);
			b[i][1]=a[i][1].inv();
			rep(j,n)a[i][j+1]=a[i][j]*a[i][1];
			rep(j,n)b[i][j+1]=b[i][j]*b[i][1];
		}
	}
	using P=pair<array<mint,k>,int>;
	P mrg(P x,P y){
		rep(i,k)
			x.a[i]+=y.a[i]*a[i][x.b];
		x.b+=y.b;
		return x;
	}
	struct gen{
		gen(){}
		vc<mint> c[k];
		template<class S>
		gen(S s){
			rep(i,k){
				c[i].pb(0);
				rep(j,s.size())
					c[i].pb(c[i][j]+a[i][j]*s[j]);
			}
		}
		P get(int l,int r){
			P res;
			rep(i,k)res.a[i]=(c[i][r]-c[i][l])*b[i][l];
			res.b=r-l;
			return res;
		}
	};
}

struct eertree{
	eertree(){}
	struct N{
		int suf,l,r;
		int len(){return r-l;}
		map<int,int> ch;
	};
	vc<N> x;
	eertree(string s){
		x.pb({-1,1,0,{}});
		x.pb({0,0,0,{}});
		auto chk=[&](int c,int i){
			x[c].l+=i-x[c].r;
			x[c].r=i;
			return x[c].l>0&&s[x[c].l-1]==s[i];
		};
		int c=1;
		rep(i,s.size()){
			while(!chk(c,i))c=x[c].suf;
			if(x[c].ch.count(s[i])==0){
				int d=x[c].suf;
				if(d!=-1)while(!chk(d,i))d=x[d].suf;
				int e=d==-1?1:x[d].ch[s[i]];
				x[c].ch[s[i]]=x.size();
				x.pb({e,x[c].l-1,x[c].r+1,{}});
			}
			c=x[c].ch[s[i]];
		}
	}
};

signed main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	cout<<fixed<<setprecision(20);
	
	rhash::init(200000);
	
	string s[2];
	eertree t[2];
	rhash::gen r[2];
	rep(k,2){
		cin>>s[k];
		t[k]=eertree(s[k]);
		r[k]=rhash::gen(s[k]);
	}
	
	int ans=ll(t[0].x.size()-2)*(t[1].x.size()-2);
	
	rep(k,2){
		int h=k^1;
		map<rhash::P,int> c1,c2;
		rng(i,2,t[h].x.size()){
			int a=t[h].x[i].len();
			int b=t[h].x[t[h].x[i].suf].len();
			if(b<=0)continue;
			int w=a-b;
			if(w*2<=a)
				c1[r[h].get(t[h].x[i].l,t[h].x[i].l+w)]++;
			c2[r[h].get(t[h].x[i].l,t[h].x[i].r)]=1;
		}
		rng(i,2,t[k].x.size()){
			int a=t[k].x[i].len();
			int b=t[k].x[t[k].x[i].suf].len();
			if(b<=0)continue;
			int w=a-b;
			auto z=r[k].get(t[k].x[i].r-w,t[k].x[i].r);
			ans-=c1[z];
			if(a%w==0)continue;
			z=rhash::mrg(z,r[k].get(t[k].x[i].r-w,t[k].x[i].r-a%w));
			ans-=c2[z];
		}
		dmp(ans);
	}
	
	map<rhash::P,int> c[2];
	rep(k,2){
		rng(i,2,t[k].x.size()){
			int a=t[k].x[i].len();
			int b=t[k].x[t[k].x[i].suf].len();
			if(b<=0)continue;
			int w=a-b;
			int d=k==0?t[k].x[i].r-w:t[k].x[i].l;
			c[k][r[k].get(d,d+w)]++;
		}
	}
	for(auto kv:c[0])
		ans+=kv.b*c[1][kv.a];
	
	cout<<ans<<endl;
}