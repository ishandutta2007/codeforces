#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<ctime>
#include<cmath>
#include<iostream>
#include<sstream>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<bitset>
#include<string>
#include<queue>
#include<iomanip>
#include<limits>
#include<typeinfo>
#include<functional>
#include<numeric>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<ld,ld> pdd;

#define X first
#define Y second

namespace cheat
{
	template<int LIMIT> class reader //LIMIT is the length of the buffer
	{
		private:
			int n;
			char *s;
		public:
			reader()
			{
				n=0;
				s=new char[LIMIT+1];
			}
			void init()
			{
				fread(s,1,LIMIT,stdin);
			}
			int read_int()
			{
				int x=0;
				for (;!isdigit(s[n]);++n);
				for (;isdigit(s[n]);x=x*10+s[n++]-'0');
				return x;
			}
			int read_signed_int()
			{
				for (;!isdigit(s[n])&&s[n]!='-';++n);
				return (s[n]=='-')?-read_int():read_int();
			}
			ll read_ll()
			{
				ll x=0;
				for (;!isdigit(s[n]);++n);
				for (;isdigit(s[n]);x=x*10+s[n++]-'0');
				return x;
			}
			ll read_signed_ll()
			{
				for (;!isdigit(s[n])&&s[n]!='-';++n);
				return (s[n]=='-')?-read_ll():read_ll();
			}
			char read_char()
			{
				return s[n++];
			}
	};
	template<int LIMIT> class writer
	{
		private:
			int n;
			char *s;
			template<class T> void dfs_int(T x)
			{
				if (!x) return;
				dfs_int(x/10);
				s[n++]=x%10+'0';
			}
		public:
			writer ()
			{
				n=0;
				s=new char[LIMIT+1];
			}
			void print()
			{
				while (s[n-1]<32||s[n-1]>127) --n;
				s[n]=0;
				puts(s);
			}
			void writeln()
			{
				s[n++]='\n';
			}
			void write_space()
			{
				s[n++]=' ';
			}
			void write_char(char x)
			{
				s[n++]=x;
			}
			void write_string(char *t)
			{
				for (int i=0;t[i];++i)
					s[n++]=t[i];
			}
			void writeln_string(char *t)
			{
				write_string(t);
				writeln();
			}
			template<class T> void write_int(T x)
			{
				if (x==0)
				{
					s[n++]='0';
					return;
				}
				dfs_int(x);
			}
			template<class T> void writeln_int(T x)
			{
				write_int(x);
				writeln();
			}
			template<class T> void write_int_space(T x)
			{
				write_int(x);
				write_space();
			}
			template<class T> void write_signed_int(T x)
			{
				if (x<0)
				{
					x=-x;
					s[n++]='-';
				}
				write_int(x);
			}
			template<class T> void writeln_signed_int(T x)
			{
				write_signed_int(x);
				writeln();
			}
			template<class T> void write_signed_int_space(T x)
			{
				write_signed_int(x);
				write_space();
			}
	};
}

