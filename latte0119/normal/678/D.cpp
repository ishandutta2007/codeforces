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

template<class Mint>
struct Matrix{
	vector<vector<Mint>>a;

	template<class... Args>
	explicit Matrix(Args... args):a(args...){}

	explicit Matrix(const initializer_list<vector<Mint>>&in):a(in.begin(),in.end()){}

	const vector<Mint>& operator[](int i)const{return a[i];}
	vector<Mint>& operator[](int i){return a[i];}
	inline int size()const{return a.size();}

	Matrix& operator+=(const Matrix &A){
		for(int i=0;i<a.size();i++){
			for(int j=0;j<a[0].size();j++){
				a[i][j]+=A[i][j];
			}
		}
		return *this;
	}
	Matrix& operator-=(const Matrix &A){
		for(int i=0;i<a.size();i++){
			for(int j=0;j<a[0].size();j++){
				a[i][j]-=A[i][j];
			}
		}
	}
	Matrix& operator*=(const Matrix &A){
		Matrix C(a.size(),vector<Mint>(A.a[0].size()));
		for(int i=0;i<a.size();i++){
			for(int j=0;j<A[0].size();j++){
				for(int k=0;k<a[0].size();k++)C[i][j]+=a[i][k]*A[k][j];
			}
		}
		return *this=C;
	}

	Matrix& operator*=(const Mint &c){
		for(int i=0;i<a.size();i++){
			for(int j=0;j<a[0].size();j++){
				a[i][j]*=c;
			}
		}
		return *this;
	}

	static Matrix identity(int n){
		Matrix I(n,vector<Mint>(n));
		for(int i=0;i<n;i++)I[i][i]=1;
		return I;
	}

	Matrix operator+(const Matrix &A)const{return Matrix(*this)+=A;}
	Matrix operator-(const Matrix &A)const{return Matrix(*this)-=A;}
	Matrix operator*(const Matrix &A)const{return Matrix(*this)*=A;}
	Matrix operator*(const Mint &c)const{return Matrix(*this)*=c;}

	Matrix pow(int n){
		Matrix res=identity(size());
		Matrix x=*this;

		while(n){
			if(n&1)res*=x;
			x*=x;
			n>>=1;
		}
		return res;
	}

	Matrix transpose(){
		Matrix T(a[0].size(),vector<Mint>(a.size()));
		for(int i=0;i<a.size();i++){
			for(int j=0;j<a[0].size();j++)T[j][i]=a[i][j];
		}
		return T;
	}

	bool operator==(const Matrix &A)const{
		return a==A.a;
	}
	bool operator!=(const Matrix &A)const{
		return a!=A.a;
	}
	bool operator<(const Matrix &A)const{
		return a<A.a;
	}
	bool operator>(const Matrix &A)const{
		return a>A.a;
	}


	Mint det(){
		Mint ret=1;
		vector<vector<Mint>>m=a;

		for(int i=0;i<a.size();i++){
			if(m[i][i]==0){
				for(int j=i+1;j<a.size();j++)if(m[j][i]!=0){
					swap(m[i],m[j]);
					ret=-ret;
					break;
				}
			}
			if(m[i][i]==0)return 0;
			ret*=m[i][i];

			Mint in=m[i][i].inv();
			for(int j=0;j<a.size();j++)m[i][j]*=in;
			for(int j=i+1;j<a.size();j++){
				Mint coef=m[j][i];
				for(int k=0;k<a.size();k++)m[j][k]-=m[i][k]*coef;
			}
		}
		return ret;
	}

	//det(A-tI)
	vector<Mint>eigenpoly(){
		int n=a.size();
		vector<Mint>eval(n+1);
		for(int i=0;i<=n;i++){
			auto A=*this;
			for(int j=0;j<n;j++)A[j][j]-=i;
			eval[i]=A.det();
		}

		vector<Mint>ret(n+1);
		for(int i=0;i<=n;i++){
			vector<Mint>p(n+1);
			p[0]=eval[i];
			Mint den=1;
			for(int j=0;j<=n;j++){
				if(j==i)continue;
				den*=i-j;
				for(int k=n-1;k>=0;k--){
					p[k+1]+=p[k];
					p[k]*=-j;
				}
			}
			den=den.inv();
			for(int j=0;j<=n;j++)p[j]*=den;
			for(int j=0;j<=n;j++)ret[j]+=p[j];
		}
		return ret;
	}
};
using mat=Matrix<mint>;
using vec=vector<mint>;
template<class Mint>
ostream& operator<<(ostream& ost,const Matrix<Mint>&A){
	for(int i=0;i<A.size();i++){
		ost<<"{";
		const vector<Mint>&a=A[i];
		for(int j=0;j<a.size();j++){
			if(j)ost<<",";
			ost<<a[j];
		}ost<<"}\n";
	}
	return ost;
}

signed main(){
	int A,B,N,X;
	cin>>A>>B>>N>>X;

	mat C{{A,B},{0,1}};

	mat v{{X},{1}};

	v=C.pow(N)*v;

	cout<<v[0][0]<<endl;
	return 0;
}