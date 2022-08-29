#pragma GCC optimize ("Ofast")
#include<bits/stdc++.h>
using namespace std;
void *wmem;
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
inline void wt_L(char a){
  putchar(a);
}
inline void wt_L(int x){
  char f[10];
  int m=0, s=0;
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
template<class S, class T> inline S chmax(S &a, T b){
  if(a<b){
    a=b;
  }
  return a;
}
template<class T> int coordcomp_L(int n, T arr[], int res[] = NULL, void *mem = wmem){
  int i, k=0;
  pair<T,int> *r;
  walloc1d(&r, n, &mem);
  for(i=0;i<(n);i++){
    r[i].first = arr[i];
    r[i].second = i;
  }
  sort(r, r+n);
  if(res != NULL){
    for(i=0;i<(n);i++){
      if(i && r[i].first != r[i-1].first){
        k++;
      }
      res[r[i].second] = k;
    }
  }
  else{
    for(i=0;i<(n);i++){
      if(i && r[i].first != r[i-1].first){
        k++;
      }
      arr[r[i].second] = k;
    }
  }
  return k+1;
}
char memarr[96000000];
int N;
int A[2000];
int cnt[2000];
int main(){
  int i, j, k, m, res, tmp;
  wmem = memarr;
  rd(N);
  {
    int Lj4PdHRW;
    for(Lj4PdHRW=0;Lj4PdHRW<(N);Lj4PdHRW++){
      rd(A[Lj4PdHRW]);
    }
  }
  m =coordcomp_L(N, A);
  res = 0;
  for(k=0;k<(N);k++){
    for(i=0;i<(m);i++){
      cnt[i] = 0;
    }
    for(i=0;i<(k);i++){
      if(cnt[A[i]]++){
        break;
      }
    }
    if(i!=k){
      break;
    }
    tmp = k;
    chmax(res, tmp);
    for(j=N-1;j>=k;j--){
      if(cnt[A[j]]++){
        break;
      }
      tmp++;
      chmax(res, tmp);
    }
  }
  res = N - res;
  wt_L(res);
  wt_L('\n');
  return 0;
}
// cLay varsion 20190830-1

// --- original code ---
// //no-unlocked
// int N, A[2000];
// 
// int cnt[2000];
// {
//   int i, j, k, m, res, tmp;
//   rd(N,A(N));
//   m = coordcomp(N, A);
// 
//   res = 0;
//   rep(k,N){
//     rep(i,m) cnt[i] = 0;
//     rep(i,k) if(cnt[A[i]]++) break;
//     if(i!=k) break;
// 
//     tmp = k;
//     res >?= tmp;
//     for(j=N-1;j>=k;j--){
//       if(cnt[A[j]]++) break;
//       tmp++;
//       res >?= tmp;
//     }
//   }
// 
//   res = N - res;
//   wt(res);
// }