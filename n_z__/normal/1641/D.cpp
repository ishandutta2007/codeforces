#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt")
#undef ONLINE_JUDGE
#include<bits/stdc++.h>
#define Luogu 1
#define Cf 2
#define At 3
#define Other 4
#define No 5
//settings-settings-settings-settings-settings-settings-settings-settings-settings-settings-settings-settings-settings-settings-settings-settings-settings-settings
                                                                    #define use_qp                 0
                                                                    #define use_inv                0
                                                                    #define use_C                  0
                                                                    #define use_pbds               0
                                                                    #define use_BIT                0
                                                                    #define use_long_long          1
                                                                    #define use_fastio             0
                                                                    #define use_multiple_test_data 0
                                                                    #define ONLINE_JUDGE           Luogu
                                                                    #define me(x,y)                memset(x,y,sizeof(x))
                                                                    #define ex(x)                  return cout<<x<<endl,void(0)
                                                                    #define length_of_double_cout  10
//settings-settings-settings-settings-settings-settings-settings-settings-settings-settings-settings-settings-settings-settings-settings-settings-settings-settings
using namespace std;
#if ONLINE_JUDGE==No
#undef ONLINE_JUDGE
#endif
#if ONLINE_JUDGE==Cf or ONLINE_JUDGE==At
#pragma GCC optimize(3)
#endif
#ifdef ONLINE_JUDGE
	namespace Fread{const int SIZE=1<<16;char buf[SIZE],*S,*T;inline char getchar(){if(S==T){T=(S=buf)+fread(buf,1,SIZE,stdin);if(S==T)return'\n';}return *S++;}}namespace Fwrite{const int SIZE=1<<16;char buf[SIZE],*S=buf,*T=buf+SIZE;inline void flush(){fwrite(buf,1,S-buf,stdout);S=buf;}inline void putchar(char c){*S++=c;if(S==T)flush();}struct NTR{~NTR(){flush();}}ztr;}
    #define getchar Fread::getchar
	#define putchar Fwrite::putchar
