#include<bits/stdc++.h>
using namespace std;

#define int long long

#define rep(i,n) for(int i=0;i<(n);i++)
#define pb push_back
#define eb emplace_back
#define all(v) (v).begin(),(v).end()
#define fi first
#define se second
typedef vector<int>vint;
typedef pair<int,int>pint;
typedef vector<pint>vpint;

template<typename A,typename B>inline void chmin(A &a,B b){if(a>b)a=b;}
template<typename A,typename B>inline void chmax(A &a,B b){if(a<b)a=b;}

template<class A,class B>
ostream& operator<<(ostream& ost,const pair<A,B>&p){
	ost<<"{"<<p.first<<","<<p.second<<"}";
	return ost;
}

template<class T>
ostream& operator<<(ostream& ost,const vector<T>&v){
	ost<<"{";
	for(int i=0;i<v.size();i++){
		if(i)ost<<",";
		ost<<v[i];
	}
	ost<<"}";
	return ost;
}

struct ModX{
	using ull=uint64_t;
	static const ull mod=(1ll<<61)-1;
	static const ull MASK30=(1ll<<30)-1;
	static const ull MASK31=(1ll<<31)-1;

	ull a;

	ModX& s(ull vv){
		a=vv<mod?vv:vv-mod;
		return *this;
	}
	ModX(ull a=0):a(a%mod){}
	
	ModX& operator+=(const ModX& x){return s(a+x.a);}
	ModX& operator-=(const ModX& x){return s(a+mod-x.a);}
	ModX& operator*=(const ModX& x){
		const ull au=a>>31;
		const ull ad=a&MASK31;
		const ull bu=x.a>>31;
		const ull bd=x.a&MASK31;
		const ull mid=ad*bu+au*bd;
		const ull midu=mid>>30;
		const ull midd=mid&MASK30;
		const ull z=au*bu*2+midu+(midd<<31)+ad*bd;
		return s((z&mod)+(z>>61));
	}

	ModX operator+(const ModX &x)const{return ModX(*this)+=x;}
	ModX operator-(const ModX &x)const{return ModX(*this)-=x;}
	ModX operator*(const ModX &x)const{return ModX(*this)*=x;}

	bool operator==(const ModX &x)const{return a==x.a;}
	bool operator!=(const ModX &x)const{return a!=x.a;}
	bool operator<(const ModX &x)const{return a<x.a;}

	ModX operator-()const{return ModX()-*this;}
};

istream& operator>>(istream& in,const ModX& a){
	return (in>>a.a);
}

ostream& operator<<(ostream& out,const ModX& a){
	return (out<<a.a);
}
using xint=ModX;
const xint base(119);
const int RHSIZE=1111111;
xint basepow[RHSIZE];
struct RHInit{
	RHInit(){
		basepow[0]=1;
		for(int i=1;i<RHSIZE;i++)basepow[i]=basepow[i-1]*base;
	}
}RHInitDummy;

template<class T>
vector<xint>calcHash(const T &v){
	vector<xint>hs(v.size()+1);
	for(int i=0;i<v.size();i++){
		hs[i+1]=hs[i]*base+v[i];
	}
	return hs;
}

int N;
string S[111111];
string T;

xint hst;
vint G[111111];
vector<xint>H;
int dfs(int v){
	int ret=0;
	for(auto u:G[v]){
		for(auto c:S[u]){
			H.pb(H.back()*base+c);
			if(H.size()>T.size()&&H.back()-H[H.size()-1-T.size()]*basepow[T.size()]==hst)ret++;
		}
		ret+=dfs(u);
		rep(i,S[u].size())H.pop_back();
	}
	return ret;
}

signed main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
	cin>>N;
	for(int i=1;i<N;i++){
		int p;
		cin>>p>>S[i];
		p--;
		G[p].pb(i);
	}
	cin>>T;

	hst=calcHash(T)[T.size()];
	H.pb(0);
	cout<<dfs(0)<<endl;
	return 0;
}