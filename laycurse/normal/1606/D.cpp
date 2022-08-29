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
template<class T> inline void walloc2d(T ***arr, int x, int y, void **mem = &wmem){
  int i;
  walloc1d(arr, x, mem);
  for(i=(0);i<(x);i++){
    walloc1d(&((*arr)[i]), y, mem);
  }
}
template<class T> inline void walloc2d(T ***arr, int x1, int x2, int y1, int y2, void **mem = &wmem){
  int i;
  walloc1d(arr, x1, x2, mem);
  for(i=(x1);i<(x2);i++){
    walloc1d(&((*arr)[i]), y1, y2, mem);
  }
}
template<class T1, class T2> void sortA_index_L(int N, T1 a[], T2 b[], void *mem = wmem){
  int i;
  pair<T1, T2>*arr;
  walloc1d(&arr, N, &mem);
  for(i=(0);i<(N);i++){
    b[i] = i;
  }
  for(i=(0);i<(N);i++){
    arr[i].first = a[i];
    arr[i].second = b[i];
  }
  sort(arr, arr+N);
  for(i=(0);i<(N);i++){
    a[i] = arr[i].first;
    b[i] = arr[i].second;
  }
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
int main(){
  int Lj4PdHRW;
  wmem = memarr;
  int ind[1000000];
  int v[1000000];
  char res[1000000];
  void*mem = wmem;
  int KL2GvlyY = rd_int();
  for(Lj4PdHRW=(0);Lj4PdHRW<(KL2GvlyY);Lj4PdHRW++){
    int i;
    int X;
    rd(X);
    int Y;
    rd(Y);
    int**A;
    int**ul;
    int**dl;
    int**ur;
    int**dr;
    walloc2d(&A, X, Y);
    walloc2d(&ul, X, Y);
    walloc2d(&dl, X, Y);
    walloc2d(&ur, X, Y);
    walloc2d(&dr, X, Y);
    {
      int cTE1_r3A;
      int RZTsC2BF;
      for(cTE1_r3A=(0);cTE1_r3A<(X);cTE1_r3A++){
        for(RZTsC2BF=(0);RZTsC2BF<(Y);RZTsC2BF++){
          rd(A[cTE1_r3A][RZTsC2BF]);
        }
      }
    }
    for(i=(0);i<(X);i++){
      v[i] = A[i][0];
    }
    sortA_index_L(X,v,ind);
    for(i=(0);i<(X);i++){
      int j;
      for(j=(0);j<(Y);j++){
        ul[i][j] = A[i][j];
      }
    }
    for(i=(0);i<(X);i++){
      int j;
      for(j=(0);j<(Y);j++){
        A[i][j] = ul[ind[i]][j];
      }
    }
    for(i=(0);i<(X);i++){
      int j;
      for(j=(0);j<(Y);j++){
        ul[i][j] = dl[i][j] = ur[i][j] = dr[i][j] = A[i][j];
      }
    }
    for(i=(0);i<(X);i++){
      int j;
      for(j=(0);j<(Y);j++){
        if(i){
          chmax(ul[i][j], ul[i-1][j]);
        }
        if(j){
          chmax(ul[i][j], ul[i][j-1]);
        }
        if(i){
          chmin(dl[X-1-i][j], dl[X-1-(i-1)][j]);
        }
        if(j){
          chmin(dl[X-1-i][j], dl[X-1-i][j-1]);
        }
        if(i){
          chmin(ur[i][Y-1-j], ur[i-1][Y-1-j]);
        }
        if(j){
          chmin(ur[i][Y-1-j], ur[i][Y-1-(j-1)]);
        }
        if(i){
          chmax(dr[X-1-i][Y-1-j], dr[X-1-(i-1)][Y-1-j]);
        }
        if(j){
          chmax(dr[X-1-i][Y-1-j], dr[X-1-i][Y-1-(j-1)]);
        }
      }
    }
    for(i=(1);i<(X);i++){
      int j;
      for(j=(1);j<(Y);j++){
        int k;
        if(ul[i-1][j-1] >= dl[i][j-1]){
          continue;
        }
        if(ur[i-1][j] <= dr[i][j]){
          continue;
        }
        for(k=(0);k<(X);k++){
          res[k] = 'R';
        }
        res[X] = '\0';
        for(k=(0);k<(i);k++){
          res[ind[k]] = 'B';
        }
        wt_L("YES");
        wt_L('\n');
        wt_L(res);
        wt_L(' ');
        wt_L(j);
        wt_L('\n');
        goto Q5VJL1cS;
      }
    }
    wt_L("NO");
    wt_L('\n');
    Q5VJL1cS:;
  }
  return 0;
}
// cLay version 20211024-1

// --- original code ---
// //no-unlocked
// int ind[1d6], v[];
// char res[];
// void *mem = wmem;
// REP(rd_int()){
//   int @X, @Y;
//   int **A, **ul, **dl, **ur, **dr;
//   walloc2d(&A, X, Y);
//   walloc2d(&ul, X, Y);
//   walloc2d(&dl, X, Y);
//   walloc2d(&ur, X, Y);
//   walloc2d(&dr, X, Y);
//   rd(A(X,Y));
//   rep(i,X) v[i] = A[i][0];
//   sortA_index(X,v,ind);
//   rep(i,X) rep(j,Y) ul[i][j] = A[i][j];
//   rep(i,X) rep(j,Y) A[i][j] = ul[ind[i]][j];
// 
//   rep(i,X) rep(j,Y) ul[i][j] = dl[i][j] = ur[i][j] = dr[i][j] = A[i][j];
//   rep(i,X) rep(j,Y){
//     if(i) ul[i][j] >?= ul[i-1][j];
//     if(j) ul[i][j] >?= ul[i][j-1];
//     if(i) dl[X-1-i][j] <?= dl[X-1-(i-1)][j];
//     if(j) dl[X-1-i][j] <?= dl[X-1-i][j-1];
//     if(i) ur[i][Y-1-j] <?= ur[i-1][Y-1-j];
//     if(j) ur[i][Y-1-j] <?= ur[i][Y-1-(j-1)];
//     if(i) dr[X-1-i][Y-1-j] >?= dr[X-1-(i-1)][Y-1-j];
//     if(j) dr[X-1-i][Y-1-j] >?= dr[X-1-i][Y-1-(j-1)];
//   }
//   rep(i,1,X) rep(j,1,Y){
//     if(ul[i-1][j-1] >= dl[i][j-1]) continue;
//     if(ur[i-1][j] <= dr[i][j]) continue;
//     rep(k,X) res[k] = 'R'; res[X] = '\0';
//     rep(k,i) res[ind[k]] = 'B';
//     wt("YES");
//     wt(res,j);
//     break_break_continue;
//   }
//   wt("NO");
// }