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
inline int BIT_popcount_L(const int x){
  return __builtin_popcount(x);
}
inline int BIT_popcount_L(const long long x){
  return __builtin_popcountll(x);
}
template<class T> inline T invDigit_L(int sz, T d[]){
  T res = 0;
  int i;
  for(i=(sz)-1;i>=(0);i--){
    res = 10 * res + d[i];
  }
  return res;
}
template<class S, class T> inline S chmin(S &a, T b){
  if(a>b){
    a=b;
  }
  return a;
}
int N;
int K;
char S[12];
template<class T1, class T2, class T3> int LexicographicGE(int N, T1 A[], int sz, T2 available_num[], T3 res[], void *mem = wmem){
  int i;
  int k;
  int*nx;
  T1*av;
  walloc1d(&av, sz, &mem);
  for(i=(0);i<(sz);i++){
    av[i] = available_num[i];
  }
  for(i=(1);i<(sz);i++){
    if(av[i-1] > av[i]){
      sort(av, av+sz);
      break;
    }
  }
  walloc1d(&nx, N, &mem);
  for(i=(0);i<(N);i++){
    nx[i] = lower_bound(av, av+sz, A[i]) - av;
    if(nx[i] == sz){
      while(i >= 0 && nx[i] >= sz-1){
        i--;
      }
      if(i < 0){
        return 0;
      }
      for(k=(0);k<(i);k++){
        res[k] = A[k];
      }
      res[i] = av[nx[i]+1];
      for(k=(i+1);k<(N);k++){
        res[k] = av[0];
      }
      return 1;
    }
    if(A[i] != av[nx[i]]){
      for(k=(0);k<(i);k++){
        res[k] = A[k];
      }
      res[i] = av[nx[i]];
      for(k=(i+1);k<(N);k++){
        res[k] = av[0];
      }
      return 1;
    }
  }
  for(i=(0);i<(N);i++){
    res[i] = A[i];
  }
  return 1;
}
int main(){
  int jZyWAPpY;
  wmem = memarr;
  int jbtyPBGc = rd_int();
  for(jZyWAPpY=(0);jZyWAPpY<(jbtyPBGc);jZyWAPpY++){
    int i, mask;
    long long res = 4611686016279904256LL;
    long long tmp;
    int av[10];
    long long t[10];
    N = rd(S);
    rd(K);
    for(i=(0);i<(N);i++){
      S[i] -= '0';
    }
    for(mask=(1);mask<(1<<10);mask++){
      if(BIT_popcount_L(mask)<= K){
        tmp = 0;
        for(i=(0);i<(10);i++){
          if(((mask) &(1<<(i)))){
            av[tmp++] = i;
          }
        }
        if(LexicographicGE(N,S,tmp,av,t)){
          reverse(t,t+N);
          chmin(res, invDigit_L(N,t));
        }
      }
    }
    wt_L(res);
    wt_L('\n');
  }
  return 0;
}
// cLay version 20210816-1

// --- original code ---
// //no-unlocked
// int N, K;
// char S[12];
// 
// template<class T1, class T2, class T3>
// int LexicographicGE(int N, T1 A[], int sz, T2 available_num[], T3 res[], void *mem = wmem){
//   int i, k, *nx;
//   T1 *av;
// 
//   walloc1d(&av, sz, &mem);
//   rep(i,sz) av[i] = available_num[i];
//   rep(i,1,sz) if(av[i-1] > av[i]){
//     sort(av, av+sz);
//     break;
//   }
// 
//   walloc1d(&nx, N, &mem);
//   rep(i,N){
//     nx[i] = lower_bound(av, av+sz, A[i]) - av;
//     if(nx[i] == sz){
//       while(i >= 0 && nx[i] >= sz-1) i--;
//       if(i < 0) return 0;
//       rep(k,i) res[k] = A[k];
//       res[i] = av[nx[i]+1];
//       rep(k,i+1,N) res[k] = av[0];
//       return 1;
//     }
//     if(A[i] != av[nx[i]]){
//       rep(k,i) res[k] = A[k];
//       res[i] = av[nx[i]];
//       rep(k,i+1,N) res[k] = av[0];
//       return 1;
//     }
//   }
//   rep(i,N) res[i] = A[i];
//   return 1;
// }
// 
// {
//   REP(rd_int()){
//     ll res = ll_inf, tmp;
//     int av[10]; ll t[10];
//     rd(S@N, K);
//     rep(i,N) S[i] -= '0';
//     rep(mask,1,1<<10) if(BIT_popcount(mask) <= K){
//       tmp = 0;
//       rep(i,10) if(BIT_ith(mask,i)) av[tmp++] = i;
//       if(LexicographicGE(N,S,tmp,av,t)){
//         reverse(t,t+N);
//         res <?= invDigit(N,t);
//       }
//     }
//     // rep_scomb(av,K,10) if(LexicographicGE(N,S,K,av,t)){
//     //   reverse(t,t+N);
//     //   res <?= invDigit(N,t);
//     // }
//     wt(res);
//   }
// }