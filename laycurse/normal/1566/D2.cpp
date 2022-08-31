#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include<bits/stdc++.h>
using namespace std;
void*wmem;
char memarr[96000000];
template<class T> inline void walloc1d(T **arr, int x, void **mem = &wmem){
  static int skip[16] = {0, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
  (*mem) = (void*)( ((char*)(*mem)) + skip[((unsigned long long)(*mem)) & 15] );
  (*arr)=(T*)(*mem);
  (*mem)=((*arr)+x);
}
template<class T> inline void walloc1d(T **arr, int x1, int x2, void **mem = &wmem){
  walloc1d(arr, x2-x1, mem);
  (*arr) -= x1;
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
template<class T> int coordcomp_L(int n, T arr[], int res[] = NULL, void *mem = wmem){
  int i;
  int k = 0;
  pair<T,int>*r;
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
int M;
int A[100000];
int arr[100000];
int id[300][300];
int s[300][300];
vector<int> x[100000];
vector<int> y[100000];
int us[100000];
int sz;
int main(){
  int Lj4PdHRW;
  wmem = memarr;
  int KL2GvlyY = rd_int();
  for(Lj4PdHRW=(0);Lj4PdHRW<(KL2GvlyY);Lj4PdHRW++){
    int i;
    int res = 0;
    int xx;
    int yy;
    rd(N);
    rd(M);
    {
      int cTE1_r3A;
      for(cTE1_r3A=(0);cTE1_r3A<(N*M);cTE1_r3A++){
        rd(A[cTE1_r3A]);
      }
    }
    sz =coordcomp_L(N*M,A);
    for(i=(0);i<(N*M);i++){
      arr[i] = A[i];
    }
    sortA_L(N*M,arr);
    for(i=(0);i<(N);i++){
      int j;
      for(j=(0);j<(M);j++){
        id[i][j] = arr[i*M+j];
      }
    }
    for(i=(0);i<(sz);i++){
      x[i].clear();
      y[i].clear();
      us[i] = 0;
    }
    for(i=(0);i<(N);i++){
      int j;
      for(j=(M)-1;j>=(0);j--){
        x[id[i][j]].push_back(i);
        y[id[i][j]].push_back(j);
      }
    }
    for(i=(0);i<(N);i++){
      int j;
      for(j=(0);j<(M);j++){
        s[i][j] = 0;
      }
    }
    for(i=(0);i<(N*M);i++){
      int j;
      xx = x[A[i]][us[A[i]]];
      yy = y[A[i]][us[A[i]]];
      us[A[i]]++;
      for(j=(0);j<(yy);j++){
        res += s[xx][j];
      }
      s[xx][yy] = 1;
    }
    wt_L(res);
    wt_L('\n');
  }
  return 0;
}
// cLay version 20210904-1

// --- original code ---
// //no-unlocked
// int N, M, A[1d5], arr[1d5];
// int id[300][300], s[300][300];
// VI x[1d5], y[1d5]; int us[1d5], sz;
// {
//   REP(rd_int()){
//     int res = 0, xx, yy;
//     rd(N,M,A(N*M));
//     sz = coordcomp(N*M,A);
//     rep(i,N*M) arr[i] = A[i];
//     sortA(N*M,arr);
//     rep(i,N) rep(j,M) id[i][j] = arr[i*M+j];
// 
//     rep(i,sz) x[i].clear(), y[i].clear(), us[i] = 0;
//     rep(i,N) rrep(j,M){
//       x[id[i][j]].push_back(i);
//       y[id[i][j]].push_back(j);
//     }
//     rep(i,N) rep(j,M) s[i][j] = 0;
//     rep(i,N*M){
//       xx = x[A[i]][us[A[i]]];
//       yy = y[A[i]][us[A[i]]];
//       us[A[i]]++;
//       rep(j,yy) res += s[xx][j];
//       s[xx][yy] = 1;
//     }
//     wt(res);
//   }
// }