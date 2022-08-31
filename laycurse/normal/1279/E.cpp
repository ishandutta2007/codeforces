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
inline int rd_int(void){
  int x;
  rd(x);
  return x;
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
template<class S, class T> inline S chmin(S &a, T b){
  if(a>b){
    a=b;
  }
  return a;
}
struct unionFind{
  int *d;
  int N;
  int M;
  inline void malloc(const int n){
    d = (int*)std::malloc(n*sizeof(int));
    M = n;
  }
  inline void free(void){
    std::free(d);
  }
  inline void walloc(const int n, void **mem=&wmem){
    walloc1d(&d, n, mem);
    M = n;
  }
  inline void init(const int n){
    int i;
    N = n;
    for(i=(0);i<(n);i++){
      d[i] = -1;
    }
  }
  inline void init(void){
    init(M);
  }
  inline int get(int a){
    int t = a;
    int k;
    while(d[t]>=0){
      t=d[t];
    }
    while(d[a]>=0){
      k=d[a];
      d[a]=t;
      a=k;
    }
    return a;
  }
  inline int connect(int a, int b){
    if(d[a]>=0){
      a=get(a);
    }
    if(d[b]>=0){
      b=get(b);
    }
    if(a==b){
      return 0;
    }
    if(d[a] < d[b]){
      d[a] += d[b];
      d[b] = a;
    }
    else{
      d[b] += d[a];
      d[a] = b;
    }
    return 1;
  }
  inline int operator()(int a){
    return get(a);
  }
  inline int operator()(int a, int b){
    return connect(a,b);
  }
  inline int& operator[](const int a){
    return d[a];
  }
  inline int size(int a){
    a = get(a);
    return -d[a];
  }
  inline int sizeList(int res[]){
    int i;
    int sz=0;
    for(i=(0);i<(N);i++){
      if(d[i]<0){
        res[sz++] = -d[i];
      }
    }
    return sz;
  }
}
;
int N;
long long K;
long long cnt[51];
long long dp[51];
int res[51];
int tmp[51];
long long fac[51];
unionFind uf;
void solve(int len, long long K){
  int st;
  int mask;
  long long num;
  if(len==1){
    tmp[0] = 0;
    return;
  }
  if(len==2){
    tmp[0] = 1;
    tmp[1] = 0;
    return;
  }
  uf.init(len);
  mask = (1<<(len-1))-1;
  tmp[0] = len - 1;
  for(st=(1);st<(len);st++){
    int i;
    for(i=(0);i<(len);i++){
      if((i!=st) && (mask&1<<i) && uf(i) != uf(st)){
        if(len-st-2 >= 0){
          num =fac[len-st-2];
        }
        else{
          num =1;
        }
        if(K < num){
          uf(i,st);
          tmp[st] = i;
          mask ^= (1<<i);
          break;
        }
        K -= num;
      }
    }
  }
}
long long mult(long long a, long long b){
  if((double) a*b >= 4611686016279904256LL){
    return 4611686016279904256LL;
  }
  return a*b;
}
int main(){
  int i, tU__gIr_;
  wmem = memarr;
  int st;
  int len;
  fac[0] = 1;
  for(i=(1);i<(51);i++){
    fac[i] = mult(fac[i-1], i);
  }
  cnt[0] = cnt[1] = 1;
  for(i=(2);i<(51);i++){
    cnt[i] = fac[i-2];
  }
  dp[0] = 1;
  for(i=(1);i<(51);i++){
    int j;
    dp[i] = 0;
    for(j=(1);j<(i+1);j++){
      dp[i] += mult(cnt[j], dp[i-j]);
      chmin(dp[i], 4611686016279904256LL);
    }
  }
  uf.malloc(50);
  int a2conNHc = rd_int();
  for(tU__gIr_=(0);tU__gIr_<(a2conNHc);tU__gIr_++){
    rd(N);
    rd(K);K += (-1);
    if(K >= dp[N]){
      wt_L(-1);
      wt_L('\n');
      continue;
    }
    st = 0;
    len = N;
    while(len){
      for(i=(1);i<(len+1);i++){
        if((double) cnt[i] * dp[len-i] > 4611686016279904256LL || K < cnt[i] * dp[len-i]){
          int j;
          solve(i, K / dp[len-i]);
          K %= dp[len-i];
          for(j=(0);j<(i);j++){
            res[st+j] = tmp[j] + st + 1;
          }
          st += i;
          len -= i;
          break;
        }
        K -= cnt[i] * dp[len-i];
      }
    }
    {
      int AlM5nNnR;
      if(N==0){
        putchar('\n');
      }
      else{
        for(AlM5nNnR=(0);AlM5nNnR<(N-1);AlM5nNnR++){
          wt_L(res[AlM5nNnR]);
          wt_L(' ');
        }
        wt_L(res[AlM5nNnR]);
        wt_L('\n');
      }
    }
  }
  return 0;
}
// cLay varsion 20191227-1

// --- original code ---
// //no-unlocked
// int N; ll K;
// ll cnt[51], dp[51];
// 
// int res[51];
// int tmp[51];
// ll fac[51];
// unionFind uf;
// 
// void solve(int len, ll K){
//   int st, mask;
//   ll num;
// 
//   if(len==1) tmp[0] = 0, return;
//   if(len==2) tmp[0] = 1, tmp[1] = 0, return;
// 
//   uf.init(len);
// 
//   mask = (1<<(len-1))-1;
//   tmp[0] = len - 1;
//   rep(st,1,len){
//     rep(i,len) if((i!=st) && (mask&1<<i) && uf(i) != uf(st)){
//       num = if[len-st-2 >= 0, fac[len-st-2], 1];
//       if(K < num){
//         uf(i,st);
//         tmp[st] = i;
//         mask ^= (1<<i);
//         break;
//       }
//       K -= num;
//     }
//   }
// }
// 
// ll mult(ll a, ll b){
//   if((double) a*b >= ll_inf) return ll_inf;
//   return a*b;
// }
// 
// {
//   int st, len;
//   fac[0] = 1;
//   rep(i,1,51) fac[i] = mult(fac[i-1], i);
// 
//   cnt[0] = cnt[1] = 1;
//   rep(i,2,51) cnt[i] = fac[i-2];
// 
//   dp[0] = 1;
//   rep(i,1,51){
//     dp[i] = 0;
//     rep(j,1,i+1){
//       dp[i] += mult(cnt[j], dp[i-j]);
//       dp[i] <?= ll_inf;
//     }
//   }
// 
//   uf.malloc(50);
// 
//   REP(rd_int()){
//     rd(N,K--);
//     if(K >= dp[N]) wt(-1), continue;
// 
//     st = 0;
//     len = N;
//     while(len){
//       rep(i,1,len+1){
//         if((double) cnt[i] * dp[len-i] > ll_inf || K < cnt[i] * dp[len-i]){
//           solve(i, K / dp[len-i]);
//           K %= dp[len-i];
//           rep(j,i) res[st+j] = tmp[j] + st + 1;
//           st += i;
//           len -= i;
//           break;
//         }
//         K -= cnt[i] * dp[len-i];
//       }
//     }
//     wt(res(N));
//   }
// }