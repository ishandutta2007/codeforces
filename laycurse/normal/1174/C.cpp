#include<bits/stdc++.h>
using namespace std;
void *wmem;
template<class S, class T> inline S min_L(S a,T b){
  return a<=b?a:b;
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
int Prime_L(int N, int res[], void *mem=wmem){
  bool *isprime;
  const int r=23000;
  int a, b, i, *sf, ss=1, sz=1;
  isprime = (bool*)mem;
  sf = (int*)(isprime + r);
  N /= 2;
  res[0] = 2;
  b =min_L(r, N);
  for(i=1;i<b;i++){
    isprime[i] = 1;
  }
  for(i=1;i<b;i++){
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
    for(i=a;i<b;i++){
      isprime[i] = 1;
    }
    for(i=1;i<ss;i++){
      while(sf[i] < b){
        isprime[sf[i]] = 0;
        sf[i] += res[i];
      }
    }
    for(i=a;i<b;i++){
      if(isprime[i]){
        res[sz++] = 2*i+1;
      }
    }
  }
  return sz;
}
char memarr[96000000];
int N;
int ps;
int p[10000];
int res[100000];
int main(){
  int i, j;
  wmem = memarr;
  rd(N);
  ps =Prime_L(N+1, p);
  for(i=0;i<ps;i++){
    for(j=p[i];j<=N;j+=p[i]){
      res[j-2] = i+1;
    }
  }
  {
    int Lj4PdHRW;
    if(N-1==0){
      putchar('\n');
    }
    else{
      for(Lj4PdHRW=0;Lj4PdHRW<N-1-1;Lj4PdHRW++){
        wt_L(res[Lj4PdHRW]);
        wt_L(' ');
      }
      wt_L(res[Lj4PdHRW]);
      wt_L('\n');
    }
  }
  return 0;
}
// cLay varsion 20190608-2

// --- original code ---
// //no-unlocked
// int N;
// int ps, p[10000];
// int res[1d5];
// {
//   int i, j;
//   rd(N);
//   ps = Prime(N+1, p);
//   rep(i,ps) for(j=p[i];j<=N;j+=p[i]) res[j-2] = i+1;
//   wt(res(N-1));
// }