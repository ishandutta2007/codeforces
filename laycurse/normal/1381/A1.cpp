#pragma GCC optimize ("Ofast")
#include<bits/stdc++.h>
using namespace std;
template<class S, class T> inline S min_L(S a,T b){
  return a<=b?a:b;
}
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
int N;
char A[100000+2];
char B[100000+2];
int ress;
int res[200000];
int x;
int y;
int f;
void del_y(void){
  if(f==0){
    y--;
  }
  else{
    y++;
  }
  N--;
}
void flip(void){
  swap(x, y);
  f ^= 1;
  res[ress++] =max_L(x, y)-min_L(x, y)+ 1;
}
void do_one(void){
  res[ress++] = 1;
}
int main(){
  int Q5VJL1cS;
  int e98WHCEY = rd_int();
  for(Q5VJL1cS=(0);Q5VJL1cS<(e98WHCEY);Q5VJL1cS++){
    int i;
    rd(N);
    rd(A);
    rd(B);
    for(i=(0);i<(N);i++){
      A[i] -= '0';
    }
    for(i=(0);i<(N);i++){
      B[i] -= '0';
    }
    ress = 0;
    x = 0;
    y = N-1;
    f = 0;
    while(N){
      if((A[y]^f) == B[N-1]){
        del_y();
        continue;
      }
      if((A[x]^f) != B[N-1]){
        flip();
        del_y();
        continue;
      }
      do_one();
      flip();
      del_y();
    }
    wt_L(ress);
    wt_L(' ');
    {
      int tU__gIr_;
      if(ress==0){
        wt_L('\n');
      }
      else{
        for(tU__gIr_=(0);tU__gIr_<(ress-1);tU__gIr_++){
          wt_L(res[tU__gIr_]);
          wt_L(' ');
        }
        wt_L(res[tU__gIr_]);
        wt_L('\n');
      }
    }
  }
  return 0;
}
// cLay varsion 20200509-1

// --- original code ---
// //no-unlocked
// int N;
// char A[1d5+2], B[1d5+2];
// int ress, res[2d5];
// int x, y, f;
// 
// void del_y(void){
//   if[f==0, y--, y++];
//   N--;
// }
// 
// void flip(void){
//   swap(x, y);
//   f ^= 1;
//   res[ress++] = max(x,y) - min(x,y) + 1;
// }
// 
// void do_one(void){
//   res[ress++] = 1;
// }
// 
// {
//   REP(rd_int()){
//     rd(N,A,B);
//     rep(i,N) A[i] -= '0';
//     rep(i,N) B[i] -= '0';
//     ress = 0;
// 
//     x = 0;
//     y = N-1;
//     f = 0;
//     while(N){
//       if((A[y]^f) == B[N-1]) del_y(), continue;
//       if((A[x]^f) != B[N-1]) flip(), del_y(), continue;
//       do_one(); flip(); del_y();
//     }
// 
//     wt(ress, res(ress));
//   }
// }