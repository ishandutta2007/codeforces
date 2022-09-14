#line 1 "a.cpp"
#include<iostream>
using namespace std;
#line 3 "/home/kotatsugame/library/math/modint.cpp"
#include<utility>
template<int m>
struct modint{
	unsigned int x;
	constexpr modint()noexcept:x(){}
	template<typename T>
	constexpr modint(T x_)noexcept:x((x_%=m)<0?x_+m:x_){}
	constexpr unsigned int val()const noexcept{return x;}
	constexpr modint&operator++()noexcept{if(++x==m)x=0;return*this;}
	constexpr modint&operator--()noexcept{if(x==0)x=m;--x;return*this;}
	constexpr modint operator++(int)noexcept{modint res=*this;++*this;return res;}
	constexpr modint operator--(int)noexcept{modint res=*this;--*this;return res;}
	constexpr modint&operator+=(const modint&a)noexcept{x+=a.x;if(x>=m)x-=m;return*this;}
	constexpr modint&operator-=(const modint&a)noexcept{if(x<a.x)x+=m;x-=a.x;return*this;}
	constexpr modint&operator*=(const modint&a)noexcept{x=(unsigned long long)x*a.x%m;return*this;}
	constexpr modint&operator/=(const modint&a)noexcept{return*this*=a.inv();}
	constexpr modint operator+()const noexcept{return*this;}
	constexpr modint operator-()const noexcept{return modint()-*this;}
	constexpr modint pow(long long n)const noexcept
	{
		if(n<0)return pow(-n).inv();
		modint x=*this,r=1;
		for(;n;x*=x,n>>=1)if(n&1)r*=x;
		return r;
	}
	constexpr modint inv()const noexcept
	{
		int s=x,t=m,x=1,u=0;
		while(t)
		{
			int k=s/t;
			s-=k*t;
			swap(s,t);
			x-=k*u;
			swap(x,u);
		}
		return modint(x);
	}
	friend constexpr modint operator+(const modint&a,const modint&b){return modint(a)+=b;}
	friend constexpr modint operator-(const modint&a,const modint&b){return modint(a)-=b;}
	friend constexpr modint operator*(const modint&a,const modint&b){return modint(a)*=b;}
	friend constexpr modint operator/(const modint&a,const modint&b){return modint(a)/=b;}
	friend constexpr bool operator==(const modint&a,const modint&b){return a.x==b.x;}
	friend constexpr bool operator!=(const modint&a,const modint&b){return a.x!=b.x;}
	friend ostream&operator<<(ostream&os,const modint&a){return os<<a.x;}
	friend istream&operator>>(istream&is,modint&a){long long v;is>>v;a=modint(v);return is;}
};
#line 1 "/home/kotatsugame/library/math/matrix.cpp"
#include<vector>
#include<cassert>
template<typename T>
struct Matrix{
	vector<vector<T> >dat;
	int N,M;//N x M matrix
	Matrix(){}
	Matrix(int N_):Matrix(N_,N_){}
	Matrix(int N_,int M_):N(N_),M(M_),dat(N_,vector<T>(M_)){}
	vector<T>&operator[](int i){return dat[i];}
	const vector<T>&operator[](int i)const{return dat[i];}
	static Matrix eye(int N)
	{
		Matrix res(N);
		for(int i=0;i<N;i++)res[i][i]=1;
		return res;
	}
	Matrix operator+(const Matrix&A)const
	{
		assert(N==A.N&&M==A.M);
		Matrix res(N,M);
		for(int i=0;i<N;i++)for(int j=0;j<M;j++)
			res[i][j]=dat[i][j]+A[i][j];
		return res;
	}
	Matrix operator-(const Matrix&A)const
	{
		assert(N==A.N&&M==A.M);
		Matrix res(N,M);
		for(int i=0;i<N;i++)for(int j=0;j<M;j++)
			res[i][j]=dat[i][j]-A[i][j];
		return res;
	}
	Matrix operator*(const Matrix&A)const
	{
		assert(M==A.N);
		Matrix res(N,A.M);
		for(int i=0;i<N;i++)for(int j=0;j<A.M;j++)for(int k=0;k<M;k++)
			res[i][j]+=dat[i][k]*A[k][j];
		return res;
	}
	Matrix pow(long long n)const
	{
		assert(N==M);
		Matrix a=*this,res=eye(N);
		for(;n;a=a*a,n>>=1)if(n&1)res=res*a;
		return res;
	}
	template<typename U>
	Matrix operator+(const U&A)const
	{
		Matrix res(N,M);
		for(int i=0;i<N;i++)for(int j=0;j<M;j++)
			res[i][j]=dat[i][j]+A;
		return res;
	}
	template<typename U>
	Matrix operator-(const U&A)const
	{
		Matrix res(N,M);
		for(int i=0;i<N;i++)for(int j=0;j<M;j++)
			res[i][j]=dat[i][j]-A;
		return res;
	}
	template<typename U>
	Matrix operator*(const U&A)const
	{
		Matrix res(N,M);
		for(int i=0;i<N;i++)for(int j=0;j<M;j++)
			res[i][j]=dat[i][j]*A;
		return res;
	}
	T det()const
	{
		assert(N==M);
		Matrix A=*this;
		T ret=1;
		for(int j=0;j<N;j++)
		{
			int id=-1;
			for(int i=j;i<N;i++)
			{
				if(A[i][j]!=0)
				{
					id=i;
					break;
				}
			}
			if(id==-1)return T(0);
			if(id!=j)
			{
				A[j].swap(A[id]);
				ret=-ret;
			}
			ret*=A[j][j];
			{
				const T a=1/A[j][j];
				for(int k=j+1;k<N;k++)A[j][k]*=a;
			}
			for(int i=j+1;i<N;i++)
			{
				const T a=A[i][j];
				for(int k=j+1;k<N;k++)A[i][k]-=A[j][k]*a;
			}
		}
		return ret;
	}
	int elimination()
	{
		int ret=0;
		for(int j=0;j<M;j++)
		{
			int id=-1;
			for(int i=ret;i<N;i++)
			{
				if(dat[i][j]!=0)
				{
					id=i;
					break;
				}
			}
			if(id==-1)continue;
			if(id!=ret)dat[ret].swap(dat[id]);
			{
				const T a=1/dat[ret][j];
				for(int k=j;k<M;k++)dat[ret][k]*=a;
			}
			for(int i=0;i<N;i++)
			{
				if(i==ret)continue;
				const T a=dat[i][j];
				for(int k=j;k<M;k++)dat[i][k]-=dat[ret][k]*a;
			}
			ret++;
		}
		return ret;
	}
};
#line 5 "a.cpp"
using mint=modint<(int)1e9+7>;
using mat=Matrix<mint>;
int N;
long long K;
long long A[100];
main()
{
	cin>>N>>K;
	for(int i=0;i<N;i++)cin>>A[i];
	mat X(N,N);
	for(int i=0;i<N;i++)for(int j=0;j<N;j++)if(__builtin_popcountll(A[i]^A[j])%3==0)X[i][j]=1;
	X=X.pow(K-1);
	mint ans=0;
	for(int i=0;i<N;i++)for(int j=0;j<N;j++)ans+=X[i][j];
	cout<<ans<<endl;
}