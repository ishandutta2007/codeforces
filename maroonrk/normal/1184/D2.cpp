#include <bits/stdc++.h>
using namespace std;

using ll=long long;
#define int ll

#define rng(i,a,b) for(int i=int(a);i<int(b);i++)
#define rep(i,b) rng(i,0,b)
#define gnr(i,a,b) for(int i=int(b)-1;i>=int(a);i--)
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
//uint mod=1;
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
	bool operator==(const mint&r)const{return v==r.v;}
};

const int vmax=(1<<21)+10;
mint fact[vmax],finv[vmax],invs[vmax];
void initfact(){
	fact[0]=1;
	rng(i,1,vmax){
		fact[i]=fact[i-1]*i;
	}
	finv[vmax-1]=fact[vmax-1].inv();
	for(int i=vmax-2;i>=0;i--){
		finv[i]=finv[i+1]*(i+1);
	}
	for(int i=vmax-1;i>=1;i--){
		invs[i]=finv[i]*fact[i-1];
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

template<class num>
struct Vector{
	vector<num> v;
	Vector(int s=0){
		v.resize(s,num(0));
	}
	int size()const{
		return v.size();
	}
	num& operator[](int i){
		return v[i];
	}
	num const& operator[](int i)const{
		return v[i];
	}
	Vector& operator+=(const Vector&rhs){
		assert(size()==rhs.size());
		rep(i,size())
			v[i]+=rhs[i];
		return *this;
	}
	Vector& operator-=(const Vector&rhs){
		assert(size()==rhs.size());
		rep(i,size())
			v[i]-=rhs[i];
		return *this;
	}
	Vector& operator*=(const num&x){
		rep(i,size())
			v[i]*=x;
		return *this;
	}
	Vector& operator/=(const num&x){
		num y=num(1)/x;
		rep(i,size())
			v[i]*=y;
		return *this;
	}
	Vector operator+(const Vector&rhs)const{
		return Vector(*this)+=rhs;
	}
	Vector operator-(const Vector&rhs)const{
		return Vector(*this)-=rhs;
	}
	Vector operator*(const num&x)const{
		return Vector(*this)*=x;
	}
	Vector operator/(const num&x)const{
		return Vector(*this)/=x;
	}
};

template<class num>
num dot(const Vector<num>&a,const Vector<num>&b){
	assert(a.size()==b.size());
	const int s=a.size();
	num ans=0;
	rep(i,s)
		ans+=a[i]*b[i];
	return ans;
}

template<class num>
struct Matrix{
	using V=Vector<num>;
	vector<V> m;
	Matrix(int s=0,num z=num(0)){
		m.resize(s,V(s));
		rep(i,size())
			m[i][i]=z;
	}
	int size()const{
		return m.size();
	}
	Matrix operator*(const Matrix&rhs)const{
		assert(size()==rhs.size());
		Matrix res(size());
		rep(i,size())rep(j,size())rep(k,size())
			res[i][j]+=m[i][k]*rhs[k][j];
		return res;
	}
	V operator*(const V&rhs)const{
		assert(size()==rhs.size());
		V res(size());
		rep(i,size())
			res[i]=Dot(m[i],rhs);
		return res;
	}
	V& operator[](int i){
		return m[i];
	}
	V const& operator[](int i) const{
		return m[i];
	}
};

template<class num>
ostream&operator<<(ostream&os,const Matrix<num>&x){
	const int s=x.size();
	os<<"----------"<<endl;
	rep(i,s){
		rep(j,s){
			os<<x[i][j];
			if(j==s-1){
				os<<endl;
			}else{
				os<<" ";
			}
		}
	}
	return os<<"----------";
}

template<class num>
num det(Matrix<num> a){
	const int s=a.size();
	num ans(1);
	rep(i,s){
		rng(j,i+1,s)if(a[j][i]){
			ans=-ans;
			swap(a[j],a[i]);
			break;
		}
		if(!a[i][i])return 0;
		ans*=a[i][i];
		rng(j,i+1,s){
			mint w=-a[j][i]/a[i][i];
			rng(k,i,s)
				a[j][k]+=a[i][k]*w;
		}
	}
	return ans;
}

using V=Vector<mint>;
using M=Matrix<mint>;

//csweep
//arank
//
vi sweep(vvc<mint>&a,int c=-1){
	if(a.empty())return {};
	if(c==-1)c=a.size();
	int h=a.size(),w=a[0].size(),r=0;
	vi res;
	rep(i,c){
		rng(j,r,h)if(a[j][i].v){
			swap(a[r],a[j]);
			break;
		}
		if(a[r][i].v==0)continue;
		rep(j,h)if(j!=r){
			mint z=-a[j][i]/a[r][i];
			rng(k,i,w)
				a[j][k]+=a[r][k]*z;
		}
		res.pb(i);
		r++;
	}
	return res;
}

//
//kernel
//aaw
// {} 
vc<mint> lineareq(vvc<mint> a,int w,vc<mint> b){
	int h=a.size();
	rep(i,h)a[i].pb(b[i]);
	vi idx=sweep(a,w);
	rng(i,idx.size(),h)
		if(a[i][w].v)return {};
	vc<mint> res(w);
	rep(i,idx.size())
		res[idx[i]]=a[i][w]/a[i][idx[i]];
	return res;
}

const int Nmax=255;
V a[Nmax][Nmax],b[Nmax][Nmax],c[Nmax][Nmax];

void waf(int i,int j,const V&v){
	a[i][j]=v;
	if(i>0)b[i][j]=v+b[i-1][j];
	else b[i][j]=v;
	if(j>0)c[i][j]=v+c[i][j-1];
	else c[i][j]=v;
}

//update vecmat

signed main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	cout<<fixed<<setprecision(20);
	
	initfact();
	
	int n,k,m;cin>>n>>k>>m;
	if(k==1||k==n){
		cout<<n<<endl;
		return 0;
	}
	
	waf(0,0,V(m-1));
	rng(i,1,m-1){
		V v(m-1);
		v[m-2]=i+1;
		waf(i,0,v);
		waf(0,i,v);
	}
	rng(i,1,m-1){
		V v(m-1);
		v[i-1]=1;
		waf(1,i,v);
	}
	rng(i,1,m-1)rng(j,1,m-1-i){
		int s=i+j+1;
		waf(i+1,j,(a[i][j]*m*(s+1)-(b[i-1][j]+c[i][j-1])*s*(s+1)*invs[s-1]-a[i][j+1]*(m-s)*(j+1))*invs[m-s]*invs[i+1]);
	}
	
	vvc<mint> p(m-2,vc<mint>(m-2));
	vc<mint> q(m-2);
	rep(i,m-2){
		V w=a[i+1][m-2-i]-(b[i][m-2-i]+c[i+1][m-2-i-1])*invs[m-1];
		rep(j,m-2)
			p[i][j]=w[j];
		q[i]=-w[m-2];
	}
	
	auto x=lineareq(p,m-2,q);
	V y(m-1);
	rep(i,m-2)y[i]=x[i];
	y[m-2]=1;
	
	mint ans=dot(y,a[k-1][n-k]);
	cout<<ans<<endl;
}