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
#define MAX 200001
int n,t[MAX];
const int P = 1e9 + 7;
LL w[MAX];
int il[MAX];
vector<int> d[MAX];
LL pot(LL a,LL w){
  LL r = 1;
  while(w){
    if(w&1){
      r*=a;
      r%=P;
    }
    w/=2;
    a*=a;
    a%=P;
  }
  return r;
}
main(){
  make(n);
  w[0] = 1;
  F(i,1,n){
    make(t[i]);t[i]--;
    w[i] = 1;
    d[t[i]].PB(i);
  }
  FD(i,n)if(i){
    LL pom = (w[i]+1)%P;
    if(il[i]){
      pom = 1;
    }
    if(pom){
      w[t[i]] *= pom;
      w[t[i]] %= P;
    }else{
      il[t[i]] ++;
    }
  }
  R(i,n){
    if(il[i])
      printf("0 ");
    else
      printf("%lld ",w[i]%P);
    R(j,d[i].size()){
      int ak = d[i][j];
      LL pom = (w[ak]+1)%P;
      if(il[ak])pom = 1;
      LL wi = w[i],ili = il[i];
      if(pom){
        wi = wi * pot(pom,P-2) % P;
      }else
        ili--;
      int pom2;
      if(ili){
        pom2 = 1;
      }else{
        pom2 = (wi + 1) % P;
      }
      if(pom2 == 0){
        il[ak]++;
      }else{
        w[ak] *= pom2;
        w[ak] %= P;
      }
    }
  }
  puts("");
}