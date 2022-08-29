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
#define db if(1)printf
template<typename C> void ma(C& a,C b){if(a<b)a=b;}
template<typename C> void mi(C& a,C b){if(a>b)a=b;}
#define MAX 100100
int n,l[MAX];
vector<PI> d[MAX];
D war[MAX];
int dfs(int nr,int oj){
  int res = 1;
  R(i,d[nr].size()){
    if(d[nr][i].FI != oj){
      int pom = dfs(d[nr][i].FI,nr);
      war[d[nr][i].SE] = 6 * (D)pom * (n-pom) / n / (n-1);
      res += pom;
    }
  }
  return res;
}
main(){
  make(n);
  R(i,n-1){
    int a,b;
    make2(a,b);a--;b--;
    make(l[i]);
    d[a].PB(MP(b,i));
    d[b].PB(MP(a,i));
  }
  dfs(0,-1);
  D wyn = 0;
  R(i,n)wyn += war[i] * l[i];
  int q;make(q);
  R(i,q){
    int a,b;
    make2(a,b);
    a--;
    wyn -= war[a] * l[a];
    l[a] = b;
    wyn += war[a] * l[a];
    printf("%.7lf\n",wyn);
  }
}