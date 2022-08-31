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
template<class S, class T> inline S chmax(S &a, T b){
  if(a<b){
    a=b;
  }
  return a;
}
template<class T> int coordcomp_L(int n, T arr[], int res[] = NULL, void *mem = wmem){
  int i;
  int k = 0;
  pair<T,int> *r;
  walloc1d(&r, n, &mem);
  for(i=(0);i<(n);i++){
    r[i].first = arr[i];
    r[i].second = i;
  }
  sort(r, r+n);
  if(res != NULL){
    for(i=(0);i<(n);i++){
      if(i && r[i].first != r[i-1].first){
        k++;
      }
      res[r[i].second] = k;
    }
  }
  else{
    for(i=(0);i<(n);i++){
      if(i && r[i].first != r[i-1].first){
        k++;
      }
      arr[r[i].second] = k;
    }
  }
  return k+1;
}
int N;
int A[200000];
int sz;
vector<int> ind[200000];
int solve(){
  int i;
  int j;
  int k;
  int res = 0;
  int tmp;
  for(i=(0);i<(sz);i++){
    ind[i].clear();
  }
  for(i=(0);i<(N);i++){
    ind[A[i]].push_back(i);
  }
  for(i=(0);i<(sz);i++){
    for(j=(0);j<(ind[i].size());j++){
      tmp = j+1;
      if(i+1 < sz){
        tmp += ind[i+1].end() - lower_bound(ind[i+1].begin(), ind[i+1].end(), ind[i][j]);
      }
      chmax(res, tmp);
    }
  }
  for(i=(0);i<(sz);i++){
    j = i;
    while(j+1 < sz && ind[j].back() < ind[j+1].front()){
      j++;
    }
    tmp = 0;
    for(k=(i);k<(j+1);k++){
      tmp += ind[k].size();
    }
    if(i){
      tmp += lower_bound(ind[i-1].begin(), ind[i-1].end(), ind[i].front()) - ind[i-1].begin();
    }
    if(j+1 < sz){
      tmp += ind[j+1].end() - lower_bound(ind[j+1].begin(), ind[j+1].end(), ind[j].back());
    }
    chmax(res, tmp);
    i = j;
  }
  return N - res;
}
int main(){
  int hCmBdyQB;
  wmem = memarr;
  int V9aVTaxx = rd_int();
  for(hCmBdyQB=(0);hCmBdyQB<(V9aVTaxx);hCmBdyQB++){
    int res;
    rd(N);
    {
      int jZyWAPpY;
      for(jZyWAPpY=(0);jZyWAPpY<(N);jZyWAPpY++){
        rd(A[jZyWAPpY]);
      }
    }
    sz =coordcomp_L(N, A);
    res = solve();
    wt_L(res);
    wt_L('\n');
  }
  return 0;
}
// cLay varsion 20200509-1

// --- original code ---
// //no-unlocked
// int N, A[2d5];
// int sz;
// vector<int> ind[2d5];
// 
// int solve(){
//   int i, j, k, res = 0, tmp;
// 
//   rep(i,sz) ind[i].clear();
//   rep(i,N) ind[A[i]].push_back(i);
// 
//   rep(i,sz) rep(j,ind[i].size()){
//     tmp = j+1;
//     if(i+1 < sz) tmp += ind[i+1].end() - lower_bound(ind[i+1].begin(), ind[i+1].end(), ind[i][j]);
//     res >?= tmp;
//   }
// 
//   rep(i,sz){
//     j = i;
//     while(j+1 < sz && ind[j].back() < ind[j+1].front()) j++;
// 
//     tmp = 0;
//     rep(k,i,j+1) tmp += ind[k].size();
//     if(i) tmp += lower_bound(ind[i-1].begin(), ind[i-1].end(), ind[i].front()) - ind[i-1].begin();
//     if(j+1 < sz) tmp += ind[j+1].end() - lower_bound(ind[j+1].begin(), ind[j+1].end(), ind[j].back());
//     res >?= tmp;
//     i = j;
//   }
//   return N - res;
// }
// 
// {
//   REP(rd_int()){
//     int res;
//     rd(N,A(N));
//     sz = coordcomp(N, A);
// 
//     res = solve();
//     wt(res);
//   }
// }