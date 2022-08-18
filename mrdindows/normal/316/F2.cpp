#pragma comment(linker, "/stack:20000000")

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
# include <ctime>
# include <stack>
# include <set>
# include <list>
# include <deque>
# include <functional>
# include <sstream>
# include <fstream>
using namespace std;

#define DEBUG


#define DB(x) cout<<#x<<"="<<x<<" "
#define DBN(x) cout<<#x<<"="<<x<<"\n"


#ifdef DEBUG
#define D(x) DEBN(x)
#define DN(x) DEBN(x)
#define DA(a,n) cout<<#a<<"=["; printarray(a,n); cout<<"]\n"
#define DAR(a,n,s) cout<<#a<<"["<<s<<"-"<<n-1<<"]=["; printarray(a,n,s); cout<<"]\n"
#else
#define D(x) 
#define DN(x)
#define DA(a,n) 
#define DAR(a,n,s)
#endif

#define mp make_pair
typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<long long,long long> pll;
typedef vector<int> vi;
typedef vector<long long> vll;

template<typename T1,typename T2,typename T3>
struct triple{T1 a;T2 b;T3 c;triple(){};triple(T1 _a,T2 _b, T3 _c):a(_a),b(_b),c(_c){}};
#define tri triple<int,int,int>
#define trl triple<ll,ll,ll>
template<typename T1,typename T2,typename T3>
bool operator<(const triple<T1,T2,T3> &t1,const triple<T1,T2,T3> &t2){if (t1.a!=t2.a) return t1.a<t2.a; else return t1.b<t2.b;}

#define FI(n) for(int i=0;i<n;i++)
#define FI1(n) for(int i=1;i<n;i++)
#define FJ(n) for(int j=0;j<n;j++)
#define FJ1(n) for(int j=1;j<n;j++)
#define FJI for(int j=0;j<i;j++)
#define FJI1 for(int j=1;j<i;j++)
#define FJIE for(int j=0;j<=i;j++)
#define FJIE1 for(int j=1;j<=i;j++)
#define For(i,a,b) for(int i=a;i<b;i++)

// Input macros
#define S(n)                        scanf("%d",&n)
#define Sc(n)                       scanf("%c",&n)
#define Sl(n)                       scanf("%I64d",&n)
#define Sf(n)                       scanf("%lf",&n)
#define Ss(n)                       scanf("%s",n)

//Output macros
#define Pr(n)                        printf("%d ",n)
#define Prn(n)                        printf("%d\n",n)
#define Prc(n)                      printf("%c",n)
#define Prcn(n)                     printf("%c\n",n)
#define Prl(n)                      printf("%I64d ",n)
#define Prln(n)                     printf("%I64d\n",n)
#define Prf(n)                      printf("%lf ",n)
#define Prfn(n)                     printf("%lf\n",n)
#define Prs(n)                      printf("%s ",n)
#define Prsn(n)                     printf("%s\n",n)

//STL containers
#define foreach(v, c)               for( auto v = (c).begin();  v != (c).end(); ++v)
#define all(a)                      a.begin(), a.end()
#define in(a,b)                     ((b).find(a) != (b).end())
#define in2(a,b)                    (find(all(b),a) != (b).end())
#define pb                          push_back
#define sz(a)                       ((int)(a.size()))
#define svi(vec,n) FI(n) S(vec[y])
#define svl(vec,n) FI(n) Sl(vec[y])
#define IT ::iterator

//fill char arrays
#define fill(a,v)                    memset(a, v, sizeof (a))

#define checkbit(n,b)                ( (n >> b) & 1)
#define INDEX(arr,ind)               (lower_bound(all(arr),ind)-arr.begin())
#define sor(a)  sort(all(a))
#define rsor(a) sort(all(a)); reverse(all(a));

//STL output ********************************
template<typename T1,typename T2>inline std::ostream& operator << (std::ostream& os, const std::pair<T1, T2>& p){return os << "(" << p.first << ", " << p.second << ")";}
template<typename T>inline std::ostream &operator<<(std::ostream &os,const std::vector<T>& v){bool first=true;os<<"[";for(unsigned int i=0;i<v.size();i++){if(!first)os<<", ";os<<v[i];first=false;}return os<<"]";}
template<typename T>inline std::ostream &operator<<(std::ostream &os,const std::set<T>&v){bool first=true;os << "[";for(typename std::set<T>::const_iterator ii=v.begin();ii!=v.end();++ii){if(!first)os<<", ";os<<*ii;first=false;}return os<<"]";}
template<typename T1, typename T2>inline std::ostream &operator << (std::ostream & os,const std::map<T1, T2>& v){bool first = true; os << "[";for (typename std::map<T1,T2>::const_iterator ii =v.begin();ii!=v.end();++ii){if(!first)os<<", ";os<<*ii;first=false;}return os<<"]";}
template<typename T,typename T2>void printarray(T  a[],T2 sz,T2 beg=0){for(T2 i=beg;i<sz;i++) cout<<a[i]<<" ";}

#define sqr(x) ((x)*(x))
#define sqrt(x) sqrt(1.0*(x))
#define pow(x,n) pow(1.0*(x),n)

inline ll binpow(ll x,ll n){ll res=1;while(n){if(n&1)res*=x;x*=x;n>>=1;}return res;}
inline ll powmod(ll x,ll n, ll _mod){ll res=1;while(n){if(n&1)res=(res*x)%_mod;x=(x*x)%_mod;n>>=1;}return res;}
inline ll mulmod(ll x,ll n, ll _mod){ll res=0;while(n){if(n&1)res=(res+x)%_mod;x=(x+x)%_mod;n>>=1;}return res;}
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


