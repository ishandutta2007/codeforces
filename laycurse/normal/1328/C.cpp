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
inline void wt_L(const char c[]){
  int i=0;
  for(i=0;c[i]!='\0';i++){
    my_putchar(c[i]);
  }
}
int N;
char C[100000];
char a[100000];
char b[100000];
int main(){
  int Lj4PdHRW;
  int fg;
  int KL2GvlyY = rd_int();
  for(Lj4PdHRW=(0);Lj4PdHRW<(KL2GvlyY);Lj4PdHRW++){
    int i;
    rd(N);
    rd(C);
    for(i=(0);i<(N);i++){
      C[i] -= '0';
    }
    for(i=(0);i<(N);i++){
      if(C[i]==2){
        a[i] = b[i] = 1;
        continue;
      }
      if(C[i]==0){
        a[i] = b[i] = 0;
        continue;
      }
      a[i] = 1;
      b[i] = 0;
      i++;
      while(i<N){
        a[i] = 0;
        b[i] = C[i];
        i++;
      }
    }
    for(i=(0);i<(N);i++){
      {
        auto tU__gIr_ = ('0');
        a[i] += tU__gIr_;
        b[i] += tU__gIr_;
      }
    }
    {
      auto a2conNHc = ('\0');
      a[N] = a2conNHc;
      b[N] = a2conNHc;
    }
    wt_L(a);
    wt_L('\n');
    wt_L(b);
    wt_L('\n');
  }
  return 0;
}
// cLay varsion 20200322-1 [beta]

// --- original code ---
// //no-unlocked
// int N;
// char C[1d5];
// char a[1d5], b[1d5];
// {
//   int fg;
// 
//   REP(rd_int()){
//     rd(N,C);
//     rep(i,N) C[i] -= '0';
// 
//     rep(i,N){
//       if(C[i]==2) a[i] = b[i] = 1, continue;
//       if(C[i]==0) a[i] = b[i] = 0, continue;
// 
//       a[i] = 1;
//       b[i] = 0;
//       i++;
//       while(i<N){
//         a[i] = 0;
//         b[i] = C[i];
//         i++;
//       }
//     }
// 
//     rep(i,N) (a[i], b[i]) += '0';
//     (a[N], b[N]) = '\0';
//     wtLn(a,b);
//   }
// }