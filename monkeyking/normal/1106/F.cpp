//Original Code:
//#define __TAKE_CONST_MOD 998244353
//#include <self/utility>
//#include <self/debug>
//#include <self/ModInt>
//#include <self/matrix>
//#include <self/factorization>
//using namespace std;
//const int g=3;
//const int B=3e5;
//const int B2=mod/B+1;
//const int hmod=1500041;
//int k;
//int b[105];
//int n,m;
//using Int=ModInt<mod>;
//using Mat=Matrix<ModInt<mod-1> >;
//int hkey[B+5],hval[B+5];
//int cnt;
//int st[hmod+5];
//int nxt[B+5];
//
//inline int fastpow(ll basic,int x)
//{
//	ll res=1;
//	while(x)
//	{
//		if(x&1) (res*=basic)%=mod;
//		(basic*=basic)%=mod;
//		x>>=1;
//	}
//	return res;
//}
//
//int find(int x)
//{
//	int t=x%hmod;
//	for(int i=st[t];i;i=nxt[i])
//	{
//		if(hkey[i]==x) return hval[i];
//	}
//	return -1;
//}
//
//void insert(int x,int v)
//{
//	if(find(x)!=-1) return;
//	int t=x%hmod;
//	hkey[cnt]=x;
//	hval[cnt]=v;
//	nxt[cnt]=st[t];
//	st[t]=cnt;
//	cnt++;
//}
//
//int getLog(int x)
//{
//	int ig=fastpow(g,mod-2);
//	int res=inf;
//	for(int i=0;i<=B2;i++)
//	{
//		int v=find(x);
//		if(v!=-1) chmin(res,v+i);
//		x=1LL*x*ig%mod;
//	}
//	assert(res!=inf);
//	return res;
//}
//
//inline int fastpow(ll basic,int x,int mod)
//{
//	ll res=1;
//	while(x)
//	{
//		if(x&1) (res*=basic)%=mod;
//		(basic*=basic)%=mod;
//		x>>=1;
//	}
//	return res;
//}
//
//Factorization fac;
//int solveEq(int a,int b,int mod)
//{
//	int g=__gcd(a,mod);
//	if(b%g!=0) over("-1");
//	a/=g,b/=g,mod/=g;
//
//	int phi=1;
//	vector<pii> d=fac.factorize(mod);
//	for(auto [p,e]:d)
//	{
//		phi*=(p-1)*fastpow(p,e-1);
//	}
//	return 1LL*b*fastpow(a,phi-1,mod)%mod;
//}
//
//int main()
//{
//	// freopen("input.txt","r",stdin);
//	cin>>k;
//	for(int i=0;i<k;i++) cin>>b[i];
//	cin>>n>>m;
//
//	cnt=1;
//	int gg=fastpow(g,B2);
//	int now=1;
//	for(int i=0;i<=B;i++)
//	{
//		insert(now,i*B2);
//		now=1LL*now*gg%mod;
//	}
//
//	m=getLog(m);
//
//	Mat mat(k,k);
//	for(int i=0;i<k;i++)
//	{
//		for(int j=0;j<k;j++)
//		{
//			if(i==0) mat[i][j]=b[j];
//			else if(j==i-1) mat[i][j]=1;
//		}
//	}
//	mat=fastpow(mat,n-k);
//
//	int x=solveEq(mat[0][0].x,m,mod-1);
//	cout<<fastpow(g,x)<<endl;
//
//	return 0;
//}

