#include<bits/stdc++.h>
template<class T> inline void read(T &x){
  x=0; register char c=getchar(); register bool f=0;
  while(!isdigit(c))f^=c=='-',c=getchar();
  while(isdigit(c))x=x*10+c-'0',c=getchar(); if(f)x=-x;
}
const int N=1e6+10;
int n,m,ans,a[N],tmp[N];
struct Query{
  int k,v;
}q[N];
struct Segment{
  int l,r,mid,min,cnt,tag;
}p[N<<2];
inline void pushup(int u,int x){p[u].min+=x,p[u].tag+=x;}
inline void pushdown(int u){if(p[u].tag)pushup(u<<1,p[u].tag),pushup(u<<1|1,p[u].tag),p[u].tag=0;}
inline void maintain(int u){
  p[u].min=std::min(p[u<<1].min,p[u<<1|1].min);
  p[u].cnt=(p[u].min==p[u<<1].min?p[u<<1].cnt:0)+(p[u].min==p[u<<1|1].min?p[u<<1|1].cnt:0);
}
void build(int u,int l,int r){
  p[u].l=l,p[u].r=r,p[u].mid=(l+r)>>1;
  if(l==r)return;
  build(u<<1,l,p[u].mid);
  build(u<<1|1,p[u].mid+1,r);
}
void affect(int u,int k,int x){
  if(p[u].l==p[u].r)return p[u].cnt+=x,void(0);
  pushdown(u);
  affect(k<=p[u].mid?u<<1:u<<1|1,k,x);
  maintain(u);
}
void modify(int u,int l,int r,int x){
  if(p[u].l==l&&p[u].r==r)return pushup(u,x);
  pushdown(u);
  if(r<=p[u].mid)modify(u<<1,l,r,x);
  else if(l>p[u].mid)modify(u<<1|1,l,r,x);
  else modify(u<<1,l,p[u].mid,x),modify(u<<1|1,p[u].mid+1,r,x);
  maintain(u);
}
void active(int k,int x){
  if(a[k]<a[k+1]){
    modify(1,a[k]+1,a[k+1],x);
  }else{
    modify(1,a[k+1]+1,a[k],x);
  }
}
int main(){
#ifdef memset0
  freopen("1.in","r",stdin);
#endif
  read(n),read(m);
  for(int i=1;i<=n;i++)read(a[i]);
  for(int i=1;i<=m;i++)read(q[i].k),read(q[i].v);
  a[0]=1919810,a[n+1]=-114514;
  for(int i=0;i<=n+1;i++)tmp[++*tmp]=a[i];
  for(int i=1;i<=m;i++)tmp[++*tmp]=q[i].v;
  std::sort(tmp+1,tmp+*tmp+1);
  *tmp=std::unique(tmp+1,tmp+*tmp+1)-tmp-1;
  for(int i=0;i<=n+1;i++)a[i]=std::lower_bound(tmp+1,tmp+*tmp+1,a[i])-tmp;
  for(int i=1;i<=m;i++)q[i].v=std::lower_bound(tmp+1,tmp+*tmp+1,q[i].v)-tmp;
  build(1,2,*tmp);
  for(int i=0;i<=n;i++)active(i,1);
  for(int i=1;i<=n;i++)affect(1,a[i],1);
  for(int i=1;i<=m;i++){
    active(q[i].k-1,-1),active(q[i].k,-1),affect(1,a[q[i].k],-1);
    a[q[i].k]=q[i].v;
    active(q[i].k-1,1),active(q[i].k,1),affect(1,a[q[i].k],1);
    printf("%d\n",p[1].min==1?p[1].cnt:0);
  }
}