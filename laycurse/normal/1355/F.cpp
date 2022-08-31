#pragma GCC optimize ("Ofast")
#include<bits/stdc++.h>
using namespace std;
void *wmem;
char memarr[96000000];
template<class S, class T> inline S min_L(S a,T b){
  return a<=b?a:b;
}
template<class S, class T> inline S max_L(S a,T b){
  return a>=b?a:b;
}
template<class T> inline void walloc1d(T **arr, int x, void **mem = &wmem){
  static int skip[16] = {0, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
  (*mem) = (void*)( ((char*)(*mem)) + skip[((unsigned long long)(*mem)) & 15] );
  (*arr)=(T*)(*mem);
  (*mem)=((*arr)+x);
}
int Prime_L(int N, int res[], void *mem=wmem){
  int i;
  int a;
  int b;
  int sz = 1;
  const int r = 23000;
  bool *isprime;
  int *sf;
  int ss = 1;
  walloc1d(&isprime, r, &mem);
  walloc1d(&sf, r, &mem);
  isprime = (bool*)mem;
  sf = (int*)(isprime + r);
  N /= 2;
  res[0] = 2;
  b =min_L(r, N);
  for(i=(1);i<(b);i++){
    isprime[i] = 1;
  }
  for(i=(1);i<(b);i++){
    if(isprime[i]){
      res[sz++] = 2*i+1;
      sf[ss] = 2*i*(i+1);
      if(sf[ss] < N){
        while(sf[ss] < r){
          isprime[sf[ss]] = 0;
          sf[ss] += res[ss];
        }
        ss++;
      }
    }
  }
  for(a=r; a<N; a+=r){
    b =min_L(a + r, N);
    isprime -= r;
    for(i=(a);i<(b);i++){
      isprime[i] = 1;
    }
    for(i=(1);i<(ss);i++){
      while(sf[i] < b){
        isprime[sf[i]] = 0;
        sf[i] += res[i];
      }
    }
    for(i=(a);i<(b);i++){
      if(isprime[i]){
        res[sz++] = 2*i+1;
      }
    }
  }
  return sz;
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
long long query(long long Q){
  printf("? %lld\n", Q);
  fflush(stdout);
  scanf("%lld",&Q);
  return Q;
}
void answer(long long ans){
  printf("! %lld\n", ans);
  fflush(stdout);
}
int ps;
int p[10000];
long long tmp[100000];
int main(){
  int Lj4PdHRW;
  wmem = memarr;
  int T;
  int i;
  int j;
  int k;
  int s;
  int res;
  long long Q;
  long long X;
  long long now;
  ps =Prime_L(10000, p);
  scanf("%d",&T);
  for(Lj4PdHRW=(0);Lj4PdHRW<(T);Lj4PdHRW++){
    int WYIGIcGE, e98WHCEY;
    s = 0;
    X = 1;
    for(e98WHCEY=(0);e98WHCEY<(18);e98WHCEY++){
      Q = 1;
      while((double)Q*p[s] < 1e18){
        Q *= p[s++];
      }
      X *= query(Q);
    }
    now = X;
    for(WYIGIcGE=(0);WYIGIcGE<(4);WYIGIcGE++){
      now *= now;
      now = query(now);
    }
    res =Divisor_L(now,tmp);
    answer(max_L(8, 2*res));
  }
  return 0;
}
// cLay varsion 20200509-1

// --- original code ---
// ll query(ll Q){
//   printf("? %lld\n", Q);
//   fflush(stdout);
//   scanf("%lld",&Q);
//   return Q;
// }
// 
// void answer(ll ans){
//   printf("! %lld\n", ans);
//   fflush(stdout);
// }
// 
// int ps, p[10000];
// ll tmp[1d5];
// {
//   int T;
//   int i, j, k, s, res;
//   ll Q, X, now;
//   ps = Prime(10000, p);
// 
//   scanf("%d",&T);
//   rep(T){
//     s = 0;
//     X = 1;
// 
//     rep(18){
//       Q = 1;
//       while((double)Q*p[s] < 1e18) Q *= p[s++];
//       X *= query(Q);
//     }
//     
//     now = X;
//     rep(4){
//       now *= now;
//       now = query(now);
//     }
//     res = Divisor(now,tmp);
//     answer(max(8,2*res));
//   }
// }