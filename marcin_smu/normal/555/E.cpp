#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> PI;
typedef long long LL;
typedef double D;
#define FI first
#define SE second
#define MP make_pair
#define PB push_back
#define R(I,N) for(int I=0;I<N;I++)
#define F(I,A,B) for(int I=A;I<B;I++)
#define FD(I,N) for(int I=N-1;I>=0;I--)
#define make(A) scanf("%d",&A)
#define make2(A,B) scanf("%d%d",&A,&B)
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())
#define db if(1)printf
template<typename C> void MA(C& a,C b){if(a<b)a=b;}
template<typename C> void MI(C& a,C b){if(a>b)a=b;}
#include<cstdio>
#include<vector>
using namespace std;
#define MAX 300100
#define PB push_back
int q;
vector<int> d2[MAX],jak[MAX];
bool cz[MAX];
void lacz(int a,int b){
  d2[a].PB(b);
  d2[b].PB(a);
}
int lacz(set<int> &a,set<int> &b){
  if(a.size() < b.size())swap(a,b);
  for(int x:b){
    if(a.find(-x)!=a.end()){
      a.erase(-x);
    }else
      a.insert(x);
  }
}
void nie(){
  puts("No");
  exit(0);
}
int dfs2(int a,set<int>& k){
  if(cz[a])return 0;
  cz[a] = 1;
  int sum = 0;
  R(i,jak[a].size()){
    k.insert(jak[a][i]);
    if(jak[a][i] < 0)
      sum--;
    else
      sum++;
  }
  R(i,d2[a].size()){
    set<int> pom;
    sum += dfs2(d2[a][i],pom);
    lacz(k,pom);
  }
  if(k.size() != abs(sum))nie();
  return sum;
}
int f[MAX];
int find(int a){
  return f[a] == a?a:f[a] = find(f[a]);
}
void uni(int a,int b){
  a = find(a);
  b = find(b);
  f[a] = b;
}
int n,m,low[MAX],po[MAX],ipo=1;
int oj[MAX];
vector<int> d[MAX];
void dfs(int nr,int o){
 if(po[nr]!=0)return;
 po[nr]=++ipo;
 oj[nr] = o;
 low[nr]=po[nr];
 for(int i=0;i<d[nr].size();i++){
  dfs(d[nr][i],nr);
 }
 for(int i=0;i<d[nr].size();i++){
  if(d[nr][i]!=o)
  low[nr]=min(low[nr],low[d[nr][i]]);
 }
}
void spr(int a,int b){
  if(oj[b] == a)swap(a,b);
  if(oj[a] == b){
    if(po[a] != low[a])uni(a,b);
  }else
    uni(a,b);
}
map<PI,int> mapa;
main(){
  int q;
  scanf("%d%d%d",&n,&m,&q);
  R(i,n){
    f[i] = i;
    oj[i] = -1;
  }
  for(int i=0;i<m;i++){
    int a,b;
    scanf("%d%d",&a,&b);
    a--;b--;
    d[a].PB(b);
    d[b].PB(a);
    if(a < b)swap(a,b);
    mapa[MP(a,b)]++;
    if(mapa[MP(a,b)] == 2)
      uni(a,b);
  }
  R(i,n)dfs(i,-1);
  
  R(i,n)for(int j=0;j<d[i].size();j++){
    spr(i,d[i][j]);
  }
  R(i,n){
    if(oj[i]!=-1 && low[i] == po[i]){
      lacz(find(i),find(oj[i]));
    }
  }
  R(i,q){
    int a,b;
    make2(a,b);a--;b--;
    a = find(a);
    b = find(b);
    if(a != b){
      jak[a].PB(i+1);
      jak[b].PB(-(i+1));
    }
  }
  set<int> z;
  R(i,n){
    z.clear();
    dfs2(i,z);
    if(z.size()!=0)nie();
  }
  puts("Yes");
}