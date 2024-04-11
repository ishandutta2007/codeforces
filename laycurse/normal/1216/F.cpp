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
inline void rd(char &c){
  int i;
  for(;;){
    i = getchar();
    if(i!=' '&&i!='\n'&&i!='\r'&&i!='\t'&&i!=EOF){
      break;
    }
  }
  c = i;
}
inline int rd(char c[]){
  int i;
  int sz = 0;
  for(;;){
    i = getchar();
    if(i!=' '&&i!='\n'&&i!='\r'&&i!='\t'&&i!=EOF){
      break;
    }
  }
  c[sz++] = i;
  for(;;){
    i = getchar();
    if(i==' '||i=='\n'||i=='\r'||i=='\t'||i==EOF){
      break;
    }
    c[sz++] = i;
  }
  c[sz]='\0';
  return sz;
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
template<class T> struct segtree_Point_Minval{
  int N;
  int logN;
  T *mn;
  void malloc(int maxN, int once = 0){
    int i;
    for(i=1;i<maxN;i*=2){
      ;
    }
    mn = new T[2*i];
    if(once){
      setN(maxN);
    }
  }
  void walloc(int maxN, int once = 0, void **mem = &wmem){
    int i;
    for(i=1;i<maxN;i*=2){
      ;
    }
    walloc1d(&mn, 2*i, mem);
    if(once){
      setN(maxN);
    }
  }
  void free(void){
    delete [] mn;
  }
  T& operator[](int i){
    return mn[N+i];
  }
  void setN(int n, int zerofill = 1, int dobuild = 1){
    int i;
    for(i=1,logN=0;i<n;i*=2,logN++){
      ;
    }
    N = i;
    if(zerofill){
      for(i=(0);i<(N);i++){
        mn[N+i] = 0;
      }
    }
    if(dobuild){
      build();
    }
  }
  void build(void){
    int i;
    for(i=N-1;i;i--){
      mn[i] =min_L(mn[2*i], mn[2*i+1]);
    }
  }
  inline void build(int a){
    while(a > 1){
      a /= 2;
      mn[a] =min_L(mn[2*a], mn[2*a+1]);
    }
  }
  inline void change(int a, T val){
    mn[a+N] = val;
    build(a+N);
  }
  inline void add(int a, T val){
    mn[a+N] += val;
    build(a+N);
  }
  inline T getMinVal(int a, int b){
    T res;
    T tmp;
    int fga = 0;
    int fgb = 0;
    a += N;
    b += N;
    while(a < b){
      if(a%2){
        if(fga){
          res =min_L(res, mn[a]);
        }
        else{
          res = mn[a];
          fga = 1;
        }
        a++;
      }
      if(b%2){
        b--;
        if(fgb){
          tmp =min_L(mn[b], tmp);
        }
        else{
          tmp = mn[b];
          fgb = 1;
        }
      }
      a /= 2;
      b /= 2;
    }
    if(fga==1 && fgb==0){
      return res;
    }
    if(fga==0 && fgb==1){
      return tmp;
    }
    if(fga==1 && fgb==1){
      res =min_L(res, tmp);
      return res;
    }
    return res;
  }
}
;
int N;
int K;
char S[200002];
long long dp[200002];
int main(){
  wmem = memarr;
  int i;
  int j;
  long long tmp;
  segtree_Point_Minval<long long> t;
  rd(N);
  rd(K);
  rd(S);
  for(i=(0);i<(N);i++){
    S[i] -= '0';
  }
  for(i=(0);i<(N);i++){
    dp[i+1] = 4611686016279904256LL;
  }
  t.malloc(N+1);
  t.setN(N+1);
  for(i=(0);i<(N+1);i++){
    t[i] = dp[i];
  }
  t.build();
  for(i=(0);i<(N);i++){
    if(dp[i+1] > dp[i] + i + 1){
      dp[i+1] = dp[i] + i + 1;
      t.change(i+1, dp[i+1]);
    }
    if(S[i]){
      tmp = t.getMinVal(max_L(0, i-K), N) + i + 1;
      j =min_L(N, i+1+K);
      if(dp[j] > tmp){
        dp[j] = tmp;
        t.change(j, tmp);
      }
    }
  }
  wt_L(dp[N]);
  wt_L('\n');
  return 0;
}
// cLay varsion 20190925-1

// --- original code ---
// //no-unlocked
// int N, K;
// char S[200002];
// ll dp[200002];
// {
//   int i, j;
//   ll tmp;
//   segtree_Point_Minval<ll> t;
//   rd(N,K,S);
//   rep(i,N) S[i] -= '0';
// 
//   rep(i,N) dp[i+1] = ll_inf;
//   
//   t.malloc(N+1);
//   t.setN(N+1);
//   rep(i,N+1) t[i] = dp[i];
//   t.build();
// 
//   rep(i,N){
//     if(dp[i+1] > dp[i] + i + 1){
//       dp[i+1] = dp[i] + i + 1;
//       t.change(i+1, dp[i+1]);
//     }
//     if(S[i]){
//       tmp = t.getMinVal(max(0,i-K), N) + i + 1;
//       j = min(N, i+1+K);
//       if(dp[j] > tmp){
//         dp[j] = tmp;
//         t.change(j, tmp);
//       }
//     }
//   }
// 
//   wt(dp[N]);
// }