#endif
#if use_pbds==1
#if ONLINE_JUDGE==Luogu
#include<bits/extc++.h>
#else
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/hash_policy.hpp>
#include<ext/pb_ds/trie_policy.hpp>
#include<ext/pb_ds/priority_queue.hpp>
#endif
using namespace __gnu_pbds;
#endif
#define Setprecision length_of_double_cout
namespace Fastio{struct Reader{template<typename T>Reader&operator>>(T&x){char c=getchar();short f=1;while(c<'0'||c>'9'){if(c=='-')f*=-1;c=getchar();}x=0;while(c>='0'&&c<='9'){x=(x<<1)+(x<<3)+(c^48);c=getchar();}x*=f;return *this;}Reader&operator>>(double&x){char c=getchar();short f=1,s=0;x=0;double t=0;while((c<'0'||c>'9')&&c!='-'&&c!='.'){if(c=='-')f*=-1;c=getchar();}while(c>='0'&&c<='9'&&c!='.')x=x*10+(c^48),c=getchar();if(c=='.')c=getchar();else return x*=f,*this;while(c>='0'&&c<='9')t=t*10+(c^48),s++,c=getchar();while(s--)t/=10.0;x=(x+t)*f;return*this;}Reader&operator>>(long double&x){char c=getchar();short f=1,s=0;x=0;long double t=0;while((c<'0'||c>'9')&&c!='-'&&c!='.'){if(c=='-')f*=-1;c=getchar();}while(c>='0'&&c<='9'&&c!='.')x=x*10+(c^48),c=getchar();if(c=='.')c=getchar();else return x*=f,*this;while(c>='0'&&c<='9')t=t*10+(c^48),s++,c=getchar();while(s--)t/=10.0;x=(x+t)*f;return*this;}Reader&operator>>(__float128&x){char c=getchar();short f=1,s=0;x=0;__float128 t=0;while((c<'0'||c>'9')&&c!='-'&&c!='.'){if(c=='-')f*=-1;c=getchar();}while(c>='0'&&c<='9'&&c!='.')x=x*10+(c^48),c=getchar();if(c=='.')c=getchar();else return x*=f,*this;while(c>='0'&&c<='9')t=t*10+(c^48),s++,c=getchar();while(s--)t/=10.0;x=(x+t)*f;return*this;}Reader&operator>>(char&c){c=getchar();while(c=='\n'||c==' '||c=='\r')c=getchar();return *this;}Reader&operator>>(char*str){int len=0;char c=getchar();while(c=='\n'||c==' '||c=='\r')c=getchar();while(c!='\n'&&c!=' '&&c!='\r')str[len++]=c,c=getchar();str[len]='\0';return*this;}Reader&operator>>(std::string&str){char c=getchar();while(c=='\n'||c==' '||c=='\r')c=getchar();while(c!='\n'&&c!=' '&&c!='\r')str.push_back(c),c=getchar();return*this;}Reader(){}}cin;const char endl='\n';struct Writer{typedef __int128 mxdouble;template<typename T>Writer&operator<<(T x){if(x==0)return putchar('0'),*this;if(x<0)putchar('-'),x=-x;static int sta[45];int top=0;while(x)sta[++top]=x%10,x/=10;while(top)putchar(sta[top]+'0'),--top;return*this;}Writer&operator<<(double x){if(x<0)putchar('-'),x=-x;mxdouble _=x;x-=(double)_;static int sta[45];int top=0;while(_)sta[++top]=_%10,_/=10;if(!top)putchar('0');while(top)putchar(sta[top]+'0'),--top;putchar('.');for(int i=0;i<Setprecision;i++)x*=10;_=x;while(_)sta[++top]=_%10,_/=10;for(int i=0;i<Setprecision-top;i++)putchar('0');while(top)putchar(sta[top]+'0'),--top;return*this;}Writer&operator<<(long double x){if(x<0)putchar('-'),x=-x;mxdouble _=x;x-=(long double)_;static int sta[45];int top=0;while(_)sta[++top]=_%10,_/=10;if(!top)putchar('0');while(top)putchar(sta[top]+'0'),--top;putchar('.');for(int i=0;i<Setprecision;i++)x*=10;_=x;while(_)sta[++top]=_%10,_/=10;for(int i=0;i<Setprecision-top;i++)putchar('0');while(top)putchar(sta[top]+'0'),--top;return*this;}Writer&operator<<(__float128 x){if(x<0)putchar('-'),x=-x;mxdouble _=x;x-=(__float128)_;static int sta[45];int top=0;while(_)sta[++top]=_%10,_/=10;if(!top)putchar('0');while(top)putchar(sta[top]+'0'),--top;putchar('.');for(int i=0;i<Setprecision;i++)x*=10;_=x;while(_)sta[++top]=_%10,_/=10;for(int i=0;i<Setprecision-top;i++)putchar('0');while(top)putchar(sta[top]+'0'),--top;return*this;}Writer&operator<<(char c){putchar(c);return*this;}Writer& operator<<(char*str){int cur=0;while(str[cur])putchar(str[cur++]);return *this;}Writer&operator<<(const char*str){int cur=0;while(str[cur])putchar(str[cur++]);return*this;}Writer&operator<<(std::string str){int st=0,ed=str.size();while(st<ed)putchar(str[st++]);return*this;}Writer(){}}cout;}
#if use_fastio==1
#define cin Fastio :: cin
#define cout Fastio :: cout
#define endl Fastio :: endl
#endif
#if use_long_long==1
#define int long long
#endif
//constants-constants-constants-constants-constants-constants-constants-constants-constants-constants-constants-constants-constants-constants-constants-constants
                                                                    #define N                      200002
                                                                    #define eps                    1e-10
                                                                    #define p                      998244353
                                                                    #undef N
                                                                    #undef p
