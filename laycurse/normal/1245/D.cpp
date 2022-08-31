#pragma GCC optimize ("Ofast")
#include<bits/stdc++.h>
using namespace std;
inline void rd(int &x){
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
template<class S> void arrInsert(const int k, int &sz, S a[], const S aval){
  int i;
  sz++;
  for(i=sz-1;i>k;i--){
    a[i] = a[i-1];
  }
  a[k] = aval;
}
template<class S, class T> void arrInsert(const int k, int &sz, S a[], const S aval, T b[], const T bval){
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
template<class S, class T, class U> void arrInsert(const int k, int &sz, S a[], const S aval, T b[], const T bval, U c[], const U cval){
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
int N;
int X[2000];
int Y[2000];
int C[2000];
int K[2000];
int vis[2000];
int bk[2000];
long long mn[2000];
long long res;
int ps;
int p[2000];
int ms;
int ma[2000];
int mb[2000];
int main(){
  int i;
  int j;
  int k;
  long long cost;
  rd(N);
  {
    int Lj4PdHRW;
    for(Lj4PdHRW=(0);Lj4PdHRW<(N);Lj4PdHRW++){
      rd(X[Lj4PdHRW]);
      rd(Y[Lj4PdHRW]);
    }
  }
  {
    int KL2GvlyY;
    for(KL2GvlyY=(0);KL2GvlyY<(N);KL2GvlyY++){
      rd(C[KL2GvlyY]);
    }
  }
  {
    int Q5VJL1cS;
    for(Q5VJL1cS=(0);Q5VJL1cS<(N);Q5VJL1cS++){
      rd(K[Q5VJL1cS]);
    }
  }
  for(i=(0);i<(N);i++){
    mn[i] = C[i];
    bk[i] = N;
  }
  for(;;){
    {
      int cTE1_r3A;
      int RZTsC2BF = 0;
      long long FmcKpFmN;
      long long xr20shxY;
      int WYIGIcGE;
      for(cTE1_r3A=(0);cTE1_r3A<(((N)-1)+1);cTE1_r3A++){
        xr20shxY = mn[cTE1_r3A];
        if(RZTsC2BF==0 || FmcKpFmN>xr20shxY){
          FmcKpFmN = xr20shxY;
          RZTsC2BF = 1;
          WYIGIcGE = cTE1_r3A;
        }
      }
      i =WYIGIcGE;
    }
    if(vis[i]++){
      break;
    }
    res += mn[i];
    mn[i] = 4611686016279904256LL;
    if(bk[i]==N){
      p[ps++] = i;
    }
    else{
      arrInsert(ms,ms,ma,i,mb,bk[i]);
    }
    for(k=(0);k<(N);k++){
      if(vis[k]==0){
        cost = (long long) (K[i] + K[k]) * (abs(X[i]-X[k]) + abs(Y[i]-Y[k]));
        if(mn[k] > cost){
          mn[k] = cost;
          bk[k] = i;
        }
      }
    }
  }
  wt_L(res);
  wt_L('\n');
  wt_L(ps);
  wt_L('\n');
  {
    int t_ynMSdg;
    if(ps==0){
      putchar('\n');
    }
    else{
      for(t_ynMSdg=(0);t_ynMSdg<(ps-1);t_ynMSdg++){
        wt_L(p[t_ynMSdg]+1);
        wt_L(' ');
      }
      wt_L(p[t_ynMSdg]+1);
      wt_L('\n');
    }
  }
  wt_L(ms);
  wt_L('\n');
  for(i=(0);i<(ms);i++){
    wt_L(ma[i]+1);
    wt_L(' ');
    wt_L(mb[i]+1);
    wt_L('\n');
  }
  return 0;
}
// cLay varsion 20191027-1

// --- original code ---
// //no-unlocked
// int N, X[2000], Y[2000], C[2000], K[2000];
// int vis[2000], bk[2000]; ll mn[2000];
// 
// ll res;
// int ps, p[2000], ms, ma[2000], mb[2000];
// {
//   int i, j, k;
//   ll cost;
//   rd(N, (X,Y)(N), C(N), K(N));
// 
//   rep(i,N) mn[i] = C[i], bk[i] = N;
//   for(;;){
//     i = argmin(mn(N));
//     if(vis[i]++) break;
//     res += mn[i];
//     mn[i] = ll_inf;
//     if(bk[i]==N) p[ps++] = i;
//     else         arrInsert(ms,ms,ma,i,mb,bk[i]);
//     rep(k,N) if(vis[k]==0){
//       cost = (ll) (K[i] + K[k]) * (abs(X[i]-X[k]) + abs(Y[i]-Y[k]));
//       if(mn[k] > cost) mn[k] = cost, bk[k] = i;
//     }
//   }
// 
//   wt(res);
//   wt(ps);
//   wt(p(ps)+1);
//   wt(ms);
//   rep(i,ms) wt(ma[i]+1, mb[i]+1);
// 
// }