#pragma GCC optimize ("Ofast")
#include<bits/stdc++.h>
using namespace std;
void *wmem;
template<class S, class T> inline S min_L(S a,T b){
  return a<=b?a:b;
}
template<class T> inline void walloc1d(T **arr, int x, void **mem = &wmem){
  static int skip[16]={0, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
  (*mem) = (void*)( ((char*)(*mem)) + skip[((unsigned long long)(*mem)) & 15] );
  (*arr)=(T*)(*mem);
  (*mem)=((*arr)+x);
}
inline void rd(int &x){
  int k, m=0;
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
  char f[10];
  int m=0, s=0;
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
inline void wt_L(long long x){
  char f[20];
  int m=0, s=0;
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
int Prime_L(int N, int res[], void *mem=wmem){
  bool *isprime;
  const int r=23000;
  int a, b, i, *sf, ss=1, sz=1;
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
template<class S, class T> inline S chmin(S &a, T b){
  if(a>b){
    a=b;
  }
  return a;
}
char memarr[96000000];
int N;
int K;
int ps;
int p[78498];
int phi[1000001];
int main(){
  int d, i, j, k, mx, mxi;
  long long res=4611686016279904256LL, tmp;
  wmem = memarr;
  rd(N);
  rd(K);
  if(K==1){
    wt_L(3);
    wt_L('\n');
    return 0;
  }
  ps =Prime_L(N+1, p);
  d = (N-2) - K;
  for(i=0;i<(N+1);i++){
    phi[i] = i;
  }
  for(k=0;k<(ps);k++){
    for(i=p[k];i<=N;i+=p[k]){
      phi[i] = (long long)phi[i] * (p[k]-1) / p[k];
    }
  }
  phi[1] = phi[2] = 0;
  tmp = 1;
  for(i=0;i<(N+1);i++){
    tmp += phi[i];
  }
  sort(phi,phi+N+1);
  for(i=0;i<(d);i++){
    tmp -= phi[N-i];
  }
  chmin(res, tmp);
  res++;
  wt_L(res);
  wt_L('\n');
  return 0;
}
// cLay varsion 20190830-1

// --- original code ---
// //no-unlocked
// int N, K;
// int ps, p[78498];
// int phi[1000001];
// {
//   int i, j, k, d, mx, mxi;
//   ll res = ll_inf, tmp;
//   
//   rd(N,K);
// 
//   if(K==1) wt(3), return 0;
//   
//   ps = Prime(N+1, p);
//   d = (N-2) - K;
// 
//   rep(i,N+1) phi[i] = i;
//   rep(k,ps) for(i=p[k];i<=N;i+=p[k]) phi[i] = (ll)phi[i] * (p[k]-1) / p[k];
//   phi[1] = phi[2] = 0;
// 
//   tmp = 1;
//   rep(i,N+1) tmp += phi[i];
//   sort(phi,phi+N+1);
//   rep(i,d) tmp -= phi[N-i];
//   res <?= tmp;
// 
//   res++;
//   wt(res);
// }