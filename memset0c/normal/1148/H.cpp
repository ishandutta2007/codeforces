#include<bits/stdc++.h>
using namespace std;
using i64=long long;
template<class T> inline void read(T &x){
  x=0; register char c=getchar(); register bool tr=0;
  while(!isdigit(c))tr^=c=='-',c=getchar();
  while(isdigit(c))x=x*10+c-'0',c=getchar(); if(tr)x=-x;
}
template<class T> inline void print(T x){
  if(x<0)putchar('-'),x=-x;
  if(x>9)print(x/10); putchar(x%10+'0');
}
template<class T> inline void print(T x,char c){print(x),putchar(c);}
const int N=2e5+10;
int n,rt[N];
struct PersistentSegmentTree{
  int nod,rt[N];
  struct Segment{
    int lc,rc;
    pair<int,i64> x;
  }p[N<<6];
  void build(int &u,int l,int r){
    u=++nod;
    if(l==r)return;
    int mid=(l+r)>>1;
    build(p[u].lc,l,mid);
    build(p[u].rc,mid+1,r);
  }
  void modify(int &u,int v,int ql,int qr,const pair<int,i64> &x,int l,int r){
    // printf("modify %d %d %d %d <%d %lld> %d %d\n",u,v,ql,qr,x.first,x.second,l,r);
    p[u=++nod]=p[v];
    if(ql==l&&qr==r){
      p[u].x.first+=x.first;
      p[u].x.second+=x.second;
      return;
    }
    int mid=(l+r)>>1;
    if(qr<=mid)modify(p[u].lc,p[v].lc,ql,qr,x,l,mid);
    else if(ql>mid)modify(p[u].rc,p[v].rc,ql,qr,x,mid+1,r);
    else{
      modify(p[u].lc,p[v].lc,ql,mid,x,l,mid);
      modify(p[u].rc,p[v].rc,mid+1,qr,x,mid+1,r);
    }
  }
  int query(int u,int k,int l,int r){
    int res=p[u].x.first;
    if(l==r)return res;
    int mid=(l+r)>>1;
    if(k<=mid)return res+query(p[u].lc,k,l,mid);
    return res+query(p[u].rc,k,mid+1,r);
  }
  i64 querySum(int u,int k,int x,int l,int r){
    i64 res=(i64)p[u].x.first*x+p[u].x.second;
    if(l==r)return res;
    int mid=(l+r)>>1;
    if(k<=mid)return res+querySum(p[u].lc,k,x,l,mid);
    return res+querySum(p[u].rc,k,x,mid+1,r);
  }
  inline void build(){build(rt[0],0,n+1);}
  inline void modify(int t,int l,int r,const pair<int,i64> &x){modify(rt[t],rt[t],l,r,x,0,n+1);}
  inline int query(int t,int k){return query(rt[t],k,0,n+1);}
  inline i64 querySum(int t,int k){return querySum(rt[t],k,t,0,n+1);}
}tr;
struct Segment{
  int l,r,mid,min;
}p[N<<2];
void build(int u,int l,int r){
  p[u].l=l,p[u].r=r,p[u].mid=(l+r)>>1;
  if(l==r)return;
  build(u<<1,l,p[u].mid);
  build(u<<1|1,p[u].mid+1,r);
}
void modify(int u,int k,int v){
  if(p[u].l==p[u].r)return p[u].min=v,void(0);
  modify(k<=p[u].mid?u<<1:u<<1|1,k,v);
  p[u].min=min(p[u<<1].min,p[u<<1|1].min);
}
int query(int u,int l,int r){
  if(p[u].l==l&&p[u].r==r)return p[u].min;
  if(r<=p[u].mid)return query(u<<1,l,r);
  if(l>p[u].mid)return query(u<<1|1,l,r);
  return min(query(u<<1,l,p[u].mid),query(u<<1|1,p[u].mid+1,r));
}
int queryTarget(int u,int tar,int min){
  if(p[u].l==p[u].r)return p[u].l;
  if(std::min(min,p[u<<1].min)>=tar){
    return queryTarget(u<<1|1,tar,std::min(min,p[u<<1].min));
  }else{
    return queryTarget(u<<1,tar,min);
  }
}
int main(){
#ifdef memset0
  freopen("1.in","r",stdin);
#endif
  read(n);
  tr.build();
  build(1,0,n+1);
  auto Modify=[&](int k,int x){
    // printf("Modify %d %d\n",k,x);
    tr.rt[k]=tr.rt[k-1];
    function<void(int)> Update=[&](int i){
      if(i>n+1)return;
      int old=tr.query(k-1,i),cur=query(1,0,i-1);
      if(cur==old)return;
      int res=queryTarget(1,cur,cur);
      tr.modify(k,i,res,{cur-old,-(i64)(k-1)*(cur-old)});
      Update(res+1);
    };
    tr.modify(k,0,0,{1,-k+1});
    modify(1,x,k);
    Update(x+1);
    // printf("g[%d] = ",k); for(int i=0;i<=n;i++)printf("%d%c",tr.query(k,i)," \n"[i==n]);
  };
  auto Query=[&](int l,int r,int k){
    // printf("Query %d %d %d\n",l,r,k);
    auto Calc=[&](int k){
      int res=l-1,ql=l,qr=r,mid;
      while(ql<=qr)(tr.query(mid=(ql+qr)>>1,k)<=l-1)?(res=mid,ql=mid+1):(qr=mid-1);
      // for(int i=l-1;i<=r;i++)printf("[%d %lld]%c",tr.query(i,k),tr.querySum(i,k)," \n"[i==r]);
      i64 ans=tr.querySum(r,k)-tr.querySum(res,k)+(i64)(res-l+1)*(l-1);
      // printf("Calc %d | l=%d r=%d res=%d |=> %lld\n",k,l,r,res,ans);
      return ans;
    };
    return Calc(k)-Calc(k+1);
  };
  long long lastans=0;
  for(int x,l,r,k,i=1;i<=n;i++){
    read(x),read(l),read(r),read(k);
    x=(x+lastans)%(n+1);
    l=(l+lastans)%i+1;
    r=(r+lastans)%i+1;
    k=(k+lastans)%(n+1);
    if(l>r)swap(l,r);
    Modify(i,x);
    print(lastans=Query(l,r,k),'\n');
  }
}