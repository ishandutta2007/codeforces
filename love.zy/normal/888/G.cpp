#include<cstdio>
#include<algorithm>
const int N=200010,M=N*32;
int n,i,a[N],q[N],son[M][2],tot;long long ans;
inline void ins(int p){
  for(int o=29,x=0;~o;o--){
    int w=p>>o&1;
    if(!son[x][w])son[x][w]=++tot;
    x=son[x][w];
  }
}
inline int ask(int p){
  int t=0;
  for(int o=29,x=0;~o;o--){
    int w=p>>o&1;
    if(son[x][w])x=son[x][w];else x=son[x][w^1],t|=1<<o;
  }
  return t;
}
void solve(int o,int l,int r){
  if(o<0||l>r)return;
  int L=l-1,R=r+1;
  for(int i=l;i<=r;i++)if(a[i]>>o&1)q[++L]=a[i];else q[--R]=a[i];
  for(int i=l;i<=r;i++)a[i]=q[i];
  solve(o-1,l,L),solve(o-1,R,r);
  if(l>L||R>r)return;
  for(int i=l;i<=L;i++)ins(a[i]);
  int ret=~0U>>1;
  for(int i=R;i<=r;i++)ret=std::min(ret,ask(a[i]));
  ans+=ret;
  for(int i=0;i<=tot;i++)son[i][0]=son[i][1]=0;
  tot=0;
}
int main(){
  scanf("%d",&n);
  for(i=1;i<=n;i++)scanf("%d",&a[i]);
  solve(29,1,n);
  printf("%I64d",ans);
  return 0;
}