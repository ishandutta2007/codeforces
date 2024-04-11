#pragma GCC optimize ("Ofast")
#include<bits/stdc++.h>
using namespace std;
void*wmem;
char memarr[96000000];
template<class S, class T> inline S min_L(S a,T b){
  return a<=b?a:b;
}
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
inline void wt_L(const char c[]){
  int i=0;
  for(i=0;c[i]!='\0';i++){
    my_putchar(c[i]);
  }
}
template<class T> long long inversion(int N, T A[], void *mem=wmem){
  int i;
  int j;
  int k;
  int p;
  int n1;
  int n2;
  T*x;
  T*y;
  long long res = 0;
  walloc1d(&x, N, &mem);
  walloc1d(&y, N, &mem);
  for(i=(0);i<(N);i++){
    x[i] = A[i];
  }
  for(k=0;k<N;k+=4){
    n1 =min_L(4, N-k);
    for(j=n1;j;j--){
      int ZIeRIny5 = j;
      for(i=(1);i<(ZIeRIny5);i++){
        if(x[k+i-1] > x[k+i]){
          swap(x[k+i-1], x[k+i]);
          res++;
        }
      }
    }
  }
  p = 4;
  while(p<N){
    for(k=0;k<N;k+=2*p){
      n1 =min_L(p, N-k);
      n2 =min_L(p, N-k-n1);
      i = j = 0;
      while(i<n1 && j<n2){
        if(x[k+i] <= x[k+n1+j]){
          y[k+i+j] = x[k+i];
          i++;
        }
        else{
          y[k+i+j] = x[k+n1+j];
          res += n1-i;
          j++;
        }
      }
      while(i<n1){
        y[k+i+j] = x[k+i];
        i++;
      }
      while(j<n2){
        y[k+i+j] = x[k+n1+j];
        j++;
      }
    }
    swap(x,y);
    p *= 2;
  }
  return res;
}
int N;
int A[100000];
int main(){
  int Lj4PdHRW;
  wmem = memarr;
  int KL2GvlyY = rd_int();
  for(Lj4PdHRW=(0);Lj4PdHRW<(KL2GvlyY);Lj4PdHRW++){
    rd(N);
    {
      int cTE1_r3A;
      for(cTE1_r3A=(0);cTE1_r3A<(N);cTE1_r3A++){
        rd(A[cTE1_r3A]);
      }
    }
    if(inversion(N,A) < (long long)N*(N-1)/2){
      wt_L("YES");
      wt_L('\n');
    }
    else{
      wt_L("NO");
      wt_L('\n');
    }
  }
  return 0;
}
// cLay varsion 20200920-1

// --- original code ---
// //no-unlocked
// int N, A[1d5];
// {
//   REP(rd_int()){
//     rd(N,A(N));
//     wt(if[inversion(N,A) < (ll)N*(N-1)/2, "YES", "NO"]);
//   }
// }