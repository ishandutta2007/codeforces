#pragma GCC optimize ("Ofast")
#include<bits/stdc++.h>
using namespace std;
void *wmem;
char memarr[96000000];
template<class T> inline void walloc1d(T **arr, int x, void **mem = &wmem){
  static int skip[16] = {0, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
  (*mem) = (void*)( ((char*)(*mem)) + skip[((unsigned long long)(*mem)) & 15] );
  (*arr)=(T*)(*mem);
  (*mem)=((*arr)+x);
}
template<class T1> void sortA_L(int N, T1 a[], void *mem = wmem){
  sort(a, a+N);
}
template<class T1> void rsortA_L(int N, T1 a[], void *mem = wmem){
  sortA_L(N, a, mem);
  reverse(a, a+N);
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
template<class T> inline T GCD_L(T a,T b){
  T r;
  while(a){
    r=b;
    b=a;
    a=r%a;
  }
  return b;
}
int N;
int P[200000];
int X;
int A;
int Y;
int B;
long long K;
int main(){
  int Lj4PdHRW;
  wmem = memarr;
  long long c;
  long long gain;
  int i;
  int j;
  int aa;
  int bb;
  int cc;
  int res;
  int KL2GvlyY = rd_int();
  for(Lj4PdHRW=(0);Lj4PdHRW<(KL2GvlyY);Lj4PdHRW++){
    rd(N);
    {
      int Q5VJL1cS;
      for(Q5VJL1cS=(0);Q5VJL1cS<(N);Q5VJL1cS++){
        rd(P[Q5VJL1cS]);
      }
    }
    rd(X);
    rd(A);
    rd(Y);
    rd(B);
    rd(K);
    for(i=(0);i<(N);i++){
      P[i] /= 100;
    }
    if(X < Y){
      swap(X,Y);
      swap(A,B);
    }
    c = (long long) A * B /GCD_L(A, B);
    rsortA_L(N,P);
    int cTE1_r3A;
    int RZTsC2BF;
    int FmcKpFmN;
    cTE1_r3A = 0;
    RZTsC2BF = N+1;
    while(cTE1_r3A < RZTsC2BF){
      int WYIGIcGE, t_ynMSdg, xr20shxY;
      if((cTE1_r3A + RZTsC2BF)%2==0){
        FmcKpFmN = (cTE1_r3A + RZTsC2BF) / 2;
      }
      else{
        FmcKpFmN = (cTE1_r3A + RZTsC2BF - 1) / 2;
      }
      gain = 0;
      cc = FmcKpFmN / c;
      aa = FmcKpFmN / A - cc;
      bb = FmcKpFmN / B - cc;
      j = 0;
      for(xr20shxY=(0);xr20shxY<(cc);xr20shxY++){
        gain += P[j++] * (X+Y);
      }
      for(WYIGIcGE=(0);WYIGIcGE<(aa);WYIGIcGE++){
        gain += P[j++] * X;
      }
      for(t_ynMSdg=(0);t_ynMSdg<(bb);t_ynMSdg++){
        gain += P[j++] * Y;
      }
      if(gain >= K){
        RZTsC2BF = FmcKpFmN;
      }
      else{
        cTE1_r3A = FmcKpFmN + 1;
      }
    }
    res =RZTsC2BF;
    if(res==N+1){
      wt_L(-1);
      wt_L('\n');
    }
    else{
      wt_L(res);
      wt_L('\n');
    }
  }
  return 0;
}
// cLay varsion 20191012-1

// --- original code ---
// //no-unlocked
// int N, P[2d5], X, A, Y, B;
// ll K;
// {
//   ll c, gain;
//   int i, j, aa, bb, cc, res;
//   REP(rd_int()){
//     rd(N,P(N),X,A,Y,B,K);
//     rep(i,N) P[i] /= 100;
//     if(X < Y) swap(X,Y), swap(A,B);
//     c = (ll) A * B / gcd(A,B);
//     rsortA(N,P);
//     res = bsearch_min[int,z,0,N+1][
//       gain = 0;
//       cc = z / c;
//       aa = z / A - cc;
//       bb = z / B - cc;
//       j = 0;
//       rep(cc) gain += P[j++] * (X+Y);
//       rep(aa) gain += P[j++] * X;
//       rep(bb) gain += P[j++] * Y;
//     ](gain >= K);
//     wt(if[res==N+1, -1, res]);
//   }
// }