#pragma GCC optimize("O3")
#ifdef ONLINE_JUDGE
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#endif
#pragma GCC optimize("unroll-loops")
#pragma comment(linker, "/stack:200000000")
#include <bits/stdc++.h>
#include <deque>
#include <type_traits>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
template<typename KeyType=int,typename Mapped=__gnu_pbds::null_type,typename Cmp_Fn=std::less<KeyType>,typename Tag=__gnu_pbds::rb_tree_tag,template<typename Const_Node_Iterator,typename Node_Iterator,typename Cmp_Fn_,typename Allocator_>class Node_Update=__gnu_pbds::tree_order_statistics_node_update,typename Allocator=std::allocator<char>>using ordered_set_t=__gnu_pbds::tree<KeyType,Mapped,Cmp_Fn,Tag,Node_Update,Allocator>;const int GRANDOM=std::chrono::high_resolution_clock::now().time_since_epoch().count();struct ghash{int operator()(int x){return std::hash<int>{}(x^GRANDOM);}};template<typename KeyType>using hash_table_t=__gnu_pbds::gp_hash_table<KeyType,int,ghash>;namespace vh{template<class T>struct like_array:is_array<T>{};template<class T,size_t N>struct like_array<array<T,N>>:true_type{};template<class T>struct like_array<vector<T>>:true_type{};template<class T>bool is_like_array(const T&a){return like_array<T>::value;}template<class T>void _R(T&x){std::cin>>x;}inline void _R(int&x){scanf("%d",&x);}inline void _R(int64_t&x){scanf("%" SCNd64,&x);}inline void _R(double&x){scanf("%lf",&x);}inline void _R(char&x){scanf(" %c",&x);}inline void _R(char*x){scanf("%s",x);}template<typename T>inline void _R(vector<T>&v,size_t ie){for(int i=0;i<ie;i++)_R(v[i]);}template<typename T>inline void _R(vector<T>&v){_R(v,v.size());}inline void R(){}template<class T,class... U>inline void R(T&head,U&... tail){_R(head);R(tail...);}template<class T>void _W(const T&x){cout<<x;}template<typename T>inline void _W(vector<T>&v,size_t ie){for(int i=0;i<ie;i++){if(i>0)_W(' ');_W(v[i]);}_W('\n');}template<typename T>inline void _W(vector<T>&v){_W(v,v.size());}template<class T>inline void _W(const vector<T>&x){for(auto i=x.begin();i!=x.end();_W(*i++))if(i!=x.cbegin())putchar(' ');}inline void W(){}template<class T,class... U>inline void W(const T&head,const U&... tail){_W(head);if(sizeof...(tail))putchar(' '),W(tail...);}template<class T,class... U>inline void WL(const T&head,const U&... tail){_W(head);putchar(sizeof...(tail)? ' ':'\n');W(tail...);}template<class T>void _RE(T&x){cin>>x;}template<class Arg,class... Args>void _RE(Arg&first,Args&... rest);void _RE(double&x){string t;_RE(t);x=stod(t);}void _RE(long double&x){string t;_RE(t);x=stold(t);}template<class T>void _RE(complex<T>&x);template<class T1,class T2>void _RE(pair<T1,T2>&p);template<class T>void _RE(vector<T>&a);template<class T,size_t SZ>void _RE(array<T,SZ>&a);template<class Arg,class... Args>void _RE(Arg&first,Args&... rest){_RE(first);_RE(rest...);}template<class T>void _RE(complex<T>&x){T a,b;_RE(a,b);x=cd(a,b);}template<class T1,class T2>void _RE(pair<T1,T2>&p){_RE(p.f,p.s);}template<class T>void _RE(vector<T>&a){for(int i=0,ie=sz(a);i<ie;i++)_RE(a[i]);}template<class T,size_t SZ>void _RE(array<T,SZ>&a){for(int i=0;i<SZ;i++)_RE(a[i]);}};
#define prec setprecision
namespace vh{typedef long long ll;typedef unsigned long long llu;template<typename T>T gcd(T m,T n){while(n){T t=m%n;m=n;n=t;};return m;}template<typename T>T exgcd(T a,T b,T&sa,T&ta){T q,r,sb=0,tb=1,sc,tc;sa=1,ta=0;if(b)do q=a/b,r=a-q*b,a=b,b=r,sc=sa-q*sb,sa=sb,sb=sc,tc=ta-q*tb,ta=tb,tb=tc;while(b);return a;}template<typename T>T mul_inv(T a,T b){T t1=a,t2=b,t3;T v1=1,v2=0,v3;T x;while(t2!=1)x=t1/t2,t3=t1-x*t2,v3=v1-x*v2,t1=t2,t2=t3,v1=v2,v2=v3;return(v2+b)%b;}template<typename T>T powmod(T a,T b,T MOD){if(b<0)return 0;T rv=1;while(b)(b%2)&&(rv=(rv*a)%MOD),a=a*a%MOD,b/=2;return rv;}template<typename T>inline T isqrt(T k){T r=sqrt((double)k)+1;while(r*r>k)r--;return r;}template<typename T>inline T icbrt(T k){T r=cbrt((double)k)+1;while(r*r*r>k)r--;return r;}template<typename T>bool mul_overflow(T&r,T a,T b){return __builtin_mul_overflow(a,b,&r);}template<ll n>struct BitSize{enum{Size=BitSize<n/2>::Size+1};};template<>struct BitSize<0>{enum{Size=1};};template<>struct BitSize<1>{enum{Size=1};};
#define BITSIZE(n) (BitSize<n>::Size)
#define TREESIZE(n) ((1<<(BitSize<n>::Size + 1))+7)
#define BITMAX(n) (BitSize<n>::Size - 1)
#define DEBUG !defined(ONLINE_JUDGE)
#define SZ(x) ((int)(x).size())
#define ALL(x) begin(x), end(x)
#define RALL(x) (x).rbegin(),(x).rend()
template<typename TH>void _dbg(const char*sdbg,TH h){cerr<<sdbg<<"="<<h<<"\n";}template<typename TH,typename... TA>void _dbg(const char*sdbg,TH h,TA... t){while(*sdbg!=',')cerr<<*sdbg++;cerr<<"="<<h<<",";_dbg(sdbg+1,t...);}
#ifdef DEBUG
#define debug(...) _dbg(#__VA_ARGS__, __VA_ARGS__)
#define debugv(x) {{cerr <<#x <<" = "; for(auto itt: x) cerr <<*itt <<", "; cerr <<"\n"; }}
#else
#define debug(...) (__VA_ARGS__)
#define debugv(x)
#define cerr if(0)cout
#endif
}namespace vh{template<typename T>int min_rotation(vector<T>s){int a=0,N=s.size();for(int b=0;b<N;b++)for(int i=0;i<N;i++){if(a+i==b||s[(a+i)%N]<s[(b+i)%N]){b+=max(0,i-1);break;}if(s[(a+i)%N]>s[(b+i)%N]){a=b;break;}}return a;};template<typename T>class StackGuard{private:T x;public:StackGuard(T x):x(x){}~StackGuard(){x();}};}namespace vh{};
namespace vh{
  int n,m;
  int _a[12][2002];
  int a[12][12];
  int solve(){
    cin>>n>>m;
    for(int i=0;i<n;i++){
      for(int j=0;j<m;j++)cin>>_a[i][j];
    }
    if(m>n){
      vector<pair<int,int>>va;
      for(int i=0;i<m;i++){
        int x=0;
        for(int j=0;j<n;j++)x=max(x,_a[j][i]);
        va.push_back({-x,i});
      }
      sort(va.begin(),va.end());
      for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
          a[i][j]=_a[i][va[j].second];
        }
      }
      m=n;
    }else{
      for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
          a[i][j]=_a[i][j];
        }
      }
    }
    int nx=1<<n;
    int nm=nx-1;
    vector<int>dp(1<<n);
    for(int i=0;i<m;i++){
      vector<int>prev=dp;
      for(int d=0;d<n;d++){
        vector<int>curr=prev;
        for(int x=0;x<nx;x++){
          for(int j=0;j<n;j++){
            if((x>>j&1))curr[x]=max(curr[x],curr[x^(1<<j)]+a[(j+d)%n][i]);
          }
          dp[x]=max(dp[x],curr[x]);
        }
      }
    }
    return dp[nm];
  }
  int main(){
    srand(GRANDOM);
    int t;cin>>t;
    while(t--){
      cout<<solve()<<'\n';
    }
    return 0;
  }
};
int main(int argc,char*argv[]){
  std::cin.sync_with_stdio(false);std::cin.tie(nullptr);
  return vh::main();
}