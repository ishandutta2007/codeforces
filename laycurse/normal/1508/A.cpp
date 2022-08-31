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
template<class T, class S> int arrCountVal(int N, T A[], S val){
  int i;
  int res = 0;
  for(i=(0);i<(N);i++){
    if(A[i]==val){
      res++;
    }
  }
  return res;
}
int N;
char S[3][200000+2];
char res[300000+2];
int main(){
  int Lj4PdHRW;
  int KL2GvlyY = rd_int();
  for(Lj4PdHRW=(0);Lj4PdHRW<(KL2GvlyY);Lj4PdHRW++){
    int i, x;
    int z[3];
    int o[3];
    int a = 0;
    int b = 0;
    int s = 0;
    int m;
    rd(N);
    {
      int cTE1_r3A;
      for(cTE1_r3A=(0);cTE1_r3A<(3);cTE1_r3A++){
        rd(S[cTE1_r3A]);
      }
    }
    res[3*N] = '\0';
    for(i=(0);i<(3);i++){
      z[i] = arrCountVal(2*N, S[i], '0');
    }
    for(i=(0);i<(3);i++){
      o[i] = arrCountVal(2*N, S[i], '1');
    }
    for(x=(0);x<(3);x++){
      int y;
      for(y=(x+1);y<(3);y++){
        if((o[x] >= z[x] && o[y] >= z[y]) || (o[x] <= z[x] && o[y] <= z[y])){
          if(o[x] >= z[x] && o[y] >= z[y]){
            m ='0';
          }
          else{
            m ='1';
          }
          while(a < 2*N && b < 2*N){
            if(S[x][a] == S[y][b]){
              res[s++] = S[x][a];
              a++;
              b++;
              continue;
            }
            if(S[x][a] == m){
              res[s++] = S[x][a++];
              continue;
            }
            if(S[y][b] == m){
              res[s++] =  S[y][b++];
              continue;
            }
          }
          while(a < 2*N){
            res[s++] = S[x][a++];
          }
          while(b < 2*N){
            res[s++] = S[y][b++];
          }
          res[s] = '\0';
          goto tU__gIr_;
        }
      }
    }
    tU__gIr_:;
    wt_L(res);
    wt_L('\n');
  }
  return 0;
}
// cLay version 20210405-1

// --- original code ---
// //no-unlocked
// int N;
// char S[3][2d5+2], res[3d5+2];
// {
//   REP(rd_int()){
//     int z[3], o[3], a = 0, b = 0, s = 0, m;
//     rd(N,S(3));
//     res[3*N] = '\0';
// 
//     rep(i,3) z[i] = arrCountVal(2*N, S[i], '0');
//     rep(i,3) o[i] = arrCountVal(2*N, S[i], '1');
//     rep(x,3) rep(y,x+1,3) if((o[x] >= z[x] && o[y] >= z[y]) || (o[x] <= z[x] && o[y] <= z[y])){
//       m = if[o[x] >= z[x] && o[y] >= z[y], '0', '1'];
//       while(a < 2*N && b < 2*N){
//         if(S[x][a] == S[y][b]) res[s++] = S[x][a], a++, b++, continue;
//         if(S[x][a] == m) res[s++] = S[x][a++], continue;
//         if(S[y][b] == m) res[s++] =  S[y][b++], continue;
//       }
//       while(a < 2*N) res[s++] = S[x][a++];
//       while(b < 2*N) res[s++] = S[y][b++];
//       res[s] = '\0';
//       break_break;
//     }
//     wt(res);
//   }
// }