//substituted with C++ Inliner
#define __TAKE_CONST_MOD 998244353
#ifndef _SELF_UTILITY
#define _SELF_UTILITY 1
#include <numeric>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <string.h>
#include <stack>
#include <assert.h>
#include <bitset>
#include <time.h>
#define Endl endl
#define mp make_pair
#define mt make_tuple
#define ll long long 
#define ull unsigned long long
#define pii pair<int,int>
#define over(A) {cout<<A<<endl;exit(0);}
#define all(A) A.begin(),A.end()
#define quickcin ios_base::sync_with_stdio(false);
#ifdef __TAKE_MOD
int mod;
#else
#ifdef __TAKE_CONST_MOD
const int mod=__TAKE_CONST_MOD;
#else
const int mod=1000000007;
#endif
#endif
const int gmod=3;
const int inf=1039074182;
const double eps=1e-9;
const ll llinf=2LL*inf*inf;
template <typename T1,typename T2> inline void chmin(T1 &x,T2 b) {if(b<x) x=b;}
template <typename T1,typename T2> inline void chmax(T1 &x,T2 b) {if(b>x) x=b;}
inline void chadd(int &x,int b) {x+=b-mod;x+=(x>>31 & mod);}
template <typename T1,typename T2> inline void chadd(T1 &x,T2 b) {x+=b;if(x>=mod) x-=mod;}
template <typename T1,typename T2> inline void chmul(T1 &x,T2 b) {x=1LL*x*b%mod;}
template <typename T1,typename T2> inline void chmod(T1 &x,T2 b) {x%=b,x+=b;if(x>=b) x-=b;}
template <typename T> inline T mabs(T x) {return (x<0?-x:x);}
using namespace std;
#endif
#ifndef _SELF_DEBUG
#define _SELF_DEBUG 1
#ifndef _SELF_OPERATOR
#define _SELF_OPERATOR 1
using namespace std;
template <typename T>
ostream &operator<<(ostream &cout, vector<T> vec)
{
	cout << "{";
	for (int i = 0; i < (int)vec.size(); i++)
	{
		cout << vec[i];
		if (i != (int)vec.size() - 1)
			cout << ',';
	}
	cout << "}";
	return cout;
}

template <typename T1, typename T2>
ostream &operator<<(ostream &cout, pair<T1, T2> p)
{
	cout << "(" << p.first << ',' << p.second << ")";
	return cout;
}

template <typename T, typename T2>
ostream &operator<<(ostream &cout, set<T, T2> s)
{
	vector<T> t;
	for (auto x : s)
		t.push_back(x);
	cout << t;
	return cout;
}

template <typename T, typename T2>
ostream &operator<<(ostream &cout, multiset<T, T2> s)
{
	vector<T> t;
	for (auto x : s)
		t.push_back(x);
	cout << t;
	return cout;
}

template <typename T>
ostream &operator<<(ostream &cout, queue<T> q)
{
	vector<T> t;
	while (q.size())
	{
		t.push_back(q.front());
		q.pop();
	}
	cout << t;
	return cout;
}

template <typename T1, typename T2, typename T3>
ostream &operator<<(ostream &cout, map<T1, T2, T3> m)
{
	for (auto &x : m)
	{
		cout << "Key: " << x.first << ' ' << "Value: " << x.second << endl;
	}
	return cout;
}

template <typename T1, typename T2>
void operator+=(pair<T1, T2> &x,const pair<T1, T2> y)
{
	x.first += y.first;
	x.second += y.second;
}
template <typename T1,typename T2>
pair<T1,T2> operator + (const pair<T1,T2> &x,const pair<T1,T2> &y)
{
	return make_pair(x.first+y.first,x.second+y.second);
}

template <typename T1,typename T2>
pair<T1,T2> operator - (const pair<T1,T2> &x,const pair<T1,T2> &y)
{
	return mp(x.first-y.first,x.second-y.second);
}

template <typename T1, typename T2>
pair<T1, T2> operator-(pair<T1, T2> x)
{
	return make_pair(-x.first, -x.second);
}

template <typename T>
vector<vector<T>> operator~(vector<vector<T>> vec)
{
	vector<vector<T>> v;
	int n = vec.size(), m = vec[0].size();
	v.resize(m);
	for (int i = 0; i < m; i++)
	{
		v[i].resize(n);
	}
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			v[i][j] = vec[j][i];
		}
	}
	return v;
}
#endif
#include <sstream>
void print0x(int x)
{
	std::vector <int> vec;
	while(x)
	{
		vec.push_back(x&1);
		x>>=1;
	}
	std::reverse(vec.begin(),vec.end());
	for(int i=0;i<(int)vec.size();i++)
	{
		std::cout<<vec[i];
	}
	std::cout<<' ';
}

