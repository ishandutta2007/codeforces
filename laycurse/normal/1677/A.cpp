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
template<class T> inline void wt_L(vector<T> x);
template<class T> inline void wt_L(set<T> x);
template<class T> inline void wt_L(multiset<T> x);
template<class T1, class T2> inline void wt_L(pair<T1,T2> x);
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
int main(){
  int Nzj9Y0kE;
  static int x[5001][5001];
  static int y[5001][5001];
  int bkxOPzPX = rd_int();
  for(Nzj9Y0kE=(0);Nzj9Y0kE<(bkxOPzPX);Nzj9Y0kE++){
    int i, k;
    int N;
    rd(N);
    int A[N];
    {
      int om7Ebh6q;
      for(om7Ebh6q=(0);om7Ebh6q<(N);om7Ebh6q++){
        rd(A[om7Ebh6q]);A[om7Ebh6q] += (-1);
      }
    }
    long long res = 0;
    for(i=(0);i<(N);i++){
      x[0][i] = 0;
    }
    for(k=(0);k<(N);k++){
      for(i=(0);i<(N);i++){
        x[k+1][i] = x[k][i];
      }
      for(i=(A[k]);i<(N);i++){
        x[k+1][i]++;
      }
    }
    for(i=(0);i<(N);i++){
      y[0][i] = 0;
    }
    for(k=(0);k<(N);k++){
      for(i=(0);i<(N);i++){
        y[k+1][i] = y[k][i];
      }
      for(i=(A[N-1-k]);i<(N);i++){
        y[k+1][i]++;
      }
    }
    for(i=(0);i<(N);i++){
      int j;
      for(j=(i+1);j<(N);j++){
        res += x[i][A[j]] * y[N-1-j][A[i]];
      }
    }
    wt_L(res);
    wt_L('\n');
  }
  return 0;
}
template<class T> inline void wt_L(vector<T> x){
  int fg = 0;
  for(auto a : x){
    if(fg){
      my_putchar(' ');
    }
    fg = 1;
    wt_L(a);
  }
}
template<class T> inline void wt_L(set<T> x){
  int fg = 0;
  for(auto a : x){
    if(fg){
      my_putchar(' ');
    }
    fg = 1;
    wt_L(a);
  }
}
template<class T> inline void wt_L(multiset<T> x){
  int fg = 0;
  for(auto a : x){
    if(fg){
      my_putchar(' ');
    }
    fg = 1;
    wt_L(a);
  }
}
template<class T1, class T2> inline void wt_L(pair<T1,T2> x){
  wt_L(x.first);
  my_putchar(' ');
  wt_L(x.second);
}
// cLay version 20220506-1

// --- original code ---
// //no-unlocked
// static int x[5001][5001], y[5001][5001];
// REP(rd_int()){
//   int @N, @A--[N];
//   ll res = 0;
// 
//   rep(i,N) x[0][i] = 0;
//   rep(k,N){
//     rep(i,N) x[k+1][i] = x[k][i];
//     rep(i,A[k],N) x[k+1][i]++;
//   }
// 
//   rep(i,N) y[0][i] = 0;
//   rep(k,N){
//     rep(i,N) y[k+1][i] = y[k][i];
//     rep(i,A[N-1-k],N) y[k+1][i]++;
//   }
// 
//   rep(i,N) rep(j,i+1,N) res += x[i][A[j]] * y[N-1-j][A[i]];
//   wt(res);
// }