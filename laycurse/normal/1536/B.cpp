#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include<bits/stdc++.h>
using namespace std;
void*wmem;
char memarr[96000000];
template<class T> inline void walloc1d(T **arr, int x, void **mem = &wmem){
  static int skip[16] = {0, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
  (*mem) = (void*)( ((char*)(*mem)) + skip[((unsigned long long)(*mem)) & 15] );
  (*arr)=(T*)(*mem);
  (*mem)=((*arr)+x);
}
template<class T> inline void walloc1d(T **arr, int x1, int x2, void **mem = &wmem){
  walloc1d(arr, x2-x1, mem);
  (*arr) -= x1;
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
inline void rd(string &x){
  char*buf = (char *)wmem;
  rd(buf);
  x = buf;
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
inline void wt_L(string &x){
  int i=0;
  for(i=0;x[i]!='\0';i++){
    my_putchar(x[i]);
  }
}
int isSubstring(string A, string B, void *mem = wmem){
  int i = 0;
  int k;
  int*fail;
  char*m;
  if(B.size() > A.size()){
    return 0;
  }
  walloc1d(&fail, B.size()+1, &mem);
  k = fail[0] = -1;
  for(i=(0);i<(B.size());i++){
    while(k>=0 && B[k] != B[i]){
      k = fail[k];
    }
    fail[i+1] = ++k;
  }
  k = 0;
  for(i=(0);i<(A.size());i++){
    while(k >= 0 && B[k] != A[i]){
      k = fail[k];
    }
    if((++k) == B.size()){
      return 1;
    }
  }
  return 0;
}
int N;
string S;
int sz = 1;
string chk[100000];
int main(){
  int cTE1_r3A, k;
  wmem = memarr;
  for(k=(0);k<(sz);k++){
    int i;
    for(i=('a');i<('z'+1);i++){
      if(sz <= 1000){
        chk[sz] = chk[k] + (char)i;
        sz++;
      }
    }
  }
  int RZTsC2BF = rd_int();
  for(cTE1_r3A=(0);cTE1_r3A<(RZTsC2BF);cTE1_r3A++){
    rd(N);
    rd(S);
    for(k=(1);k<(sz);k++){
      if(!isSubstring(S,chk[k])){
        wt_L(chk[k]);
        wt_L('\n');
        break;
      }
    }
  }
  return 0;
}
// cLay version 20210607-1

// --- original code ---
// //no-unlocked
// int N; string S;
// int sz = 1; string chk[1d5];
// {
//   rep(k,sz) rep(i,'a','z'+1) if(sz <= 1000){
//     chk[sz] = chk[k] + (char)i;
//     sz++;
//   }
//   REP(rd_int()){
//     rd(N,S);
//     rep(k,1,sz) if(!isSubstring(S,chk[k])) wt(chk[k]), break;
//   }
// }