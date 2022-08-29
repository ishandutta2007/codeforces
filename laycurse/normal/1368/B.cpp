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
inline void rd(long long &x){
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
long long K;
const char *cf = "codeforces";
int ress;
char res[100000];
int main(){
  int i;
  int ind = 0;
  long long len[10];
  long long tmp;
  for(i=(0);i<(10);i++){
    len[i] = 1;
  }
  rd(K);
  for(;;){
    {
      int cTE1_r3A;
      long long RZTsC2BF;
      if(10==0){
        RZTsC2BF = 1;
      }
      else{
        RZTsC2BF = len[0];
        for(cTE1_r3A=(1);cTE1_r3A<(10);cTE1_r3A++){
          RZTsC2BF *= len[cTE1_r3A];
        }
      }
      tmp =RZTsC2BF;
    }
    if(tmp >= K){
      break;
    }
    len[ind]++;
    ind = (ind+1) % 10;
  }
  for(i=(0);i<(10);i++){
    int KrdatlYV;
    for(KrdatlYV=(0);KrdatlYV<(len[i]);KrdatlYV++){
      res[ress++] = cf[i];
    }
  }
  wt_L(res);
  wt_L('\n');
  return 0;
}
// cLay varsion 20200509-1

// --- original code ---
// //no-unlocked
// ll K;
// 
// const char *cf = "codeforces";
// int ress; char res[1d5];
// 
// {
//   int ind = 0;
//   ll len[10], tmp;
//   rep(i,10) len[i] = 1;
//   rd(K);
//   for(;;){
//     tmp = mul(len(10));
//     if(tmp >= K) break;
//     len[ind]++;
//     ind = (ind+1) % 10;
//   }
//   rep(i,10) rep(len[i]) res[ress++] = cf[i];
//   wt(res);
// }