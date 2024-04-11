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
inline void wt_L(const char c[]){
  int i=0;
  for(i=0;c[i]!='\0';i++){
    my_putchar(c[i]);
  }
}
template<class T> int Distinct(int N, T A[], int sorted=0, void *mem = wmem){
  int i;
  int k;
  int res = 1;
  T*a;
  if(N==0){
    return 0;
  }
  if(sorted){
    for(i=(1);i<(N);i++){
      if(A[i]!=A[i-1]){
        res++;
      }
    }
  }
  else{
    walloc1d(&a,N,&mem);
    for(i=(0);i<(N);i++){
      a[i] = A[i];
    }
    sort(a,a+N);
    for(i=(1);i<(N);i++){
      if(a[i]!=a[i-1]){
        res++;
      }
    }
  }
  return res;
}
int N;
int A[100000];
int ress;
int res[100000][3];
int main(){
  int i;
  wmem = memarr;
  rd(N);
  {
    int Lj4PdHRW;
    for(Lj4PdHRW=(0);Lj4PdHRW<(N);Lj4PdHRW++){
      rd(A[Lj4PdHRW]);
    }
  }
  for(i=(0);i<(N-2);i+=(2)){
    {
      auto RZTsC2BF = (i);
      auto FmcKpFmN = ( i+1);
      auto xr20shxY = ( i+2);
      res[ress][0] = RZTsC2BF;
      res[ress][1] = FmcKpFmN;
      res[ress][2] = xr20shxY;
    }
    {
      auto WYIGIcGE = (A[res[ress][0]]^A[res[ress][1]]^A[res[ress][2]]);
      A[res[ress][0]] = WYIGIcGE;
      A[res[ress][1]] = WYIGIcGE;
      A[res[ress][2]] = WYIGIcGE;
    }
    ress++;
  }
  for(i=(0);i<(N-4);i+=(2)){
    {
      auto ao_dF3pO = (i);
      auto tU__gIr_ = ( i+1);
      auto a2conNHc = ( N-2);
      res[ress][0] = ao_dF3pO;
      res[ress][1] = tU__gIr_;
      res[ress][2] = a2conNHc;
    }
    {
      auto hCmBdyQB = (A[res[ress][0]]^A[res[ress][1]]^A[res[ress][2]]);
      A[res[ress][0]] = hCmBdyQB;
      A[res[ress][1]] = hCmBdyQB;
      A[res[ress][2]] = hCmBdyQB;
    }
    ress++;
  }
  if(Distinct(N,A) != 1){
    wt_L("NO");
    wt_L('\n');
    return 0;
  }
  wt_L("YES");
  wt_L('\n');
  wt_L(ress);
  wt_L('\n');
  for(i=(0);i<(ress);i++){
    {
      int YREPHmFM;
      if(3==0){
        wt_L('\n');
      }
      else{
        for(YREPHmFM=(0);YREPHmFM<(3-1);YREPHmFM++){
          wt_L(res[i][YREPHmFM]+1);
          wt_L(' ');
        }
        wt_L(res[i][YREPHmFM]+1);
        wt_L('\n');
      }
    }
  }
  return 0;
}
// cLay varsion 20201115-1

// --- original code ---
// //no-unlocked
// int N, A[1d5];
// int ress, res[1d5][3];
// {
//   rd(N,A(N));
//   rep(i,0,N-2,2){
//     (res[ress][0], res[ress][1], res[ress][2]) = (i, i+1, i+2);
//     (A[res[ress][0]], A[res[ress][1]], A[res[ress][2]]) = A[res[ress][0]]^A[res[ress][1]]^A[res[ress][2]];
//     ress++;
//   }
//   rep(i,0,N-4,2){
//     (res[ress][0], res[ress][1], res[ress][2]) = (i, i+1, N-2);
//     (A[res[ress][0]], A[res[ress][1]], A[res[ress][2]]) = A[res[ress][0]]^A[res[ress][1]]^A[res[ress][2]];
//     ress++;
//   }
//   if(Distinct(N,A) != 1) wt("NO"), return 0;
// 
//   wt("YES");
//   wt(ress);
//   rep(i,ress) wt(res[i](3)+1);
// }