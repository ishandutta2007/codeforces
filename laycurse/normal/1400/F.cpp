#pragma GCC optimize ("Ofast")
#include<bits/stdc++.h>
using namespace std;
void *wmem;
char memarr[96000000];
template<class S, class T> inline S min_L(S a,T b){
  return a<=b?a:b;
}
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
  int XJIcIBrW = x;
  for(i=(1);i<(XJIcIBrW);i++){
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
    my_putchar('-');
  }
  while(s--){
    my_putchar(f[s]+'0');
  }
}
template<class S, class T> inline S chmin(S &a, T b){
  if(a>b){
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
int N;
int X;
char S[1002];
AhoCorasick_Sum<int> aho;
int tmp[100];
void doit(int dep, int rem){
  int i;
  int j;
  int s;
  if(rem == 0){
    for(i=(0);i<(dep);i++){
      s = 0;
      for(j=(i);j<(dep);j++){
        s += tmp[j];
        if(s != X && X % s == 0){
          return;
        }
      }
    }
    aho.addWord(tmp, dep, 1);
    return;
  }
  int RZTsC2BF = min_L(10, rem+1);
  for(i=(1);i<(RZTsC2BF);i++){
    tmp[dep] = i;
    doit(dep+1, rem - i);
  }
}
int dp[100000];
int nx[100000];
int main(){
  wmem = memarr;
  int i;
  int j;
  int k;
  int node;
  N = rd(S);
  rd(X);
  aho.malloc(100000,10);
  doit(0,X);
  aho.construct();
  node = aho.node;
  for(i=(1);i<(node);i++){
    dp[i] = 1073709056;
  }
  for(k=(0);k<(N);k++){
    for(i=(0);i<(node);i++){
      nx[i] =min_L(1073709056, dp[i] + 1);
    }
    for(i=(0);i<(node);i++){
      if(dp[i] < 1073709056){
        j = aho.next(i, S[k]-'0');
        if(aho.sum[j]){
          continue;
        }
        chmin(nx[j], dp[i]);
      }
    }
    for(i=(0);i<(node);i++){
      dp[i] = nx[i];
    }
  }
  {
    int jbtyPBGc;
    int ZIeRIny5;
    if(node==0){
      ZIeRIny5 = 0;
    }
    else{
      ZIeRIny5 = dp[0];
      for(jbtyPBGc=(1);jbtyPBGc<(node);jbtyPBGc++){
        ZIeRIny5 = min_L(ZIeRIny5, dp[jbtyPBGc]);
      }
    }
    wt_L(ZIeRIny5);
    wt_L('\n');
  }
  return 0;
}
// cLay varsion 20200813-1 [beta]

// --- original code ---
// //no-unlocked
// int N, X;
// char S[1002];
// 
// AhoCorasick_Sum<int> aho;
// 
// int tmp[100];
// void doit(int dep, int rem){
//   int i, j, s;
//   if(rem == 0){
//     rep(i,dep){
//       s = 0;
//       rep(j,i,dep){
//         s += tmp[j];
//         if(s != X && X % s == 0) return;
//       }
//     }
//     aho.addWord(tmp, dep, 1);
//     return;
//   }
//   REP(i,1,min(10,rem+1)){
//     tmp[dep] = i;
//     doit(dep+1, rem - i);
//   }
// }
// 
// int dp[1d5], nx[1d5];
// 
// {
//   int i, j, k, node;
//   rd(S@N,X);
//   aho.malloc(1d5,10);
//   doit(0,X);
//   aho.construct();
// 
//   node = aho.node;
//   rep(i,1,node) dp[i] = int_inf;
//   rep(k,N){
//     rep(i,node) nx[i] = min(int_inf, dp[i] + 1);
//     rep(i,node) if(dp[i] < int_inf){
//       j = aho.next(i, S[k]-'0');
//       if(aho.sum[j]) continue;
//       nx[j] <?= dp[i];
//     }
//     rep(i,node) dp[i] = nx[i];
//   }
//   wt(min(dp(node)));
// }