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
int N;
int A[100000];
int sz;
int in[1000001];
int ress;
int res[100000];
int sts;
int st[100000];
int main(){
  int i;
  rd(N);
  {
    int Lj4PdHRW;
    for(Lj4PdHRW=(0);Lj4PdHRW<(N);Lj4PdHRW++){
      rd(A[Lj4PdHRW]);
    }
  }
  for(i=(0);i<(N);i++){
    if(A[i] < 0){
      A[i] *= -1;
      if(in[A[i]]!=1){
        wt_L(-1);
        wt_L('\n');
        return 0;
      }
      sz--;
    }
    else{
      if(in[A[i]]!=0){
        wt_L(-1);
        wt_L('\n');
        return 0;
      }
      sz++;
    }
    in[A[i]]++;
    st[sts++] = A[i];
    if(sz==0){
      res[ress++] = i+1;
      while(sts){
        in[st[--sts]] = 0;
      }
    }
  }
  if(sz){
    wt_L(-1);
    wt_L('\n');
    return 0;
  }
  for(i=(ress)-1;i>=(1);i--){
    res[i] -= res[i-1];
  }
  wt_L(ress);
  wt_L('\n');
  {
    int t_ynMSdg;
    if(ress==0){
      putchar('\n');
    }
    else{
      for(t_ynMSdg=(0);t_ynMSdg<(ress-1);t_ynMSdg++){
        wt_L(res[t_ynMSdg]);
        wt_L(' ');
      }
      wt_L(res[t_ynMSdg]);
      wt_L('\n');
    }
  }
  return 0;
}
// cLay varsion 20191123-1

// --- original code ---
// //no-unlocked
// int N, A[1d5];
// int sz, in[1000001];
// int ress, res[1d5], sts, st[1d5];
// {
//   rd(N,A(N));
// 
//   rep(i,N){
//     if(A[i] < 0){
//       A[i] *= -1;
//       if(in[A[i]]!=1) wt(-1), return 0;
//       sz--;
//     } else {
//       if(in[A[i]]!=0) wt(-1), return 0;
//       sz++;
//     }
//     in[A[i]]++;
//     st[sts++] = A[i];
// 
//     if(sz==0){
//       res[ress++] = i+1;
//       while(sts) in[st[--sts]] = 0;
//     }
//   }
//   if(sz) wt(-1), return 0;
// 
//   rrep(i,1,ress) res[i] -= res[i-1];
//   wt(ress);
//   wt(res(ress));
// }