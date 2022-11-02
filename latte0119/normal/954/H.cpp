#include<bits/stdc++.h>
using namespace std;

#define int long long

#define rep(i,n) for(int i=0;i<(n);i++)
#define pb push_back
#define eb emplace_back
#define all(v) (v).begin(),(v).end()
#define fi first
#define se second

using vint=vector<int>;
using pint=pair<int,int>;
using vpint=vector<pint>;

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

inline int topbit(unsigned long long x){
	return x?63-__builtin_clzll(x):-1;
}

inline int popcount(unsigned long long x){
	return __builtin_popcountll(x);
}

inline int parity(unsigned long long x){
	return __builtin_parity(x);
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
istream& operator>>(istream& in,ModInt<mod>& a){
	return (in>>a.a);
}
template<uint32_t mod>
ostream& operator<<(ostream& out,const ModInt<mod>& a){
	return (out<<a.a);
}
using mint=ModInt<1000000007>;

int N;
int A[5555];


mint f[2][5010],f2[2][10010];
mint ans[10010];
signed main(){
	cin>>N;
	rep(i,N-1)cin>>A[i];

	f[(N-1)&1][0]=1;
	f2[(N-1)&1][0]=1;
	for(int i=N-2;i>=0;i--){
		for(int j=1;j<=2*(N-1);j++){
			ans[j]*=A[i];			
		}
		const int bi=A[i]*(A[i]-1)/2;
		for(int j=2;j<=2*(N-1);j++){
			ans[j]+=f2[(i+1)&1][j-2]*bi;
		}
		for(int j=1;j<=N-1;j++){
			ans[j]+=f[(i+1)&1][j-1]*A[i];
		}

		for(int j=1;j<=N-1;j++){
			f[i&1][j]=f[(i+1)&1][j-1]*A[i];
		}
		f[i&1][0]=1;

		f2[i&1][0]=1;
		for(int j=1;j<=N-1;j++){
			f2[i&1][j]+=f[(i+1)&1][j-1]*A[i]*2;
		}
		for(int j=2;j<=2*(N-1);j++){
			f2[i&1][j]+=f2[(i+1)&1][j-2]*A[i]*A[i];
		}


		for(int j=0;j<=N-1;j++)f[(i+1)&1][j]=0;
		for(int j=0;j<=2*(N-1);j++)f2[(i+1)&1][j]=0;
	}

	for(int i=1;i<=2*(N-1);i++){
		if(i!=1)cout<<" ";
		cout<<ans[i];
	}
	cout<<endl;
	return 0;
}