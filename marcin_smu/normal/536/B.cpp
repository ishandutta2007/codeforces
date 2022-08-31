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
#define MAX 1001000
const int P = 1e9 +7;
LL pot(LL a,LL w){
  LL res = 1;
  while(w){
    if(w&1){
      res *= a;
      res %= P;
    }
    w/=2;
    a*=a;
    a%=P;
  }
  return res;
}
int n,m;
char z[MAX];
int kmp[MAX];
bool cz[MAX];
int q[MAX];
main(){
  make2(n,m);
  scanf("%s",z);
  int d = 0;while(z[d])d++;
  int t = 0;
  F(i,1,d){
    while(t!=0 && z[i]!=z[t])t = kmp[t-1];
    if(z[i] == z[t])t++;
    kmp[i] = t;
  }
  int ak = kmp[d-1];
  while(ak){
    cz[ak] = 1;
    ak = kmp[ak-1];
  }
  int wyn = 0;
  int ost = -d+1;
  R(i,m){
    int pom;make(pom);
    if(pom - ost >= d){
      wyn += pom - ost - d;
    }else{
      if(cz[d - pom + ost] == 0){
        puts("0");
        return 0;
      }
    }
    ost = pom;
  }
  wyn += n - ost - d + 1; 
  printf("%lld\n",pot(26,wyn));
}