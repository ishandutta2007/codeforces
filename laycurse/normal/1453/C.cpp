#pragma GCC optimize ("Ofast")
#include<bits/stdc++.h>
using namespace std;
template<class S, class T> inline S max_L(S a,T b){
  return a>=b?a:b;
}
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
    my_putchar('-');
  }
  while(s--){
    my_putchar(f[s]+'0');
  }
}
template<class S, class T> inline S chmin(S &a, T b){
  if(a>b){
    a=b;
  }
  return a;
}
template<class S, class T> inline S chmax(S &a, T b){
  if(a<b){
    a=b;
  }
  return a;
}
int N;
char S[2000][2002];
char tmp[2000][2000];
int res[10];
int xmin[10];
int xmax[10];
int mn[10];
int mx[10];
int main(){
  int Lj4PdHRW;
  int KL2GvlyY = rd_int();
  for(Lj4PdHRW=(0);Lj4PdHRW<(KL2GvlyY);Lj4PdHRW++){
    int i, loop;
    rd(N);
    {
      int cTE1_r3A;
      for(cTE1_r3A=(0);cTE1_r3A<(N);cTE1_r3A++){
        rd(S[cTE1_r3A]);
      }
    }
    for(i=(0);i<(N);i++){
      int j;
      for(j=(0);j<(N);j++){
        S[i][j] -= '0';
      }
    }
    for(i=(0);i<(10);i++){
      res[i] = 0;
    }
    for(loop=(0);loop<(2);loop++){
      int k;
      for(k=(0);k<(10);k++){
        xmin[k] = 1073709056;
        xmax[k] = -1073709056;
      }
      for(i=(0);i<(N);i++){
        int j;
        for(j=(0);j<(N);j++){
          chmin(xmin[S[i][j]], i);
          chmax(xmax[S[i][j]], i);
        }
      }
      for(i=(0);i<(N);i++){
        int j;
        for(k=(0);k<(10);k++){
          mn[k] = 1073709056;
          mx[k] = -1073709056;
        }
        for(j=(0);j<(N);j++){
          chmin(mn[S[i][j]], j);
          chmax(mx[S[i][j]], j);
        }
        for(k=(0);k<(10);k++){
          if(mn[k] != 1073709056){
            chmax(res[k], (mx[k] - mn[k]) *max_L(N-1-i, i));
            chmax(res[k], max_L(N-1 - mn[k], mx[k])*max_L(i - xmin[k], xmax[k] - i));
          }
        }
      }
      for(i=(0);i<(N);i++){
        int j;
        for(j=(0);j<(N);j++){
          tmp[i][j] = S[i][j];
        }
      }
      for(i=(0);i<(N);i++){
        int j;
        for(j=(0);j<(N);j++){
          S[i][j] = tmp[j][i];
        }
      }
    }
    {
      int o3WxPXbE;
      if(10==0){
        wt_L('\n');
      }
      else{
        for(o3WxPXbE=(0);o3WxPXbE<(10-1);o3WxPXbE++){
          wt_L(res[o3WxPXbE]);
          wt_L(' ');
        }
        wt_L(res[o3WxPXbE]);
        wt_L('\n');
      }
    }
  }
  return 0;
}
// cLay version 20201205-1

// --- original code ---
// //no-unlocked
// int N;
// char S[2000][2002], tmp[2000][2000];
// int res[10];
// int xmin[10], xmax[10], mn[10], mx[10];
// {
//   REP(rd_int()){
//     rd(N,S(N));
//     rep(i,N) rep(j,N) S[i][j] -= '0';
//     rep(i,10) res[i] = 0;
//     rep(loop,2){
//       rep(k,10) xmin[k] = int_inf, xmax[k] = -int_inf;
//       rep(i,N) rep(j,N){
//         xmin[S[i][j]] <?= i;
//         xmax[S[i][j]] >?= i;
//       }
//       rep(i,N){
//         rep(k,10) mn[k] = int_inf, mx[k] = -int_inf;
//         rep(j,N){
//           mn[S[i][j]] <?= j;
//           mx[S[i][j]] >?= j;
//         }
//         rep(k,10) if(mn[k] != int_inf){
//           res[k] >?= (mx[k] - mn[k]) * max(N-1-i, i);
//           res[k] >?= max(N-1 - mn[k], mx[k]) * max(i - xmin[k], xmax[k] - i);
//         }
//       }
//       rep(i,N) rep(j,N) tmp[i][j] = S[i][j];
//       rep(i,N) rep(j,N) S[i][j] = tmp[j][i];
//     }
//     wt(res(10));
//   }
// }