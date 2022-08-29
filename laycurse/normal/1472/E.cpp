#pragma GCC optimize ("Ofast")
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
template<class T1, class T2> void sortA_L(int N, T1 a[], T2 b[], void *mem = wmem){
  int i;
  pair<T1, T2>*arr;
  walloc1d(&arr, N, &mem);
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
template<class T1, class T2, class T3> void sortA_L(int N, T1 a[], T2 b[], T3 c[], void *mem = wmem){
  int i;
  pair<T1, pair<T2, T3> >*arr;
  walloc1d(&arr, N, &mem);
  for(i=(0);i<(N);i++){
    arr[i].first = a[i];
    arr[i].second.first = b[i];
    arr[i].second.second = c[i];
  }
  sort(arr, arr+N);
  for(i=(0);i<(N);i++){
    a[i] = arr[i].first;
    b[i] = arr[i].second.first;
    c[i] = arr[i].second.second;
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
int N;
int X[200000];
int Y[200000];
int ind[200000];
int res[200000];
int main(){
  int Lj4PdHRW;
  wmem = memarr;
  int KL2GvlyY = rd_int();
  for(Lj4PdHRW=(0);Lj4PdHRW<(KL2GvlyY);Lj4PdHRW++){
    int i;
    int k = 0;
    int mn = 1073709056;
    int mnind;
    rd(N);
    {
      int cTE1_r3A;
      for(cTE1_r3A=(0);cTE1_r3A<(N);cTE1_r3A++){
        rd(X[cTE1_r3A]);
        rd(Y[cTE1_r3A]);
      }
    }
    for(i=(0);i<(N);i++){
      ind[i] = i;
    }
    for(i=(0);i<(N);i++){
      if(X[i] > Y[i]){
        swap(X[i], Y[i]);
      }
      ;
    }
    sortA_L(N, X, Y, ind);
    for(i=(0);i<(N);i++){
      while(X[k] < X[i]){
        if(mn > Y[k]){
          {
            auto V9aVTaxx = (Y[k]);
            auto APIVbQlN = ( k);
            mn = V9aVTaxx;
            mnind = APIVbQlN;
          }
        }
        k++;
      }
      if(mn < Y[i]){
        res[ind[i]] =ind[mnind]+1;
      }
      else{
        res[ind[i]] =-1;
      }
    }
    {
      int YREPHmFM;
      if(N==0){
        wt_L('\n');
      }
      else{
        for(YREPHmFM=(0);YREPHmFM<(N-1);YREPHmFM++){
          wt_L(res[YREPHmFM]);
          wt_L(' ');
        }
        wt_L(res[YREPHmFM]);
        wt_L('\n');
      }
    }
  }
  return 0;
}
// cLay version 20210103-1

// --- original code ---
// //no-unlocked
// int N, X[2d5], Y[2d5];
// int ind[2d5], res[2d5];
// {
//   REP(rd_int()){
//     int i, k = 0, mn = int_inf, mnind;
//     rd(N,(X,Y)(N));
//     rep(i,N) ind[i] = i;
//     rep(i,N) sortE(X[i], Y[i]);
//     sortA(N, X, Y, ind);
// 
//     rep(i,N){
//       while(X[k] < X[i]){
//         if(mn > Y[k]) (mn, mnind) = (Y[k], k);
//         k++;
//       }
//       res[ind[i]] = if[mn < Y[i], ind[mnind]+1, -1];
//     }
//     wt(res(N));
//   }
// }