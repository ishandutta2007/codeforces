#pragma GCC optimize ("Ofast")
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
int N;
char A[100000+2];
char B[100000+2];
int main(){
  int Lj4PdHRW;
  int KL2GvlyY = rd_int();
  for(Lj4PdHRW=(0);Lj4PdHRW<(KL2GvlyY);Lj4PdHRW++){
    int i;
    int j;
    int k;
    int nx;
    int res = 0;
    rd(N);
    rd(A);
    rd(B);
    for(i=(0);i<(N);i++){
      A[i] -= 'a';
    }
    for(i=(0);i<(N);i++){
      B[i] -= 'a';
    }
    for(k=(0);k<(20);k++){
      nx = 20;
      for(i=(0);i<(N);i++){
        if(A[i]==k && B[i]!=k){
          chmin(nx, B[i]);
        }
      }
      if(nx < k){
        wt_L(-1);
        wt_L('\n');
        goto Q5VJL1cS;
      }
      if(nx == 20){
        continue;
      }
      res++;
      for(i=(0);i<(N);i++){
        if(A[i]==k && B[i]!=k){
          A[i] = nx;
        }
      }
    }
    wt_L(res);
    wt_L('\n');
    Q5VJL1cS:;
  }
  return 0;
}
// cLay varsion 20200509-1

// --- original code ---
// //no-unlocked
// int N;
// char A[1d5+2], B[1d5+2];
// {
//   REP(rd_int()){
//     int i, j, k, nx, res = 0;
//     rd(N,A,B);
//     rep(i,N) A[i] -= 'a';
//     rep(i,N) B[i] -= 'a';
//     rep(k,20){
//       nx = 20;
//       rep(i,N) if(A[i]==k && B[i]!=k) nx <?= B[i];
//       if(nx < k) wt(-1), break_continue;
//       if(nx == 20) continue;
//       res++;
//       rep(i,N) if(A[i]==k && B[i]!=k) A[i] = nx;
//     }
//     wt(res);
//   }
// }