#pragma comment(linker, "/stack:20000000")
#define _CRT_SECURE_NO_WARNINGS

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
# include <complex>
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

double __begin;
#define CHECK_TIME(ccc) __begin = clock(); ccc; std::cerr<<"Time of work = "<<(clock()-__begin)/CLOCKS_PER_SEC<<std::endl; 

#define mp make_pair
typedef long long ll;
typedef unsigned int uint;
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
#define Pr(n)                       printf("%d ",n)
#define Prn(n)                      printf("%d\n",n)
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

//int some_primes[10] = {100271, 500179, 1000003, 2000227, 5000321}
//fill char arrays
#define fill(a,v)                    memset(a, v, sizeof (a))

inline int bits_count(int v){v=v-((v>>1)&0x55555555);v=(v&0x33333333)+((v>>2)&0x33333333);return((v+(v>>4)&0xF0F0F0F)*0x1010101)>>24;}
inline int sign(int x){return (x >> 31) | (-x >> 31);}
inline bool ispow2(int x){return !(x&(x-1));}
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

#define FREIN(FILE) freopen(FILE,"rt",stdin)
#define FREOUT(FILE) freopen(FILE,"wt",stdout)

#define sqr(x) ((x)*(x))
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

// Useful constants

#define INF            1011111111
#define EPS            (double)1e-8
#define mod 1000000009
#define PI 3.14159265358979
//******************************************************************************
/*
int n;
int t[5];

int main()
{
    S(n);
    int sum = 0;
    for (int i=0;i<n;++i)
    {
        int x;
        scanf("%d",&x);
        t[x]++;
        sum += x;
    }
    if (sum==1 || sum==2 || sum==5)
    {
        puts("-1");
        return 0;
    }
    int ans = 0;
    int c12 = min(t[1],t[2]);
    t[1] -= c12;
    t[2] -= c12;
    return 0;
}


/**/
string x,y;
ll n,m;
int arr[30][1000000];
int main()
{
    cin>>n>>m;
    if (n<m)
        cin>>x>>y;
    else
        cin>>y>>x;
    ll t = gcd(n,m);
    n/=t;
    m/=t;
    ll ans = 0;

    ll a = x.size();
    ll b = y.size();
    ll c = gcd(a,b);
    for (int i=0;i<b;++i)
    {
        arr[y[i]-'a'][i%c]++;
    }

    for (int i=0;i<a;++i)
    {
        char c1 = x[i] - 'a';
        ans += (b/c - arr[c1][i%c]); 
    }
    ans *= t;
    cout<<ans<<endl;
    return 0;
}


/*0
//#define INTARR(_name, _size) int *_name = new int[_size];
const int N = 1<<20;
const int K = 1<<19;
int l[N], r[N], x[N];
int tr[N+N];
bool full[N+N];
int ans[N+N];
int get(int cur, int l, int r, int x)
{
    if (x<l || x>r)
    {
        while(true) cur++;
    }
    if (full[cur] || l==r)
    {
        return tr[cur];
    }
    else
    {
        int m = (l+r)>>1;
        int dcur = cur+cur;
        if (x<=m)
            return get(dcur,l,m,x);
        else
            return get(dcur+1,m+1,r,x);
    }
}
void upd(int cur, int l, int r, int x, int y, int val)
{
    //DB(cur); DB(l); DB(r);
    if (l==x && r==y)
    {
        tr[cur] = val;
        full[cur] = true;
    }
    else
    {
        int dcur = cur+cur;
        int m = (l+r)>>1;
        if (full[cur])
        {
            full[dcur+1] = true;
            full[dcur] = true;
            tr[dcur] = tr[dcur+1] = tr[cur];

            full[cur] = false;
        }
        if (y<=m)
        {
            upd(dcur,l,m,x,y,val);
        }
        else if (x>m)
        {
            upd(dcur+1,m+1,r,x,y,val);
        }
        else
        {
            upd(dcur, l, m, x,m,val);
            upd(dcur+1,m+1,r,m+1,y,val);
        }

    }

}
int main()
{
    cout<<K<<endl;
    int n,m;
    scanf("%d%d",&n,&m);
    for (int i=0;i<n+2;++i)
    {
        ans[i] = -1;
    }
    for (int i=0;i<m;++i)
    {
        scanf("%d%d%d",l+i,r+i,x+i);
    }
    for (int i=m-1;i>=0;--i)
    {
        ans[x[i]] = get(1,0,K-1,x[i]);
        upd(1,0,K-1,l[i],r[i],x[i]);
    }
    int k = 0;
    for (int i=1;i<=n;++i)
    {
        if (ans[i]==-1)
        {
            ans[i] = get(1,0,K-1,i);
        }
        if (ans[i]==0)
        {
            ++k;
        }
        printf("%d ",ans[i]);
    }
    cout<<endl;
    if (k!=1)
        exit(-1);
    return 0;
}


/***/