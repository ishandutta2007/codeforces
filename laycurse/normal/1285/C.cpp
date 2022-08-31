#pragma GCC optimize ("Ofast")
#include<bits/stdc++.h>
using namespace std;
void *wmem;
char memarr[96000000];
template<class T> inline void walloc1d(T **arr, int x, void **mem = &wmem){
  static int skip[16] = {0, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
  (*mem) = (void*)( ((char*)(*mem)) + skip[((unsigned long long)(*mem)) & 15] );
  (*arr)=(T*)(*mem);
  (*mem)=((*arr)+x);
}
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
    putchar('-');
  }
  while(s--){
    putchar(f[s]+'0');
  }
}
template<class T> int Factor_L(T N, T fac[], int fs[]){
  T i;
  int sz = 0;
  if(N%2==0){
    fac[sz] = 2;
    fs[sz] = 1;
    N /= 2;
    while(N%2==0){
      N /= 2;
      fs[sz]++;
    }
    sz++;
  }
  for(i=3;i*i<=N;i+=2){
    if(N%i==0){
      fac[sz] = i;
      fs[sz] = 1;
      N /= i;
      while(N%i==0){
        N /= i;
        fs[sz]++;
      }
      sz++;
    }
  }
  if(N > 1){
    fac[sz] = N;
    fs[sz] = 1;
    sz++;
  }
  return sz;
}
template<class T> int Divisor_L(T N, T res[], void *mem = wmem){
  int i;
  int j;
  int k;
  int s;
  int sz = 0;
  T *fc;
  int *fs;
  int fsz;
  walloc1d(&fc, 100, &mem);
  walloc1d(&fs, 100, &mem);
  fsz =Factor_L(N, fc, fs);
  res[sz++] = 1;
  for(i=(0);i<(fsz);i++){
    s = sz;
    k = s * fs[i];
    for(j=(0);j<(k);j++){
      res[sz++] = res[j] * fc[i];
    }
  }
  sort(res, res+sz);
  return sz;
}
template<class T> inline T GCD_L(T a,T b){
  T r;
  while(a){
    r=b;
    b=a;
    a=r%a;
  }
  return b;
}
long long X;
int ys;
long long y[100000];
int main(){
  int i;
  wmem = memarr;
  long long a;
  long long b = 4611686016279904256LL;
  rd(X);
  ys =Divisor_L(X, y);
  for(i=(0);i<(ys);i++){
    if(y[i] <= X/y[i] &&GCD_L(y[i], X/y[i])== 1){
      if(b > X/y[i]){
        a = y[i];
        b = X/y[i];
      }
    }
  }
  wt_L(a);
  wt_L(' ');
  wt_L(b);
  wt_L('\n');
  return 0;
}
// cLay varsion 20191229-1 [beta]

// --- original code ---
// //no-unlocked
// ll X;
// int ys; ll y[1d5];
// {
//   ll a, b = ll_inf;
//   rd(X);
//   ys = Divisor(X, y);
//   rep(i,ys) if(y[i] <= X/y[i] && gcd(y[i], X/y[i]) == 1){
//     if(b > X/y[i]) a = y[i], b = X/y[i];
//   }
//   wt(a,b);
// }