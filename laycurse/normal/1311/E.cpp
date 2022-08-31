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
inline void wt_L(const char c[]){
  int i=0;
  for(i=0;c[i]!='\0';i++){
    putchar(c[i]);
  }
}
int N;
int D;
int dep[5001];
int cs[5001];
int res[5001];
int main(){
  int Lj4PdHRW;
  int KL2GvlyY = rd_int();
  for(Lj4PdHRW=(0);Lj4PdHRW<(KL2GvlyY);Lj4PdHRW++){
    int ao_dF3pO;
    int i;
    int j;
    int k;
    int s;
    int rem;
    rd(N);
    rd(D);
    if(N*(N-1)/2 < D){
      wt_L("NO");
      wt_L('\n');
      continue;
    }
    for(i=(0);i<(N);i++){
      dep[i] = 0;
    }
    rem = N - 1;
    dep[0] = 1;
    for(i=(1);i<(N);i++){
      k =min_L(2*dep[i-1], rem);
      dep[i] = k;
      rem -= k;
    }
    s = 0;
    for(i=(0);i<(N);i++){
      s += i * dep[i];
    }
    if(s > D){
      wt_L("NO");
      wt_L('\n');
      continue;
    }
    wt_L("YES");
    wt_L('\n');
    for(ao_dF3pO=(0);ao_dF3pO<(D-s);ao_dF3pO++){
      for(i=(1);i<(N);i++){
        if(2*(dep[i-1]-1) >= dep[i]+1){
          break;
        }
      }
      dep[i]++;
      dep[i-1]--;
    }
    cs[0] = 0;
    for(i=(1);i<(N);i++){
      cs[i] = cs[i-1] + dep[i-1];
    }
    for(i=(1);i<(N);i++){
      for(j=(0);j<(dep[i]);j++){
        res[cs[i]+j-1] = cs[i-1] + 1 + (j / 2);
      }
    }
    {
      int AlM5nNnR;
      if(N-1==0){
        putchar('\n');
      }
      else{
        for(AlM5nNnR=(0);AlM5nNnR<(N-1-1);AlM5nNnR++){
          wt_L(res[AlM5nNnR]);
          wt_L(' ');
        }
        wt_L(res[AlM5nNnR]);
        wt_L('\n');
      }
    }
  }
  return 0;
}
// cLay varsion 20200217-1

// --- original code ---
// //no-unlocked
// int N, D;
// int dep[5001], cs[5001];
// int res[5001];
// {
//   REP(rd_int()){
//     int i, j, k, s, rem;
//     rd(N,D);
//     if(N*(N-1)/2 < D) wt("NO"), continue;
// 
//     rep(i,N) dep[i] = 0;
//     rem = N - 1;
//     dep[0] = 1;
//     rep(i,1,N){
//       k = min(2*dep[i-1], rem);
//       dep[i] = k;
//       rem -= k;
//     }
// 
//     s = 0;
//     rep(i,N) s += i * dep[i];
//     if(s > D) wt("NO"), continue;
//     wt("YES");
// 
//     rep(D-s){
//       rep(i,1,N) if(2*(dep[i-1]-1) >= dep[i]+1) break;
//       dep[i]++;
//       dep[i-1]--;
//     }
// 
//     cs[0] = 0;
//     rep(i,1,N) cs[i] = cs[i-1] + dep[i-1];
//     rep(i,1,N) rep(j,dep[i]){
//       res[cs[i]+j-1] = cs[i-1] + 1 + (j / 2);
//     }
//     wt(res(N-1));
//   }
// }