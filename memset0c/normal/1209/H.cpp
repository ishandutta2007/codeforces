#include<bits/stdc++.h>
using f64=long double;
const int N=4e5+10;
const f64 eps=1e-9;
int n,m,L,al[N],ar[N],s[N];
f64 ans,f[N],l[N],r[N],v[N],av[N],sum[N];
std::vector<int> id;
struct Segment{
  int l,r,mid;
  f64 min,tag;
}p[N<<2];
inline void pushup(int u,f64 x){p[u].min+=x,p[u].tag+=x;}
inline void pushdown(int u){pushup(u<<1,p[u].tag),pushup(u<<1|1,p[u].tag),p[u].tag=0;}
void build(int u,int l,int r){
  p[u].l=l,p[u].r=r,p[u].mid=(l+r)>>1;
  if(l==r)return p[u].min=sum[l],void(0);
  build(u<<1,l,p[u].mid);
  build(u<<1|1,p[u].mid+1,r);
  p[u].min=std::min(p[u<<1].min,p[u<<1|1].min);
}
void modify(int u,int l,int r,f64 x){
  if(p[u].l==l&&p[u].r==r)return pushup(u,-x);
  pushdown(u);
  if(r<=p[u].mid)modify(u<<1,l,r,x);
  else if(l>p[u].mid)modify(u<<1|1,l,r,x);
  else modify(u<<1,l,p[u].mid,x),modify(u<<1|1,p[u].mid+1,r,x);
  p[u].min=std::min(p[u<<1].min,p[u<<1|1].min);
}
f64 query(int u,int l,int r){
  if(p[u].l==l&&p[u].r==r)return p[u].min;
  pushdown(u);
  if(r<=p[u].mid)return query(u<<1,l,r);
  if(l>p[u].mid)return query(u<<1|1,l,r);
  return std::min(query(u<<1,l,p[u].mid),query(u<<1|1,p[u].mid+1,r));
}
int main(){
#ifdef memset0
  freopen("1.in","r",stdin);
#endif
  scanf("%d%d",&n,&L),ar[0]=0,al[n+1]=L;
  for(int i=1;i<=n;i++)scanf("%d%d",&al[i],&ar[i]),std::cin>>av[i];
  for(int i=0;i<=n;i++){
    if(i)++m,s[m]=ar[i]-al[i],v[m]=av[i]+1;
    if(ar[i]!=al[i+1])++m,s[m]=al[i+1]-ar[i],v[m]=1;
  }
  for(int i=1;i<=m;i++){
    id.push_back(i);
    f[i]=1/v[i];
    l[i]=-s[i]/(v[i]+1);
    r[i]=s[i]/(v[i]-1);
  }
  f64 lim=-std::accumulate(l+1,l+m+1,(f64)0);
  for(int i=1;i<=m;i++){
    r[i]=std::min(r[i],lim);
    sum[i]=sum[i-1]+r[i];
    ans+=s[i]/v[i]+r[i]*f[i];
  }
  std::sort(id.begin(),id.end(),[](int x,int y){return f[x]==f[y]?x<y:f[x]>f[y];});
  // for(int i=1;i<=m;i++)printf("[%d] s=%d v=%.2Lf f=%.2Lf l=%.2Lf r=%.2Lf\n",i,s[i],v[i],f[i],l[i],r[i]);
  build(1,1,m);
  // for(int i=1;i<=m;i++)printf("%.3Lf%c",sum[i]," \n"[i==m]);
  for(int i:id){
    f64 x=std::min(r[i]-l[i],query(1,i,m));
    ans-=x*f[i];
    // printf("%d %.6Lf %.6Lf : %.4Lf %.4Lf\n",i,r[i]-x,f[i],x,ans);
    modify(1,i,m,x);
    // for(int i=1;i<=m;i++)printf("%.2Lf%c",query(1,i,i)," \n"[i==m]);
  }
  std::cout<<std::setprecision(10)<<ans<<std::endl;
}