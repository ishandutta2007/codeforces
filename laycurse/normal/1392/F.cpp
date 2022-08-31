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
inline void wt_L(long long x){
  int s=0;
  int m=0;
  char f[20];
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
long long H[1000000];
long long sm;
long long c;
int main(){
  int i;
  rd(N);
  {
    int Lj4PdHRW;
    for(Lj4PdHRW=(0);Lj4PdHRW<(N);Lj4PdHRW++){
      rd(H[Lj4PdHRW]);
    }
  }
  {
    int e98WHCEY;
    long long cTE1_r3A;
    if(N==0){
      cTE1_r3A = 0;
    }
    else{
      cTE1_r3A = H[0];
      for(e98WHCEY=(1);e98WHCEY<(N);e98WHCEY++){
        cTE1_r3A += H[e98WHCEY];
      }
    }
    sm =cTE1_r3A;
  }
  for(i=(0);i<(N);i++){
    sm -= (H[i] = i);
  }
  c = sm / N;
  for(i=(0);i<(N);i++){
    H[i] += c;
    sm -= c;
  }
  for(i=(0);i<(sm);i++){
    H[i]++;
  }
  {
    int a2conNHc;
    if(N==0){
      wt_L('\n');
    }
    else{
      for(a2conNHc=(0);a2conNHc<(N-1);a2conNHc++){
        wt_L(H[a2conNHc]);
        wt_L(' ');
      }
      wt_L(H[a2conNHc]);
      wt_L('\n');
    }
  }
  return 0;
}
// cLay varsion 20200813-1 [beta]

// --- original code ---
// //no-unlocked
// int N;
// ll H[1d6], sm, c;
// {
//   rd(N,H(N));
//   sm = sum(H(N));
//   rep(i,N) sm -= (H[i] = i);
//   c = sm / N;
//   rep(i,N) H[i] += c, sm -= c;
//   rep(i,sm) H[i]++;
//   wt(H(N));
// }