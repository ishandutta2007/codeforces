#include<bits/stdc++.h>
const int S=1<<21; char ibuf[S],*iS,*iT,obuf[S],*oS=obuf,*oT=oS+S-1;
#define flush() (fwrite(obuf,1,oS-obuf,stdout),oS=obuf,void())
#define getchar() (iS==iT?(iT=(iS=ibuf)+fread(ibuf,1,S,stdin),(iS==iT?EOF:*iS++)):*iS++)
#define putchar(x) (*oS++=(x),oS==oT?flush():void())
struct Flusher_{~Flusher_(){flush();}}flusher_;
template<class T> inline void read(T &x){
  x=0; register char c=getchar(); register bool f=0;
  while(!isdigit(c))f^=c=='-',c=getchar();
  while(isdigit(c))x=x*10+c-'0',c=getchar(); if(f)x=-x;
}
template<class T> inline void print(T x){
  if(x<0)putchar('-'),x=-x;
  if(x>9)print(x/10); putchar(x%10+'0');
}
template<class T> inline void print(T x,char c){print(x),putchar(c);}
template<class T> inline void setmin(T &x,T y){if(y<x)x=y;}
const int N=1e5+10,M=2e3+10;
int n,m,k,same;
bool vis[N];
long long dis[N];
std::tuple<int,int,int,size_t> e[N];
std::vector<std::pair<int,int>> G[N];
struct Query{
  int o,c;
  std::vector<int> v;
}q[M];
template<class T> struct RadixHeap{
  static const T inf=std::numeric_limits<T>::max();
  static const size_t bit=std::numeric_limits<T>::digits;
  RadixHeap():sz(0),last(0){std::fill(vm,vm+bit+1,inf);}
  static inline int pos(int x){return !x?0:32-__builtin_clz(x);}
  static inline int pos(long long x){return !x?0:64-__builtin_clzll(x);}
  inline void push(T x,int y){
    const auto vi=pos(x^last);
    v[vi].emplace_back(x,y),++sz,setmin(vm[vi],x);
  }
  inline std::pair<T,int> get(){
    if(v[0].empty()){
      int i=1;while(v[i].empty())++i;
      last=vm[i];
      for(const auto &p:v[i]){
        const auto vi=pos(p.first^last);
        v[vi].emplace_back(p),setmin(vm[vi],p.first);
      }
      v[i].clear(),vm[i]=inf;
    }
    return v[0].back();
  }
  inline std::pair<T,int> pop(){const auto ret=get();v[0].pop_back(),--sz;return ret;}
  inline std::pair<T,int> top(){return get();}
  inline bool empty()const{return !sz;}
  inline int size()const{return sz;}
  std::vector<std::pair<T,int>> v[bit+1];
  T last,vm[bit+1];
  int sz;
};
void dij(){
  static RadixHeap<long long> q;
  if(same)return;
  same=true;
  memset(vis,0,sizeof(vis));
  memset(dis,63,sizeof(dis));
  dis[1]=0;
  q.push(0,1);
  while(q.size()){
    int u=q.pop().second;
    if(vis[u])continue; vis[u]=true;
    for(const auto &e:G[u])
      if(dis[u]+e.second<dis[e.first]){
        dis[e.first]=e.second+dis[u];
        q.push(dis[e.first],e.first);
      }
  }
}
int main(){
#ifdef memset0
  freopen("1.in","r",stdin);
#endif
  read(n),read(m),read(k);
  for(int u,v,w,i=1;i<=m;i++){
    read(u),read(v),read(w);
    e[i]={u,v,w,G[u].size()};
    G[u].push_back({v,w});
  }
  int cnt=0;
  for(int i=1;i<=k;i++){
    read(q[i].o),read(q[i].c);
    if(q[i].o==2){
      q[i].v.resize(q[i].c);
      for(int j=0;j<q[i].c;j++)read(q[i].v[j]);
    }
    cnt+=q[i].o==1;
  }
  bool flag=cnt<=(k>>1);
  dij();
  for(int i=1;i<=k;i++)
    if(q[i].o==1){
      if(flag)dij();
      print(dis[q[i].c]>1e18?-1:dis[q[i].c],'\n');
    }else{
      same=false;
      for(int l:q[i].v){
        G[std::get<0>(e[l])][std::get<3>(e[l])].second++;
      }
      if(!flag)dij();
    }
}