template <typename T>
void print0x(T x,int len)
{
	std::vector <int> vec;
	while(x)
	{
		vec.push_back(x&1);
		x>>=1;
	}
	reverse(vec.begin(),vec.end());
	for(int i=(int)vec.size();i<len;i++)
	{
		putchar('0');
	}
	for(size_t i=0;i<vec.size();i++)
	{
		std::cout<<vec[i];
	}
	std::cout<<' ';
}
vector<string> vec_splitter(string s) {
	s += ',';
	vector<string> res;
	while(!s.empty()) {
		res.push_back(s.substr(0, s.find(',')));
		s = s.substr(s.find(',') + 1);
	}
	return res;
}
void debug_out(
vector<string> __attribute__ ((unused)) args,
__attribute__ ((unused)) int idx, 
__attribute__ ((unused)) int LINE_NUM) { cerr << endl; } 
template <typename Head, typename... Tail>
void debug_out(vector<string> args, int idx, int LINE_NUM, Head H, Tail... T) {
	if(idx > 0) cerr << ", "; else cerr << "Line(" << LINE_NUM << ") ";
	stringstream ss; ss << H;
	cerr << args[idx] << " = " << ss.str();
	debug_out(args, idx + 1, LINE_NUM, T...);
}
#define debug(...) debug_out(vec_splitter(#__VA_ARGS__), 0, __LINE__, __VA_ARGS__)
#endif
#ifndef SELF_MODINT
#define SELF_MODINT 1
template <int mod>
struct ModInt
{
	int x;
	ModInt(){x=0;}
	ModInt(int _x){x=_x%mod;if(x<0) x+=mod;}
	ModInt(ll _x){x=_x%mod;if(x<0) x+=mod;}
	ModInt <mod>& operator ++()// prefix
	{
		++x;
		if(x==mod) x=0;
		return *this;
	}
	ModInt <mod> operator ++(int)
	{
		int t=x;
		x++;
		if(x==mod) x=0;
		return t;
	}
	ModInt <mod>& operator --()// prefix
	{
		--x;
		if(x==-1) x+=mod;
		return *this;
	}
	ModInt <mod> operator --(int)
	{
		int t=x;
		x--;
		if(x==-1) x+=mod;
		return t;
	}
	ModInt <mod> operator -()const
	{
		return ModInt <mod>((x==0?0:mod-x));
	}
};

template <int mod>
inline int mabs(const ModInt <mod> &a)
{
	return a.x;
}

template <int mod>
bool operator == (const ModInt <mod> &a,const ModInt <mod> &b)
{
	return a.x==b.x;
}

template <int mod>
bool operator == (ModInt <mod> a,int x)
{
	return (a.x==x);
}

template <int mod>
bool operator != (const ModInt <mod> &a,const ModInt <mod> &b)
{
	return (a.x!=b.x);
}

template <int mod>
bool operator != (ModInt <mod> a,int x)
{
	return (a.x!=x);
}

template <int mod>
inline ModInt <mod> operator + (ModInt <mod> a,int b)
{
	a.x+=b;
	if(a.x>=mod) a.x-=mod;
	return a;
}

template <int mod>
inline ModInt <mod> operator + (ModInt <mod> a,ModInt <mod> b)
{
	int tmp=a.x+b.x;
	if(tmp>=mod) tmp-=mod;
	return tmp;
}

template <int mod>
inline ModInt <mod> operator - (ModInt <mod> a,ModInt <mod> b)
{
	int tmp=a.x-b.x;
	if(tmp<0) tmp+=mod;
	return tmp;
}

template <int mod>
inline ModInt <mod> operator - (ModInt <mod> a,int b)
{
	return a-(ModInt <mod> )b;
}

template <int mod>
inline void operator -= (ModInt <mod> &a,ModInt <mod> b)
{
	a.x-=b.x;
	a.x+=(a.x>>31&mod);
}

template <int mod,typename T>
inline void operator -= (ModInt <mod> &a,const T &b)
{
	a.x-=b;
	a.x+=(a.x>>31&mod);
}

template <int mod>
inline ModInt <mod> operator * (const ModInt <mod> &a,const ModInt <mod> &b)
{
	return 1LL*a.x*b.x%mod;
}

template <int mod>
inline ModInt <mod> operator * (const ModInt <mod> &a,const int &b)
{
	return 1LL*a.x*b%mod;
}

template <int mod>
inline void operator *= (ModInt <mod> &a,const ModInt <mod> &b)
{
	a.x=1LL*a.x*b.x%mod;
}

template <int mod,typename T>
inline void operator *= (ModInt <mod> &a,const T &b)
{
	a=a*b;
}

template <int mod>
inline void operator += (ModInt <mod> &a,const ModInt <mod> &b)
{
	a.x+=b.x;
	if(a.x>=mod) a.x-=mod;
}

