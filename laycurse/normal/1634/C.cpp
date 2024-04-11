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
int main(){
  int Nzj9Y0kE;
  int bkxOPzPX = rd_int();
  for(Nzj9Y0kE=(0);Nzj9Y0kE<(bkxOPzPX);Nzj9Y0kE++){
    int i;
    int N;
    rd(N);
    int K;
    rd(K);
    int a[N][K];
    if(K==1){
      int i;
      wt_L("YES");
      wt_L('\n');
      for(i=(0);i<(N);i++){
        wt_L(i+1);
        wt_L('\n');
      }
      continue;
    }
    if(N%2){
      wt_L("NO");
      wt_L('\n');
      continue;
    }
    for(i=(0);i<(N);i++){
      int j;
      for(j=(0);j<(K);j++){
        a[i][j] = ((i/2)*2) * K + (i%2) + 2*j + 1;
      }
    }
    wt_L("YES");
    wt_L('\n');
    {
      int pyHJGNQc;
      int wbH8AaCb;
      for(pyHJGNQc=(0);pyHJGNQc<(N);pyHJGNQc++){
        if(K==0){
          wt_L('\n');
        }
        else{
          for(wbH8AaCb=(0);wbH8AaCb<(K-1);wbH8AaCb++){
            wt_L(a[pyHJGNQc][wbH8AaCb]);
            wt_L(' ');
          }
          wt_L(a[pyHJGNQc][wbH8AaCb]);
          wt_L('\n');
        }
      }
    }
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
// cLay version 20220116-1 [+beta]

// --- original code ---
// //no-unlocked
// REP(rd_int()){
//   int @N, @K, a[N][K];
//   if(K==1){
//     wt("YES");
//     rep(i,N) wt(i+1);
//     continue;
//   }
//   if(N%2) wt("NO"), continue;
//   rep(i,N) rep(j,K) a[i][j] = ((i/2)*2) * K + (i%2) + 2*j + 1;
//   wt("YES");
//   wt(a(N,K));
// }