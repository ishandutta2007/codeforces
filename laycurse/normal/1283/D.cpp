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
    putchar('-');
  }
  while(s--){
    putchar(f[s]+'0');
  }
}
template<class S> void arrInsert(const int k, int &sz, S a[], const S aval){
  int i;
  sz++;
  for(i=sz-1;i>k;i--){
    a[i] = a[i-1];
  }
  a[k] = aval;
}
template<class S, class T> void arrInsert(const int k, int &sz, S a[], const S aval, T b[], const T bval){
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
template<class S, class T, class U> void arrInsert(const int k, int &sz, S a[], const S aval, T b[], const T bval, U c[], const U cval){
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
int N;
int M;
int X[200000];
long long dist;
int Y[200000];
set<int> alr;
int q[1000000];
int d[1000000];
int qs;
int qe;
void push(int p, int r){
  if(alr.count(p)==0){
    alr.insert(p);
    arrInsert(qe,qe,q,p,d,r);
  }
}
int main(){
  int m;
  int i;
  int j;
  rd(N);
  rd(M);
  {
    int Lj4PdHRW;
    for(Lj4PdHRW=(0);Lj4PdHRW<(N);Lj4PdHRW++){
      rd(X[Lj4PdHRW]);
    }
  }
  for(i=(0);i<(N);i++){
    alr.insert(X[i]);
  }
  for(i=(0);i<(N);i++){
    for(j=(-1);j<(2);j++){
      if(j){
        push(X[i] + j, 1);
      }
    }
  }
  for(m=(0);m<(M);m++){
    dist += (i = d[qs]);
    j = Y[m] = q[qs++];
    push(j-1, i+1);
    push(j+1, i+1);
  }
  wt_L(dist);
  wt_L('\n');
  {
    int ao_dF3pO;
    if(M==0){
      putchar('\n');
    }
    else{
      for(ao_dF3pO=(0);ao_dF3pO<(M-1);ao_dF3pO++){
        wt_L(Y[ao_dF3pO]);
        wt_L(' ');
      }
      wt_L(Y[ao_dF3pO]);
      wt_L('\n');
    }
  }
  return 0;
}
// cLay varsion 20191227-1

// --- original code ---
// //no-unlocked
// int N, M, X[2d5];
// 
// ll dist; int Y[2d5];
// set<int> alr;
// int q[1d6], d[1d6], qs, qe;
// 
// void push(int p, int r){
//   if(alr.count(p)==0){
//     alr.insert(p);
//     arrInsert(qe,qe,q,p,d,r);
//   }
// }
// 
// {
//   int i, j;
//   rd(N,M,X(N));
//   rep(i,N) alr.insert(X[i]);
//   rep(i,N) rep(j,-1,2) if(j) push(X[i] + j, 1);
// 
//   rep(m,M){
//     dist += (i = d[qs]);
//     j = Y[m] = q[qs++];
//     push(j-1, i+1);
//     push(j+1, i+1);
//   }
//   wt(dist);
//   wt(Y(M));
// }