//#define abs(x) (((x)>0)?(x):(-x))
// Useful constants

#define MAXINT 111111111
#define INF            2111111111
#define EPS            (double)5*(1e-7)
#define mod 1000000000
#define PI 3.14159265358979328462
/******************************************************************************/
bool a[1621][1621];
bool used[1621][1621];
bool used2[1621][1621];
bool used3[1621][1621];
const int maxl = 15;
const int maxs = 10;
int w,h;
int k = 0;
int cur = 0;
int basei, basej;
tri q[10000];
int qs = 0;
void go2(int i, int j)
{
	if (((abs(i-basei)+abs(j-basej))>=maxl) || (!a[i][j]) || used2[i][j]) return;
	used2[i][j] = true;
// 	go2(i-1,j);
// 	go2(i+1,j);
// 	go2(i,j-1);
// 	go2(i,j+1);

	qs = 0;
	q[qs].a = i;
	q[qs].b = j;
	q[qs++].c = 0;
	int qc = 0;
	while(qc<qs)
	{
		int curi = q[qc].a;
		int curj = q[qc].b;
		int curl = q[qc++].c;
		if (curl==maxl) break;
		for (int t=-1;t<=1;t++)
			for (int w=-1;w<=1;w++)
			{
				if (!used2[curi+t][curj+w] && a[curi+t][curj+w])
				{
					used2[curi+t][curj+w] = true;
					q[qs].a = curi+t;
					q[qs].b =curj+w;
					q[qs++].c = curl+1;
				}

			}
		
	}
}
vector<pair<int,int>> v3;
bool check(int i,int j)
{
	int s = 0;
	qs = 0;
	q[qs].a = i;
	q[qs].b = j;
	q[qs++].c = 0;
	used3[i][j] = true;
	int qc = 0;
	v3.clear();
	while(qc<qs)
	{
		int curi = q[qc].a;
		int curj = q[qc].b;
		int curl = q[qc++].c;
		if (max(abs(basei-curi),abs(basej-curj))>2) continue;
		if (a[curi][curj]) s++;
		for (int t=-1;t<=1;t++)
			for (int w=-1;w<=1;w++)
			{
				if (!used3[curi+t][curj+w])
				{
					used3[curi+t][curj+w] = true;
					v3.push_back(mp(curi+t,curj+w));
					q[qs].a = curi+t;
					q[qs].b =curj+w;
					q[qs++].c = curl+1;
				}

			}
	}
	for (int i=0;i<v3.size();i++)
	{
		used3[v3[i].first][v3[i].second] = false;
	}
// 	for (int q=-2;q<=2;q++)
// 	{
// 		for (int w=-2;w<=2;w++)
// 		{
// 			s+=a[i+q][j+w];
// 		}
// 	}
	//DBN(s);
	return (s<maxs);
}
void go(int i, int j)
{
	if ((!a[i][j]) || used[i][j]) return;
	used[i][j] = true;
	go(i-1,j);
	go(i+1,j);
	go(i,j-1);
	go(i,j+1);
	if (used2[i][j]) return;
	int t = 0;
	if (a[i-1][j] == 0) t++;
	if (a[i][j-1] == 0) t++;
	if (a[i+1][j] == 0) t++;
	if (a[i][j+1] == 0) t++;
	//DBN(t);
	if (t>=2)
	{
		//DB(i);	DBN(j);
		basei = i;
		basej = j;
		if (check(i,j))
		{

			cur++;
			go2(i,j);

		}
	}
}
vector<int> ans;
int main()
{
	S(w);
	S(h);
	int x;
	for (int i=5;i<w+5;i++)
	{
		for (int j=5;j<h+5;j++)
		{
			S(x);
			a[i][j] = x;
			used[i][j] = used2[i][j] = false;
		}
	}
	for (int i=5;i<w+5;i++)
	{
		for (int j=5;j<h+5;j++)
		{
			if ((!used[i][j]) && a[i][j])
			{
				k++;
				cur = 0;
				go(i,j);
				ans.push_back(cur);
			}
		}
	}
	cout<<k<<endl;
	sort(all(ans));
	for (int i=0;i<k;i++)
	{
		cout<<ans[i]<<" ";
	}
	cout<<endl;
	return 0;
}
// int a[101001];
// int b[201001];
// int c[201001];
// int f[200000];
// int main()
// {
// 	int n,m;
// 	S(n);
// 	S(m);
// 	getar(a,n);
// 	int t;
// 	int x,v;
// 	f[0] = 1;
// 	f[1] = 1;
// 	for (int i=2;i<=n;i++)
// 	{
// 		f[i] = (f[i-1]+f[i-2]) % mod;
// 	}
// 	for (int i=0;i<n;i++)
// 	{
// 		a[i] = a[i]%mod;
// 	}
// 	for (int i=0;i<m;i++)
// 	{
// 		S(t);
// 		if (t==1)
// 		{
// 			scanf("%d%d",&x,&v);
// 			x--;
// 			a[x] = v % mod;
// 		}
// 		else if (t==2)
// 		{
// 			scanf("%d%d",&x,&v);
// 			x--;v--;
// 			ll res = 0;
// 			for (int i=0;i<=v-x;i++)
// 			{
// 				res = (res + 1LL*f[i]*a[i+x])% mod;
// 			}
// 			Prln(res);
// 		}
// 		else
// 		{
// 
// 		}
// 	}
// 	return 0;
// }