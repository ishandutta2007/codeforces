#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include<bits/stdc++.h>
using namespace std;
inline int my_getchar(){
  static char buf[1048576];
  static int s = 1048576;
  static int e = 1048576;
  if(s == e && e == 1048576){
    e = fread(buf, 1, 1048576, stdin);
    s = 0;
  }
  if(s == e){
    return EOF;
  }
  return buf[s++];
}
inline void rd(int &x){
  int k;
  int m=0;
  x=0;
  for(;;){
    k = my_getchar();
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
    k = my_getchar();
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
    i = my_getchar();
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
    i = my_getchar();
    if(i!=' '&&i!='\n'&&i!='\r'&&i!='\t'&&i!=EOF){
      break;
    }
  }
  c[sz++] = i;
  for(;;){
    i = my_getchar();
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
struct MY_WRITER{
  char buf[1048576];
  int s;
  int e;
  MY_WRITER(){
    s = 0;
    e = 1048576;
  }
  ~MY_WRITER(){
    if(s){
      fwrite(buf, 1, s, stdout);
    }
  }
}
;
MY_WRITER MY_WRITER_VAR;
void my_putchar(int a){
  if(MY_WRITER_VAR.s == MY_WRITER_VAR.e){
    fwrite(MY_WRITER_VAR.buf, 1, MY_WRITER_VAR.s, stdout);
    MY_WRITER_VAR.s = 0;
  }
  MY_WRITER_VAR.buf[MY_WRITER_VAR.s++] = a;
}
inline void wt_L(char a){
  my_putchar(a);
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
    my_putchar('-');
  }
  while(s--){
    my_putchar(f[s]+'0');
  }
}
inline int BIT_popcount_L(const int x){
  return __builtin_popcount(x);
}
inline int BIT_popcount_L(const long long x){
  return __builtin_popcountll(x);
}
template<class S, class T> inline S chmin(S &a, T b){
  if(a>b){
    a=b;
  }
  return a;
}
int N;
int K;
char S[12];
int main(){
  int Lj4PdHRW;
  int KL2GvlyY = rd_int();
  for(Lj4PdHRW=(0);Lj4PdHRW<(KL2GvlyY);Lj4PdHRW++){
    int i, mask;
    long long res = 4611686016279904256LL;
    long long tmp;
    int up[11];
    N = rd(S);
    rd(K);
    for(i=(0);i<(N);i++){
      S[i] -= '0';
    }
    for(mask=(1);mask<(1<<10);mask++){
      if(BIT_popcount_L(mask)<= K){
        int k;
        for(i=(0);i<(11);i++){
          if(((mask) &(1<<(i)))){
            up[i] =i;
          }
          else{
            up[i] =10;
          }
        }
        for(i=(11)-1;i>=(1);i--){
          chmin(up[i-1], up[i]);
        }
        for(k=(0);k<(N+1);k++){
          tmp = 0;
          for(i=(0);i<(k);i++){
            if(up[S[i]] == 10){
              goto tU__gIr_;
            }
            tmp = 10 * tmp + up[S[i]];
          }
          if(k < N){
            if(up[S[i]+1] == 10){
              continue;
            }
            tmp = 10 * tmp + up[S[i]+1];
          }
          for(i=(k+1);i<(N);i++){
            tmp = 10 * tmp + up[0];
          }
          chmin(res, tmp);
          tU__gIr_:;
        }
      }
    }
    wt_L(res);
    wt_L('\n');
  }
  return 0;
}
// cLay version 20210816-1

// --- original code ---
// //no-unlocked
// int N, K;
// char S[12];
// {
//   REP(rd_int()){
//     ll res = ll_inf, tmp;
//     int up[11];
//     rd(S@N, K);
//     rep(i,N) S[i] -= '0';
//     rep(mask,1,1<<10) if(BIT_popcount(mask) <= K){
//       rep(i,11) up[i] = if[BIT_ith(mask,i), i, 10];
//       rrep(i,1,11) up[i-1] <?= up[i];
// 
//       rep(k,N+1){
//         tmp = 0;
//         rep(i,k){
//           if(up[S[i]] == 10) break_continue;
//           tmp = 10 * tmp + up[S[i]];
//         }
//         if(k < N){
//           if(up[S[i]+1] == 10) continue;
//           tmp = 10 * tmp + up[S[i]+1];
//         }
//         rep(i,k+1,N) tmp = 10 * tmp + up[0];
//         res <?= tmp;
//       }
//     }
//     wt(res);
//   }
// }