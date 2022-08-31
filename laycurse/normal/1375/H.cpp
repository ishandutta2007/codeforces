#pragma GCC optimize ("Ofast")
#include<bits/stdc++.h>
using namespace std;
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
template<class S> inline void arrInsert(const int k, int &sz, S a[], const S aval){
  int i;
  sz++;
  for(i=sz-1;i>k;i--){
    a[i] = a[i-1];
  }
  a[k] = aval;
}
template<class S, class T> inline void arrInsert(const int k, int &sz, S a[], const S aval, T b[], const T bval){
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
template<class S, class T, class U> inline void arrInsert(const int k, int &sz, S a[], const S aval, T b[], const T bval, U c[], const U cval){
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
template<class S, class T, class U, class V> inline void arrInsert(const int k, int &sz, S a[], const S aval, T b[], const T bval, U c[], const U cval, V d[], const V dval){
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
  for(i=sz-1;i>k;i--){
    d[i] = d[i-1];
  }
  a[k] = aval;
  b[k] = bval;
  c[k] = cval;
  d[k] = dval;
}
int N;
int Q;
int A[100000];
int L;
int R;
int ra[100000];
int cnt;
int r;
int us;
int u1[3000000];
int u2[3000000];
map<int,int> memo[200000];
int solve(int sz, int arr[], int L, int R, int mn, int mx, int nd){
  int md = (mn + mx) / 2;
  int r1;
  int r2;
  int res = -1;
  unsigned long long h1;
  unsigned long long h2;
  unsigned long long hs;
  while(sz && arr[0] < mn){
    sz--;
    arr = arr + 1;
  }
  while(sz && arr[sz-1] >= mx){
    sz--;
  }
  if(sz==0){
    return -1;
  }
  if(sz==1){
    return ra[arr[0]]+1;
  }
  while(A[L] < mn || A[L] >= mx){
    L++;
  }
  while(A[R] < mn || A[R] >= mx){
    R--;
  }
  hs = L*100000 + R;
  if(memo[nd].count(hs)){
    return memo[nd][hs];
  }
  r1 = solve(sz, arr, L, R, mn, md, nd+1);
  r2 = solve(sz, arr, L, R, md, mx, nd+1);
  res = -1;
  if(r1==-1){
    res = r2;
  }
  if(r2==-1){
    res = r1;
  }
  if(res==-1){
    cnt++;
    arrInsert(us, us, u1, r1, u2, r2);
    res = cnt;
  }
  return memo[nd][hs] = res;
}
int arr[100000];
int res[1000000];
int main(){
  int i, q;
  int sz;
  r = rand()%100000;
  rd(N);
  rd(Q);
  {
    int WYIGIcGE;
    for(WYIGIcGE=(0);WYIGIcGE<(N);WYIGIcGE++){
      rd(A[WYIGIcGE]);A[WYIGIcGE] += (-1);
    }
  }
  cnt = N;
  for(i=(0);i<(N);i++){
    ra[A[i]] = i;
  }
  for(q=(0);q<(Q);q++){
    rd(L);L += (-1);
    rd(R);R += (-1);
    sz = 0;
    for(i=(0);i<(N);i++){
      if(L <= ra[i]  &&  ra[i] <= R){
        arr[sz++] = i;
      }
    }
    res[q] = solve(sz, arr, L, R, 0, N, 0);
  }
  wt_L(cnt);
  wt_L('\n');
  for(i=(0);i<(us);i++){
    wt_L(u1[i]);
    wt_L(' ');
    wt_L(u2[i]);
    wt_L('\n');
  }
  {
    int jbtyPBGc;
    if(Q==0){
      wt_L('\n');
    }
    else{
      for(jbtyPBGc=(0);jbtyPBGc<(Q-1);jbtyPBGc++){
        wt_L(res[jbtyPBGc]);
        wt_L(' ');
      }
      wt_L(res[jbtyPBGc]);
      wt_L('\n');
    }
  }
  return 0;
}
// cLay varsion 20200509-1

// --- original code ---
// //no-unlocked
// //working_memory=20MB
// int N, Q, A[1d5], L, R;
// 
// int ra[1d5];
// int cnt;
// int r;
// 
// int us, u1[3d6], u2[3d6];
// 
// map<int,int> memo[2d5];
// int solve(int sz, int arr[], int L, int R, int mn, int mx, int nd){
//   int md = (mn + mx) / 2;
//   int r1, r2, res = -1;
//   ull h1, h2, hs;
// 
//   while(sz && arr[0] < mn){
//     sz--;
//     arr = arr + 1;
//   }
//   while(sz && arr[sz-1] >= mx){
//     sz--;
//   }
//   if(sz==0) return -1;
//   if(sz==1) return ra[arr[0]]+1;
//   while(A[L] < mn || A[L] >= mx) L++;
//   while(A[R] < mn || A[R] >= mx) R--;
// 
//   hs = L*1d5 + R;
//   if(memo[nd].count(hs)) return memo[nd][hs];
// 
//   r1 = solve(sz, arr, L, R, mn, md, nd+1);
//   r2 = solve(sz, arr, L, R, md, mx, nd+1);
//   res = -1;
//   if(r1==-1) res = r2;
//   if(r2==-1) res = r1;
//   if(res==-1){
//     cnt++;
//     arrInsert(us, us, u1, r1, u2, r2);
//     res = cnt;
//   }
//   return memo[nd][hs] = res;
// }
// 
// int arr[1d5];
// int res[1d6];
// {
//   int sz;
//   r = rand()%100000;
//   rd(N,Q,(A--)(N));
// 
//   // N = 1<<12;
//   // Q = 1<<16;
//   // rep(i,N) A[i] = i;
//   // random_shuffle(A, A+N);
// 
//   cnt = N;
//   rep(i,N) ra[A[i]] = i;
//   rep(q,Q){
//     rd(L--,R--);
//     // L = rand()%N;
//     // R = rand()%N;
//     // sortE(L,R);
// 
//     sz = 0;
//     rep(i,N) if(L <= ra[i] <= R) arr[sz++] = i;
// //    wt("--",arr(sz));
//     res[q] = solve(sz, arr, L, R, 0, N, 0);
//   }
//   wt(cnt);
//   rep(i,us) wt(u1[i], u2[i]);
//   wt(res(Q));
// }