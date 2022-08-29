#pragma GCC optimize ("Ofast")
#include<bits/stdc++.h>
using namespace std;
void *wmem;
char memarr[96000000];
template<class T> void malloc1d(T **arr, int x){
  (*arr) = (T*)malloc(x*sizeof(T));
}
template<class T> void free1d(T *arr){
  free(arr);
}
template<class T> void malloc2d(T ***arr, int x, int y){
  int i;
  (*arr) = (T**)malloc(x*sizeof(T*));
  (*arr)[0] = (T*)malloc(x*y*sizeof(T));
  int o3WxPXbE = x;
  for(i=(1);i<(o3WxPXbE);i++){
    (*arr)[i]=(*arr)[i-1]+y;
  }
}
template<class T> void free2d(T **arr){
  free(arr[0]);
  free(arr);
}
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
inline void rd(char &c){
  int i;
  for(;;){
    i = my_getchar();
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
    i = my_getchar();
    if(i!=' '&&i!='\n'&&i!='\r'&&i!='\t'&&i!=EOF){
      break;
    }
  }
  c[sz++] = i;
  for(;;){
    i = my_getchar();
    if(i==' '||i=='\n'||i=='\r'||i=='\t'||i==EOF){
      break;
    }
    c[sz++] = i;
  }
  c[sz]='\0';
  return sz;
}
inline int rd_int(void){
  int x;
  rd(x);
  return x;
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
inline void wt_L(char a){
  my_putchar(a);
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
    my_putchar('-');
  }
  while(s--){
    my_putchar(f[s]+'0');
  }
}
inline int BIT_popcount_L(const int x){
  return __builtin_popcount(x);
}
inline int BIT_popcount_L(const long long x){
  return __builtin_popcountll(x);
}
template<class S, class T> inline S chmax(S &a, T b){
  if(a<b){
    a=b;
  }
  return a;
}
template<class S> struct AhoCorasick_Sum{
  int node;
  int mem;
  int alphabet;
  int **nx;
  int *failed;
  S *sum;
  void init(void){
    int i;
    node = 1;
    for(i=(0);i<(alphabet);i++){
      nx[0][i] = -1;
    }
    failed[0] = 0;
    sum[0] = 0;
  }
  void malloc(const int n, const int k){
    int i;
    malloc2d(&nx,n,k);
    malloc1d(&failed,n);
    malloc1d(&sum,n);
    node = n;
    alphabet = k;
    init();
  }
  void free(void){
    free2d(nx);
    free1d(failed);
    free1d(sum);
  }
  template<class T> void addWord(const T word[], const int len, S val){
    int i;
    int j;
    int k;
    int now = 0;
    for(i=(0);i<(len);i++){
      if(nx[now][word[i]]==-1){
        k = node++;
        nx[now][word[i]] = k;
        for(j=(0);j<(alphabet);j++){
          nx[k][j] = -1;
        }
        sum[k] = 0;
      }
      now = nx[now][word[i]];
    }
    sum[now] += val;
  }
  void construct(void *mem = wmem){
    int i;
    int j;
    int k;
    int now;
    int *q;
    int qs;
    int qe;
    q = (int*) mem;
    qs = qe = 0;
    now = 0;
    for(k=(0);k<(alphabet);k++){
      if(nx[now][k] != -1){
        q[qe++] = nx[now][k];
        failed[ nx[now][k] ] = now;
      }
    }
    while(qs < qe){
      now = q[qs++];
      for(k=(0);k<(alphabet);k++){
        if(nx[now][k] != -1){
          i = failed[now];
          while(i){
            if(nx[i][k] != -1){
              break;
            }
            i = failed[i];
          }
          if(nx[i][k] != -1){
            i = nx[i][k];
          }
          failed[ nx[now][k] ] = i;
          sum[ nx[now][k] ] += sum[i];
          q[qe++] = nx[now][k];
        }
      }
    }
  }
  template<class T> inline int next(const int n, const T c){
    int i;
    int now;
    now = n;
    if(nx[n][c]!=-1){
      return nx[n][c];
    }
    while(now && nx[now][c]==-1){
      now=failed[now];
    }
    if(nx[now][c]!=-1){
      now = nx[now][c];
    }
    return nx[n][c] = now;
  }
}
;
char T[1002];
int C;
int Ts;
char S[400000+2];
int N;
AhoCorasick_Sum<long long> aho;
int bt[16384];
long long dp[16384][1001];
long long nx[1001];
int jump[1001];
long long gain[1001];
int main(){
  int Lj4PdHRW, i;
  wmem = memarr;
  int now = 0;
  int go;
  int hatena = 0;
  int nm;
  int nn;
  int node;
  long long g;
  long long res = -4611686016279904256LL;
  ;
  aho.malloc(1001, 14);
  int KL2GvlyY = rd_int();
  for(Lj4PdHRW=(0);Lj4PdHRW<(KL2GvlyY);Lj4PdHRW++){
    int i;
    Ts = rd(T);
    rd(C);
    for(i=(0);i<(Ts);i++){
      T[i] -= 'a';
    }
    aho.addWord(T, Ts, C);
  }
  aho.construct();
  node = aho.node;
  for(i=(0);i<(1<<14);i++){
    bt[i] =BIT_popcount_L(i);
  }
  for(i=(0);i<(1<<14);i++){
    int j;
    for(j=(0);j<(node);j++){
      dp[i][j] = -4611686016279904256LL;
    }
  }
  dp[0][0] = 0;
  N = rd(S);
  for(i=(0);i<(N);i++){
    if(S[i]!='?'){
      S[i] -= 'a';
    }
  }
  while(now < N){
    go = now;
    while(go < N && S[go] != '?'){
      go++;
    }
    if(now < go){
      for(i=(0);i<(node);i++){
        int j;
        jump[i] = i;
        gain[i] = 0;
        for(j=(now);j<(go);j++){
          jump[i] = aho.next(jump[i], S[j]);
          gain[i] += aho.sum[jump[i]];
        }
      }
      for(i=(0);i<(1<<14);i++){
        if(bt[i]==hatena){
          int j;
          for(j=(0);j<(node);j++){
            nx[j] = -4611686016279904256LL;
          }
          for(j=(0);j<(node);j++){
            if(dp[i][j] > -4611686016279904256LL){
              chmax(nx[jump[j]], dp[i][j] + gain[j]);
            }
          }
          for(j=(0);j<(node);j++){
            dp[i][j] = nx[j];
          }
        }
      }
      now = go;
      continue;
    }
    for(i=(0);i<(1<<14);i++){
      if(bt[i]==hatena){
        int j;
        for(j=(0);j<(node);j++){
          if(dp[i][j] > -4611686016279904256LL){
            int k;
            for(k=(0);k<(14);k++){
              if(!((i) &(1<<(k)))){
                nn = aho.next(j,k);
                chmax(dp[i|(1<<k)][nn], dp[i][j] + aho.sum[nn]);
              }
            }
          }
        }
      }
    }
    hatena++;
    now++;
  }
  for(i=(0);i<(1<<14);i++){
    if(bt[i]==hatena){
      int j;
      for(j=(0);j<(node);j++){
        chmax(res, dp[i][j]);
      }
    }
  }
  wt_L(res);
  wt_L('\n');
  return 0;
}
// cLay varsion 20200322-1 [beta]

