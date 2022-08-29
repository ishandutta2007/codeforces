#pragma GCC optimize ("Ofast")
#include<bits/stdc++.h>
using namespace std;
void *wmem;
char memarr[96000000];
template<class S, class T> inline S min_L(S a,T b){
  return a<=b?a:b;
}
template<class S, class T> inline S max_L(S a,T b){
  return a>=b?a:b;
}
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
int N;
int A[100000];
int res[100000];
int val[100000];
int ind[100000];
int up[100000];
int dw[100000];
int main(){
  wmem = memarr;
  int i;
  int j;
  int k;
  int m;
  int mx;
  int mn;
  set<int> s;
  rd(N);
  {
    int Lj4PdHRW;
    for(Lj4PdHRW=(0);Lj4PdHRW<(N);Lj4PdHRW++){
      rd(A[Lj4PdHRW]);
    }
  }
  {
    int e98WHCEY;
    int cTE1_r3A;
    if(N==0){
      cTE1_r3A = 0;
    }
    else{
      cTE1_r3A = A[0];
      for(e98WHCEY=(1);e98WHCEY<(N);e98WHCEY++){
        cTE1_r3A = max_L(cTE1_r3A, A[e98WHCEY]);
      }
    }
    mx =cTE1_r3A;
  }
  {
    int xr20shxY;
    int WYIGIcGE;
    if(N==0){
      WYIGIcGE = 0;
    }
    else{
      WYIGIcGE = A[0];
      for(xr20shxY=(1);xr20shxY<(N);xr20shxY++){
        WYIGIcGE = min_L(WYIGIcGE, A[xr20shxY]);
      }
    }
    mn =WYIGIcGE;
  }
  if(mx > 2*mn){
    for(i=(0);i<(N);i++){
      ind[i] = i;
      val[i] = A[i];
    }
    sortA_L(N, val, ind);
    for(k=(N)-1;k>=(0);k--){
      i = ind[k];
      s.insert(i);
      s.insert(i + N);
      j = *(s.upper_bound(i));
      if(j == i+N){
        up[i] = -1;
      }
      else{
        up[i] = j - i;
      }
    }
    s.clear();
    j = 0;
    for(k=(0);k<(N);k++){
      i = ind[k];
      while(j < N && 2 * val[j] < A[i]){
        s.insert(ind[j]);
        s.insert(ind[j] + N);
        j++;
      }
      if(s.size()==0){
        dw[i] = -1;
        continue;
      }
      m = *(s.upper_bound(i));
      dw[i] = m - i;
    }
    for(i=(0);i<(N);i++){
      res[i] = 1073709056;
    }
    for(i=(0);i<(N);i++){
      if(dw[i] != -1){
        chmin(res[i], dw[i]);
      }
    }
    for(k=(0);k<(3);k++){
      for(i=(N)-1;i>=(0);i--){
        if(up[i] != -1){
          chmin(res[i], res[(i+up[i])%N] + up[i]);
        }
      }
    }
  }
  else{
    for(i=(0);i<(N);i++){
      res[i] = -1;
    }
  }
  {
    int qSsg05KM;
    if(N==0){
      putchar('\n');
    }
    else{
      for(qSsg05KM=(0);qSsg05KM<(N-1);qSsg05KM++){
        wt_L(res[qSsg05KM]);
        wt_L(' ');
      }
      wt_L(res[qSsg05KM]);
      wt_L('\n');
    }
  }
  return 0;
}
// cLay varsion 20191108-1

// --- original code ---
// //no-unlocked
// int N, A[1d5];
// int res[1d5];
// 
// int val[1d5], ind[1d5];
// int up[1d5], dw[1d5];
// 
// {
//   int i, j, k, m, mx, mn;
//   set<int> s;
// 
//   rd(N,A(N));
//   mx = max(A(N));
//   mn = min(A(N));
//   if(mx > 2*mn){
//     rep(i,N) ind[i] = i, val[i] = A[i];
//     sortA(N, val, ind);
//     rrep(k,N){
//       i = ind[k];
//       s.insert(i);
//       s.insert(i + N);
//       j = *(s.upper_bound(i));
//       if[j == i+N, up[i] = -1, up[i] = j - i];
//     }
//     s.clear();
// 
//     j = 0;
//     rep(k,N){
//       i = ind[k];
//       while(j < N && 2 * val[j] < A[i]){
//         s.insert(ind[j]);
//         s.insert(ind[j] + N);
//         j++;
//       }
//       if(s.size()==0) dw[i] = -1, continue;
//       m = *(s.upper_bound(i));
//       dw[i] = m - i;
//     }
// 
//     rep(i,N) res[i] = int_inf;
//     rep(i,N) if(dw[i] != -1) res[i] <?= dw[i];
//     rep(k,3) rrep(i,N) if(up[i] != -1) res[i] <?= res[(i+up[i])%N] + up[i];
//   } else {
//     rep(i,N) res[i] = -1;
//   }
//   wt(res(N));
// }