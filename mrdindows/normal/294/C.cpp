# include <iostream>
# include <cmath>
# include <algorithm>
# include <cstdio>
# include <cstring>
# include <string>
# include <cstdlib>
# include <vector>
# include <bitset>
# include <map>
# include <queue>
# include <stack>
# include <set>
# include <list>
# include <deque>
# include <functional>
# include <sstream>
# include <fstream>
using namespace std;

//#define DEBUG

#define DB(x) cout<<#x<<"="<<x<<" "
#define DBN(x) cout<<#x<<"="<<x<<"\n"

#define  DEBUG
#ifdef DEBUG
#define D(x) DB(x)
#define DN(x) DBN(x)
#define DA(c,n) cout<<#c<<"=["; printarray(c,n); cout<<"]\n"
#define DAR(c,n,s) cout<<#c<<"["<<s<<"-"<<n-1<<"]=["; printarray(c,n,s); cout<<"]\n"
#else
#define D(x) 
#define DN(x)
#define DA(c,n) 
#define DAR(c,n,s)
#endif

#ifdef DEBUG
#define DPR(fmt, ...) \
	do { printf(fmt, ## __VA_ARGS__); } while (0)
#else
#define DPR(fmt, ...) \
	do { } while (0)
#endif

#define PR(fmt, ...) \
	do { printf(fmt, ## __VA_ARGS__); } while (0)


// Useful constants

#define INF				(int)1e9
#define EPS             (double)1e-9
#define mod				1000000007

#define pii pair<int,int>
#define pll pair<long long,long long>
#define mp make_pair
#define F first 
#define S second
#define ll long long

template<typename T1,typename T2,typename T3>
struct triple{T1 a;T2 b;T3 c;triple(T1 _a,T2 _b, T3 _c):a(_a),b(_b),c(_c){}};
#define tri triple<int,int,int>
#define trl triple<ll,ll,ll>

#define For(i,c,a) for(int i=c;i<a;i++)


// Input macros
#define S(n)                        scanf("%d",&n)
#define Sc(n)                       scanf("%c",&n)
#define Sl(n)                       scanf("%I64d",&n)
#define Sf(n)                       scanf("%lf",&n)
#define Ss(n)                       scanf("%s",n)

//Output macros
#define Pr(n)						printf("%d ",n)
#define Prn(n)						printf("%d\n",n)
#define Prc(n)                      printf("%c",n)
#define Prcn(n)                     printf("%c\n",n)
#define Prl(n)                      printf("%I64d ",n)
#define Prln(n)                     printf("%I64d\n",n)
#define Prf(n)                      printf("%lf ",n)
#define Prfn(n)                     printf("%lf\n",n)
#define Prs(n)                      printf("%s ",n)
#define Prsn(n)                     printf("%s\n",n)



//STL containers
#define foreach(v, c)               for( typeof( (c).begin()) v = (c).begin();  v != (c).end(); ++v)
#define all(c)                      c.begin(), c.end()
#define in(c,a)                     ((a).find(c) != (a).end())
#define in2(c,a)                    (find(all(a),c) != (a).end())
#define pb                          push_back
#define sz(c)                       ((int)(c.size()))
#define vi vector<int>
#define vl vector<long long>
#define svi(vec,n) FI(n) s(vec[i])
#define svl(vec,n) FI(n) sl(vec[i])
#define it ::iterator

//fill char arrays
#define fill(c,v)                    memset(c, v, sizeof (c))

#define checkbit(n,a)                ( (n >> a) & 1)
#define INDEX(arr,ind)               (lower_bound(all(arr),ind)-arr.begin())
#define sor(c)  sort(all(c))
#define rsor(c) sort(all(c)); reverse(all(c));
#define exchange(t,c,a) typeof(c) t =c; c=a; a=t

//STL output ********************************
template<typename T1,typename T2>inline std::ostream& operator << (std::ostream& os, const std::pair<T1, T2>& p){return os << "(" << p.first << ", " << p.second << ")";}
template<typename T>inline std::ostream &operator<<(std::ostream &os,const std::vector<T>& v){bool first=true;os<<"[";for(unsigned int i=0;i<v.size();i++){if(!first)os<<", ";os<<v[i];first=false;}return os<<"]";}
template<typename T>inline std::ostream &operator<<(std::ostream &os,const std::set<T>&v){bool first=true;os << "[";for(typename std::set<T>::const_iterator ii=v.begin();ii!=v.end();++ii){if(!first)os<<", ";os<<*ii;first=false;}return os<<"]";}
template<typename T1, typename T2>inline std::ostream &operator << (std::ostream & os,const std::map<T1, T2>& v){bool first = true; os << "[";for (typename std::map<T1,T2>::const_iterator ii =v.begin();ii!=v.end();++ii){if(!first)os<<", ";os<<*ii;first=false;}return os<<"]";}
template<typename T,typename T2>void printarray(T  a[],T2 sz,T2 beg=0){for(T2 i=beg;i<sz;i++) cout<<a[i]<<" ";}

#define sqrt(x) sqrt(1.0*(x))
#define pow(x,n) pow(1.0*(x),n)

inline ll binpow(ll x,ll n){ll res=1;while(n){if(n&1)res*=x;x*=x;n>>=1;}return res;}
inline ll powmod(ll x,ll n, ll _mod){ll res=1;while(n){if(n&1)res=(res*x)%_mod;x=(x*x)%_mod;n>>=1;}return res;}
inline ll gcd(ll a,ll b){ll t;while(b){a=a%b;t=a;a=b;b=t;}return a;}
inline int gcd(int a,int b){int t;while(b){a=a%b;t=a;a=b;b=t;}return a;}
inline ll lcm(int a,int b){return a/gcd(a,b)*(ll)b;}
inline ll lcm(ll a,ll b){return a/gcd(a,b)*b;}
inline ll gcd(ll a,ll b,ll c){return gcd(gcd(a,b),c);}
inline int gcd(int a,int b,int c){return gcd(gcd(a,b),c);}
inline ll lcm(ll a,ll b,ll c){return lcm(lcm(a,b),c);}
inline ll lcm(int a,int b,int c){return lcm(lcm(a,b),(ll)c);}

inline ll max(ll a,ll b){return (a>b)?a:b;}
inline int max(int a,int b){return (a>b)?a:b;}
inline double max(double a,double b){return (a>b)?a:b;}
inline ll max(ll a,ll b,ll c){return max(a,max(b,c));}
inline int max(int a,int b,int c){return max(a,max(b,c));}
inline double max(double a,double b,double c){return max(a,max(b,c));}
inline ll min(ll a,ll b){return (a<b)?a:b;}
inline int min(int a,int b){return (a<b)?a:b;}
inline double min(double a,double b){return (a<b)?a:b;}
inline ll min(ll a,ll b,ll c){return min(a,min(b,c));}
inline int min(int a,int b,int c){return min(a,min(b,c));}
inline double min(double a,double b,double c){return min(a,min(b,c));}

inline void getar(int *a,int n){for (int ii=0;ii<n;ii++){scanf("%d",a+ii);}}
inline void getar(ll *a,int n){for (int ii=0;ii<n;ii++){scanf("%I64",a+ii);}}

int a[1005];
int b[1005];
int t[1005];
int main()
{
	int n;
	cin>>n;
	int m;
	cin>>m;
	memset(a,0,4*n+4);
	a[0] = -1;
	for (int i=1;i<=m;i++)
	{
		scanf("%d",a+i);
		a[i]--;
	}
	a[m+1] = n;
	for (int i=1;i<=n-m;i++)
	{
		int tmp = i;
		for (int j=2;j*j<=tmp;j++)
		{
			while (tmp%j==0)
			{
				tmp/=j;
				t[j]++;
			}
		}
		if (tmp>1)
		{
			t[tmp]++;
		}
	}
	sort(a,a+m+2);
	int x = a[1]-a[0]-1;
	int y = a[m+1]-a[m]-1;
	if (x>0)
		t[2] -= x-1;
	if (y>0)
		t[2] -= y-1;
	ll ans = 1;
	int d;
	//cout<<t[2]<<endl;
	for (int i=1;i<=m+1;i++)
	{
		d = a[i] - a[i-1] - 1 ;
		if (d==0) continue;
		t[2]+=d-1;
		//cout<<t[2]<<endl;
	//	DBN(d);
		for (int j=1;j<=d;j++)
		{
			int tmp = j;
			for (int q=2;q*q<=tmp;q++)
			{
				while (tmp%q==0)
				{
					tmp/=q;
					t[q]--;
				}
			}
			if (tmp>1)
			{
				t[tmp]--;
			}
		}

	}

	for (int i=2;i<=n;i++)
	{
	//	cout<<i<<" "<<t[i]<<endl;
		for (int j=0;j<t[i];j++)
		{
			ans = (ans * i)%mod;
		}
	}
	cout<<ans<<endl;
	return 0;
}