template <int mod,typename T>
void operator +=(ModInt <mod> &a,const T &b)
{
	a.x+=b;
	if(a.x>=mod) a.x-=mod;
}

template <int mod>
inline ModInt <mod> mod_inv(ModInt <mod> x)
{
	int m=mod-2;
	ModInt <mod> basic=x;
	x=1;
	while(m)
	{
		if(m&1) x*=basic;
		m>>=1;
		basic*=basic;
	}
	return x;
}

template <int mod>
ModInt <mod> operator / (ModInt <mod> a,ModInt <mod> b)
{
	return a*mod_inv(b);
}

template <int mod>
ModInt <mod> operator / (ModInt <mod> a,int b)
{
	return a*mod_inv((ModInt <mod>)b);
}

template <int mod>
void operator /= (ModInt <mod> &a,int b)
{
	a*=mod_inv(ModInt <mod> (b));
}

template <int mod>
void operator /= (ModInt <mod> &a,ModInt <mod> b)
{
	a=a/b;
}

template <int mod>
inline ModInt <mod> operator ^ (ModInt <mod> basic,int x)
{
	ModInt <mod> res=1;
	while(x)
	{
		if(x&1)	res*=basic;
		basic*=basic;
		x>>=1;
	}
	return res;
}

template <int mod>
istream & operator >> (istream &cin,ModInt <mod> &x)
{
	cin>>x.x;
	x.x%=mod;
	if(x.x<0) x.x+=mod;
	return cin;
}

template <int mod>
ostream & operator << (ostream &cout,ModInt <mod> x)
{
	cout<<x.x;
	return cout;
}
#endif
namespace MATRIX
{
	template <typename T>
	struct Matrix
	{
		vector <vector<T> > a;
		int row;
		int column;
		bool initialized=false;
		Matrix(){}
		Matrix(int n,int m){row=n;column=m;initialized=true;a.resize(n,vector <T> (m,T(0)));}
		Matrix(vector <vector <T> > _a){a=_a;row=a.size();if(row==0) throw domain_error("wrong argument n=0");column=a[0].size();initialized=true;}
		vector <T> & operator [](int x)
		{
			return a[x];
		}
		const vector <T> & operator [](int x)const
		{
			return a[x];
		}
		void init(int n,int m)
		{
			initialized=true;
			row=n;
			column=m;
			a.resize(n);
			for(int i=0;i<n;i++)
			{
				a[i].resize(m);
			}
			clear();
		}
		void clear()
		{
			if(!initialized)
			{
				throw runtime_error("clearing a matrix while not having initialized it");
			}
			for(int i=0;i<row;i++)
			{
				for(int j=0;j<column;j++)
				{
					a[i][j]=0;
				}
			}
		}
		void E()
		{
			clear();
			if(row!=column)
			{
				throw logic_error("Matrix E not satisfying Column(A)=Row(B)");
			}
			for(int i=0;i<row;i++)
			{
				a[i][i]=1;
			}
		}
		void print(bool format=true)const&
		{
			if(!initialized)
			{
				throw runtime_error("printing a matrix while not having initialized it");
			}
			if(!format)
			{
				cout<<a<<endl;
				return;
			}
			cout<<"Matrix: \n";
			for(int i=0;i<row;i++)
			{
				for(int j=0;j<column;j++)
				{
					cout<<a[i][j]<<' ';
				}
				cout<<endl;
			}
			cout<<endl;
		}
		inline void getMul(const Matrix <T> &x,const Matrix <T> &y)
		{
			for(int i=0;i<row;i++)
			{
				for(int j=0;j<column;j++)
				{
					a[i][j]=0;
				}
			}
			for(int i=0;i<row;i++)
			{
				for(int k=0;k<x.column;k++)
				{
					for(int j=0;j<column;j++)
					{
						a[i][j]+=x.a[i][k]*y.a[k][j];
					}
				}
			}
		}
		inline Matrix <T> inv()
		{
			Matrix <T> mat=(*this);
			invert(mat);
			return mat;
		}
		inline Matrix <T> triangle()
		{
			Matrix <T> mat=(*this);
			triangular(mat);
			return mat;
		}
	};

	template <typename T>
	ostream & operator << (ostream &cout,Matrix <T> mat)
	{
		cout<<mat.a;
		return cout;
	}

