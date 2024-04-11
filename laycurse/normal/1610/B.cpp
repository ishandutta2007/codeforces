#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
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
template<class T> inline int isPalindrome(const int N, const T A[]){
  int i = 0;
  int j = N-1;
  while(i < j){
    if(A[i] != A[j]){
      return 0;
    }
    ;
    i++;
    j--;
  }
  return 1;
}
int main(){
  int Lj4PdHRW;
  int KL2GvlyY = rd_int();
  for(Lj4PdHRW=(0);Lj4PdHRW<(KL2GvlyY);Lj4PdHRW++){
    int i, m;
    int N;
    rd(N);
    int A[N];
    {
      int cTE1_r3A;
      for(cTE1_r3A=(0);cTE1_r3A<(N);cTE1_r3A++){
        rd(A[cTE1_r3A]);
      }
    }
    int sz;
    int chk[N];
    int x[2];
    if(isPalindrome(N,A)){
      wt_L("YES");
      wt_L('\n');
      continue;
    }
    for(i=(0);i<(N);i++){
      if(A[i] != A[N-1-i]){
        auto t_ynMSdg = ((A[i]));
        auto KrdatlYV = (( A[N-1-i]));
        x[0]=t_ynMSdg;
        x[1]=KrdatlYV;
        break;
      }
    }
    for(m=(0);m<(2);m++){
      sz = 0;
      for(i=(0);i<(N);i++){
        if(A[i] != x[m]){
          chk[sz++] = A[i];
        }
      }
      if(isPalindrome(sz,chk)){
        wt_L("YES");
        wt_L('\n');
        goto Q5VJL1cS;
      }
    }
    wt_L("NO");
    wt_L('\n');
    Q5VJL1cS:;
  }
  return 0;
}
// cLay version 20211024-1 [beta]

// --- original code ---
// //no-unlocked
// REP(rd_int()){
//   int @N, @A[N], sz, chk[N], x[2];
//   if(isPalindrome(N,A)) wt("YES"), continue;
//   rep(i,N) if(A[i] != A[N-1-i]) (x[0], x[1]) = (A[i], A[N-1-i]), break;
// 
//   rep(m,2){
//     sz = 0;
//     rep(i,N) if(A[i] != x[m]) chk[sz++] = A[i];
//     if(isPalindrome(sz,chk)) wt("YES"), break_continue;
//   }
//   wt("NO");
// }