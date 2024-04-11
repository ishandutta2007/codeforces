#pragma GCC optimize ("Ofast")
#include<bits/stdc++.h>
using namespace std;
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
    putchar('-');
  }
  while(s--){
    putchar(f[s]+'0');
  }
}
template<class S> inline void arrInsert(const int k, int &sz, S a[], const S aval){
  int i;
  sz++;
  for(i=sz-1;i>k;i--){
    a[i] = a[i-1];
  }
  a[k] = aval;
}
template<class S, class T> inline void arrInsert(const int k, int &sz, S a[], const S aval, T b[], const T bval){
  int i;
  sz++;
  for(i=sz-1;i>k;i--){
    a[i] = a[i-1];
  }
  for(i=sz-1;i>k;i--){
    b[i] = b[i-1];
  }
  a[k] = aval;
  b[k] = bval;
}
template<class S, class T, class U> inline void arrInsert(const int k, int &sz, S a[], const S aval, T b[], const T bval, U c[], const U cval){
  int i;
  sz++;
  for(i=sz-1;i>k;i--){
    a[i] = a[i-1];
  }
  for(i=sz-1;i>k;i--){
    b[i] = b[i-1];
  }
  for(i=sz-1;i>k;i--){
    c[i] = c[i-1];
  }
  a[k] = aval;
  b[k] = bval;
  c[k] = cval;
}
template<class S, class T, class U, class V> inline void arrInsert(const int k, int &sz, S a[], const S aval, T b[], const T bval, U c[], const U cval, V d[], const V dval){
  int i;
  sz++;
  for(i=sz-1;i>k;i--){
    a[i] = a[i-1];
  }
  for(i=sz-1;i>k;i--){
    b[i] = b[i-1];
  }
  for(i=sz-1;i>k;i--){
    c[i] = c[i-1];
  }
  for(i=sz-1;i>k;i--){
    d[i] = d[i-1];
  }
  a[k] = aval;
  b[k] = bval;
  c[k] = cval;
  d[k] = dval;
}
int N;
int K;
char S[2002];
char t[2002];
int ress;
int res1[2000];
int res2[2000];
int main(){
  int Lj4PdHRW;
  int i;
  int j;
  int x;
  int KL2GvlyY = rd_int();
  for(Lj4PdHRW=(0);Lj4PdHRW<(KL2GvlyY);Lj4PdHRW++){
    rd(N);
    rd(K);
    rd(S);
    ress = 0;
    x = 0;
    for(i=(0);i<(K-1);i++){
      t[x++] = '(';
      t[x++] = ')';
    }
    for(i=(0);i<(N/2-K+1);i++){
      t[x++] ='(';
    }
    for(i=(0);i<(N/2-K+1);i++){
      t[x++] =')';
    }
    for(i=(0);i<(N);i++){
      for(j=(i);j<(N);j++){
        if(S[j]==t[i]){
          break;
        }
      }
      if(j==i){
        continue;
      }
      reverse(S+i,S+j+1);
      arrInsert(ress,ress,res1,i,res2,j);
    }
    wt_L(ress);
    wt_L('\n');
    for(i=(0);i<(ress);i++){
      wt_L(res1[i]+1);
      wt_L(' ');
      wt_L(res2[i]+1);
      wt_L('\n');
    }
  }
  return 0;
}
// cLay varsion 20200217-1

// --- original code ---
// //no-unlocked
// int N, K; char S[2002], t[2002];
// int ress, res1[2000], res2[2000];
// {
//   int i, j, x;
//   REP(rd_int()){
//     rd(N,K,S);
//     ress = 0;
// 
//     x = 0;
//     rep(i,K-1) t[x++] = '(', t[x++] = ')';
//     rep(i,N/2-K+1) t[x++] ='(';
//     rep(i,N/2-K+1) t[x++] =')';
// 
//     rep(i,N){
//       rep(j,i,N) if(S[j]==t[i]) break;
//       if(j==i) continue;
//       reverse(S+i,S+j+1);
//       arrInsert(ress,ress,res1,i,res2,j);
//     }
// 
//     wt(ress);
//     rep(i,ress) wt(res1[i]+1, res2[i]+1);
//   }
// }