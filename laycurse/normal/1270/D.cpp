#pragma GCC optimize ("Ofast")
#include<bits/stdc++.h>
using namespace std;
int N;
int K;
int q[500];
int pos;
int val;
void query(){
  int i;
  printf("?");
  for(i=(0);i<(N);i++){
    if(q[i]){
      printf(" %d", i+1);
    }
  }
  printf("\n");
  fflush(stdout);
  scanf("%d%d",&pos,&val);
  pos--;
}
void answer(int M){
  printf("! %d\n", M);
  fflush(stdout);
  exit(0);
}
int main(){
  int i;
  int j;
  int k;
  int x;
  int fpos;
  int fval;
  int fg;
  int res;
  scanf("%d%d",&N,&K);
  if(K==1){
    answer(1);
  }
  for(i=(0);i<(K);i++){
    q[i] = 1;
  }
  query();
  fpos = pos;
  fval = val;
  x = 0;
  if(k==pos){
    x++;
  }
  for(i=(K);i<(N);i++){
    swap(q[x], q[i]);
    query();
    swap(q[x], q[i]);
    if(val != fval){
      if(val > fval){
        fg =1;
      }
      else{
        fg =-1;
      }
      res = 1;
      for(j=(0);j<(K);j++){
        if(j != x && j != fpos){
          swap(q[i], q[j]);
          query();
          swap(q[i], q[j]);
          if(val != fval){
            res++;
          }
        }
      }
      if(fg==1){
        res++;
      }
      else{
        res = K - res;
      }
      answer(res);
    }
  }
  res = fg = 0;
  for(i=(0);i<(K);i++){
    if(i != x && i != fpos){
      swap(q[i], q[N-1]);
      query();
      swap(q[i], q[N-1]);
      if(fval != val){
        res++;
        if(fval > val){
          fg =-1;
        }
        else{
          fg =1;
        }
      }
    }
  }
  if(fg){
    if(fg==1){
      res++;
    }
    else{
      res = K - res;
    }
    answer(res);
  }
  swap(q[pos], q[N-1]);
  query();
  swap(q[pos], q[N-1]);
  if(fval > val){
    res =K;
  }
  else{
    res =1;
  }
  answer(res);
  return 0;
}
// cLay varsion 20191229-1 [beta]

// --- original code ---
// int N, K;
// 
// int q[500];
// int pos, val;
// void query(){
//   printf("?");
//   rep(i,N) if(q[i]) printf(" %d", i+1);
//   printf("\n");
//   fflush(stdout);
//   scanf("%d%d",&pos,&val);
//   pos--;
// }
// 
// void answer(int M){
//   printf("! %d\n", M);
//   fflush(stdout);
//   exit(0);
// }
// 
// 
// {
//   int i, j, k, x, fpos, fval, fg, res;
//   scanf("%d%d",&N,&K);
// 
//   if(K==1) answer(1);
// 
//   rep(i,K) q[i] = 1;
//   query();
//   fpos = pos;
//   fval = val;
//   
//   x = 0;
//   if(k==pos) x++;
// 
//   rep(i,K,N){
//     swap(q[x], q[i]);
//     query();
//     swap(q[x], q[i]);
//     if(val != fval){
//       fg = if[val > fval, 1, -1];
//       res = 1;
//       rep(j,K) if(j != x && j != fpos){
//         swap(q[i], q[j]);
//         query();
//         swap(q[i], q[j]);
//         if(val != fval) res++;
//       }
//       if(fg==1) res++;
//       else      res = K - res;
//       answer(res);
//     }
//   }
// 
//   res = fg = 0;
//   rep(i,K) if(i != x && i != fpos){
//     swap(q[i], q[N-1]);
//     query();
//     swap(q[i], q[N-1]);
//     if(fval != val){
//       res++;
//       fg = if[fval > val, -1, 1];
//     }
//   }
//   if(fg){
//     if(fg==1) res++;
//     else      res = K - res;
//     answer(res);
//   }
// 
//   swap(q[pos], q[N-1]);
//   query();
//   swap(q[pos], q[N-1]);
//   res = if[fval > val, K, 1];
//   answer(res);
// }