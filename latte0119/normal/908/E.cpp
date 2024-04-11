#include<bits/stdc++.h>
using namespace std;

#define int long long

#define rep(i,n) for(int i=0;i<(n);i++)
#define pb push_back
#define all(v) (v).begin(),(v).end()
#define fi first
#define se second
typedef vector<int>vint;
typedef pair<int,int>pint;
typedef vector<pint>vpint;

template<typename A,typename B>inline void chmin(A &a,B b){if(a>b)a=b;}
template<typename A,typename B>inline void chmax(A &a,B b){if(a<b)a=b;}

/*
GF(p)
inverse:O(log p) based on Fermat's little theorem (a^(p-1)=1 mod p)
*/

template<int32_t mod>
struct ModInt{
	int32_t a;
	inline int32_t normalize(int64_t x){
		x%=mod;
		if(x<0)x+=mod;
		return x;
	}
	ModInt(const int64_t a=0):a(normalize(a)){}

	ModInt& operator+=(const ModInt &x){
		a+=x.a;
		if(a>=mod)a-=mod;
		return *this;
	}
	ModInt& operator-=(const ModInt &x){
		a-=x.a;
		if(a<0)a+=mod;
		return *this;
	}
	ModInt& operator*=(const ModInt &x){
		a=(int64_t)a*x.a%mod;
		return *this;
	}
	ModInt& operator/=(const ModInt &x){
		*this*=x.inv();
		return *this;
	}

	ModInt operator+(const ModInt x){return ModInt(*this)+=x;}
	ModInt operator-(const ModInt x){return ModInt(*this)-=x;}
	ModInt operator*(const ModInt x){return ModInt(*this)*=x;}
	ModInt operator/(const ModInt x){return ModInt(*this)/=x;}
	bool operator==(const ModInt x){return a==x.a;}
	bool operator!=(const ModInt x){return a!=x.a;}

	ModInt operator-(){return ModInt(0)-ModInt(*this);}
	ModInt pow(int64_t ex)const{
		int64_t x=a;
		int64_t res=1;
		while(ex){
			if(ex&1)res=res*x%mod;
			x=x*x%mod;
			ex>>=1;
		}
		return ModInt(res);
	}
	ModInt inv()const{return pow(mod-2);}
};

template<int32_t mod>
istream& operator>>(istream& in,ModInt<mod>& a){
	return (in>>a.a);
}
template<int32_t mod>
ostream& operator<<(ostream& out,const ModInt<mod>& a){
	return (out<<a.a);
}

using mint=ModInt<1000000007>;
using Cd = complex<double>;
namespace std {
  template<>
  Cd& Cd::operator*=(const Cd& y) {
    double a = this->real();
    double b = this->imag();
    double c = y.real();
    double d = y.imag();
    return *this=Cd(a*c-b*d, a*d+b*c);
  }
}

template<class Mint,class C>
struct ArbitraryModConvolution15{
    static constexpr double PI=acos(-1);

    static void dft(vector<C>&f){
        int n=f.size();
		int s=__lg(n);

		static vector<vector<C>>w(30);
		w[0]=vector<C>(1,C(1.0,0.0));
		for(int i=1;i<=s;i++){
			if(w[i].size())continue;
			w[i]=vector<C>(1<<i);
			const double t=2*PI/(1<<i);
			for(int j=0;j<1<<i;j++)w[i][j]=(j&1)?polar(1.0,j*t):w[i-1][j>>1];
		}
		

        for(int i=0,j=1;j<n-1;j++){
            for(int k=n>>1;k>(i^=k);k>>=1);
            if(i>j)swap(f[i],f[j]);
        }

		for(int m=1;m<=s;m++){
			for(int i=0;i<n;i+=1<<m){
				for(int j=0;j<1<<m-1;j++){
					C f0=f[i+j],f1=w[m][j]*f[i+j+(1<<m-1)];
					f[i+j]=f0+f1;
					f[i+j+(1<<m-1)]=f0-f1;
				}
			}
		}
	}
	static void idft(vector<C>&f){
		dft(f);
		reverse(f.begin()+1,f.end());
		double in=1.0/f.size();
		for(int i=0;i<f.size();i++)f[i]*=in;
	}

	static vector<Mint>convolute(vector<Mint>A,vector<Mint>B){
		int n=1<<__lg(A.size()+B.size()-2)+1;
        vector<C>g(n),h(n);
		for(int i=0;i<A.size();i++)g[i]=C(A[i].a&~(~0<<15),A[i].a>>15);
		for(int i=0;i<B.size();i++)h[i]=C(B[i].a&~(~0<<15),B[i].a>>15);
		
		dft(g);
		dft(h);

		vector<C>gc=g;
		reverse(gc.begin()+1,gc.end());
		
		C I(0,1);
		for(int i=0;i<n;i++){
			gc[i]=conj(gc[i]);

			C a=(g[i]+gc[i])*h[i]*0.5;
			C b=(g[i]-gc[i])*h[i]*I*(-0.5);
			g[i]=a;h[i]=b;
		}

		idft(g);
		idft(h);
		vector<Mint>AB(A.size()+B.size()-1);
		for(int i=0;i<AB.size();i++){
			Mint ll=g[i].real()+0.5;
			Mint lh=g[i].imag()+0.5;
			Mint hl=h[i].real()+0.5;
			Mint hh=h[i].imag()+0.5;
			AB[i]=(hh*(1<<15)+(lh+hl))*(1<<15)+ll;
		}
		return AB;
	}
};
using FFT=ArbitraryModConvolution15<mint,complex<double>>;

