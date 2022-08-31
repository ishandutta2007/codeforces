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
int A;
int B;
char S[200000+2];
int main(){
  int Lj4PdHRW;
  int KL2GvlyY = rd_int();
  for(Lj4PdHRW=(0);Lj4PdHRW<(KL2GvlyY);Lj4PdHRW++){
    int i;
    int j;
    rd(A);
    rd(B);
    N = rd(S);
    for(i=(0);i<(N);i++){
      if(S[i] == '?' && S[N-1-i] != '?'){
        S[i] = S[N-1-i];
      }
    }
    for(i=(0);i<(N);i++){
      if(S[i] != S[N-1-i]){
        wt_L("-1");
        wt_L('\n');
        goto Q5VJL1cS;
      }
    }
    A -= arrCountVal(N,S,'0');
    B -= arrCountVal(N,S,'1');
    if(A < 0 || B < 0){
      wt_L("-1");
      wt_L('\n');
      continue;
    }
    for(i=(0);i<(N);i++){
      if(S[i] == '?'){
        j = N - 1 - i;
        if(i == j && A > 0){
          A--;
          S[i] = '0';
          break;
        }
        if(i == j && B > 0){
          B--;
          S[i] = '1';
          break;
        }
        if(A >= 2){
          S[i] = S[j] = '0';
          A -= 2;
          continue;
        }
        if(B >= 2){
          S[i] = S[j] = '1';
          B -= 2;
          continue;
        }
        wt_L("-1");
        wt_L('\n');
        goto Q5VJL1cS;
      }
    }
    wt_L(S);
    wt_L('\n');
    Q5VJL1cS:;
  }
  return 0;
}
// cLay version 20210405-1

// --- original code ---
// //no-unlocked
// int N, A, B;
// char S[2d5+2];
// {
//   REP(rd_int()){
//     int i, j;
//     rd(A,B,S@N);
//     rep(i,N) if(S[i] == '?' && S[N-1-i] != '?') S[i] = S[N-1-i];
//     rep(i,N) if(S[i] != S[N-1-i]) wt("-1"), break_continue;
//     A -= arrCountVal(N,S,'0');
//     B -= arrCountVal(N,S,'1');
//     if(A < 0 || B < 0) wt("-1"), continue;
//     rep(i,N) if(S[i] == '?'){
//       j = N - 1 - i;
//       if(i == j && A > 0) A--, S[i] = '0', break;
//       if(i == j && B > 0) B--, S[i] = '1', break;
//       if(A >= 2) S[i] = S[j] = '0', A -= 2, continue;
//       if(B >= 2) S[i] = S[j] = '1', B -= 2, continue;
//       wt("-1"), break_continue;
//     }
//     wt(S);
//   }
// }