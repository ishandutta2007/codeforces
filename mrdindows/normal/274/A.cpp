# include <iostream>
# include <sstream>
# include <fstream>
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
# include <iomanip>
using namespace std;

#define DEBUG


#define DEB(x) cout<<#x<<"="<<x<<" "
#define DEBN(x) cout<<#x<<"="<<x<<"\n"


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

#ifdef DEBUG
#define DPR(fmt, ...) \
    do { printf(fmt, ## __VA_ARGS__); } while (0)
#else
#define DPR(fmt, ...) \
    do { } while (0)
#endif

#define PR(fmt, ...) \
    do { printf(fmt, ## __VA_ARGS__); } while (0)


#pragma comment(linker, "/STACK:10000000")
// Useful constants

template<typename T1,typename T2,typename T3>
struct triple{T1 a;T2 b;T3 c;triple(T1 _a,T2 _b, T3 _c):a(_a),b(_b),c(_c){}};


typedef long long           ll;
typedef long double         ld;
typedef pair<int,int>       pii;
typedef pair<long,long>     pll;
typedef triple<int,int,int> tri;
typedef triple<ll,ll,ll>    trl;
typedef vector<int>         vi;
typedef vector<ll>          vll;
typedef vector<double>      vd;
typedef vector<pii>         vpii;
typedef vector<vi>          vvi;


#define mp make_pair
#define F first 
#define S second


#define FI(n) for(i=0;i<n;i++)
#define FI1(n) for(i=1;i<n;i++)
#define FJ(n) for(j=0;j<n;j++)
#define FJ1(n) for(j=1;j<n;j++)
#define FJI for(j=0;j<i;j++)
#define FJI1 for(j=1;j<i;j++)
#define FJIE for(j=0;j<=i;j++)
#define FJIE1 for(j=1;j<=i;j++)
#define For(i,a,b) for(i=a;i<b;i++)

// Input macros
#define s(n)                        scanf("%d",&n)
#define sc(n)                       scanf("%c",&n)
#define sl(n)                       scanf("%I64d",&n)
#define sf(n)                       scanf("%lf",&n)
#define ss(n)                       scanf("%s",n)

//Output macros
#define pr(n)                       printf("%d ",n)
#define prn(n)                      printf("%d\n",n)
#define prc(n)                      printf("%c",n)
#define prcn(n)                     printf("%c\n",n)
#define prl(n)                      printf("%I64d ",n)
#define prln(n)                     printf("%I64d\n",n)
#define prf(n)                      printf("%lf ",n)
#define prfn(n)                     printf("%lf\n",n)
#define prs(n)                      printf("%s ",n)
#define prsn(n)                     printf("%s\n",n)



//STL containers
#define foreach(v, c)               for( typeof( (c).begin()) v = (c).begin();  v != (c).end(); ++v)
#define all(a)                      a.begin(), a.end()
#define in(a,b)                     ((b).find(a) != (b).end())
#define in2(a,b)                    (find(all(b),a) != (b).end())
#define pb                          push_back
#define sz(a)                       ((int)(a.size()))
#define svi(vec,n) FI(n) s(vec[i])
#define svl(vec,n) FI(n) sl(vec[i])
#define it ::iterator

//fill char arrays
#define fill(a,v)                    memset(a, v, sizeof (a))

#define checkbit(n,b)                ( (n >> b) & 1)
#define INDEX(arr,ind)               (lower_bound(all(arr),ind)-arr.begin())
#define sor(a)  sort(all(a))
#define rsor(a) sort(all(a)); reverse(all(a));
#define exchange(t,a,b) typeof(a) t =a; a=b; b=t

//STL output ********************************
template<typename T1,typename T2>inline std::ostream& operator << (std::ostream& os, const std::pair<T1, T2>& p){return os << "(" << p.first << ", " << p.second << ")";}
template<typename T>inline std::ostream &operator<<(std::ostream &os,const std::vector<T>& v){bool first=true;os<<"[";for(unsigned int i=0;i<v.size();i++){if(!first)os<<", ";os<<v[i];first=false;}return os<<"]";}
template<typename T>inline std::ostream &operator<<(std::ostream &os,const std::set<T>&v){bool first=true;os << "[";for(typename std::set<T>::const_iterator ii=v.begin();ii!=v.end();++ii){if(!first)os<<", ";os<<*ii;first=false;}return os<<"]";}
template<typename T1, typename T2>inline std::ostream &operator << (std::ostream & os,const std::map<T1, T2>& v){bool first = true; os << "[";for (typename std::map<T1,T2>::const_iterator ii =v.begin();ii!=v.end();++ii){if(!first)os<<", ";os<<*ii;first=false;}return os<<"]";}
template<typename T,typename T2>void printarray(T  a[],T2 sz,T2 beg=0){for(T2 i=beg;i<sz;i++) cout<<a[i]<<" ";}

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

//template<typename T>inline T max(T a, T b){return (a>b)?a:b;}
//template<typename T>inline T min(T a, T b){return (a<b)?a:b;}
//template<typename T>inline T max(T a, T b, T c){return (a>=b && a>=c)?a:(b>=c && b>=a)?b:c;}
//template<typename T>inline T min(T a, T b, T c){return (a<=b && a<=c)?a:(b<=c && b<=a)?b:c;}
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

#define INF         (int)1e9
#define EPS         (double)1e-9
#define mod         1000000007
#define PI          3.14159265358979

int main()
{
    int n,k;
    cin>>n>>k;
    int *a=new int[n];
    for (int i=0;i<n;i++)
    {
        scanf("%d",a+i);
    }
    sort(a,a+n);
    set<int> s;
    for (int i=0;i<n;i++)
    {
        if (a[i]%k!=0 || (s.find(a[i]/k)==s.end()))
        {
            s.insert(a[i]);
        }
    }
    cout<<s.size()<<endl;
    return 0;
}