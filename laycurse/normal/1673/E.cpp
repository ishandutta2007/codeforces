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
template<class S, class T> inline S chmax(S &a, T b){
  if(a<b){
    a=b;
  }
  return a;
}
template<class T> inline int Cmod2(T n, T k){
  if((n&k)==k){
    return 1;
  }
  return 0;
}
int main(){
  int i;
  int N;
  rd(N);
  int K;
  rd(K);
  int A[N];
  {
    int Nzj9Y0kE;
    for(Nzj9Y0kE=(0);Nzj9Y0kE<(N);Nzj9Y0kE++){
      rd(A[Nzj9Y0kE]);
    }
  }
  int p;
  int r;
  int k;
  int b;
  int res[1<<20] = {};
  int f = 0;
  static int memo[30][1<<20];
  for(i=(0);i<(30);i++){
    int j;
    for(j=(0);j<(1<<20);j++){
      memo[i][j] = Cmod2(N-i, j);
    }
    for(j=(1);j<(1<<20);j++){
      memo[i][j] ^= memo[i][j-1];
    }
  }
  for(i=(0);i<(N);i++){
    int j;
    p = A[i];
    for(j=(i);j<(N);j++){
      if(j != i){
        if(A[j] > 20 || (double)p * (double)(1<<A[j]) > 1000000000){
          break;
        }
        p *= (1 << A[j]);
        if(p >= (1<<20)){
          break;
        }
      }
      r = (N - 1) - (j - i);
      k = K;
      if(i!=0){
        r--;
        k--;
      }
      if(j!=N-1){
        r--;
        k--;
      }
      chmax(k, 0);
      if(r < k){
        continue;
      }
      b = memo[N-r][r];
      if(k){
        b ^= memo[N-r][k-1];
      }
      if(b==0){
        continue;
      }
      res[p] ^= 1;
    }
  }
  for(i=(1<<20)-1;i>=(0);i--){
    if(res[i]){
      f = 1;
    }
    if(f){
      wt_L(res[i]);
    }
  }
  if(!f){
    wt_L(0);
  }
  wt_L("");
  wt_L('\n');
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
// cLay version 20220312-1 [+beta]

// --- original code ---
// //no-unlocked
// int @N, @K, @A[N];
// int p, r, k, b;
// int res[1<<20] = {}, f = 0;
// static int memo[30][1<<20];
// 
// rep(i,30){
//   rep(j,1<<20) memo[i][j] = Cmod2(N-i, j);
//   rep(j,1,1<<20) memo[i][j] ^= memo[i][j-1];
// }
// 
// rep(i,N){
//   p = A[i];
//   rep(j,i,N){
//     if(j != i){
//       if(A[j] > 20 || (double)p * (double)(1<<A[j]) > 1d9) break;
//       p *= (1 << A[j]);
//       if(p >= (1<<20)) break;
//     }
// 
//     r = (N - 1) - (j - i);
//     k = K;
//     if(i!=0) r--, k--;
//     if(j!=N-1) r--, k--;
//     k >?= 0;
//     if(r < k) continue;
// 
//     b = memo[N-r][r];
//     if(k) b ^= memo[N-r][k-1];
//     // b = 0;
//     // rep(m,k,r+1) b ^= Cmod2(r,m);
//     if(b==0) continue;
// 
//     res[p] ^= 1;
//   }
// }
// 
// rrep(i,1<<20){
//   if(res[i]) f = 1;
//   if(f) wtN(res[i]);
// }
// if(!f) wtN(0);
// wt("");