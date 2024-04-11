#include<bits/stdc++.h>
template<class T> inline void read(T &x){
  x=0;register char c=getchar();register bool f=0;
  while(!isdigit(c))f^=c=='-',c=getchar();
  while(isdigit(c))x=x*10+c-'0',c=getchar();if(f)x=-x;
}
template<class T> inline void print(T x){
  if(x<0)putchar('-'),x=-x;
  if(x>9)print(x/10);putchar(x%10+'0');
}
template<class T> inline void print(T x,char c){print(x),putchar(c);}
std::mt19937 rng(20040725^std::chrono::steady_clock::now().time_since_epoch().count());
template<class T> inline T rand(T l,T r){return std::uniform_int_distribution<T>(l,r)(rng);}
template<class T> inline T gcd(T n,T m){return m?gcd(m,n%m):n;}
const int N=5e5+10,p1=998244353,p2=1e9+7,seed=131131;
int T,n,m;
long long ans,c[N];
std::vector<int> G[N];
std::pair<long long,long long> g[N];
std::map<std::pair<long long,long long>,long long> map;
int main(){
#ifdef memset0
  freopen("1.in","r",stdin);
#endif
  for(read(T);T--;){
    read(n),read(m),ans=0,map.clear();
    for(int i=1;i<=n;i++)read(c[i]),G[i].clear();
    for(int i=1,u,v;i<=m;i++)read(u),read(v),G[v].push_back(u);
    for(int i=1;i<=n;i++){
      std::sort(G[i].begin(),G[i].end());
      g[i].first=g[i].second=0;
      for(int x:G[i]){
        g[i].first=((long long)g[i].first*seed+x)%p1;
        g[i].second=((long long)g[i].second*seed+x)%p2;
      }
    }
    // for(int i=1;i<=n;i++)printf("%lld : %lld %lld\n",c[i],g[i].first,g[i].second);
    // for(int i=1;i<=n;i++)map[g[i]]+=c[i];
    for(int i=1;i<=n;i++)if(G[i].size())map[g[i]]+=c[i];
    for(const auto &it:map){
      // printf(">> %lld %lld : %lld\n",it.first.first,it.first.second,it.second);
      ans=gcd(ans,it.second);
    }
    print(ans),putchar('\n');
  }
}