//constants-constants-constants-constants-constants-constants-constants-constants-constants-constants-constants-constants-constants-constants-constants-constants
#if (use_qp==1||use_C==1||use_inv==1)
#ifdef p
int qp(int x,int n=p-2,int P=p){int r=1;while(n){if(n&1)r=r*x%P;x=x*x%P,n>>=1;}return r;}
#else
int qp(int x,int n,int P){int r=1;while(n){if(n&1)r=r*x%P;x=x*x%P,n>>=1;}return r;}
#endif
#endif
#if (use_C==1||use_inv==1)
int fac[N+100],ifac[N+100];
void init(int n,int P=p){fac[0]=1;for(int x=1;x<=n;x++)fac[x]=fac[x-1]*x%P;ifac[n]=qp(fac[n],P-2,P);for(int x=n;x>=1;x--)ifac[x-1]=ifac[x]*x%P;}
int C(int x,int y,int P=p){if(x<y||y<0)return 0;return fac[x]*ifac[y]%P*ifac[x-y]%P;}
int iC(int x,int y,int P=p){if(x<y||y<0)return 0;return ifac[x]*fac[y]%P*fac[x-y]%P;}
int inv(int x,int P=p){return iC(x,1,P);}
#endif
#if use_BIT==1
void add(int n,int u,int *a,int U=N){for(int x=n;x<=U;x+=x&-x)a[x]+=u;}
int query(int n, int *a){int r=0;for(int x=n;x;x-=x&-x)r+=a[x];return r;}
#endif
#define exmax(a,...) (max({a,##__VA_ARGS__}))
#define exmin(a,...) (min({a,##__VA_ARGS__}))
#define mymax(x, y)  ({__typeof(x) _x = x;__typeof(y) _y = y;_x > _y ? _x : _y;})
#define mymin(x, y)  ({__typeof(x) _x = x;__typeof(y) _y = y;_x < _y ? _x : _y;})
#define ff(a,l,r) for(int a=l;a<=r;a++)
#define fb(a,r,l) for(int a=r;a>=l;a--)
void Init_for_all_task()
{
#if (use_C==1||use_inv==1)
init(N+10);
#endif
//111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111//
//111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111//
}
/*main-head---------------------------------------------------------------------------------------*/
//222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222//
//222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222//
/*default-var-------------------------------------------------------------------------------------*/
namespace nz{
/*namespace-head----------------------------------------------------------------------------------*/
//333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333//
//333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333//
/*var-and-func------------------------------------------------------------------------------------*/
void Main(){
struct custom_hash{static uint64_t splitmix64(uint64_t x) {x += 0x9e3779b97f4a7c15;x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;x = (x ^ (x >> 27)) * 0x94d049bb133111eb;return x ^ (x >> 31);}size_t operator()(uint64_t x) const {static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();return splitmix64(x + FIXED_RANDOM);}};
/*Main-head---------------------------------------------------------------------------------------*/
//444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444//
//when using um,us,gp or cc,add a hash function named custom_hash,use it like unordered_map<int,int,custom_hash>
//also,if want to hack them,https://codeforces.com/blog/entry/62393 is a good choise.
const int =64;
int n,m;
cin>>n>>m;
unordered_map<int,int,custom_hash>um,un,uf;
struct www
{
    int qwq[11];
    int w;
}a[n+1];
for(int x=1;x<=n;x++)
{
    for(int y=1;y<=m;y++)
    {
        int z;
        cin>>z;
        if(!um[z])um[z]=um.size();
        a[x].qwq[y]=um[z];
        un[um[z]]++;
    }
    cin>>a[x].w;
}
sort(a+1,a+1+n,[](www a,www b)->bool{return a.w<b.w;});
/*for(int x=1;x<=n;x++)
{
    for(int y=1;y<=m;y++)
    cout<<a[x].qwq[y]<<' ';
    cout<<a[x].w<<endl;
}*/
int B=sqrt(1.0*n*n/m/);
vector<int>cs[n+1];
vector<bitset<100005>>qd(1);
for(int x=1;x<=n;x++)
for(int y=1;y<=m;y++)
if(un[a[x].qwq[y]]>B){
    if(!uf[a[x].qwq[y]])uf[a[x].qwq[y]]=uf.size(),qd.push_back(bitset<100005>());
    qd[uf[a[x].qwq[y]]][x]=1;
}
else cs[x].push_back(a[x].qwq[y]);
/*for(int x=1;x<=6;x++){
for(int y=1;y<=n;y++)
cout<<qd[x][y];cout<<endl;}*/
int ans=10000000000;
for(int y=1;y<=n;y++)
{
    bitset<100005>qqdd;
    for(int x=1;x<=m;x++)
    if(un[a[y].qwq[x]]>B)qqdd|=qd[uf[a[y].qwq[x]]]/*,cout<<x<<',';cout<<endl*/;
    qqdd.flip();
    qqdd[0]=0;
    /*for(int x=1;x<=n;x++)
    cout<<qqdd[x];cout<<endl;*/
    for(int x=qqdd._Find_first();x<=n;x=qqdd._Find_next(x))
    {
        bool bo=true;
        for(auto q:cs[y])
        if(bo)
        for(auto w:cs[x])
        if(q==w){bo=false;break;}
        else ;
        else break;
        if(bo){ans=min(ans,a[y].w+a[x].w);/*cout<<x<<','<<y<<','<<a[x].w<<','<<a[y].w<<endl;*/break;}
    }
}
if(ans==10000000000)cout<<-1<<endl;
else cout<<ans<<endl;
//444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444//
/*Main-end----------------------------------------------------------------------------------------*/
}
/*Main-end----------------------------------------------------------------------------------------*/
}
/*namespace-end-----------------------------------------------------------------------------------*/
main()
{
    Init_for_all_task();
#if use_multiple_test_data==1
    int t;cin>>t;while(t--)
#endif
    nz::Main();
}
/*main-end----------------------------------------------------------------------------------------*/