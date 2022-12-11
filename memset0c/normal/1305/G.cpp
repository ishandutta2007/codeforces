#include<bits/stdc++.h>
template<class T> inline void read(T &x){
  x=0; register char c=getchar(); register bool f=0;
  while(!isdigit(c))f^=c=='-',c=getchar();
  while(isdigit(c))x=x*10+c-'0',c=getchar(); if(f)x=-x;
}
const int N=2.7e5;
int n,max,lim,a[N],fa[N],cnt[N];
long long ans;
int find(int x){return fa[x]==x?x:fa[x]=find(fa[x]);}
void merge(int u,int v,long long w){
  if(cnt[u]&&cnt[v]){
    u=find(u),v=find(v);
    if(u!=v){
      // printf("merge %d[%d] %d[%d] => %lld * %d\n",u,cnt[u],v,cnt[v],w,cnt[u]+cnt[v]-1);
      ans+=w*(cnt[u]+cnt[v]-1);
      fa[u]=v,cnt[v]=1;
    }
  }
}
int main(){
#ifdef memset0
  freopen("1.in","r",stdin);
#endif
  read(n),cnt[0]=1;
  for(int i=1;i<=n;i++){
    read(a[i]),cnt[a[i]]++;
    ans-=a[i];
    max=std::max(max,a[i]);
  }
  int lim=1<<32-__builtin_clz(max);
  for(int i=0;i<lim;i++)fa[i]=i;
  for(int i=lim-1;~i;i--){
    for(int j=i;j;j=(j-1)&i)if(cnt[j]&&cnt[i^j])merge(j,i^j,i);
    merge(i,0,i);
  }
  printf("%lld\n",ans);
}