// --- original code ---
// //no-unlocked
// char T[1002]; int C, Ts;
// char S[4d5+2]; int N;
// 
// AhoCorasick_Sum<ll> aho;
// int bt[16384];
// ll dp[16384][1001], nx[1001];
// int jump[1001]; ll gain[1001];
// 
// {
//   int now = 0, go, hatena = 0;
//   int nm, nn, node;
//   ll g, res = -ll_inf;;
// 
//   aho.malloc(1001, 14);
//   REP(rd_int()){
//     rd(T@Ts, C);
//     rep(i,Ts) T[i] -= 'a';
//     aho.addWord(T, Ts, C);
//   }
//   aho.construct();
// 
//   node = aho.node;
//   rep(i,1<<14) bt[i] = BIT_popcount(i);
// 
//   rep(i,1<<14) rep(j,node) dp[i][j] = -ll_inf;
//   dp[0][0] = 0;
// 
//   rd(S@N);
//   rep(i,N) if(S[i]!='?') S[i] -= 'a';
// 
//   while(now < N){
//     go = now;
//     while(go < N && S[go] != '?') go++;
// 
//     if(now < go){
//       rep(i,node){
//         jump[i] = i;
//         gain[i] = 0;
//         rep(j,now,go){
//           jump[i] = aho.next(jump[i], S[j]);
//           gain[i] += aho.sum[jump[i]];
//         }
//       }
// 
//       rep(i,1<<14) if(bt[i]==hatena){
//         rep(j,node) nx[j] = -ll_inf;
//         rep(j,node) if(dp[i][j] > -ll_inf) nx[jump[j]] >?= dp[i][j] + gain[j];
//         rep(j,node) dp[i][j] = nx[j];
//       }
//       now = go;
//       continue;
//     }
// 
//     rep(i,1<<14) if(bt[i]==hatena) rep(j,node) if(dp[i][j] > -ll_inf){
//       rep(k,14) if(!BIT_ith(i,k)){
//         nn = aho.next(j,k);
//         dp[i|(1<<k)][nn] >?= dp[i][j] + aho.sum[nn];
//       }
//     }
//     hatena++;
//     now++;
//   }
// 
// 
//   rep(i,1<<14) if(bt[i]==hatena) rep(j,node) res >?= dp[i][j];
//   wt(res);
// }