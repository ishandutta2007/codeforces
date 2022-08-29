#pragma GCC optimize ("Ofast")
#include<bits/stdc++.h>
using namespace std;
template<class S, class T> inline S max_L(S a,T b){
  return a>=b?a:b;
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
template<class T> inline T getLast(multiset<T> &a){
  typename multiset<T>::iterator it;
  it = a.end();
  it--;
  return *it;
}
template<class T> inline T getLast(set<T> &a){
  typename set<T>::iterator it;
  it = a.end();
  it--;
  return *it;
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
int M;
int A[2000];
int B[2000];
int C[2000];
int D[2000];
int mx[2000000+5];
vector<int> s[1000000+5];
int main(){
  int i;
  int j;
  int k;
  long long res = 4611686016279904256LL;
  long long tmp;
  multiset<int> ms;
  rd(N);
  rd(M);
  {
    int Lj4PdHRW;
    for(Lj4PdHRW=(0);Lj4PdHRW<(N);Lj4PdHRW++){
      rd(A[Lj4PdHRW]);
      rd(B[Lj4PdHRW]);
    }
  }
  {
    int e98WHCEY;
    for(e98WHCEY=(0);e98WHCEY<(M);e98WHCEY++){
      rd(C[e98WHCEY]);
      rd(D[e98WHCEY]);
    }
  }
  for(i=(0);i<(M);i++){
    chmax(mx[C[i]], D[i] + 1);
  }
  for(i=(2000000+4)-1;i>=(0);i--){
    chmax(mx[i], mx[i+1]);
  }
  for(i=(0);i<(N);i++){
    for(j=(0);j<(M);j++){
      if(A[i] <= C[j]){
        s[C[j]-A[i]+1].push_back(i);
      }
    }
  }
  for(i=(0);i<(N);i++){
    ms.insert(mx[A[i]] - B[i]);
  }
  chmin(res, max_L(0, getLast(ms)));
  for(i=(1);i<(1000000+5);i++){
    if(s[i].size()){
      sort(s[i].begin(), s[i].end());
      for(j=(0);j<(s[i].size());j++){
        k = s[i][j];
        if(j && k==s[i][j-1]){
          continue;
        }
        ms.erase(ms.find(mx[A[k]+i-1] - B[k]));
        ms.insert(mx[A[k]+i] - B[k]);
      }
      chmin(res, i +max_L(0, getLast(ms)));
    }
  }
  wt_L(res);
  wt_L('\n');
  return 0;
}
// cLay varsion 20200926-1

// --- original code ---
// //no-unlocked
// int N, M, A[2000], B[2000], C[2000], D[2000];
// int mx[2d6+5];
// vector<int> s[1d6+5];
// {
//   int i, j, k;
//   ll res = ll_inf, tmp;
//   multiset<int> ms;
//   rd(N,M,(A,B)(N),(C,D)(M));
//   rep(i,M) mx[C[i]] >?= D[i] + 1;
//   rrep(i,2d6+4) mx[i] >?= mx[i+1];
// 
//   rep(i,N) rep(j,M) if(A[i] <= C[j]) s[C[j]-A[i]+1].push_back(i);
//   rep(i,N) ms.insert(mx[A[i]] - B[i]);
// 
//   res <?= max(0,getLast(ms));
// 
//   rep(i,1,1d6+5) if(s[i].size()){
//     sort(s[i].begin(), s[i].end());
//     rep(j,s[i].size()){
//       k = s[i][j];
//       if(j && k==s[i][j-1]) continue;
//       ms.erase(ms.find(mx[A[k]+i-1] - B[k]));
//       ms.insert(mx[A[k]+i] - B[k]);
//     }
//     res <?= i + max(0,getLast(ms));
//   }
// 
//   wt(res);
// }