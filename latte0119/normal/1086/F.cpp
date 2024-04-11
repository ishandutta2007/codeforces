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

using mint=ModInt<998244353>;


template<class T>
struct Polynomial:vector<T>{
	using vector<T>::vector;
	Polynomial& operator+=(const Polynomial &x){
		if((*this).size()<x.size())(*this).resize(x.size());
		for(int i=0;i<x.size();i++)(*this)[i]+=x[i];
		return *this;
	}
	Polynomial& operator-=(const Polynomial &x){
		if((*this).size()<x.size())(*this).resize(x.size());
		for(int i=0;i<x.size();i++)(*this).operator[](i)-=x[i];
		return *this;
	}
	Polynomial& operator*=(const Polynomial &x){
		if((*this).size()==0||x.size()==0){
			(*this).clear();
			return *this;
		}
		Polynomial z((*this).size()+x.size()-1);
		for(int i=0;i<(*this).size();i++){
			for(int j=0;j<x.size();j++){
				z[i+j]+=(*this).operator[](i)*x[j];
			}
		}
		return *this=z;
	}
	Polynomial& operator+=(const T &x){
		if((*this).size()==0)(*this).resize(1);
		(*this).operator[](0)+=x;
		return *this;
	}
	Polynomial& operator-=(const T &x){
		if((*this).size()==0)(*this).resize(1);
		(*this).operator[](0)-=x;
		return *this;
	}
	Polynomial& operator*=(const T &x){
		for(int i=0;i<(*this).size();i++)(*this).operator[](i)*=x;
		return *this;
	}
	Polynomial& operator/=(const T &x){
		for(int i=0;i<(*this).size();i++)(*this).operator[](i)/=x;
		return *this;
	}
	
	Polynomial operator+(const Polynomial &x)const{
		return Polynomial(*this)+=x;
	}
	Polynomial operator-(const Polynomial &x)const{
		return Polynomial(*this)-=x;
	}
	Polynomial operator*(const Polynomial &x)const{
		return Polynomial(*this)*=x;
	}
	Polynomial operator+(const T &x)const{
		return Polynomial(*this)+=x;
	}
	Polynomial operator-(const T &x)const{
		return Polynomial(*this)-=x;
	}
	Polynomial operator*(const T &x)const{
		return Polynomial(*this)*=x;
	}
	Polynomial operator/(const T &x)const{
		return Polynomial(*this)/=x;
	}
	
	T eval(T x){
		T ret=0;
		T powX=1;
		for(int i=0;i<(*this).size();i++){
			ret+=(*this).operator[](i)*powX;
			powX*=x;
		}
		return ret;
	}
};
template<class T>
Polynomial<T>simpleInterpolate(vector<T>x,vector<T>y){
	Polynomial<T>ret;
	for(int i=0;i<x.size();i++){
		Polynomial<T>prod={1};
		T div=1;
		for(int j=0;j<x.size();j++)if(i!=j){
			div*=x[i]-x[j];
			Polynomial<T>tmp={-x[j],1};
			prod*=tmp;
		}
		ret+=prod*y[i]/div;
	}
	return ret;
}

using poly=Polynomial<mint>;




int N,T;
int X[55],Y[55];

mint calcNumCovered(int t){
	vint ys;
	rep(i,N){
		ys.pb(Y[i]-t);
		ys.pb(Y[i]+t+1);
	}
	sort(all(ys));
	ys.erase(unique(all(ys)),ys.end());

	vector<pint>qs;
	rep(i,N){
		qs.pb({X[i]-t,i*2});
		qs.pb({X[i]+t+1,i*2+1});
	}
	sort(all(qs));
	int lastX=0;
	
	mint ret=0;
	vint num(ys.size());
	rep(i,qs.size()){
		int x=qs[i].fi;
		int k=qs[i].se/2;
		
		int sum=0;
		for(int j=0;j+1<ys.size();j++)if(num[j])sum+=ys[j+1]-ys[j];
		ret+=mint(sum)*(x-lastX);
		lastX=x;

		int l=lower_bound(all(ys),Y[k]-t)-ys.begin();
		int r=lower_bound(all(ys),Y[k]+t+1)-ys.begin();
		int coef;
		if(qs[i].se&1)coef=-1;
		else coef=1;
		for(int j=l;j<r;j++)num[j]+=coef;
	}
	return ret;
}


signed main(){
	cin>>N>>T;
	rep(i,N)cin>>X[i]>>Y[i];

	mint ans;

	vint ts;
	for(int i=0;i<N;i++){
		for(int j=i+1;j<N;j++){
			int ma=max(abs(X[i]-X[j]),abs(Y[i]-Y[j]));
			ma=(ma+1)/2;
			if(ma>T)continue;
			ts.pb(ma);
		}
	}
	ts.pb(0);ts.pb(T);
	sort(all(ts));ts.erase(unique(all(ts)),ts.end());

	for(int i=0;i+1<ts.size();i++){
		int l=ts[i];
		int r=ts[i+1];

		vector<mint>x(4),y(4);
		x[0]=l-1;
		y[0]=0;

		for(int i=1;i<4;i++){
			x[i]=l+i-1;
			y[i]=y[i-1]+calcNumCovered(l+i-1);
		}
		poly p=simpleInterpolate(x,y);
		ans-=p.eval(r-1);
	}

	ans+=calcNumCovered(T)*T;
	cout<<ans<<endl;
}