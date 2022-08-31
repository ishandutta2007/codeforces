#pragma GCC optimize ("Ofast")
#include<bits/stdc++.h>
using namespace std;
template<class S, class T> inline S min_L(S a,T b){
  return a<=b?a:b;
}
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
template<class S, class T> inline S divup_L(S a, T b){
  return (a+b-1)/b;
}
template<class S, class T> inline S chmax(S &a, T b){
  if(a<b){
    a=b;
  }
  return a;
}
int N;
int A[100000];
int sz;
int b[200000];
int main(){
  int Lj4PdHRW;
  int KL2GvlyY = rd_int();
  for(Lj4PdHRW=(0);Lj4PdHRW<(KL2GvlyY);Lj4PdHRW++){
    int i;
    int mx;
    int mn;
    int res = 0;
    rd(N);
    {
      int cTE1_r3A;
      for(cTE1_r3A=(0);cTE1_r3A<(N);cTE1_r3A++){
        rd(A[cTE1_r3A]);
      }
    }
    sz = 0;
    for(i=(1);i<(N);i++){
      if(A[i-1]!=-1 && A[i]==-1){
        b[sz++] = A[i-1];
      }
    }
    for(i=(1);i<(N);i++){
      if(A[i]!=-1 && A[i-1]==-1){
        b[sz++] = A[i];
      }
    }
    for(i=(1);i<(N);i++){
      if(A[i-1]!=-1 && A[i]!=-1){
        chmax(res, abs(A[i]-A[i-1]));
      }
    }
    if(sz==0){
      wt_L(0);
      wt_L(' ');
      wt_L(0);
      wt_L('\n');
      continue;
    }
    {
      int a2conNHc;
      int hCmBdyQB;
      if(sz==0){
        hCmBdyQB = 0;
      }
      else{
        hCmBdyQB = b[0];
        for(a2conNHc=(1);a2conNHc<(sz);a2conNHc++){
          hCmBdyQB = min_L(hCmBdyQB, b[a2conNHc]);
        }
      }
      mn =hCmBdyQB;
    }
    {
      int YREPHmFM;
      int jZyWAPpY;
      if(sz==0){
        jZyWAPpY = 0;
      }
      else{
        jZyWAPpY = b[0];
        for(YREPHmFM=(1);YREPHmFM<(sz);YREPHmFM++){
          jZyWAPpY = max_L(jZyWAPpY, b[YREPHmFM]);
        }
      }
      mx =jZyWAPpY;
    }
    wt_L(max_L(res,divup_L((mx-mn),2)));
    wt_L(' ');
    wt_L((mn+mx)/2);
    wt_L('\n');
  }
  return 0;
}
// cLay varsion 20200119-1

// --- original code ---
// //no-unlocked
// int N, A[1d5];
// int sz, b[2d5];
// {
//   REP(rd_int()){
//     int mx, mn, res = 0;
//     rd(N,A(N));
//     sz = 0;
//     rep(i,1,N) if(A[i-1]!=-1 && A[i]==-1) b[sz++] = A[i-1];
//     rep(i,1,N) if(A[i]!=-1 && A[i-1]==-1) b[sz++] = A[i];
//     rep(i,1,N) if(A[i-1]!=-1 && A[i]!=-1) res >?= abs(A[i]-A[i-1]);
//     if(sz==0) wt(0,0), continue;
//     mn = min(b(sz));
//     mx = max(b(sz));
//     wt(max(res,(mx-mn)/+2), (mn+mx)/2);
//   }
// }