/*
each operation:O(n) or O(nlogn) 
*/
 
template<class Mint,class Convoluter>
struct Poly{
	vector<Mint>v;
    inline void normalize(){
        while(v.size()&&v.back()==0)v.pop_back();
    }
	template<class...Args>
	Poly(Args...args):v(args...){}
 
	Poly(const initializer_list<Mint>&in):v(in.begin(),in.end()){}
 
	int size()const{return v.size();}
 
	inline Mint coef(const int i)const{return (i<v.size())?v[i]:Mint(0);}
 
	Poly operator+(const Poly &x){
		int n=max(size(),x.size());
		vector<Mint>res(n);
		for(int i=0;i<n;i++)res[i]=coef(i)+x.coef(i);
		return res;
	}
	Poly operator-(const Poly &x){
		int n=max(size(),x.size());
		vector<Mint>res(n);
		for(int i=0;i<n;i++)res[i]=coef(i)-x.coef(i);
		return res;
	}
	Poly operator*(const Poly& x){
		return Convoluter::convolute(v,x.v);
	}
	Poly operator*(const Mint& x){
		int n=size();
		vector<Mint>res(n);
		for(int i=0;i<n;i++)res[i]=v[i]*x;
		return res;
	}
	Poly operator/(const Mint& x){
		return (*this)*x.inv();
	}
 
	Poly& operator+=(const Poly& x){return *this=(*this)+x;}
	Poly& operator-=(const Poly& x){return *this=(*this)-x;}
	Poly& operator*=(const Poly& x){return *this=(*this)*x;}
	Poly& operator*=(const Mint& x){return *this=(*this)*x;}
	Poly& operator/=(const Mint& x){return *this=(*this)/x;}
 
    Poly pre(int n){
        return {v.begin(),v.begin()+min(n,size())};
    }
    Poly rev(){
        vector<Mint>res=v;
        reverse(res.begin(),res.end());
        return res;
    }

    Poly diff(int n){
        vector<Mint>res(n);
        for(int i=1;i<size()&&i<=n;i++)res[i-1]=coef(i)*i;
        return res;
    }
    Poly inte(int n){
        vector<Mint>res(n);
        for(int i=0;i<size()&&i+1<n;i++)res[i+1]=coef(i)/(i+1);
        return res;
    }
 
    Poly inv(int m){
        Poly res{1};
        for(int i=1;i<m;i*=2){
            res=(res*Mint(2)-res*res*pre(2*i)).pre(2*i);
        }
        return res.pre(m);
    }
    Poly exp(int n){
        Poly f{1};
        for(int i=1;i<n;i*=2){
            f=(f*(pre(2*i)-f.log(2*i))+f).pre(2*i);
        }
        return f.pre(n);
    }
 
    Poly log(int n){
        return (diff(n-1)*inv(n-1)).inte(n);
    }
 
 
	Poly pow(int n,Mint m){
		Poly res=log(n);
		res*=m;
		return res.exp(n);
	}

	Mint& operator[](const int i){return v[i];}
};
using poly=Poly<mint,FFT>;
 
template<class Mint,class Convoluter>
ostream& operator<<(ostream& ost,Poly<Mint,Convoluter>a){
    for(int i=0;i<a.size();i++){
        if(i)cout<<" ";
        cout<<a.v[i];
    }
    return ost;
}

/*
EGF of Bell Number
B_{n+1}=\sum_{k=0}^{n} \binom{n}{k} B_k

B'=exp(x)*B
<=>exp(x)=B'/B
<=>exp(x)-1=logB
<=>B=exp(exp(x)-1)
*/
poly BellEGF(int n){
	return (poly{0,1}.exp(n+1)-poly{1}).exp(n+1);
}

signed main(){
	int N,M;cin>>M>>N;
	vector<int>A(M);
	rep(i,N){
		string s;cin>>s;
		rep(j,M)if(s[j]=='1')A[j]|=1ll<<i;
	}

	map<int,int>cnt;
	rep(i,M)cnt[A[i]]++;


	auto B=BellEGF(M+1);
	mint f=1;
	for(int i=0;i<=M;i++){
		B[i]*=f;
		f*=(i+1);
	}
	mint ans=1;
	for(auto p:cnt)ans*=B[p.se];
	cout<<ans<<endl;
	return 0;
}