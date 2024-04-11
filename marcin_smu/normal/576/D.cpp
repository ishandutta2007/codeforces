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
#define MAX 151
int n,m;
struct mac{
  bitset<MAX> t[MAX];
  void dod(int a,int b){
    t[a][b] = 1;
  }
  mac(){};
  mac(mac& a,mac& b){
    R(i,n){
      R(j,n){
      if(a.t[i][j])
        t[i] |= b.t[j];
      }
    }
  }
}ak,dm;
vector<mac> lo;
int t = 0;
int odp(int i){
  while(i){
    i--;
    mac kan(dm,lo[i]);
    if(kan.t[0][n-1] == 0){
      dm = kan;
      t+=1<<i;
    }
  }
  printf("%d\n",t+1);
  exit(0);
}
vector<pair<int,PI> > w;
void pot(int wyk){
  lo.clear();
  lo.PB(ak);
  int i = 0;
  while(wyk){
    if(wyk&1){
      mac kan(dm,lo[i]);
      if(kan.t[0][n-1]){
        odp(i);
      }
      dm = kan;
      t+=1<<i;
    }
    wyk/=2;
    lo.PB(mac(lo[i],lo[i]));
    i++;
  }
}
main(){
  make(n);
  make(m);
  ak.dod(n-1,n-1);
  R(i,n){
    dm.dod(i,i);
  }
  R(i,m){
    int a,b,d;
    make2(a,b);
    a--;b--;
    make(d);
    w.PB({d,MP(a,b)});
  }
  sort(ALL(w));
  int i = 0;
  w.PB({(int)1e9+200,{0,0}});
  while(i<m){
    while(i < m && w[i].FI == t){
      ak.dod(w[i].SE.FI,w[i].SE.SE);
      i++;
    }
    pot(w[i].FI-t);
  }
  puts("Impossible");
}