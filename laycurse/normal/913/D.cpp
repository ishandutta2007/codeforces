#include<bits/stdc++.h>
using namespace std;
void *wmem;
template<class T1, class T2, class T3> void sortA_L(int N, T1 a[], T2 b[], T3 c[], void *mem = wmem){
  int i;
  pair<T1, pair<T2, T3> > *arr=(pair<T1, pair<T2, T3> > *) mem;
  for(i=0;i<N;i++){
    arr[i].first = a[i];
    arr[i].second.first = b[i];
    arr[i].second.second = c[i];
  }
  sort(arr, arr+N);
  for(i=0;i<N;i++){
    a[i] = arr[i].first;
    b[i] = arr[i].second.first;
    c[i] = arr[i].second.second;
  }
}
void rd(int &x){
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
void wt_L(int x){
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
char memarr[96000000];
int A[200000], L, N, T[200000], arr[200000], ind[200000];
int main(){
  int i, j, k, res;
  priority_queue< pair<int,int> > q;
  wmem = memarr;
  rd(N);
  rd(L);
  {
    int Lj4PdHRW;
    for(Lj4PdHRW=0;Lj4PdHRW<N;Lj4PdHRW++){
      rd(A[Lj4PdHRW]);
      rd(T[Lj4PdHRW]);
    }
  }
  {
    int KL2GvlyY;
    for(KL2GvlyY=0;KL2GvlyY<(N-1) + 1;KL2GvlyY++){
      ind[KL2GvlyY] = (KL2GvlyY - (0) + (1));
    }
  }
  {
    int Q5VJL1cS;
    for(Q5VJL1cS=0;Q5VJL1cS<(N-1) + 1;Q5VJL1cS++){
      A[Q5VJL1cS] *= -1;
    }
  }
  sortA_L(N, A, T, ind);
  {
    int e98WHCEY;
    for(e98WHCEY=0;e98WHCEY<(N-1) + 1;e98WHCEY++){
      A[e98WHCEY] *= -1;
    }
  }
  for(i=0;i<N;i++){
    if(q.size() >= A[i]){
      break;
    }
    if(q.size() && L < T[i]){
      k = q.top().first;
      if(k < T[i]){
        continue;
      }
      L += k;
      q.pop();
    }
    if(L >= T[i]){
      q.push( make_pair(T[i],ind[i]) );
      L -= T[i];
    }
  }
  res = q.size();
  i = 0;
  while(q.size()){
    arr[i++] = q.top().second;
    q.pop();
  }
  wt_L(res);
  putchar('\n');
  wt_L(res);
  putchar('\n');
  {
    int cTE1_r3A;
    if(res==0){
      putchar('\n');
    }
    else{
      for(cTE1_r3A=0;cTE1_r3A<res-1;cTE1_r3A++){
        wt_L(arr[cTE1_r3A]);
        putchar(' ');
      }
      wt_L(arr[cTE1_r3A]);
      putchar('\n');
    }
  }
  return 0;
}
// cLay varsion 20180108-2

// --- original code ---
// //no-unlocked
// int N, L, A[2d5], T[2d5], ind[2d5];
// int arr[2d5];
// {
//   int i, j, k;
//   int res;
//   priority_queue< pair<int,int> > q;
//   
//   rd(N,L,(A,T)(N));
//   ind[0..N-1] = (1..);
//   A[0..N-1] *= -1;
//   sortA(N, A, T, ind);
//   A[0..N-1] *= -1;
// 
//   rep(i,N){
//     if(q.size() >= A[i]) break;
//     if(q.size() && L < T[i]){
//       k = q.top().first;
//       if(k < T[i]) continue;
//       L += k;
//       q.pop();
//     }
//     if(L >= T[i]){
//       q.push( make_pair(T[i],ind[i]) );
//       L -= T[i];
//     }
//   }
// 
//   res = q.size();
//   i = 0;
//   while(q.size()){
//     arr[i++] = q.top().second;
//     q.pop();
//   }
//   
//   wt(res);
//   wt(res);
//   wt(arr(res));
// }