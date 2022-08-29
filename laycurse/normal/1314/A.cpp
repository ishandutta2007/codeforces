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
inline void rd(long long &x){
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
template<class T> inline T popLast(multiset<T> &a){
  T res;
  typename multiset<T>::iterator it;
  it = a.end();
  it--;
  res = *it;
  a.erase(it);
  return res;
}
template<class T> inline T popLast(set<T> &a){
  T res;
  typename set<T>::iterator it;
  it = a.end();
  it--;
  res = *it;
  a.erase(it);
  return res;
}
int N;
long long A[200000+1];
long long T[200000];
int main(){
  int i;
  wmem = memarr;
  long long cur;
  long long res = 0;
  multiset<long long> s;
  long long sm = 0;
  rd(N);
  {
    int Lj4PdHRW;
    for(Lj4PdHRW=(0);Lj4PdHRW<(N);Lj4PdHRW++){
      rd(A[Lj4PdHRW]);
    }
  }
  {
    int e98WHCEY;
    for(e98WHCEY=(0);e98WHCEY<(N);e98WHCEY++){
      rd(T[e98WHCEY]);
    }
  }
  sortA_L(N,A,T);
  A[N] = 4611686016279904256LL;
  for(i=(0);i<(N);i++){
    cur = A[i];
    s.insert(T[i]);
    sm += T[i];
    while(i+1 < N && A[i+1] == cur){
      i++;
      s.insert(T[i]);
      sm += T[i];
    }
    while(s.size() && cur < A[i+1]){
      sm -= popLast(s);
      res += sm;
      cur++;
    }
  }
  wt_L(res);
  wt_L('\n');
  return 0;
}
// cLay varsion 20200217-1

// --- original code ---
// //no-unlocked
// int N; ll A[2d5+1], T[2d5];
// {
//   ll cur, res = 0;
//   multiset<ll> s;
//   ll sm = 0;
// 
//   rd(N,A(N),T(N));
//   sortA(N,A,T);
//   A[N] = ll_inf;
// 
//   rep(i,N){
//     cur = A[i];
//     s.insert(T[i]);
//     sm += T[i];
//     while(i+1 < N && A[i+1] == cur){
//       i++;
//       s.insert(T[i]);
//       sm += T[i];
//     }
// 
//     while(s.size() && cur < A[i+1]){
//       sm -= popLast(s);
//       res += sm;
//       cur++;
//     }
//   }
// 
//   wt(res);
// }