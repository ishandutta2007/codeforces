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
inline int rd_int(void){
  int x;
  rd(x);
  return x;
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
template<class S, class T> inline S chmin(S &a, T b){
  if(a>b){
    a=b;
  }
  return a;
}
template<class S, class T> inline S chmax(S &a, T b){
  if(a<b){
    a=b;
  }
  return a;
}
int cnt[5001];
int dist[5001][5001];
int fs;
int f[100];
int fn[100];
int a[5001][5001];
int sm[5001][5001];
int mx[5001];
int main(){
  int Lj4PdHRW;
  int i;
  int j;
  int k;
  long long res = 4611686016279904256LL;
  long long tmp;
  int KL2GvlyY = rd_int();
  for(Lj4PdHRW=(0);Lj4PdHRW<(KL2GvlyY);Lj4PdHRW++){
    cnt[rd_int()]++;
  }
  for(i=(2);i<(5001);i++){
    fs =Factor_L(i, f, fn);
    for(j=(0);j<(5001);j++){
      a[i][j] = a[i-1][j];
    }
    for(j=(0);j<(fs);j++){
      a[i][f[j]] += fn[j];
    }
    mx[i] = f[fs-1];
  }
  for(i=(0);i<(5001);i++){
    sm[i][0] = a[i][0];
    for(j=(1);j<(5001);j++){
      sm[i][j] += sm[i][j-1] + a[i][j];
    }
  }
  for(i=(2);i<(5001);i++){
    k = mx[i];
    for(j=(i)-1;j>=(0);j--){
      dist[i][j] = dist[j][i] = sm[i][k-1] + sm[j][k-1] + a[i][k] - a[j][k];
      chmax(k, mx[j]);
    }
  }
  for(i=(0);i<(5001);i++){
    tmp = 0;
    for(j=(0);j<(5001);j++){
      tmp += (long long) dist[i][j] * cnt[j];
    }
    chmin(res, tmp);
  }
  wt_L(res);
  wt_L('\n');
  return 0;
}
// cLay varsion 20200119-1

// --- original code ---
// //no-unlocked
// int cnt[5001];
// int dist[5001][5001];
// 
// int fs, f[100], fn[100];
// int a[5001][5001], sm[5001][5001], mx[5001];
// 
// {
//   int i, j, k;
//   ll res = ll_inf, tmp;
//   REP(rd_int()) cnt[rd_int()]++;
// 
//   rep(i,2,5001){
//     fs = Factor(i, f, fn);
//     rep(j,5001) a[i][j] = a[i-1][j];
//     rep(j,fs) a[i][f[j]] += fn[j];
//     mx[i] = f[fs-1];
//   }
//   rep(i,5001){
//     sm[i][0] = a[i][0];
//     rep(j,1,5001) sm[i][j] += sm[i][j-1] + a[i][j];
//   }
// 
//   rep(i,2,5001){
//     k = mx[i];
//     rrep(j,i){
//       dist[i][j] = dist[j][i] = sm[i][k-1] + sm[j][k-1] + a[i][k] - a[j][k];
//       k >?= mx[j];
//     }
//   }
// 
//   rep(i,5001){
//     tmp = 0;
//     rep(j,5001) tmp += (ll) dist[i][j] * cnt[j];
//     res <?= tmp;
//   }
//   wt(res);
// }