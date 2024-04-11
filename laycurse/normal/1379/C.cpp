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
template<class T1, class T2> void sortA_L(int N, T1 a[], T2 b[], void *mem = wmem){
  int i;
  pair<T1, T2> *arr;
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
template<class T1> void rsortA_L(int N, T1 a[], void *mem = wmem){
  sortA_L(N, a, mem);
  reverse(a, a+N);
}
template<class T1, class T2> void rsortA_L(int N, T1 a[], T2 b[], void *mem = wmem){
  sortA_L(N, a, b, mem);
  reverse(a, a+N);
  reverse(b, b+N);
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
template<class S, class T> inline S chmax(S &a, T b){
  if(a<b){
    a=b;
  }
  return a;
}
long long N;
long long M;
long long A[100000];
long long B[100000];
long long sm[100000+1];
int main(){
  int Lj4PdHRW;
  wmem = memarr;
  int KL2GvlyY = rd_int();
  for(Lj4PdHRW=(0);Lj4PdHRW<(KL2GvlyY);Lj4PdHRW++){
    int i;
    int j;
    int k;
    long long res = 0;
    long long tmp;
    long long r;
    rd(N);
    rd(M);
    {
      int cTE1_r3A;
      for(cTE1_r3A=(0);cTE1_r3A<(M);cTE1_r3A++){
        rd(A[cTE1_r3A]);
        rd(B[cTE1_r3A]);
      }
    }
    rsortA_L(M,A,B);
    for(i=(0);i<(M);i++){
      sm[i+1] = sm[i] + A[i];
    }
    if(N <= M){
      chmax(res, sm[N]);
    }
    for(i=(0);i<(M);i++){
      int ao_dF3pO;
      int tU__gIr_;
      int a2conNHc;
      ao_dF3pO = 0;
      tU__gIr_ = M;
      while(ao_dF3pO < tU__gIr_){
        if((ao_dF3pO + tU__gIr_)%2==0){
          a2conNHc = (ao_dF3pO + tU__gIr_) / 2;
        }
        else{
          a2conNHc = (ao_dF3pO + tU__gIr_ + 1) / 2;
        }
        if(A[a2conNHc-1] > B[i]){
          ao_dF3pO = a2conNHc;
        }
        else{
          tU__gIr_ = a2conNHc - 1;
        }
      }
      k =tU__gIr_;
      r = N - k;
      tmp = sm[k];
      if(A[i] <= B[i]){
        r--;
        tmp += A[i];
      }
      if(r < 0){
        continue;
      }
      tmp += r * B[i];
      chmax(res, tmp);
    }
    wt_L(res);
    wt_L('\n');
  }
  return 0;
}
// cLay varsion 20200509-1

// --- original code ---
// //no-unlocked
// ll N, M, A[1d5], B[1d5];
// ll sm[1d5+1];
// {
//   REP(rd_int()){
//     int i, j, k;
//     ll res = 0, tmp, r;
//     rd(N,M,(A,B)(M));
//     rsortA(M,A,B);
// 
//     rep(i,M) sm[i+1] = sm[i] + A[i];
//     if(N <= M) res >?= sm[N];
// 
//     rep(i,M){
//       k = bsearch_max[int,x,0,M](A[x-1] > B[i]);
//       r = N - k;
//       tmp = sm[k];
//       if(A[i] <= B[i]) r--, tmp += A[i];
//       if(r < 0) continue;
//       tmp += r * B[i];
//       res >?= tmp;
//     }
//     wt(res);
//   }
// }