	template <typename T>
	inline Matrix <T> operator * (const Matrix <T> &a,const Matrix <T> &b)
	{
		int n=a.row;
		int m=b.column;
		if(a.column!=b.row)
		{
			throw logic_error("Matrix multipication A*B not satisfying Column(A)=Row(B)");
		}
		int l=a.column;
		Matrix <T> res;
		res.init(n,m);
		for(int i=0;i<n;i++)
		{
			for(int k=0;k<l;k++)
			{
				for(int j=0;j<m;j++)
				{
					res.a[i][j]+=(a[i][k]*b[k][j]);
				}
			}
		}
		return res;
	}

	template <typename T>
	inline void operator *=(Matrix <T> &a,Matrix <T> b)
	{
		a=a*b;
	}

	template <typename T>
	inline Matrix <T> fastpow(Matrix <T> basic,ll n)
	{
		if(basic.row!=basic.column) throw logic_error("calculating A^n while A is not a n*n format matrix");
		Matrix <T> res;
		res.init(basic.row,basic.row);
		res.E();
		while(n)
		{
			if(n&1) res=res*basic;
			basic=basic*basic;
			n>>=1;
		}
		return res;
	}

	template <typename T>
	inline void triangular(Matrix <T> &mat,int useM=-1)
	{
		int n=mat.row;
		int m=mat.column;
		if(useM==-1) useM=m;
		vector <int> where(n,-1);
		for(int col=0,row=0;col<useM;col++)
		{
			int sel=row;
			for(int i=row+1;i<n;i++)
			{
				if(mabs(mat[i][col])>mabs(mat[sel][col])) sel=i;
			}
			if(mat[sel][col]==0) continue;
			for(int j=col;j<m;j++)
			{
				swap(mat[row][j],mat[sel][j]);
			}
			T multiplier=T(1)/mat[row][col];
			for(int j=col;j<m;j++)
			{
				mat[row][j]*=multiplier;
			}
			for(int i=row+1;i<n;i++)
			{
				if(mat[i][col]==0) continue;
				for(int j=m-1;j>=col;j--)
				{
					mat[i][j]-=mat[i][col]*mat[row][j];
				}
			}
			where[row]=col;
			row++;
		}
		for(int row=n-1;row>=0;row--)
		{
			if(where[row]==-1) continue;
			int col=where[row];
			assert(mat[row][col]==1);
			for(int i=0;i<row;i++)
			{
				for(int j=m-1;j>=col;j--)
				{
					mat[i][j]-=mat[row][j]*mat[i][col];
				}
			}
		}
	}