namespace algorithm
{
	namespace math
	{
		template<class T> T gcd(T a,T b)
		{
			return (!b)?a:gcd(b,a%b);
		}
		template<class T,class V> T power(T x,V y) //x^y. class T can be matrix.
		{
			if (y==0) return T(1);
			T t=power(x,y/2);
			t=t*t;
			if (y%2) t=t*x;
			return t;
		}
		template<class T> T power(T x,T y,T z) //x^y%z. T can be int, long long, biginteger
		{
			if (y==0) return T(1);
			T t=power(x,y/2,z);
			t=t*t%z;
			if (y%2) t=t*x%z;
			return t;
		}
		ll prime_modular_inverse(ll x,ll p) //x^-1 mod p. p is a prime.
		{
			return power(x,p-2,p);
		}
		int Legendre_symbol(ll a,ll p)
		{
			ll t=power(a,(p-1)/2,p);
			if (t==0) return 0;
			if (t==1) return 1;
			return -1;
		}
		ll Tonelli_Shanks(ll n,ll p) //find a number x s.t. x^2=n(mod p)
		{
			if (n==0) return 0;
			if (Legendre_symbol(n,p)!=1) return -1; //no solution!
			ll Q=p-1,S=0;
			while (Q%2==0)
			{
				Q/=2;
				++S;
			}
			if (S==1) return power(n,(p+1)/4,p);
			ll z=2;
			while (Legendre_symbol(z,p)!=-1) ++z;
			ll c=power(z,Q,p);
			ll R=power(n,(Q+1)/2,p),t=power(n,Q,p),M=S;
			while (1)
			{
				if (t==1) break;
				ll tmp=t*t%p,i=1;
				for (;tmp!=1;++i) tmp=tmp*tmp%p;
				ll b=power(c,power(2ll,M-i-1,p-1),p);
				R=R*b%p;
				c=b*b%p;
				t=t*c%p;
				M=i;
			}
			return R;
		}
		ll prime_modular_log(ll A,ll x,ll p) //minimize n such that A^n=x(mod p)
		{
			ll t=sqrt(p)+1;
			map<ll,ll> F;
			ll A_t=1;
			for (ll i=1;i<=t;++i)
			{
				A_t=A_t*A%p;
				F[x*A_t%p]=i;
			}
			for (ll i=1,v=A_t;i<=t;++i,v=v*A_t%p)
				if (F.count(v)) return i*t-F[v];
			return -1;
		}
		ll prime_modular_log(ll A,ll x,ll p,ll b) //minimize n such that A^n=x(mod p) && n=b(mod 2)
		{
			ll t=sqrt(p)+1;
			map<ll,ll> F;
			ll A_t=1;
			for (ll i=1;i<=t;++i)
			{
				A_t=A_t*A%p;
				F[x*A_t%p]=i;
			}
			for (ll i=1,v=A_t;i<=t;++i,v=v*A_t%p)
				if (F.count(v)) if ((i*t-F[v])%2==b) return i*t-F[v];
			return -1;
		}
		template<class T,int n> class square_matrix
		{
			public:
				T **v;
				square_matrix ()
				{
					v=new T*[n];
					for (int i=0;i<n;++i)
					{
						v[i]=new T[n];
						for (int j=0;j<n;++j)
							v[i][j]=0;
					}
				}
				square_matrix (T x)
				{
					square_matrix();
					for (int i=0;i<n;++i)
						v[i][i]=x;
				}
				square_matrix operator + (square_matrix A)
				{
					for (int i=0;i<n;++i)
						for (int j=0;j<n;++j)
							A.v[i][j]+=v[i][j];
					return A;
				}
				square_matrix operator - (square_matrix A)
				{
					for (int i=0;i<n;++i)
						for (int j=0;j<n;++j)
							A.v[i][j]-=v[i][j];
					return A;
				}
				square_matrix operator * (square_matrix A)
				{
					square_matrix p;
					for (int i=0;i<n;++i)
						for (int j=0;j<n;++j)
							for (int k=0;k<n;++k)
								p.v[i][j]+=v[i][k]*A.v[k][j];
					return p;
				}
		};
		template<class T,int n,T mod> class square_matrix_mod
		{
			public:
				T **v;
				square_matrix_mod ()
				{
					v=new T*[n];
					for (int i=0;i<n;++i)
					{
						v[i]=new T[n];
						for (int j=0;j<n;++j)
							v[i][j]=0;
					}
				}
				square_matrix_mod (T x)
				{
					square_matrix_mod();
					x%=mod;
					for (int i=0;i<n;++i)
						v[i][i]=x;
				}
				square_matrix_mod operator + (square_matrix_mod A)
				{
					for (int i=0;i<n;++i)
						for (int j=0;j<n;++j)
							(A.v[i][j]+=v[i][j])%=mod;
					return A;
				}
				square_matrix_mod operator - (square_matrix_mod A)
				{
					for (int i=0;i<n;++i)
						for (int j=0;j<n;++j)
							(A.v[i][j]-=v[i][j])%=mod;
					return A;
				}
				square_matrix_mod operator * (square_matrix_mod A)
				{
					square_matrix_mod p;
					for (int i=0;i<n;++i)
						for (int j=0;j<n;++j)
							for (int k=0;k<n;++k)
								(p.v[i][j]+=v[i][k]*A.v[k][j])%=mod;
					return p;
				}
		};
	}
	namespace geometry
	{
		template<class T> class point
		{
			public:
				T x,y;
				point ()
				{
					x=y=0;
				}
				point (T _x,T _y)
				{
					x=_x;
					y=_y;
				}
				point operator + (point A)
				{
					return point(x+A.x,y+A.y);
				}
				point operator - (point A)
				{
					return point(x-A.x,y-A.y);
				}
				point operator * (T A)
				{
					return point(x*A,y*A);
				}
				point operator / (T A)
				{
					return point(x/A,y/A);
				}
				T operator * (point A) //dot
				{
					return x*A.x+y*A.y;
				}
				T operator / (point A) //det
				{
					return x*A.y-y*A.x;
				}
				T sqr_len()
				{
					return x*x+y*y;
				}
				double len()
				{
					return sqrt(sqr_len());
				}
				double arg()
				{
					return arctan2(y,x);
				}
		};
	}
	namespace widely_used
	{
		template<class T> int discrete(T *a,int n)
		{
			vector<T> v;
			for (int i=1;i<=n;++i)
				v.push_back(a[i]);
			sort(v.begin(),v.end());
			v.erase(unique(v.begin(),v.end()),v.end());
			for (int i=1;i<=n;++i)
				a[i]=lower_bound(v.begin(),v.end(),a[i])-v.begin()+1;
			return v.size();
		}
	}
	namespace max_flow
	{
		template<class type=int> class flow_graph
		{
			private:
				const type INF=typeid(int)==typeid(type)?1000000000:1000000000000000000LL;
				//const static type INF=1000000000;
			public:
				int n,S,T;
			private:
				vector<int> h,vh;
				struct node
				{
					int way;
					type cap;
					node *next,*rev;
				};
				vector<node*> v;
				int max_flow(int x,int flow)
				{
					if (x==T) return flow;
					int now=flow;
					int minh=n-1;
					for (node *it=v[x];it;it=it->next)
						if (it->cap>0)
						{
							if (h[it->way]+1==h[x])
							{
								int tmp=max_flow(it->way,min(now,it->cap));
								now-=tmp;
								it->cap-=tmp;
								it->rev->cap+=tmp;
								if (h[S]>=n) return flow-now;
								if (!now) break;
							}
							minh=min(minh,h[it->way]);
						}
					if (flow==now)
					{
						if (!--vh[h[x]]) h[S]=n;
						++vh[h[x]=minh+1];
					}
					return flow-now;
				}
			public:
				flow_graph (int _n,int _S,int _T)
				{
					n=_n;
					S=_S;
					T=_T;
					h.resize(n+1);
					vh.resize(n+1);
					v.resize(n+1);
				}
				void addedge(int x,int y,int c)
				{
					node *p=new node;
					node *q=new node;
					*p=(node){y,c,v[x],q};
					*q=(node){x,0,v[y],p};
					v[x]=p;
					v[y]=q;
				}
				int solve()
				{
					int ans=0;
					for (vh[0]=n;h[S]<n;ans+=max_flow(S,INF));
					return ans;
				}
		};
	}
	namespace data_structure
	{
		template<class T=int,class OPR=plus<T> > class BIT //for eg. opr=plus<int>, bit_xor<int>
		{
			private:
				OPR opr;
				int n;
				T *a;
			public:
				BIT(int _n)
				{
					n=_n;
					a=new T[n+1]();
				}
				void modify(int x,T p)
				{
					for (;x<=n;x+=x&-x)
						a[x]=opr(a[x],p);
				}
				T query(int x)
				{
					T p=T();
					for (;x;x-=x&-x)
						p=opr(p,a[x]);
					return p;
				}
		};
		template<class T=int,class OPR_D=plus<int>,class OPR_U=plus<int> > class segment_tree
		{
//#define SEGMENT_TREE_TAG
			private:
				OPR_D opr_d;
				OPR_U opr_u;
				int n;
				T *val;
#ifdef SEGMENT_TREE_TAG
				T *tag;
#endif
				void change(T &v,T p)
				{
					v=p;
				}
#ifdef SEGMENT_TREE_TAG
				void clear(int k,int L,int R)
				{
					if (tag[k])
					{
						tag[k]=T();
					}
				}
#endif
				void update(int k,int L,int R)
				{
					val[k]=opr_u(val[k<<1],val[k<<1|1]);
				}
				void modify(int k,int L,int R,int x,int y,T p)
				{
					if (L==x&&R==y)
					{
						change(val[k],p);
						return;
					}
#ifdef SEGMENT_TREE_TAG
					clear(k,L,R);
#endif
					int m=(L+R)>>1;
					if (y<=m)
						modify(k<<1,L,m,x,y,p);
					else if (x>m)
						modify(k<<1|1,m+1,R,x,y,p);
					else
					{
						modify(k<<1,L,m,x,m,p);
						modify(k<<1|1,m+1,R,m+1,y,p);
					}
					update(k,L,R);
				}
				T query(int k,int L,int R,int x,int y)
				{
					if (L==x&&R==y) return val[k];
#ifdef SEGMENT_TREE_TAG
					clear(k,L,R);
#endif
					int m=(L+R)>>1;
					if (y<=m)
						return query(k<<1,L,m,x,y);
					if (x>m)
						return query(k<<1|1,m+1,R,x,y);
					return opr_u(query(k<<1,L,m,x,m),query(k<<1|1,m+1,R,m+1,y));
				}
			public:
				segment_tree (int _n)
				{
					n=1;
					while (n<_n) n<<=1;
					val=new T[n*2]();
#ifdef SEGMENT_TREE_TAG
					tag=new T[n*2]();
#endif
				}
				void modify(int x,T p)
				{
					return modify(1,1,n,x,x,p);
				}
				void modify(int x,int y,T p)
				{
					return modify(1,1,n,x,y,p);
				}
				T query(int x)
				{
					return query(1,1,n,x,x);
				}
				T query(int x,int y)
				{
					return query(1,1,n,x,y);
				}
		};
	}
}

//cheat::reader<10000> reader;
//cheat::writer<10000> writer;

const int INF=1000000000;

int F[110][2][2];

int main()
{
	//reader.init();
	for (int i=0;i<=100;++i)
		for (int j=0;j<2;++j)
			for (int k=0;k<2;++k)
				F[i][j][k]=INF;
	F[0][0][0]=0;
	int n;
	cin>>n;
	for (int i=0;i<n;++i)
	{
		int x,y;
		cin>>x>>y;
		x&=1;
		y&=1;
		for (int j=0;j<2;++j)
			for (int k=0;k<2;++k)
			{
				F[i+1][j^x][k^y]=min(F[i+1][j^x][k^y],F[i][j][k]);
				F[i+1][j^y][k^x]=min(F[i+1][j^y][k^x],F[i][j][k]+1);
			}
	}
	if (F[n][0][0]==INF) F[n][0][0]=-1;
	cout<<F[n][0][0]<<endl;
	//writer.print();
	return 0;
}