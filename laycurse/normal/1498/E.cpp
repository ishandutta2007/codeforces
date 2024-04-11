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
template<class T1, class T2> void rsortA_L(int N, T1 a[], T2 b[], void *mem = wmem){
  sortA_L(N, a, b, mem);
  reverse(a, a+N);
  reverse(b, b+N);
}
template<class T1, class T2, class T3> void rsortA_L(int N, T1 a[], T2 b[], T3 c[], void *mem = wmem){
  sortA_L(N, a, b, c, mem);
  reverse(a, a+N);
  reverse(b, b+N);
  reverse(c, c+N);
}
inline int my_getchar(){
  return getchar();
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
inline void my_putchar(const int k){
  putchar(k);
  if(k=='\n'){
    fflush(stdout);
  }
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
int N;
int A[500];
int sz;
int x[1000000];
int y[1000000];
int s[1000000];
char buf[10];
int main(){
  int i;
  wmem = memarr;
  rd(N);
  {
    int Lj4PdHRW;
    for(Lj4PdHRW=(0);Lj4PdHRW<(N);Lj4PdHRW++){
      rd(A[Lj4PdHRW]);
    }
  }
  for(i=(0);i<(N);i++){
    int j;
    for(j=(i+1);j<(N);j++){
      x[sz] = i;
      y[sz] = j;
      s[sz] = A[i] - A[j];
      if(s[sz] < 0){
        swap(x[sz], y[sz]);
        s[sz] *= -1;
      }
      sz++;
    }
  }
  rsortA_L(sz, s, x, y);
  for(i=(0);i<(sz);i++){
    wt_L("?");
    wt_L(' ');
    wt_L(x[i]+1);
    wt_L(' ');
    wt_L(y[i]+1);
    wt_L('\n');
    rd(buf);
    if(buf[0] == 'Y'){
      wt_L("!");
      wt_L(' ');
      wt_L(x[i]+1);
      wt_L(' ');
      wt_L(y[i]+1);
      wt_L('\n');
      return 0;
    }
  }
  wt_L("!");
  wt_L(' ');
  wt_L(0);
  wt_L(' ');
  wt_L(0);
  wt_L('\n');
  return 0;
}
// cLay version 20210328-1 [beta]

// --- original code ---
// //interactive
// int N, A[500];
// int sz, x[1d6], y[1d6], s[1d6];
// char buf[10];
// {
//   rd(N,A(N));
//   rep(i,N) rep(j,i+1,N){
//     x[sz] = i;
//     y[sz] = j;
//     s[sz] = A[i] - A[j];
//     if(s[sz] < 0) swap(x[sz], y[sz]), s[sz] *= -1;
//     sz++;
//   }
//   rsortA(sz, s, x, y);
//   rep(i,sz){
//     wt("?", x[i]+1, y[i]+1);
//     rd(buf);
//     if(buf[0] == 'Y') wt("!", x[i]+1, y[i]+1), return 0;
//   }
//   wt("!", 0, 0);
// }