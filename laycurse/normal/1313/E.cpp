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
template<class T> void SuffixArray(T *s, int N, int K, int *SA, int *LCP = NULL, void *mem = wmem){
  int i;
  int j;
  int d;
  int m;
  int *s1;
  int name;
  int prev;
  int pos;
  char *t;
  char *lms;
  int *cnt;
  int *cnt1;
  int *cnt2;
  walloc1d(&t, N+1, &mem);
  walloc1d(&lms, N+1, &mem);
  walloc1d(&cnt, K+1, &mem);
  walloc1d(&cnt1, K+1, &mem);
  walloc1d(&cnt2, K+1, &mem);
  N++;
  s[N-1] = 0;
  t[N-1] = 1;
  t[N-2] = 0;
  for(i=N-3;i>=0;i--){
    if(s[i] < s[i+1] || (s[i]==s[i+1] && t[i+1])){
      t[i] = 1;
    }
    else{
      t[i] = 0;
    }
  }
  lms[0] = 0;
  int Oq6TK1Zh = N;
  for(i=(1);i<(Oq6TK1Zh);i++){
    if(t[i] && !t[i-1]){
      lms[i] = 1;
    }
    else{
      lms[i] = 0;
    }
  }
  for(i=(0);i<(K+1);i++){
    cnt1[i] = 0;
  }
  for(i=(0);i<(N);i++){
    cnt1[s[i]]++;
  }
  j = 0;
  for(i=(0);i<(K+1);i++){
    j += cnt1[i];
    cnt2[i] = j - cnt1[i];
    cnt1[i] = j;
  }
  for(i=(0);i<(K+1);i++){
    cnt[i] = cnt1[i];
  }
  for(i=0; i<N; i++){
    SA[i] = -1;
  }
  for(i=1; i<N; i++){
    if(lms[i]){
      SA[--cnt[s[i]]]=i;
    }
  }
  for(i=(0);i<(K+1);i++){
    cnt[i] = cnt2[i];
  }
  for(i=(0);i<(N);i++){
    j = SA[i]-1;
    if(j>=0 && !t[j]){
      SA[cnt[s[j]]++] = j;
    }
  }
  for(i=(0);i<(K+1);i++){
    cnt[i] = cnt1[i];
  }
  for(i=N-1;i>=0;i--){
    j = SA[i] - 1;
    if(j>=0 && t[j]){
      SA[--cnt[s[j]]] = j;
    }
  }
  m = 0;
  for(i=(0);i<(N);i++){
    if(lms[SA[i]]){
      SA[m++] = SA[i];
    }
  }
  int niykphg5 = N;
  for(i=(m);i<(niykphg5);i++){
    SA[i] = -1;
  }
  name=0;
  prev=-1;
  for(i=(0);i<(m);i++){
    pos = SA[i];
    for(d=(0);d<(N);d++){
      if(prev==-1 || s[pos+d]!=s[prev+d] || t[pos+d]!=t[prev+d]){
        name++;
        prev=pos;
        break;
      }
      else if(d>0 && (lms[pos+d] || lms[prev+d])){
        break;
      }
    }
    pos /= 2;
    SA[m+pos]=name-1;
  }
  for(i=N-1, j=N-1; i>=m; i--){
    if(SA[i]>=0){
      SA[j--]=SA[i];
    }
  }
  s1 = SA+N-m;
  if(name<m){
    SuffixArray(s1, m-1, name-1, SA, NULL, mem);
  }
  else{
    for(i=0; i<m; i++){
      SA[s1[i]] = i;
    }
  }
  for(i=(0);i<(K+1);i++){
    cnt[i] = cnt1[i];
  }
  for(i=1, j=0; i<N; i++){
    if(lms[i]){
      s1[j++]=i;
    }
  }
  for(i=0; i<m; i++){
    SA[i]=s1[SA[i]];
  }
  for(i=m; i<N; i++){
    SA[i]=-1;
  }
  for(i=m-1; i>=0; i--){
    j=SA[i];
    SA[i]=-1;
    SA[--cnt[s[j]]]=j;
  }
  for(i=(0);i<(N);i++){
    j = SA[i]-1;
    if(j>=0 && !t[j]){
      SA[cnt2[s[j]]++] = j;
    }
  }
  for(i=N-1;i>=0;i--){
    j = SA[i] - 1;
    if(j>=0 && t[j]){
      SA[--cnt1[s[j]]] = j;
    }
  }
  if(LCP != NULL){
    cnt = (int*)t;
    d = 0;
    for(i=(0);i<(N);i++){
      cnt[SA[i]] = i;
    }
    for(i=(0);i<(N);i++){
      if(cnt[i]){
        for(j=SA[cnt[i]-1]; j+d<N-1&&i+d<N-1&&s[j+d]==s[i+d];d++){
          ;
        }
        LCP[cnt[i]]=d;
      }
      else{
        LCP[cnt[i]] = -1;
      }
      if(d>0){
        d--;
      }
    }
  }
}
template<class T> struct fenwick{
  int size;
  int memory;
  T *data;
  void malloc(int mem);
  void walloc(int mem, void **workMemory = &wmem);
  void free(void);
  void init(int N);
  void add(int k, T val);
  T get(int k);
  T range(int a, int b);
  int kth(T k);
}
;
int N;
int M;
char A[500000+2];
char B[500000+2];
char S[1000000+2];
int Asa[500000+2];
int Alcp[500000+2];
int Bsa[500000+2];
int Blcp[500000+2];
int Al[1000000+2];
int Ar[1000000+2];
int Bl[1000000+2];
int Br[1000000+2];
int main(){
  int i, k;
  wmem = memarr;
  int x;
  int y;
  int xa;
  int xb;
  int ya;
  int yb;
  long long res = 0;
  long long tmp = 0;
  fenwick<int> fa;
  fenwick<int> fb;
  rd(N);
  rd(M);
  rd(A);
  rd(B);
  rd(S);
  reverse(B, B+N);
  SuffixArray(A, N, 128, Asa, Alcp);
  SuffixArray(B, N, 128, Bsa, Blcp);
  for(i=(1);i<(N+1);i++){
    if(A[Asa[i]] == S[0]){
      break;
    }
  }
  if(i==N+1){
    wt_L(0);
    wt_L('\n');
    return 0;
  }
  x = y = i;
  while(y+1 < N+1 && A[Asa[y+1]] == S[0]){
    y++;
  }
  Al[1] = x;
  Ar[1] = y;
  for(k=(2);k<(M);k++){
    while(x <= y && (Asa[x]+k-1 >= N || A[Asa[x]+k-1] != S[k-1])){
      x++;
    }
    while(x <= y && (Asa[y]+k-1 >= N || A[Asa[y]+k-1] != S[k-1])){
      y--;
    }
    if(x > y){
      Al[k] = Ar[k] = -1;
      continue;
    }
    Al[k] = x;
    Ar[k] = y;
  }
  for(i=(1);i<(N+1);i++){
    if(B[Bsa[i]] == S[M-1]){
      break;
    }
  }
  if(i==N+1){
    wt_L(0);
    wt_L('\n');
    return 0;
  }
  x = y = i;
  while(y+1 < N+1 && B[Bsa[y+1]] == S[M-1]){
    y++;
  }
  Bl[1] = x;
  Br[1] = y;
  for(k=(2);k<(M);k++){
    while(x <= y && (Bsa[x]+k-1 >= N || B[Bsa[x]+k-1] != S[M-k])){
      x++;
    }
    while(x <= y && (Bsa[y]+k-1 >= N || B[Bsa[y]+k-1] != S[M-k])){
      y--;
    }
    if(x > y){
      Bl[k] = Br[k] = -1;
      continue;
    }
    Bl[k] = x;
    Br[k] = y;
  }
  fa.malloc(N);
  fa.init(N);
  fb.malloc(N);
  fb.init(N);
  xa = 1;
  ya = N;
  xb = yb = -1;
  for(i=(0);i<(N);i++){
    fa.add(i, 1);
  }
  for(k=(1);k<(M);k++){
    if(Al[k]==-1){
      break;
    }
    while(xa < Al[k]){
      tmp -= fb.range(Asa[xa],min_L(Asa[xa]+M-2, N-1));
      fa.add(Asa[xa], -1);
      xa++;
    }
    while(ya > Ar[k]){
      tmp -= fb.range(Asa[ya],min_L(Asa[ya]+M-2, N-1));
      fa.add(Asa[ya], -1);
      ya--;
    }
    if(Bl[M-k] == -1){
      continue;
    }
    if(xb == -1){
      xb = Bl[M-k] + 1;
      yb = Bl[M-k];
    }
    while(xb > Bl[M-k]){
      xb--;
      x = N - 1 - Bsa[xb];
      tmp += fa.range(max_L(0, x-M+2), x);
      fb.add(x, 1);
    }
    while(yb < Br[M-k]){
      yb++;
      x = N - 1 - Bsa[yb];
      tmp += fa.range(max_L(0, x-M+2), x);
      fb.add(x, 1);
    }
    res += tmp;
  }
  wt_L(res);
  wt_L('\n');
  return 0;
}
template<class T> void fenwick<T>::malloc(int mem){
  memory = mem;
  data = (T*)std::malloc(sizeof(T)*mem);
}
template<class T> void fenwick<T>::walloc(int mem, void **workMemory /* = &wmem*/){
  memory = mem;
  walloc1d(&data, mem, workMemory);
}
template<class T> void fenwick<T>::free(void){
  memory = 0;
  free(data);
}
template<class T> void fenwick<T>::init(int N){
  size = N;
  memset(data,0,sizeof(T)*N);
}
template<class T> void fenwick<T>::add(int k, T val){
  while(k < size){
    data[k] += val;
    k |= k+1;
  }
}
template<class T> T fenwick<T>::get(int k){
  T res = 0;
  while(k>=0){
    res += data[k];
    k = (k&(k+1))-1;
  }
  return res;
}
template<class T> T fenwick<T>::range(int a, int b){
  if(b==-1){
    b=size-1;
  }
  return get(b) - get(a-1);
}
template<class T> int fenwick<T>::kth(T k){
  int i=0;
  int j=size;
  int c;
  T v;
  while(i<j){
    c = (i+j)/2;
    v = get(c);
    if(v <= k){
      i=c+1;
    }
    else{
      j=c;
    }
  }
  return i==size?-1:i;
}
// cLay varsion 20200217-1

