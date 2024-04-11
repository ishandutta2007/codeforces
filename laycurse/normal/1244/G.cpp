#pragma GCC optimize ("Ofast")
#include<bits/stdc++.h>
using namespace std;
template<class S, class T> inline S max_L(S a,T b){
  return a>=b?a:b;
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
inline void rd(long long &x){
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
int N;
long long K;
int p[1000000];
int q[1000000];
int main(){
  int i;
  long long res = 0;
  int j;
  int g;
  int m;
  rd(N);
  rd(K);
  for(i=(0);i<(N);i++){
    K -= i + 1;
  }
  if(K < 0){
    wt_L(-1);
    wt_L('\n');
    return 0;
  }
  for(i=(0);i<(N);i++){
    p[i] = i + 1;
  }
  for(i=(0);i<(N);i++){
    j = N - i;
    g =max_L(0, j - p[i]);
    if(g >= K){
      int k;
      j = p[i] + K;
      q[i] = j;
      m = 1;
      for(k=(i+1);k<(N);k++){
        if(m==j){
          m++;
        }
        q[k] = m++;
      }
      break;
    }
    else{
      K -= g;
      q[i] = j;
    }
  }
  for(i=(0);i<(N);i++){
    res +=max_L(p[i], q[i]);
  }
  wt_L(res);
  wt_L('\n');
  {
    int Q5VJL1cS;
    if(N==0){
      putchar('\n');
    }
    else{
      for(Q5VJL1cS=(0);Q5VJL1cS<(N-1);Q5VJL1cS++){
        wt_L(p[Q5VJL1cS]);
        wt_L(' ');
      }
      wt_L(p[Q5VJL1cS]);
      wt_L('\n');
    }
  }
  {
    int e98WHCEY;
    if(N==0){
      putchar('\n');
    }
    else{
      for(e98WHCEY=(0);e98WHCEY<(N-1);e98WHCEY++){
        wt_L(q[e98WHCEY]);
        wt_L(' ');
      }
      wt_L(q[e98WHCEY]);
      wt_L('\n');
    }
  }
  return 0;
}
// cLay varsion 20191027-1

// --- original code ---
// //no-unlocked
// int N; ll K;
// int p[1d6], q[1d6];
// {
//   ll res = 0;
//   int j, g, m;
//   rd(N,K);
//   rep(i,N) K -= i + 1;
//   if(K < 0) wt(-1), return 0;
// 
//   rep(i,N) p[i] = i + 1;
//   rep(i,N){
//     j = N - i;
//     g = max(0, j - p[i]);
//     if(g >= K){
//       j = p[i] + K;
//       q[i] = j;
//       m = 1;
//       rep(k,i+1,N){
//         if(m==j) m++;
//         q[k] = m++;
//       }
//       break;
//     } else {
//       K -= g;
//       q[i] = j;
//     }
//   }
//   rep(i,N) res += max(p[i],q[i]);
//   wt(res);
//   wt(p(N));
//   wt(q(N));
// }