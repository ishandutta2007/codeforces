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

template<uint32_t mod>
struct ModInt{
	uint32_t a;
	ModInt& s(uint32_t vv){
		a=vv<mod?vv:vv-mod;
		return *this;
	}

    ModInt(int64_t x=0){s(x%mod+mod);}

	ModInt& operator+=(const ModInt &x){return s(a+x.a);}
	ModInt& operator-=(const ModInt &x){return s(a+mod-x.a);}
	ModInt& operator*=(const ModInt &x){
		a=uint64_t(a)*x.a%mod;
		return *this;
	}
	ModInt& operator/=(const ModInt &x){
		*this*=x.inv();
		return *this;
	}

	ModInt operator+(const ModInt &x)const{return ModInt(*this)+=x;}
	ModInt operator-(const ModInt &x)const{return ModInt(*this)-=x;}
	ModInt operator*(const ModInt &x)const{return ModInt(*this)*=x;}
	ModInt operator/(const ModInt &x)const{return ModInt(*this)/=x;}
	bool operator==(const ModInt &x)const{return a==x.a;}
	bool operator!=(const ModInt &x)const{return a!=x.a;}
	bool operator<(const ModInt &x)const{return a<x.a;}

	ModInt operator-()const{return ModInt()-*this;}
	ModInt pow(int64_t n)const{
		ModInt res(1),x(*this);
		while(n){
			if(n&1)res*=x;
			x*=x;
			n>>=1;
		}
		return res;
	}

    ModInt inv()const{return pow(mod-2);}
};

template<uint32_t mod>
istream& operator>>(istream& in,const ModInt<mod>& a){
	return (in>>a.a);
}
template<uint32_t mod>
ostream& operator<<(ostream& out,const ModInt<mod>& a){
	return (out<<a.a);
}
using mint=ModInt<998244353>;

int N,M,A;
int B[222222];

mint calc(int L){
	mint al=mint(A).pow(2*L);
	mint sb=mint(A).pow(L);

	return sb+(al-sb)/2;
}
signed main(){
	scanf("%lld%lld%lld",&N,&M,&A);
	rep(i,M)scanf("%lld",&B[i+1]);

	mint ans=1;
	for(int i=0;i<M;i++)ans*=calc(B[i+1]-B[i]);
	ans=ans*mint(A).pow(N-2*B[M]);
	cout<<ans<<endl;
	return 0;
}