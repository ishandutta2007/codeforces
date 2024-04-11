#pragma GCC optimize ("Ofast")
#include<bits/stdc++.h>
using namespace std;
void *wmem;
template<class S, class T> inline S min_L(S a,T b){
  return a<=b?a:b;
}
template<class T> inline void walloc1d(T **arr, int x, void **mem = &wmem){
  static int skip[16]={0, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
  (*mem) = (void*)( ((char*)(*mem)) + skip[((unsigned long long)(*mem)) & 15] );
  (*arr)=(T*)(*mem);
  (*mem)=((*arr)+x);
}
inline void rd(int &x){
  int k, m=0;
  x=0;
  for(;;){
    k = getchar();
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
    k = getchar();
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
    i = getchar();
    if(i!=' '&&i!='\n'&&i!='\r'&&i!='\t'&&i!=EOF){
      break;
    }
  }
  c = i;
}
inline int rd(char c[]){
  int i, sz=0;
  for(;;){
    i = getchar();
    if(i!=' '&&i!='\n'&&i!='\r'&&i!='\t'&&i!=EOF){
      break;
    }
  }
  c[sz++] = i;
  for(;;){
    i = getchar();
    if(i==' '||i=='\n'||i=='\r'||i=='\t'||i==EOF){
      break;
    }
    c[sz++] = i;
  }
  c[sz]='\0';
  return sz;
}
inline void wt_L(char a){
  putchar(a);
}
inline void wt_L(const char c[]){
  int i=0;
  for(i=0;c[i]!='\0';i++){
    putchar(c[i]);
  }
}
template<class T> int longestSuffixPrefix(int As, T A[], int Bs, T B[], void *mem = wmem){
  int *fail, i, k, res;
  if(As > Bs){
    A += As-Bs;
    As = Bs;
  }
  if(As < Bs){
    Bs = As;
  }
  walloc1d(&fail, Bs, &mem);
  k = fail[0] = -1;
  for(i=0;i<(Bs);i++){
    while(k>=0 && B[k]!=B[i]){
      k = fail[k];
    }
    fail[i+1] = ++k;
  }
  res = 0;
  for(i=0;i<(As);i++){
    while(res && A[i]!=B[res]){
      res = fail[res];
    }
    if(A[i]==B[res]){
      res++;
    }
  }
  return res;
}
char memarr[96000000];
int N;
char S[1000002];
int len;
char res[1000002];
int ress;
int main(){
  int Lj4PdHRW, i, k;
  wmem = memarr;
  rd(N);
  for(Lj4PdHRW=0;Lj4PdHRW<(N);Lj4PdHRW++){
    len = rd(S);
    k = longestSuffixPrefix(ress,res,len,S);
    for(i=(k);i<(len);i++){
      res[ress++] = S[i];
    }
  }
  wt_L(res);
  wt_L('\n');
  return 0;
}
// cLay varsion 20190820-1

// --- original code ---
// //no-unlocked
// int N; char S[1000002]; int len;
// char res[1000002]; int ress;
// 
// {
//   int i, k;
//   rd(N);
//   rep(N){
//     rd(S@len);
//     k = longestSuffixPrefix(ress,res,len,S);
//     rep(i,k,len) res[ress++] = S[i];
//   }
//   wt(res);
// }