	template <typename T>
	inline bool invert(Matrix <T> &mat)
	{
		if(mat.row!=mat.column) return false;
		int n=mat.row;
		Matrix <T> extendedMat(n,n+n);
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				extendedMat[i][j]=mat[i][j];
			}
			extendedMat[i][n+i]=1;
		}
		triangular(extendedMat,n);
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				if((i==j && extendedMat[i][j]!=1) || (i!=j && extendedMat[i][j]!=0)) return false;
			}
		}
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				mat[i][j]=extendedMat[i][j+n];
			}
		}
		return true;
	}
}
using MATRIX::Matrix;
using namespace std;
class Factorization
{
	public:
	vector <int> primes;
	bool *isprime;
	int n;
	void initPrimeList(int _n)
	{
		n=_n;
		isprime=new bool[n+5];
		for(int i=0;i<=n;i++)
		{
			isprime[i]=true;
		}
		isprime[0]=isprime[1]=false;
		for(int i=2;i<=n;i++)
		{
			if(isprime[i]) primes.push_back(i);
			for(auto &j:primes)
			{
				if(i*j>n) break;
				isprime[i*j]=false;
				if(i%j==0) break;
			}
		}
	}
	int getPrimeID(int p)
	{
		return lower_bound(primes.begin(),primes.end(),p)-primes.begin();
	}
	template <typename T>
	inline vector <T> getfactors(T x)
	{
		vector <T> vec;
		for(T i=1;i*i<=x;i++)
		{
			if(x%i==0)
			{
				vec.push_back(i);
				if(i!=x/i) vec.push_back(x/i);
			}
		}
		sort(vec.begin(),vec.end());
		return vec;
	}
	inline vector <pair<int,int> > factorizeFast(int x)
	{
		vector <pair<int,int> > vec;
		int nx=x;
		for(auto i:primes)
		{
			if(i*i>x) break;
			if(nx%i==0)
			{
				int s=0;
				while(nx%i==0)
				{
					s++;
					nx/=i;
				}
				vec.push_back(make_pair(i,s));
			}
		}
		if(nx!=1) vec.push_back(make_pair(nx,1));
		return vec;
	}
	inline vector <pair<int,int> > factorize(int x)
	{
		vector <pair<int,int> > vec;
		int nx=x;
		for(int i=2;i*i<=x;i++)
		{
			if(nx%i==0)
			{
				int s=0;
				while(nx%i==0)
				{
					s++;
					nx/=i;
				}
				vec.push_back(make_pair(i,s));
			}
		}
		if(nx!=1) vec.push_back(make_pair(nx,1));
		return vec;
	}
	inline vector <int> factorizeflat(int x)
	{
		vector <int> vec;
		int nx=x;
		for(int i=2;i*i<=x;i++)
		{
			if(nx%i==0)
			{
				int s=0;
				while(nx%i==0)
				{
					s++;
					nx/=i;
					vec.push_back(i);
				}
			}
		}
		if(nx!=1) vec.push_back(nx);
		return vec;
	}
	template <typename T>
	inline bool checkPrime(T x)
	{
		for(T i=2;i*i<=x;i++)
		{
			if(x%i==0) return false;
		}
		return true;
	}
};
using namespace std;
const int g=3;
const int B=3e5;
const int B2=mod/B+1;
const int hmod=1500041;
int k;
int b[105];
int n,m;
using Int=ModInt<mod>;
using Mat=Matrix<ModInt<mod-1> >;
int hkey[B+5],hval[B+5];
int cnt;
int st[hmod+5];
int nxt[B+5];

inline int fastpow(ll basic,int x)
{
	ll res=1;
	while(x)
	{
		if(x&1) (res*=basic)%=mod;
		(basic*=basic)%=mod;
		x>>=1;
	}
	return res;
}

int find(int x)
{
	int t=x%hmod;
	for(int i=st[t];i;i=nxt[i])
	{
		if(hkey[i]==x) return hval[i];
	}
	return -1;
}

void insert(int x,int v)
{
	if(find(x)!=-1) return;
	int t=x%hmod;
	hkey[cnt]=x;
	hval[cnt]=v;
	nxt[cnt]=st[t];
	st[t]=cnt;
	cnt++;
}

int getLog(int x)
{
	int ig=fastpow(g,mod-2);
	int res=inf;
	for(int i=0;i<=B2;i++)
	{
		int v=find(x);
		if(v!=-1) chmin(res,v+i);
		x=1LL*x*ig%mod;
	}
	assert(res!=inf);
	return res;
}

inline int fastpow(ll basic,int x,int mod)
{
	ll res=1;
	while(x)
	{
		if(x&1) (res*=basic)%=mod;
		(basic*=basic)%=mod;
		x>>=1;
	}
	return res;
}

Factorization fac;
int solveEq(int a,int b,int mod)
{
	int g=__gcd(a,mod);
	if(b%g!=0) over("-1");
	a/=g,b/=g,mod/=g;

	int phi=1;
	vector<pii> d=fac.factorize(mod);
	for(auto [p,e]:d)
	{
		phi*=(p-1)*fastpow(p,e-1);
	}
	return 1LL*b*fastpow(a,phi-1,mod)%mod;
}

int main()
{
//	// freopen("input.txt","r",stdin);
	cin>>k;
	for(int i=0;i<k;i++) cin>>b[i];
	cin>>n>>m;

	cnt=1;
	int gg=fastpow(g,B2);
	int now=1;
	for(int i=0;i<=B;i++)
	{
		insert(now,i*B2);
		now=1LL*now*gg%mod;
	}

	m=getLog(m);

	Mat mat(k,k);
	for(int i=0;i<k;i++)
	{
		for(int j=0;j<k;j++)
		{
			if(i==0) mat[i][j]=b[j];
			else if(j==i-1) mat[i][j]=1;
		}
	}
	mat=fastpow(mat,n-k);

	int x=solveEq(mat[0][0].x,m,mod-1);
	cout<<fastpow(g,x)<<endl;

	return 0;
}