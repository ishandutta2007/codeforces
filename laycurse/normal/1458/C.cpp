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
template<class S, class T> inline S moddw_L(S a, const T b){
  a %= b;
  if(a < 0){
    a += b;
  }
  return a;
}
int N;
int Q;
int A[1000][1000];
int tmp[1000][1000];
int arr[1000];
char S[100000+2];
void do_move(int x, int y){
  int i;
  for(i=(0);i<(N);i++){
    int j;
    for(j=(0);j<(N);j++){
      tmp[i][j] = A[i][j];
    }
  }
  for(i=(0);i<(N);i++){
    int j;
    for(j=(0);j<(N);j++){
      A[i][j] = tmp[(moddw_L((i-x),N))][(moddw_L((j-y),N))];
    }
  }
}
void do_rot_x(void){
  int j;
  for(j=(0);j<(N);j++){
    int i;
    for(i=(0);i<(N);i++){
      arr[A[i][j]] = i;
    }
    for(i=(0);i<(N);i++){
      A[i][j] = arr[i];
    }
  }
}
void do_rot_y(void){
  int i;
  for(i=(0);i<(N);i++){
    int j;
    for(j=(0);j<(N);j++){
      arr[A[i][j]] = j;
    }
    for(j=(0);j<(N);j++){
      A[i][j] = arr[j];
    }
  }
}
int main(){
  int ZIeRIny5;
  int iMWUTgY_ = rd_int();
  for(ZIeRIny5=(0);ZIeRIny5<(iMWUTgY_);ZIeRIny5++){
    int i, q;
    int x[6] = {};
    int y[6] = {};
    int cur = 0;
    rd(N);
    rd(Q);
    {
      int jPV_0s1p;
      int BUotOFBp;
      for(jPV_0s1p=(0);jPV_0s1p<(N);jPV_0s1p++){
        for(BUotOFBp=(0);BUotOFBp<(N);BUotOFBp++){
          rd(A[jPV_0s1p][BUotOFBp]);A[jPV_0s1p][BUotOFBp] += (-1);
        }
      }
    }
    rd(S);
    for(q=(0);q<(Q);q++){
      if(S[q] == 'R'){
        y[cur]++;
      }
      if(S[q] == 'L'){
        y[cur]--;
      }
      if(S[q] == 'D'){
        x[cur]++;
      }
      if(S[q] == 'U'){
        x[cur]--;
      }
      if(S[q] == 'I'){
        if(cur%2){
          cur =(moddw_L((cur +-1),6));
        }
        else{
          cur =(moddw_L((cur +1),6));
        }
      }
      if(S[q] == 'C'){
        if(cur%2){
          cur =(moddw_L((cur +1),6));
        }
        else{
          cur =(moddw_L((cur +-1),6));
        }
      }
    }
    for(i=(0);i<(6);i++){
      do_move(x[i], y[i]);
      if(i%2==0){
        do_rot_y();
      }
      else{
        do_rot_x();
      }
    }
    for(i=(0);i<(cur);i++){
      if(i%2==0){
        do_rot_y();
      }
      else{
        do_rot_x();
      }
    }
    {
      int O3U4gd88;
      int H31bcJ8S;
      for(O3U4gd88=(0);O3U4gd88<(N);O3U4gd88++){
        if(N==0){
          wt_L('\n');
        }
        else{
          for(H31bcJ8S=(0);H31bcJ8S<(N-1);H31bcJ8S++){
            wt_L(A[O3U4gd88][H31bcJ8S]+1);
            wt_L(' ');
          }
          wt_L(A[O3U4gd88][H31bcJ8S]+1);
          wt_L('\n');
        }
      }
    }
  }
  return 0;
}
// cLay version 20201229-1

// --- original code ---
// //no-unlocked
// int N, Q, A[1000][1000], tmp[1000][1000], arr[1000];
// char S[1d5+2];
// 
// void do_move(int x, int y){
//   rep(i,N) rep(j,N) tmp[i][j] = A[i][j];
//   rep(i,N) rep(j,N) A[i][j] = tmp[(i-x)%%N][(j-y)%%N];
// }
// 
// void do_rot_x(void){
//   rep(j,N){
//     rep(i,N) arr[A[i][j]] = i;
//     rep(i,N) A[i][j] = arr[i];
//   }
// }
// 
// void do_rot_y(void){
//   rep(i,N){
//     rep(j,N) arr[A[i][j]] = j;
//     rep(j,N) A[i][j] = arr[j];
//   }
// }
// 
// {
//   REP(rd_int()){
//     int x[6] = {}, y[6] = {}, cur = 0;
//     rd(N,Q,(A--)(N,N),S);
// 
//     rep(q,Q){
//       if(S[q] == 'R') y[cur]++;
//       if(S[q] == 'L') y[cur]--;
//       if(S[q] == 'D') x[cur]++;
//       if(S[q] == 'U') x[cur]--;
//       if(S[q] == 'I') cur = (cur + if[cur%2, -1, 1]) %% 6;
//       if(S[q] == 'C') cur = (cur + if[cur%2, 1, -1]) %% 6;
//     }
// 
//     rep(i,6){
//       do_move(x[i], y[i]);
//       if[i%2==0, do_rot_y(), do_rot_x()];
//     }
//     rep(i,cur){
//       if[i%2==0, do_rot_y(), do_rot_x()];
//     }
// 
//     wt(A(N,N)+1);
//   }
// }