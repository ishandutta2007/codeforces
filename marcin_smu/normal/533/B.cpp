#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<LL,LL> PI;
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
#define MAX 210001
int n;
int c[MAX];
LL w1[MAX],w2[MAX];
vector<int> d[MAX];
PI dfs(int nr){
  PI res = MP(0ll,(LL)-1e18);
  R(i,d[nr].size()){
    PI pom = dfs(d[nr][i]);
    res = MP(
      max(pom.FI + res.FI,pom.SE+res.SE),
      max(pom.FI + res.SE,pom.SE+res.FI)
    );
  }
  MA(res.SE,res.FI + c[nr]);
  return res;
}
main(){
  make(n);
  R(i,n){
    int a;
    make2(a,c[i]);
    if(a != -1){
      a--;
      d[a].PB(i);
    }
  }
  PI wyn = dfs(0);
  printf("%lld\n",max(wyn.FI,wyn.SE));
}