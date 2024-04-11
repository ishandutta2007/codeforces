#pragma GCC optimize ("Ofast")
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
template<class T1> void sortA_L(int N, T1 a[], void *mem = wmem){
  sort(a, a+N);
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
int A[100000];
int res[100000];
int main(){
  wmem = memarr;
  int i;
  int mx;
  int opt;
  rd(N);
  {
    int Lj4PdHRW;
    for(Lj4PdHRW=(0);Lj4PdHRW<(N);Lj4PdHRW++){
      rd(A[Lj4PdHRW]);
    }
  }
  sortA_L(N, A);
  mx = (N-1) / 2;
  int e98WHCEY;
  int cTE1_r3A;
  int RZTsC2BF;
  e98WHCEY = 0;
  cTE1_r3A = mx;
  while(e98WHCEY < cTE1_r3A){
    if((e98WHCEY + cTE1_r3A)%2==0){
      RZTsC2BF = (e98WHCEY + cTE1_r3A) / 2;
    }
    else{
      RZTsC2BF = (e98WHCEY + cTE1_r3A + 1) / 2;
    }
    for(i=(0);i<(RZTsC2BF);i++){
      if(A[i] >= A[N-RZTsC2BF-1+i]){
        break;
      }
    }
    if(i==RZTsC2BF){
      e98WHCEY = RZTsC2BF;
    }
    else{
      cTE1_r3A = RZTsC2BF - 1;
    }
  }
  opt =cTE1_r3A;
  for(i=(0);i<(opt);i++){
    res[2*i+1] = A[i];
  }
  for(i=(0);i<(opt+1);i++){
    res[2*i] = A[N-opt-1+i];
  }
  for(i=(opt);i<(N-opt-1);i++){
    res[i+opt+1] = A[i];
  }
  wt_L(opt);
  wt_L('\n');
  {
    int APIVbQlN;
    if(N==0){
      wt_L('\n');
    }
    else{
      for(APIVbQlN=(0);APIVbQlN<(N-1);APIVbQlN++){
        wt_L(res[APIVbQlN]);
        wt_L(' ');
      }
      wt_L(res[APIVbQlN]);
      wt_L('\n');
    }
  }
  return 0;
}
// cLay varsion 20200916-1

// --- original code ---
// //no-unlocked
// int N, A[1d5];
// int res[1d5];
// 
// {
//   int i, mx, opt;
//   rd(N,A(N));
// 
//   sortA(N, A);
// 
//   mx = (N-1) / 2;
//   opt = bsearch_max[int,x,0,mx][
//     rep(i,x) if(A[i] >= A[N-x-1+i]) break;
//   ](i==x);
// 
//   rep(i,opt) res[2*i+1] = A[i];
//   rep(i,opt+1) res[2*i] = A[N-opt-1+i];
//   rep(i,opt,N-opt-1) res[i+opt+1] = A[i];
// 
//   wt(opt);
//   wt(res(N));
// }