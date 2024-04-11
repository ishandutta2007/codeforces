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
#define MAX 200100
int n,m;
int p[MAX],l[MAX];
int wyn[MAX];
struct prze{
  int a,b;
  int war;
  int len(){return b-a;}
};
int all = 0;
vector<prze> s;
vector<PI> zap[MAX];
main(){
  make(n);
  R(i,n)make2(p[i],l[i]);
  make(m);
  R(i,m){
    int a,b;
    make2(a,b);a--;b--;
    zap[a].PB(MP(b,i));
  }
  s.PB({int(2e9)-1,int(2e9),0});
  FD(i,n-1){
    if(p[i] + l[i] < p[i+1]){
      all += p[i+1] - (p[i]+l[i]);
      s.PB({p[i]+l[i],p[i+1],all});
    }
    while(p[i]+l[i] >= s.back().b){
      all -= s.back().len();
      s.pop_back();
    }
    if(p[i]+l[i] > s.back().a){
      all -= s.back().len();
      s.back().a = p[i]+l[i];
      all += s.back().len();
      s.back().war = all;
    }
    R(j,zap[i].size()){
      int pom = p[zap[i][j].FI];
      int po = 0,ko = s.size();
      while(po+1 != ko){
        int m = (po+ko)/2;
        if(s[m].a < pom)
          ko = m;
        else
          po = m;
      }
      wyn[zap[i][j].SE] = all - s[po].war;
    }
  }
  R(i,m)printf("%d\n",wyn[i]);
}