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
const int MAX = (1<<17) + 5;
int P;
struct mac{
  LL t[2][2];
  void jed(){
    t[0][0] = t[1][1] = 1;
    t[1][0] = t[0][1] = 0;
  }
  void ust(int k){
    t[0][0] = 0;
    t[0][1] = 1;
    t[1][0] = t[1][1] = k;
  }
  void scal(mac a,mac b){
//     R(i,2){R(j,2)
//       printf("%lld ",b.t[i][j]);
//       puts("");
//     }
//     puts("");
    R(i,2)R(j,2){
      t[i][j] = a.t[i][0] * b.t[0][j] + a.t[i][1] * b.t[1][j];
      t[i][j] %= P;
    }
    
  }
}dp[MAX],wyn;
LL k;
int n,nn;
int m;
vector<pair<LL,int>> d;
int pk,kk;
void dod(int nr = 1,int pp = 0,int kp = nn){
  if(pp >= kk || pk >= kp)return;
  //printf("%d %d %d\n",nr,pp,kp);
  if(pk <= pp && kp <= kk){
    wyn.scal(wyn,dp[nr]);
    return;
  }
  dod(nr*2,pp,pp+kp>>1);
  dod(nr*2+1,pp+kp>>1,kp);
}
void pot(mac a,LL w){
  while(w){
    if(w&1)
      wyn.scal(wyn,a);
    w/=2;
    a.scal(a,a);
  }
}
main(){
  scanf("%lld%d",&k,&P);
  make(n);
  nn = 1;while(nn <= n)nn*=2;
  R(i,nn){
    if(i<n){
      int pom;
      make(pom);
      dp[nn+i].ust(pom);
    }else{
      dp[nn+i].jed();
    }
  }
  FD(i,nn){
    dp[i].scal(dp[i*2],dp[i*2+1]);
  }
  make(m);
  R(i,m){
    LL j;
    int v;
    scanf("%lld%d",&j,&v);
    d.PB({j,v});
  }
  d.PB({k,-1});
  sort(ALL(d));
  LL ak = 0;
  int i = 0;
  wyn.jed();
  while(ak < k){
    LL p = d[i].FI;
  //  printf("pk %lld %lld\n",ak,p);
    if(ak == p){
  //    puts("1");
      mac pom;
      pom.ust(d[i].SE);
      i++;
      ak++;
      wyn.scal(wyn,pom);
    }else if(ak/n == p/n){
  //    puts("2");
      pk = ak % n;
      kk = p % n;
  //    printf("%d %d\n",pk,kk);
      dod();
      ak = p;
    }else if(ak % n != 0){
  //    puts("3");
      pk = ak % n;
      kk = nn;
      dod();
      ak = (ak/n+1)*n;
    }else{
   //   puts("4:");
      LL wyn = p/n - ak/n;
   //   printf("%lld\n",wyn);
      pot(dp[1],wyn);
      ak += wyn * n;
    }
  }
  printf("%lld\n",wyn.t[0][1]);
}