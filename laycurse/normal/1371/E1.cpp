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
template<class T1> void sortA_L(int N, T1 a[], void *mem = wmem){
  sort(a, a+N);
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
inline void rd(long long &x){
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
inline void wt_L(const char c[]){
  int i=0;
  for(i=0;c[i]!='\0';i++){
    my_putchar(c[i]);
  }
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
int N;
int P;
long long A[100000];
long long cnt[100000];
int ok[1000000];
int ress;
long long res[1000000];
int main(){
  wmem = memarr;
  long long i;
  long long j;
  long long k;
  long long x;
  long long y;
  long long mn = -4611686016279904256LL;
  long long mx = 4611686016279904256LL;
  rd(N);
  rd(P);
  {
    int Lj4PdHRW;
    for(Lj4PdHRW=(0);Lj4PdHRW<(N);Lj4PdHRW++){
      rd(A[Lj4PdHRW]);
    }
  }
  sortA_L(N, A);
  for(i=(0);i<(N);i++){
    cnt[i] = i + 1 - A[i];
  }
  for(i=(0);i<(N);i++){
    chmax(mn, 1 - cnt[i]);
  }
  for(i=(P);i<(N+1);i+=(P)){
    chmin(mx, i - cnt[i-1] - 1);
  }
  if(mn > mx){
    wt_L(0);
    wt_L('\n');
    wt_L("");
    wt_L('\n');
    return 0;
  }
  for(i=(0);i<(N);i++){
    x = P - cnt[i];
    y = (i+1) / P * P - cnt[i];
    while(x < mn){
      k = (mn - x) / P;
      chmax(k, 1);
      x += k * P;
    }
    while(y > mx){
      k = (y - mx) / P;
      chmax(k, 1);
      y -= k * P;
    }
    if(x > y){
      continue;
    }
    ok[x-mn]++;
    ok[y+P-mn]--;
  }
  for(i=(mn+P);i<(mx+1);i++){
    ok[i-mn] += ok[i-P-mn];
  }
  for(i=(mn);i<(mx+1);i++){
    if(!ok[i-mn]){
      res[ress++] = i;
    }
  }
  wt_L(ress);
  wt_L('\n');
  {
    int jbtyPBGc;
    if(ress==0){
      wt_L('\n');
    }
    else{
      for(jbtyPBGc=(0);jbtyPBGc<(ress-1);jbtyPBGc++){
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
// int N, P; ll A[1d5];
// 
// ll cnt[1d5];
// int ok[1d6];
// int ress; ll res[1d6];
// {
//   ll i, j, k, x, y;
//   ll mn = -ll_inf, mx = ll_inf;
//   rd(N,P,A(N));
//   sortA(N, A);
//   rep(i,N) cnt[i] = i + 1 - A[i];
// //  wt(cnt(N));
// 
//   rep(i,N) mn >?= 1 - cnt[i];
//   rep(i,P,N+1,P) mx <?= i - cnt[i-1] - 1;
// //  wt(mn,mx);
//   if(mn > mx) wt(0), wt(""), return 0;
// 
//   rep(i,N){
//     x = P - cnt[i];
//     y = (i+1) / P * P - cnt[i];
//     while(x < mn){
//       k = (mn - x) / P;
//       k >?= 1;
//       x += k * P;
//     }
//     while(y > mx){
//       k = (y - mx) / P;
//       k >?= 1;
//       y -= k * P;
//     }
//     if(x > y) continue;
//     ok[x-mn]++;
//     ok[y+P-mn]--;
//   }
// 
//   rep(i,mn+P,mx+1) ok[i-mn] += ok[i-P-mn];
//   rep(i,mn,mx+1) if(!ok[i-mn]) res[ress++] = i;
//   wt(ress);
//   wt(res(ress));
// }