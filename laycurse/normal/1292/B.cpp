#pragma GCC optimize ("Ofast")
#include<bits/stdc++.h>
using namespace std;
inline void rd(long long &x){
  int k;
  int m=0;
  x=0;
  for(;;){
    k = getchar();
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
    k = getchar();
    if(k<'0'||k>'9'){
      break;
    }
    x=x*10+k-'0';
  }
  if(m){
    x=-x;
  }
}
inline void wt_L(char a){
  putchar(a);
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
    putchar('-');
  }
  while(s--){
    putchar(f[s]+'0');
  }
}
template<class S> inline void arrInsert(const int k, int &sz, S a[], const S aval){
  int i;
  sz++;
  for(i=sz-1;i>k;i--){
    a[i] = a[i-1];
  }
  a[k] = aval;
}
template<class S, class T> inline void arrInsert(const int k, int &sz, S a[], const S aval, T b[], const T bval){
  int i;
  sz++;
  for(i=sz-1;i>k;i--){
    a[i] = a[i-1];
  }
  for(i=sz-1;i>k;i--){
    b[i] = b[i-1];
  }
  a[k] = aval;
  b[k] = bval;
}
template<class S, class T, class U> inline void arrInsert(const int k, int &sz, S a[], const S aval, T b[], const T bval, U c[], const U cval){
  int i;
  sz++;
  for(i=sz-1;i>k;i--){
    a[i] = a[i-1];
  }
  for(i=sz-1;i>k;i--){
    b[i] = b[i-1];
  }
  for(i=sz-1;i>k;i--){
    c[i] = c[i-1];
  }
  a[k] = aval;
  b[k] = bval;
  c[k] = cval;
}
template<class S, class T, class U, class V> inline void arrInsert(const int k, int &sz, S a[], const S aval, T b[], const T bval, U c[], const U cval, V d[], const V dval){
  int i;
  sz++;
  for(i=sz-1;i>k;i--){
    a[i] = a[i-1];
  }
  for(i=sz-1;i>k;i--){
    b[i] = b[i-1];
  }
  for(i=sz-1;i>k;i--){
    c[i] = c[i-1];
  }
  for(i=sz-1;i>k;i--){
    d[i] = d[i-1];
  }
  a[k] = aval;
  b[k] = bval;
  c[k] = cval;
  d[k] = dval;
}
template<class S, class T> inline S chmax(S &a, T b){
  if(a<b){
    a=b;
  }
  return a;
}
int N;
long long X[100];
long long Y[100];
long long SX;
long long SY;
long long T;
int main(){
  int i;
  int res = 0;
  int tmp;
  long long x0;
  long long y0;
  long long ax;
  long long ay;
  long long bx;
  long long by;
  long long tm;
  long long cx;
  long long cy;
  rd(x0);
  rd(y0);
  rd(ax);
  rd(ay);
  rd(bx);
  rd(by);
  rd(SX);
  rd(SY);
  rd(T);
  arrInsert(N, N, X, x0, Y, y0);
  for(;;){
    X[N] = X[N-1] * ax + bx;
    Y[N] = Y[N-1] * ay + by;
    if(X[N] > 30000000000000000LL || Y[N] > 30000000000000000LL){
      break;
    }
    N++;
  }
  for(i=(0);i<(N);i++){
    int j;
    for(j=(i);j<(N);j++){
      int k;
      cx = SX;
      cy = SY;
      tm = 0;
      for(k=(i);k<(j+1);k++){
        tm += abs(cx - X[k]) + abs(cy - Y[k]);
        cx = X[k];
        cy = Y[k];
        if(tm > T){
          break;
        }
      }
      if(tm <= T){
        chmax(res, j - i + 1);
      }
      cx = SX;
      cy = SY;
      tm = 0;
      for(k=(j+1)-1;k>=(i);k--){
        tm += abs(cx - X[k]) + abs(cy - Y[k]);
        cx = X[k];
        cy = Y[k];
        if(tm > T){
          break;
        }
      }
      if(tm <= T){
        chmax(res, j - i + 1);
      }
    }
  }
  wt_L(res);
  wt_L('\n');
  return 0;
}
// cLay varsion 20200119-1

// --- original code ---
// //no-unlocked
// int N; ll X[100], Y[100];
// ll SX, SY, T;
// 
// {
//   int res = 0, tmp;
//   ll x0, y0, ax, ay, bx, by, tm;
//   ll cx, cy;
// 
//   rd(x0, y0, ax, ay, bx, by);
//   rd(SX, SY, T);
//   arrInsert(N, N, X, x0, Y, y0);
// 
//   for(;;){
//     X[N] = X[N-1] * ax + bx;
//     Y[N] = Y[N-1] * ay + by;
//     if(X[N] > 3d16 || Y[N] > 3d16) break;
//     N++;
//   }
// 
//   rep(i,N) rep(j,i,N){
//     cx = SX; cy = SY;
//     tm = 0;
//     rep(k,i,j+1){
//       tm += abs(cx - X[k]) + abs(cy - Y[k]);
//       cx = X[k];
//       cy = Y[k];
//       if(tm > T) break;
//     }
//     if(tm <= T) res >?= j - i + 1;
// 
//     cx = SX; cy = SY;
//     tm = 0;
//     rrep(k,i,j+1){
//       tm += abs(cx - X[k]) + abs(cy - Y[k]);
//       cx = X[k];
//       cy = Y[k];
//       if(tm > T) break;
//     }
//     if(tm <= T) res >?= j - i + 1;
//   }
// 
//   wt(res);
// }