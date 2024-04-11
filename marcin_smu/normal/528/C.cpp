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
int deg[MAX];
vector<PI> d[MAX];
vector<int> np;
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
int ie;
void add_edge(int a,int b){
  d[a].PB(MP(b,ie));
  d[b].PB(MP(a,ie));
  ie++;
}
main(){
  make2(n,m);
  R(i,m){
    int a,b;
    make2(a,b);
    a--;b--;
    add_edge(a,b);
    deg[a]++;
    deg[b]++;
  }
  R(i,n){
    if(deg[i]&1){
      np.PB(i);
    }
  }
  for(int j=0;j<np.size();j+=2){
    add_edge(np[j],np[j+1]);
  }
  if(ie&1)add_edge(0,0);
  dfs(0);
  cykl.PB(0);
  printf("%d\n",ie);
  R(i,(int)cykl.size()-1){
    if(i&1)
      printf("%d %d\n",cykl[i]+1,cykl[i+1]+1);
    else
      printf("%d %d\n",cykl[i+1]+1,cykl[i]+1);
  }
}