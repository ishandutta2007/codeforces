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
#define MAX 100010
int n;
vector<int> d[MAX],d2[MAX];
bool cz[MAX],cz2[MAX];
int ile[MAX];
void dfs(int nr,int o){
  if(SZ(d[nr]) <= 2){
    cz[nr] = 1;
    R(i,d[nr].size()){
      if(d[nr][i] != o)
        dfs(d[nr][i],nr);
    }
  }else{
    ile[nr]++;
  }
}
void tnij(){
  R(i,n){
    if(SZ(d[i]) == 1){
      dfs(i,-1);
    }
  }
}
void tnij2(){
  R(i,n){
    if(ile[i] == 2 && SZ(d[i]) == 3)
      cz[i] = 1;
  }
}
void spr3(){
  R(i,n){
    if(cz[i] == 0){
      int deg = 0;
      R(j,SZ(d[i])){
        if(cz[d[i][j]] == 0)
          deg++;
      }
      if(deg > 2){
        puts("No");
        exit(0);
      }
    }
  }
}
main(){
  make(n);
  R(i,n-1){
    int a,b;
    make2(a,b);
    a--;b--;
    d[a].PB(b);
    d[b].PB(a);
  }
  tnij();
  tnij2();
  spr3();
  puts("Yes");
}