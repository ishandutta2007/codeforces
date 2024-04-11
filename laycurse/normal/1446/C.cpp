#pragma GCC optimize ("Ofast")
#include<bits/stdc++.h>
using namespace std;
void*wmem;
char memarr[96000000];
template<class S, class T> inline S max_L(S a,T b){
  return a>=b?a:b;
}
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
template<class T1> void rsortA_L(int N, T1 a[], void *mem = wmem){
  sortA_L(N, a, mem);
  reverse(a, a+N);
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
int N;
int A[200000];
int cnt[200000];
int solve(int N, int A[], int cnt[]){
  int i;
  int j;
  int k;
  int tmp = 0;
  int res = 0;
  for(i=(0);i<(N);i++){
    cnt[i] = 0;
    for(j=(0);j<(31);j++){
      if(((A[i]) &(1<<(j)))){
        cnt[i] = j+1;
      }
    }
  }
  i = j = 0;
  while(i < N){
    while(j < N && cnt[i] == cnt[j]){
      j++;
    }
    if(j - i > 1){
      for(k=(i);k<(j);k++){
        A[k] ^= (1<<(cnt[i]-1));
      }
      if(j < N){
        chmax(res, solve(j-i, A+i, cnt+i) + tmp +1);
      }
      else{
        chmax(res, solve(j-i, A+i, cnt+i) + tmp +0);
      }
    }
    tmp++;
    i = j;
  }
  return max_L(tmp, res);
}
int main(){
  wmem = memarr;
  int res;
  rd(N);
  {
    int ao_dF3pO;
    for(ao_dF3pO=(0);ao_dF3pO<(N);ao_dF3pO++){
      rd(A[ao_dF3pO]);
    }
  }
  rsortA_L(N,A);
  res = solve(N, A, cnt);
  wt_L(N-res);
  wt_L('\n');
  return 0;
}
// cLay varsion 20201115-2

// --- original code ---
// //no-unlocked
// int N, A[2d5];
// int cnt[2d5];
// 
// int solve(int N, int A[], int cnt[]){
//   int i, j, k, tmp = 0, res = 0;
//   
//   rep(i,N){
//     cnt[i] = 0;
//     rep(j,31) if(BIT_ith(A[i],j)) cnt[i] = j+1;
//   }
// 
//   i = j = 0;
//   while(i < N){
//     while(j < N && cnt[i] == cnt[j]) j++;
//     if(j - i > 1){
//       rep(k,i,j) A[k] ^= (1<<(cnt[i]-1));
//       res >?= solve(j-i, A+i, cnt+i) + tmp + if[j < N, 1, 0];
//     }
//     tmp++;
//     i = j;
//   }
// 
//   return max(tmp, res);
// }
// 
// {
//   int res;
//   rd(N,A(N));
//   rsortA(N,A);
//   res = solve(N, A, cnt);
//   wt(N-res);
// }