#pragma GCC optimize ("Ofast")
#include<bits/stdc++.h>
using namespace std;
struct Rand{
  unsigned x;
  unsigned y;
  unsigned z;
  unsigned w;
  Rand(void){
    x=123456789;
    y=362436069;
    z=521288629;
    w=(unsigned)time(NULL);
  }
  Rand(unsigned seed){
    x=123456789;
    y=362436069;
    z=521288629;
    w=seed;
  }
  inline unsigned get(void){
    unsigned t;
    t = (x^(x<<11));
    x=y;
    y=z;
    z=w;
    w = (w^(w>>19))^(t^(t>>8));
    return w;
  }
  inline double getUni(void){
    return get()/4294967296.0;
  }
  inline int get(int a){
    return (int)(a*getUni());
  }
  inline int get(int a, int b){
    return a+(int)((b-a+1)*getUni());
  }
  inline long long get(long long a){
    return(long long)(a*getUni());
  }
  inline long long get(long long a, long long b){
    return a+(long long)((b-a+1)*getUni());
  }
  inline double get(double a, double b){
    return a+(b-a)*getUni();
  }
  inline int getExp(int a){
    return(int)(exp(getUni()*log(a+1.0))-1.0);
  }
  inline int getExp(int a, int b){
    return a+(int)(exp(getUni()*log((b-a+1)+1.0))-1.0);
  }
}
;
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
inline void rd(char &c){
  int i;
  for(;;){
    i = getchar();
    if(i!=' '&&i!='\n'&&i!='\r'&&i!='\t'&&i!=EOF){
      break;
    }
  }
  c = i;
}
inline int rd(char c[]){
  int i;
  int sz = 0;
  for(;;){
    i = getchar();
    if(i!=' '&&i!='\n'&&i!='\r'&&i!='\t'&&i!=EOF){
      break;
    }
  }
  c[sz++] = i;
  for(;;){
    i = getchar();
    if(i==' '||i=='\n'||i=='\r'||i=='\t'||i==EOF){
      break;
    }
    c[sz++] = i;
  }
  c[sz]='\0';
  return sz;
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
int N;
char S[4002];
char T[4002];
int A[2000];
int B[2000];
int fn[2000];
int sz;
int cnt[4];
int ress;
int res[8002];
void doit(int k){
  int i;
  res[ress++] = k;
  reverse(A, A+k);
  for(i=(0);i<(k);i++){
    if(A[i]==1){
      A[i]++;
    }
    else if(A[i]==2){
      A[i]--;
    }
    else{
      ;
    }
  }
}
void doit(int a, int b, int c = -1){
  doit(a);
  doit(b);
  if(c != -1){
    doit(c);
  }
}
int main(){
  int Q5VJL1cS;
  int r;
  int mx;
  Rand rnd;
  int e98WHCEY = rd_int();
  for(Q5VJL1cS=(0);Q5VJL1cS<(e98WHCEY);Q5VJL1cS++){
    int i;
    N = rd(S);
    rd(T);
    N /= 2;
    for(i=(0);i<(4);i++){
      cnt[i] = 0;
    }
    for(i=(0);i<(2*N);i++){
      S[i] -= '0';
      T[i] -= '0';
    }
    for(i=(0);i<(N);i++){
      A[i] = S[2*i]*2 + S[2*i+1];
    }
    for(i=(0);i<(N);i++){
      B[i] = T[2*i]*2 + T[2*i+1];
    }
    for(i=(0);i<(N);i++){
      cnt[A[i]]++;
      cnt[B[i]]--;
    }
    if(cnt[0] || cnt[3]){
      wt_L(-1);
      wt_L('\n');
      continue;
    }
    for(;;){
      ress = 0;
      r = N;
      for(i=(0);i<(N);i++){
        A[i] = S[2*i]*2 + S[2*i+1];
      }
      for(i=(0);i<(N);i++){
        B[i] = T[2*i]*2 + T[2*i+1];
      }
      while(r){
        if(A[r-1] == B[r-1]){
          r--;
          continue;
        }
        sz = mx = 0;
        for(i=(0);i<(r);i++){
          int k;
          for(k=(0);k<(i+1);k++){
            if(A[i-k] != B[r-1-k]){
              break;
            }
            if(mx > k+1){
              continue;
            }
            if(mx < k+1){
              mx = k+1;
              sz = 0;
            }
            fn[sz++] = i;
          }
        }
        if(mx <= 2 && ((A[0]==1 && B[r-1]==2)||(A[0]==2 && B[r-1]==1))){
          doit(r);
          continue;
        }
        if(sz){
          doit(fn[rnd.get(sz)]+1, r);
          continue;
        }
        sz = 0;
        for(i=(0);i<(r);i++){
          if(A[i] == 3-B[r-1]){
            fn[sz++] = i;
          }
        }
        doit(fn[rnd.get(sz)]+1, 1, r);
        continue;
      }
      if(ress <= 2*N+1){
        break;
      }
    }
    wt_L(ress);
    wt_L('\n');
    {
      int Hjfu7Vx7;
      if(ress==0){
        putchar('\n');
      }
      else{
        for(Hjfu7Vx7=(0);Hjfu7Vx7<(ress-1);Hjfu7Vx7++){
          wt_L(res[Hjfu7Vx7]*2);
          wt_L(' ');
        }
        wt_L(res[Hjfu7Vx7]*2);
        wt_L('\n');
      }
    }
  }
  return 0;
}
// cLay varsion 20191108-1

// --- original code ---
// //no-unlocked
// int N; char S[4002], T[4002];
// int A[2000], B[2000];
// 
// int fn[2000], sz;
// int cnt[4];
// int ress, res[8002];
// 
// void doit(int k){
//   res[ress++] = k;
//   reverse(A, A+k);
//   rep(i,k) if[A[i]==1, A[i]++, A[i]==2, A[i]--];
// }
// 
// void doit(int a, int b, int c = -1){
//   doit(a); doit(b);
//   if(c != -1) doit(c);
// }
// 
// {
//   int r, mx;
//   Rand rnd;
//   REP(rd_int()){
//     rd(S@N, T);
//     N /= 2;
//     rep(i,4) cnt[i] = 0;
//     rep(i,2N) S[i] -= '0', T[i] -= '0';
//     rep(i,N) A[i] = S[2i]*2 + S[2i+1];
//     rep(i,N) B[i] = T[2i]*2 + T[2i+1];
//     rep(i,N) cnt[A[i]]++, cnt[B[i]]--;
//     if(cnt[0] || cnt[3]) wt(-1), continue;
//     for(;;){
//       ress = 0;
//       r = N;
//       rep(i,N) A[i] = S[2i]*2 + S[2i+1];
//       rep(i,N) B[i] = T[2i]*2 + T[2i+1];
//       while(r){
//         if(A[r-1] == B[r-1]) r--, continue;
// 
//         sz = mx = 0;
//         rep(i,r) rep(k,i+1){
//           if(A[i-k] != B[r-1-k]) break;
//           if(mx > k+1) continue;
//           if(mx < k+1) mx = k+1, sz = 0;
//           fn[sz++] = i;
//         }
//         if(mx <= 2 && ((A[0]==1 && B[r-1]==2)||(A[0]==2 && B[r-1]==1))) doit(r), continue;
//         if(sz) doit(fn[rnd.get(sz)]+1, r), continue;
// 
//         sz = 0;
//         rep(i,r) if(A[i] == 3-B[r-1]) fn[sz++] = i;
//         doit(fn[rnd.get(sz)]+1, 1, r), continue;
//       }
//       if(ress <= 2N+1) break;
//     }
//     wt(ress);
//     wt(res(ress)*2);
//   }
// }