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
int K;
int ress;
char res[200000+2];
int main(){
  int i;
  rd(N);
  rd(K);
  for(i=(0);i<(K);i++){
    res[ress++] = i;
  }
  for(i=(K)-1;i>=(1);i--){
    int j;
    res[ress++] = i;
    for(j=(0);j<(i-1);j++){
      res[ress++] = j;
      res[ress++] = i;
    }
    res[ress++] = i-1;
  }
  for(i=(ress);i<(N);i++){
    res[i] = res[i-ress];
  }
  for(i=(0);i<(N);i++){
    res[i] += 'a';
  }
  res[N] = '\0';
  wt_L(res);
  wt_L('\n');
  return 0;
}
// cLay version 20210405-1

// --- original code ---
// //no-unlocked
// int N, K;
// int ress; char res[2d5+2];
// {
//   rd(N,K);
//   rep(i,K) res[ress++] = i;
//   rrep(i,1,K){
//     res[ress++] = i;
//     rep(j,i-1) res[ress++] = j, res[ress++] = i;
//     res[ress++] = i-1;
//   }
//   rep(i,ress,N) res[i] = res[i-ress];
//   rep(i,N) res[i] += 'a';
//   res[N] = '\0';
//   wt(res);
// }