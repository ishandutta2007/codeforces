#pragma GCC optimize ("Ofast")
#include<bits/stdc++.h>
using namespace std;
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
int L[32];
int R[32];
long long dp[2][2][2][32];
long long solve(int x, int a, int b, int d){
  if(d < 0){
    return 1 + x;
  }
  long long &res = dp[x][a][b][d];
  if(res >= 0){
    return res;
  }
  res = 0;
  if(a==1 || L[d]==0){
    if(R[d]==1){
      res += solve(x, a,1, d-1);
    }
    else{
      res += solve(x, a,b, d-1);
    }
  }
  if( (a==1 || L[d]==0) && (b==1 || R[d]==1) ){
    res += solve(1, a, b, d-1);
  }
  if(x==1){
    if(L[d]==0){
      if(R[d]==1){
        res += solve(1,1,1, d-1);
      }
      else{
        res += solve(1,1,b, d-1);
      }
    }
    else{
      if(R[d]==1){
        res += solve(1,a,1, d-1);
      }
      else{
        res += solve(1,a,b, d-1);
      }
    }
  }
  return res;
}
int main(){
  int Lj4PdHRW;
  int i;
  int j;
  int KL2GvlyY = rd_int();
  for(Lj4PdHRW=(0);Lj4PdHRW<(KL2GvlyY);Lj4PdHRW++){
    int k;
    rd(i);
    rd(j);
    for(k=(0);k<(32);k++){
      L[k] = i%2;
      i/=2;
    }
    for(k=(0);k<(32);k++){
      R[k] = j%2;
      j/=2;
    }
    for(i=(0);i<(2);i++){
      for(j=(0);j<(2);j++){
        for(k=(0);k<(2);k++){
          int m;
          for(m=(0);m<(32);m++){
            dp[i][j][k][m] = -1;
          }
        }
      }
    }
    wt_L(solve(0,0,0,31));
    wt_L('\n');
  }
  return 0;
}
// cLay varsion 20191027-1

// --- original code ---
// //no-unlocked
// int L[32], R[32];
// ll dp[2][2][2][32];
// 
// ll solve(int x, int a, int b, int d){
//   if(d < 0) return 1 + x;
// 
//   ll &res = dp[x][a][b][d];
//   if(res >= 0) return res;
//   res = 0;
// 
//   if(a==1 || L[d]==0){
//     res += solve(x, a, if[R[d]==1,1,b], d-1);
//   }
//   if( (a==1 || L[d]==0) && (b==1 || R[d]==1) ){
//     res += solve(1, a, b, d-1);
//   }
//   if(x==1){
//     res += solve(1, if[L[d]==0,1,a], if[R[d]==1,1,b], d-1);
//   }
// 
//   return res;
// }
// 
// {
//   int i, j;
//   REP(rd_int()){
//     rd(i,j);
//     rep(k,32) L[k] = i%2, i/=2;
//     rep(k,32) R[k] = j%2, j/=2;
//     rep(i,2) rep(j,2) rep(k,2) rep(m,32) dp[i][j][k][m] = -1;
//     wt(solve(0,0,0,31));
//   }
// }