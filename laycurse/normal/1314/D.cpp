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
template<class S, class T> inline S chmin(S &a, T b){
  if(a>b){
    a=b;
  }
  return a;
}
int N;
int K;
int D[80][80];
int two[80][80][80];
int ind[80][80][80];
int path[11];
int dame[80];
long long opt = 4611686016279904256LL;
void solve(int dep){
  int i;
  if(dep==K){
    int i;
    int a;
    int b;
    long long tmp = 0;
    for(i=(1);i<(K+1);i+=(2)){
      int j;
      a = path[i-1];
      b = path[i+1];
      for(j=(0);j<(N);j++){
        if(dame[ind[a][b][j]]==0){
          break;
        }
      }
      if(j==N){
        return;
      }
      tmp += two[a][b][j];
    }
    chmin(opt, tmp);
    return;
  }
  for(i=(0);i<(N);i++){
    path[dep] = i;
    dame[i]++;
    solve(dep+2);
    dame[i]--;
  }
}
int main(){
  int i;
  wmem = memarr;
  rd(N);
  rd(K);
  for(i=(0);i<(N);i++){
    {
      int WYIGIcGE;
      for(WYIGIcGE=(0);WYIGIcGE<(N);WYIGIcGE++){
        rd(D[i][WYIGIcGE]);
      }
    }
  }
  for(i=(0);i<(N);i++){
    D[i][i] = 1073709056;
  }
  for(i=(0);i<(N);i++){
    int j;
    for(j=(0);j<(N);j++){
      int k;
      for(k=(0);k<(N);k++){
        two[i][j][k] = D[i][k] + D[k][j];
        ind[i][j][k] = k;
      }
      sortA_L(N, two[i][j], ind[i][j]);
    }
  }
  dame[0] = 1;
  solve(2);
  wt_L(opt);
  wt_L('\n');
  return 0;
}
// cLay varsion 20200217-1

// --- original code ---
// //no-unlocked
// int N, K, D[80][80];
// 
// int two[80][80][80], ind[80][80][80];
// int path[11], dame[80];
// ll opt = ll_inf;
// 
// void solve(int dep){
//   if(dep==K){
//     int a, b;
//     ll tmp = 0;
//     rep(i,1,K+1,2){
//       a = path[i-1];
//       b = path[i+1];
//       rep(j,N) if(dame[ind[a][b][j]]==0) break;
//       if(j==N) return;
//       tmp += two[a][b][j];
//     }
//     opt <?= tmp;
//     return;
//   }
// 
//   rep(i,N){
//     path[dep] = i;
//     dame[i]++;
//     solve(dep+2);
//     dame[i]--;
//   }
// }
// 
// {
//   rd(N,K);
//   rep(i,N) rd(D[i](N));
// 
//   rep(i,N) D[i][i] = int_inf;
//   rep(i,N) rep(j,N){
//     rep(k,N) two[i][j][k] = D[i][k] + D[k][j], ind[i][j][k] = k;
//     sortA(N, two[i][j], ind[i][j]);
//   }
// 
//   dame[0] = 1;
//   solve(2);
//   wt(opt);
// }