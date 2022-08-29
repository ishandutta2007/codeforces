#pragma GCC optimize ("Ofast")
#include<bits/stdc++.h>
using namespace std;
template<class S, class T> inline S min_L(S a,T b){
  return a<=b?a:b;
}
inline void rd(int &x){
  int k;
  int m=0;
  x=0;
  for(;;){
    k = getchar();
    if(k=='-'){
      m=1;
      break;
    }
    if('0'<=k&&k<='9'){
      x=k-'0';
      break;
    }
  }
  for(;;){
    k = getchar();
    if(k<'0'||k>'9'){
      break;
    }
    x=x*10+k-'0';
  }
  if(m){
    x=-x;
  }
}
inline int rd_int(void){
  int x;
  rd(x);
  return x;
}
inline void wt_L(char a){
  putchar(a);
}
inline void wt_L(int x){
  int s=0;
  int m=0;
  char f[10];
  if(x<0){
    m=1;
    x=-x;
  }
  while(x){
    f[s++]=x%10;
    x/=10;
  }
  if(!s){
    f[s++]=0;
  }
  if(m){
    putchar('-');
  }
  while(s--){
    putchar(f[s]+'0');
  }
}
inline void wt_L(unsigned x){
  int s=0;
  char f[10];
  while(x){
    f[s++]=x%10;
    x/=10;
  }
  if(!s){
    f[s++]=0;
  }
  while(s--){
    putchar(f[s]+'0');
  }
}
inline void wt_L(long long x){
  int s=0;
  int m=0;
  char f[20];
  if(x<0){
    m=1;
    x=-x;
  }
  while(x){
    f[s++]=x%10;
    x/=10;
  }
  if(!s){
    f[s++]=0;
  }
  if(m){
    putchar('-');
  }
  while(s--){
    putchar(f[s]+'0');
  }
}
inline void wt_L(unsigned long long x){
  int s=0;
  char f[21];
  while(x){
    f[s++]=x%10;
    x/=10;
  }
  if(!s){
    f[s++]=0;
  }
  while(s--){
    putchar(f[s]+'0');
  }
}
inline void wt_L(double x){
  printf("%.15f",x);
}
inline void wt_L(const char c[]){
  int i=0;
  for(i=0;c[i]!='\0';i++){
    putchar(c[i]);
  }
}
inline void wt_L(string &x){
  int i=0;
  for(i=0;x[i]!='\0';i++){
    putchar(x[i]);
  }
}
template<class S, class T> inline S chmin(S &a, T b){
  if(a>b){
    a=b;
  }
  return a;
}
int N;
int A[300000];
int B[300000];
long long dp[3];
long long nx[3];
int main(){
  int Lj4PdHRW;
  int KL2GvlyY = rd_int();
  for(Lj4PdHRW=(0);Lj4PdHRW<(KL2GvlyY);Lj4PdHRW++){
    int i, j;
    rd(N);
    {
      int Q5VJL1cS;
      for(Q5VJL1cS=(0);Q5VJL1cS<(N);Q5VJL1cS++){
        rd(A[Q5VJL1cS]);
        rd(B[Q5VJL1cS]);
      }
    }
    for(j=(0);j<(3);j++){
      dp[j] = (long long) j * B[0];
    }
    for(i=(1);i<(N);i++){
      for(j=(0);j<(3);j++){
        nx[j] = 4611686016279904256LL;
      }
      for(j=(0);j<(3);j++){
        int k;
        for(k=(0);k<(3);k++){
          if(A[i-1]+j != A[i]+k){
            chmin(nx[k], dp[j] + (long long) k * B[i]);
          }
        }
      }
      for(j=(0);j<(3);j++){
        dp[j] = nx[j];
      }
    }
    {
      int e98WHCEY;
      long long cTE1_r3A;
      if(3==0){
        cTE1_r3A = 0;
      }
      else{
        cTE1_r3A = dp[0];
        for(e98WHCEY=(1);e98WHCEY<(3);e98WHCEY++){
          cTE1_r3A = min_L(cTE1_r3A, dp[e98WHCEY]);
        }
      }
      wt_L(cTE1_r3A);
      wt_L('\n');
    }
  }
  return 0;
}
// cLay varsion 20190921-1

// --- original code ---
// //no-unlocked
// int N, A[3d5], B[3d5];
// ll dp[3], nx[3];
// {
//   REP(rd_int()){
//     rd(N,(A,B)(N));
//     rep(j,3) dp[j] = (ll) j * B[0];
//     rep(i,1,N){
//       rep(j,3) nx[j] = ll_inf;
//       rep(j,3) rep(k,3) if(A[i-1]+j != A[i]+k) nx[k] <?= dp[j] + (ll) k * B[i];
//       rep(j,3) dp[j] = nx[j];
//     }
//     wt(min(dp(3)));
//   }
// }