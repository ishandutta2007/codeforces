#pragma GCC optimize ("Ofast")
#include<bits/stdc++.h>
using namespace std;
void *wmem;
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
inline void rd(int &x){
  int k;
  int m=0;
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
  int i;
  int sz = 0;
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
inline int rd_int(void){
  int x;
  rd(x);
  return x;
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
template<class T> long long inversion(int N, T A[], void *mem=wmem){
  int i;
  int j;
  int k;
  int p;
  int n1;
  int n2;
  T *x;
  T *y;
  long long res = 0;
  walloc1d(&x, N, &mem);
  walloc1d(&y, N, &mem);
  for(i=(0);i<(N);i++){
    x[i] = A[i];
  }
  for(k=0;k<N;k+=4){
    n1 =min_L(4, N-k);
    for(j=n1;j;j--){
      int X9Iss0pP = j;
      for(i=(1);i<(X9Iss0pP);i++){
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
char S[200002];
char T[200002];
int c1[26];
int c2[26];
int main(){
  int Lj4PdHRW;
  wmem = memarr;
  int KL2GvlyY = rd_int();
  for(Lj4PdHRW=(0);Lj4PdHRW<(KL2GvlyY);Lj4PdHRW++){
    int i;
    rd(N);
    rd(S);
    rd(T);
    for(i=(0);i<(26);i++){
      c1[i] = c2[i] = 0;
    }
    for(i=(0);i<(N);i++){
      c1[S[i] -= 'a']++;
    }
    for(i=(0);i<(N);i++){
      c2[T[i] -= 'a']++;
    }
    for(i=(0);i<(26);i++){
      if(c1[i] != c2[i]){
        wt_L("NO");
        wt_L('\n');
        goto Q5VJL1cS;
      }
    }
    for(i=(0);i<(26);i++){
      if(c1[i] > 1){
        wt_L("YES");
        wt_L('\n');
        goto Q5VJL1cS;
      }
    }
    if(inversion(N,S)%2 != inversion(N,T)%2){
      wt_L("NO");
      wt_L('\n');
      continue;
    }
    wt_L("YES");
    wt_L('\n');
    Q5VJL1cS:;
  }
  return 0;
}
// cLay varsion 20191110-1

// --- original code ---
// //no-unlocked
// int N;
// char S[200002], T[200002];
// int c1[26], c2[26];
// {
//   REP(rd_int()){
//     rd(N,S,T);
//     rep(i,26) c1[i] = c2[i] = 0;
//     rep(i,N) c1[S[i] -= 'a']++;
//     rep(i,N) c2[T[i] -= 'a']++;
//     rep(i,26) if(c1[i] != c2[i]) wt("NO"), break_continue;
//     rep(i,26) if(c1[i] > 1) wt("YES"), break_continue;
//     if(inversion(N,S)%2 != inversion(N,T)%2) wt("NO"), continue;
//     wt("YES");
//   }
// }