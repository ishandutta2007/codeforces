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
template<class S> void arrErase(int k, int &sz, S a[]){
  int i;
  sz--;
  for(i=(k);i<(sz);i++){
    a[i] = a[i+1];
  }
}
template<class S, class T> void arrErase(int k, int &sz, S a[], T b[]){
  int i;
  sz--;
  for(i=(k);i<(sz);i++){
    a[i] = a[i+1];
  }
  for(i=(k);i<(sz);i++){
    b[i] = b[i+1];
  }
}
template<class S, class T, class U> void arrErase(int k, int &sz, S a[], T b[], U c[]){
  int i;
  sz--;
  for(i=(k);i<(sz);i++){
    a[i] = a[i+1];
  }
  for(i=(k);i<(sz);i++){
    b[i] = b[i+1];
  }
  for(i=(k);i<(sz);i++){
    c[i] = c[i+1];
  }
}
int N;
int F[200000];
int cnt[200000+1];
int sz;
int ls[200000];
int main(){
  int i;
  int st;
  int j;
  rd(N);
  {
    int Lj4PdHRW;
    for(Lj4PdHRW=(0);Lj4PdHRW<(N);Lj4PdHRW++){
      rd(F[Lj4PdHRW]);
    }
  }
  for(i=(0);i<(N);i++){
    cnt[F[i]]++;
  }
  for(i=(0);i<(N);i++){
    if(F[i]==0){
      st = i;
      break;
    }
  }
  for(i=(0);i<(N);i++){
    if(cnt[i+1]==0){
      ls[sz++] = i+1;
    }
  }
  for(i=(0);i<(N);i++){
    if(F[i]==0){
      if(ls[sz-1] != i+1){
        F[i] = ls[sz-1];
        arrErase(sz-1,sz,ls);
        continue;
      }
      if(sz >= 2){
        F[i] = ls[sz-2];
        arrErase(sz-2,sz,ls);
        continue;
      }
      F[i] = ls[sz-1];
      swap(F[i], F[st]);
    }
  }
  {
    int ao_dF3pO;
    if(N==0){
      putchar('\n');
    }
    else{
      for(ao_dF3pO=(0);ao_dF3pO<(N-1);ao_dF3pO++){
        wt_L(F[ao_dF3pO]);
        wt_L(' ');
      }
      wt_L(F[ao_dF3pO]);
      wt_L('\n');
    }
  }
  return 0;
}
// cLay varsion 20191227-1

// --- original code ---
// //no-unlocked
// int N, F[2d5];
// int cnt[2d5+1];
// int sz, ls[2d5];
// {
//   int st, j;
//   rd(N,F(N));
//   rep(i,N) cnt[F[i]]++;
//   rep(i,N) if(F[i]==0) st = i, break;
//   rep(i,N) if(cnt[i+1]==0) ls[sz++] = i+1;
//   rep(i,N) if(F[i]==0){
//     if(ls[sz-1] != i+1){
//       F[i] = ls[sz-1];
//       arrErase(sz-1,sz,ls);
//       continue;
//     }
//     if(sz >= 2){
//       F[i] = ls[sz-2];
//       arrErase(sz-2,sz,ls);
//       continue;
//     }
//     F[i] = ls[sz-1];
//     swap(F[i], F[st]);
//   }
//   wt(F(N));
// }