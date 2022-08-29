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
int M;
int D;
int C[1000];
int res[1000];
int p[1001];
int main(){
  int i;
  int k = -1;
  rd(N);
  rd(M);
  rd(D);
  {
    int Lj4PdHRW;
    for(Lj4PdHRW=(0);Lj4PdHRW<(M);Lj4PdHRW++){
      rd(C[Lj4PdHRW]);
    }
  }
  p[M] = N;
  for(i=(M)-1;i>=(0);i--){
    p[i] = p[i+1] - C[i];
  }
  for(i=(0);i<(M);i++){
    int j;
    k =min_L(k+D, p[i]);
    for(j=(0);j<(C[i]);j++){
      res[k++] = i + 1;
    }
    k--;
  }
  if(k + D < N){
    wt_L("NO");
    wt_L('\n');
    return 0;
  }
  wt_L("YES");
  wt_L('\n');
  {
    int KrdatlYV;
    if(N==0){
      putchar('\n');
    }
    else{
      for(KrdatlYV=(0);KrdatlYV<(N-1);KrdatlYV++){
        wt_L(res[KrdatlYV]);
        wt_L(' ');
      }
      wt_L(res[KrdatlYV]);
      wt_L('\n');
    }
  }
  return 0;
}
// cLay varsion 20191110-1

// --- original code ---
// //no-unlocked
// int N, M, D, C[1000];
// int res[1000], p[1001];
// {
//   int k = -1;
//   rd(N,M,D,C(M));
//   p[M] = N;
//   rrep(i,M) p[i] = p[i+1] - C[i];
//   rep(i,M){
//     k = min(k+D, p[i]);
//     rep(j,C[i]) res[k++] = i + 1;
//     k--;
//   }
//   if(k + D < N) wt("NO"), return 0;
//   wt("YES");
//   wt(res(N));
// }