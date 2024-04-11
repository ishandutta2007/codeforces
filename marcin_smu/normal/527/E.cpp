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
#define db if(1)printf
template<typename C> void MA(C& a,C b){if(a<b)a=b;}
template<typename C> void MI(C& a,C b){if(a>b)a=b;}
#define MAX 100100
int n,m;
int f[MAX],deg[MAX],il[MAX];
int find(int a){
  return f[a] == a?a:f[a] = find(f[a]);
}
void uni(int a,int b){
  a = find(a);
  b = find(b);
  if(a == b){
    il[a] ++;
    return;
  }
  f[a] = b;
  il[b] += il[a]+1;
}
vector<PI> d[MAX];
vector<int> np[MAX];
set<int> s;
vector<PI> wyn;
int gd[MAX];
bool czm[5*MAX];
vector<int> cykl;
void dfs(int nr){
  while(gd[nr] < d[nr].size()){
    PI pom = d[nr][gd[nr]];
    if(czm[pom.SE] == 0){
      czm[pom.SE] = 1;
      dfs(pom.FI);
      cykl.PB(pom.FI);
    }
    gd[nr]++;
  }
}
void licz(int i){
  //printf("licz %d\n",i);
  cykl.clear();
  dfs(i);
  cykl.PB(i);
  R(i,(int)cykl.size()-1){
    if(i&1)
      wyn.PB(MP(cykl[i],cykl[i+1]));
    else
      wyn.PB(MP(cykl[i+1],cykl[i]));
  }
}
int ie;
void add_edge(int a,int b){
  d[a].PB(MP(b,ie));
  d[b].PB(MP(a,ie));
  ie++;
}
bool cz[MAX];
main(){
  make2(n,m);
  R(i,n){
    f[i] = i;
    il[i] = 0;
  }
  R(i,m){
    int a,b;
    make2(a,b);
    a--;b--;
    add_edge(a,b);
    deg[a]++;
    deg[b]++;
    uni(a,b);
  }
  //R(i,n)printf("%d\n",find(i));
  R(i,n){
    if(deg[i]&1){
      np[find(i)].PB(i);
      s.insert(find(i));
    }
  }
  R(i,n){
    int ak = find(i);
    if(np[ak].empty() && cz[ak] == 0){
     // printf("ak: %d\n",ak);
      cz[ak] = 1;
      if(il[ak]&1){
        add_edge(i,i);
      }
      licz(i);
      dfs(i);
    }
  }
  if(!s.empty()){
    vector<int> ss;
    for(int a:s)ss.PB(a);
    ss.PB(ss[0]);
    R(i,int(ss.size())-1){
      add_edge(np[ss[i]][0],np[ss[i+1]][1]);
      for(int j=2;j<np[ss[i]].size();j+=2){
        add_edge(np[ss[i]][j],np[ss[i]][j+1]);
      }
    }
    if(ie&1)add_edge(ss[0],ss[0]);
    licz(ss[0]);
  }
  //printf("%d\n",ie);
  printf("%d\n",(int)wyn.size());
  R(i,wyn.size()){
    printf("%d %d\n",wyn[i].FI+1,wyn[i].SE+1);
  }
}