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
template<class S, class T> inline S chmin(S &a, T b){
  if(a>b){
    a=b;
  }
  return a;
}
template<class S, class T> inline S chmax(S &a, T b){
  if(a<b){
    a=b;
  }
  return a;
}
template<class T> int coordcomp_L(int n, T arr[], int res[] = NULL, void *mem = wmem){
  int i;
  int k = 0;
  pair<T,int> *r;
  walloc1d(&r, n, &mem);
  for(i=(0);i<(n);i++){
    r[i].first = arr[i];
    r[i].second = i;
  }
  sort(r, r+n);
  if(res != NULL){
    for(i=(0);i<(n);i++){
      if(i && r[i].first != r[i-1].first){
        k++;
      }
      res[r[i].second] = k;
    }
  }
  else{
    for(i=(0);i<(n);i++){
      if(i && r[i].first != r[i-1].first){
        k++;
      }
      arr[r[i].second] = k;
    }
  }
  return k+1;
}
int N;
int A[300000];
int f[300000];
int e[300000];
int main(){
  int Lj4PdHRW;
  wmem = memarr;
  int i;
  int j;
  int m;
  int mx;
  int KL2GvlyY = rd_int();
  for(Lj4PdHRW=(0);Lj4PdHRW<(KL2GvlyY);Lj4PdHRW++){
    rd(N);
    {
      int Q5VJL1cS;
      for(Q5VJL1cS=(0);Q5VJL1cS<(N);Q5VJL1cS++){
        rd(A[Q5VJL1cS]);
      }
    }
    m =coordcomp_L(N, A);
    for(i=(0);i<(m);i++){
      f[i] = N;
      e[i] = -1;
    }
    for(i=(0);i<(N);i++){
      chmin(f[A[i]], i);
      chmax(e[A[i]], i);
    }
    mx = j = 0;
    for(i=(1);i<(m);i++){
      if(e[i-1] >= f[i]){
        j = i;
      }
      chmax(mx, i - j);
    }
    wt_L(m - mx - 1);
    wt_L('\n');
  }
  return 0;
}
// cLay varsion 20191012-1

// --- original code ---
// //no-unlocked
// int N, A[3d5];
// int f[3d5], e[3d5];
// {
//   int i, j, m, mx;
//   REP(rd_int()){
//     rd(N,A(N));
//     m = coordcomp(N, A);
//     rep(i,m) f[i] = N, e[i] = -1;
//     rep(i,N) f[A[i]] <?= i, e[A[i]] >?= i;
//     mx = j = 0;
//     rep(i,1,m){
//       if(e[i-1] >= f[i]) j = i;
//       mx >?= i - j;
//     }
//     wt(m - mx - 1);
//   }
// }