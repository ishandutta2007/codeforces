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
int isValidBracket1(int N, char S[]){
  int i;
  int k = 0;
  if(N%2){
    return 0;
  }
  for(i=(0);i<(N);i++){
    if(S[i] == '('){
      k++;
    }
    else if(S[i] == ')'){
      k--;
    }
    else{
      return 0;
    }
    if(k < 0){
      return 0;
    }
  }
  if(k==0){
    return 1;
  }
  return 0;
}
int N;
char S[200000+2];
char A[200000+2];
char B[200000+2];
int main(){
  int Lj4PdHRW;
  int KL2GvlyY = rd_int();
  for(Lj4PdHRW=(0);Lj4PdHRW<(KL2GvlyY);Lj4PdHRW++){
    int i;
    int on;
    int x = 0;
    int y = 0;
    rd(N);
    rd(S);
    on = arrCountVal(N,S,'1');
    if(on % 2){
      wt_L("NO");
      wt_L('\n');
      continue;
    }
    for(i=(0);i<(N);i++){
      if(S[i]=='1'){
        if(x < on/2){
          A[i] = B[i] ='(';
        }
        else{
          A[i] = B[i] =')';
        }
        x++;
      }
    }
    for(i=(0);i<(N);i++){
      if(S[i]=='0'){
        A[i] = '(';
        B[i] = ')';
        if((y++)%2){
          swap(A[i], B[i]);
        }
      }
    }
    if(isValidBracket1(N,A)==0 || isValidBracket1(N,B)==0){
      wt_L("NO");
      wt_L('\n');
      continue;
    }
    A[N] = B[N] = '\0';
    wt_L("YES");
    wt_L('\n');
    wt_L(A);
    wt_L('\n');
    wt_L(B);
    wt_L('\n');
  }
  return 0;
}
// cLay version 20210404-1

// --- original code ---
// //no-unlocked
// int N; char S[2d5+2];
// char A[], B[];
// {
//   REP(rd_int()){
//     int on, x = 0, y = 0;
//     rd(N,S);
//     on = arrCountVal(N,S,'1');
//     if(on % 2) wt("NO"), continue;
//     
//     rep(i,N) if(S[i]=='1') A[i] = B[i] = if[x < on/2, '(', ')'], x++;
//     rep(i,N) if(S[i]=='0'){
//       A[i] = '(';
//       B[i] = ')';
//       if((y++)%2) swap(A[i], B[i]);
//     }
// 
//     if(isValidBracket1(N,A)==0 || isValidBracket1(N,B)==0) wt("NO"), continue;
//     A[N] = B[N] = '\0';
//     wtLn("YES", A, B);
//   }
// }