// --- original code ---
// //no-unlocked
// int N, M;
// char A[5d5+2], B[5d5+2], S[1d6+2];
// 
// int Asa[5d5+2], Alcp[5d5+2], Bsa[5d5+2], Blcp[5d5+2];
// 
// int Al[1d6+2], Ar[1d6+2];
// int Bl[1d6+2], Br[1d6+2];
// 
// {
//   int x, y, xa, xb, ya, yb;
//   ll res = 0, tmp = 0;
//   fenwick<int> fa, fb;
// 
//   rd(N,M,A,B,S);
//   reverse(B, B+N);
//   SuffixArray(A, N, 128, Asa, Alcp);
//   SuffixArray(B, N, 128, Bsa, Blcp);
// 
//   rep(i,1,N+1) if(A[Asa[i]] == S[0]) break;
//   if(i==N+1) wt(0), return 0;
//   x = y = i;
//   while(y+1 < N+1 && A[Asa[y+1]] == S[0]) y++;
// 
//   Al[1] = x; Ar[1] = y;
//   rep(k,2,M){
//     while(x <= y && (Asa[x]+k-1 >= N || A[Asa[x]+k-1] != S[k-1])) x++;
//     while(x <= y && (Asa[y]+k-1 >= N || A[Asa[y]+k-1] != S[k-1])) y--;
//     if(x > y) Al[k] = Ar[k] = -1, continue;
//     Al[k] = x;
//     Ar[k] = y;
//   }
// 
//   rep(i,1,N+1) if(B[Bsa[i]] == S[M-1]) break;
//   if(i==N+1) wt(0), return 0;
//   x = y = i;
//   while(y+1 < N+1 && B[Bsa[y+1]] == S[M-1]) y++;
// 
//   Bl[1] = x; Br[1] = y;
//   rep(k,2,M){
//     while(x <= y && (Bsa[x]+k-1 >= N || B[Bsa[x]+k-1] != S[M-k])) x++;
//     while(x <= y && (Bsa[y]+k-1 >= N || B[Bsa[y]+k-1] != S[M-k])) y--;
//     if(x > y) Bl[k] = Br[k] = -1, continue;
//     Bl[k] = x;
//     Br[k] = y;
//   }
// 
//   fa.malloc(N);
//   fa.init(N);
//   fb.malloc(N);
//   fb.init(N);
// 
//   xa = 1; ya = N;
//   xb = yb = -1;
//   rep(i,N) fa.add(i, 1);
// 
//   rep(k,1,M){
//     //wt("K", k);
//     if(Al[k]==-1) break;
// 
//     while(xa < Al[k]){
//       tmp -= fb.range(Asa[xa], min(Asa[xa]+M-2,N-1));
//       fa.add(Asa[xa], -1);
//       //wt("erase A:", Asa[xa]);
//       xa++;
//     }
//     while(ya > Ar[k]){
//       tmp -= fb.range(Asa[ya], min(Asa[ya]+M-2,N-1));
//       fa.add(Asa[ya], -1);
//       //wt("erase A:", Asa[ya]);
//       ya--;
//     }
// 
//     if(Bl[M-k] == -1) continue;
//     if(xb == -1) xb = Bl[M-k] + 1, yb = Bl[M-k];
// 
//     while(xb > Bl[M-k]){
//       xb--;
//       x = N - 1 - Bsa[xb];
//       tmp += fa.range(max(0,x-M+2), x);
//       fb.add(x, 1);
//       //wt("add B:", x);
//     }
// 
//     while(yb < Br[M-k]){
//       yb++;
//       x = N - 1 - Bsa[yb];
//       tmp += fa.range(max(0,x-M+2), x);
//       fb.add(x, 1);
//       //wt("add B:", x);
//     }
// 
//     res += tmp;
//   }
// 
//   wt(res);
// }