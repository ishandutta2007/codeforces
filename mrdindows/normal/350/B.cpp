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
bool operator<(const triple<T1,T2,T3> &t1,const triple<T1,T2,T3> &t2){ if (t1.a!=t2.a) return t1.a<t2.a; else if (t1.b!=t2.b) return t1.b<t2.b; else return t1.c<t2.c;}
template<typename T1,typename T2,typename T3>
ostream& operator<<(std::ostream & os,const triple<T1,T2,T3> &tr) {os<<"{"<<tr.a<<","<<tr.b<<","<<tr.c<<"}"; return os;}


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

#define S2(n1,n2)                   scanf("%d%d",&n1,&n2)
#define Sl2(n1,n2)                  scanf("%I64d%I64d",&n1,&n2)
#define S3(n1,n2,n3)                scanf("%d%d%d",&n1,&n2,&n3)
#define Sl3(n1,n2,n3)               scanf("%I64d%I64d%I64d",&n1,&n2,&n3)

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
template<typename T,typename T2>void printarray(T  a[],T2 sz,T2 beg=0){for(T2 i=beg;i<sz;i++) cout<<a[i]<<" ";cout<<endl;}

#define sqr(x) ((x)*(x))
#define sqrt(x) sqrt(1.0*(x))
#define pow(x,n) pow(1.0*(x),n)

inline ll binpow(ll x,ll n){ll res=1;while(n){if(n&1)res*=x;x*=x;n>>=1;}return res;}
inline ll mulmod(ll x,ll n, ll _mod){ll res=0;while(n){if(n&1)res=(res+x)%_mod;x=(x<<1)%_mod;n>>=1;}return res;}
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
inline int fastMax(int x, int y) { return (((y-x)>>(32-1))&(x^y))^y; }
inline int fastMin(int x, int y) { return (((y-x)>>(32-1))&(x^y))^x; }

inline void getar(int *a,int n){for (int ii=0;ii<n;ii++){scanf("%d",a+ii);}}
inline void getar(const int *a,int n){for (int ii=0;ii<n;ii++){scanf("%d",a+ii);}}
inline void getar(ll *a,int n){for (int ii=0;ii<n;ii++){scanf("%I64",a+ii);}}

// Useful constants

#define INF           1010000000
#define LLINF 1000000LL*1000000LL*1000000LL
#define EPS            (double)1e-7
#define mod 101
#define PI 3.14159265358979328462
const double EXP = exp(1.0);
/******************************************************************************/

int a[100010];
int t[100010];
int c[100010];
int n;
bool used[100010];
vector<int> ans;
vector<int> res;
void go(int cur)
{
    if (c[cur]>1)
    {
        if (res.size()>ans.size())
        {
            ans = res;
        }
        return;
    }
    res.push_back(cur+1);
    if (a[cur]) go(a[cur]-1);
    else
    {
        if (res.size()>ans.size())
        {
            ans = res;
        }
    }
}
int main()
{
    S(n);
    getar(t,n);
    getar(a,n);

    for (int i=0;i<n;i++)
    {
        if (a[i])
            c[a[i]-1]++;
    }
    for (int i=0;i<n;i++)
    {
        if (t[i])
        {
            res.clear();
            go(i);
        }
    }
    cout<<ans.size()<<endl;
    reverse(ans.begin(),ans.end());
    for (int i=0;i<ans.size();++i)
    {
        printf("%d ",ans[i]);
    }
    cout<<endl;
    return 0;
}