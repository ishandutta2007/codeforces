#pragma GCC optimize ("Ofast")
#include<bits/stdc++.h>
using namespace std;
int TEST;
int N;
int X;
int As[1000];
int A[1000][1000];
int mx;
int sen;
int sz;
int q[1000];
int ok[1000];
int ress;
int res[1000];
int query(void){
  int i;
  int res;
  printf("? %d", sz);
  for(i=(0);i<(sz);i++){
    printf(" %d", q[i]+1);
  }
  printf("\n");
  fflush(stdout);
  scanf("%d",&res);
  return res - 1;
}
void answer(void){
  int i;
  char buf[100];
  printf("!");
  for(i=(0);i<(ress);i++){
    printf(" %d", res[i]+1);
  }
  printf("\n");
  fflush(stdout);
  scanf("%s",buf);
}
int main(){
  int cTE1_r3A;
  int x;
  int y;
  int z;
  scanf("%d",&TEST);
  for(cTE1_r3A=(0);cTE1_r3A<(TEST);cTE1_r3A++){
    int i;
    scanf("%d%d",&N,&X);
    for(i=(0);i<(X);i++){
      int j;
      scanf("%d",As+i);
      for(j=(0);j<(As[i]);j++){
        scanf("%d",A[i]+j);
        A[i][j]--;
      }
    }
    sz = N;
    for(i=(0);i<(N);i++){
      q[i] = i;
    }
    mx = query();
    x = 0;
    y = N - 1;
    while(x < y){
      z = (x + y) / 2;
      sz = 0;
      for(i=(x);i<(z+1);i++){
        q[sz++] = i;
      }
      if(query() == mx){
        y = z;
      }
      else{
        x = z + 1;
      }
    }
    ress = X;
    for(i=(0);i<(X);i++){
      res[i] = mx;
    }
    for(i=(0);i<(X);i++){
      int j;
      for(j=(0);j<(As[i]);j++){
        if(A[i][j]==x){
          int k;
          for(k=(0);k<(N);k++){
            ok[k] = 1;
          }
          for(j=(0);j<(As[i]);j++){
            ok[A[i][j]] = 0;
          }
          sz = 0;
          for(k=(0);k<(N);k++){
            if(ok[k]){
              q[sz++] = k;
            }
          }
          res[i] = query();
          break;
        }
      }
    }
    answer();
  }
  return 0;
}
// cLay varsion 20200509-1

// --- original code ---
// int TEST;
// int N, X, As[1000], A[1000][1000];
// int mx, sen;
// int sz, q[1000], ok[1000];
// int ress, res[1000];
// 
// int query(void){
//   int res;
//   printf("? %d", sz);
//   rep(i,sz) printf(" %d", q[i]+1);
//   printf("\n");
//   fflush(stdout);
//   scanf("%d",&res);
//   return res - 1;
// }
// 
// void answer(void){
//   char buf[100];
//   printf("!");
//   rep(i,ress) printf(" %d", res[i]+1);
//   printf("\n");
//   fflush(stdout);
//   scanf("%s",buf);
// }
// 
// {
//   int x, y, z;
//   scanf("%d",&TEST);
//   rep(TEST){
//     scanf("%d%d",&N,&X);
//     rep(i,X){
//       scanf("%d",As+i);
//       rep(j,As[i]) scanf("%d",A[i]+j), A[i][j]--;
//     }
//     sz = N;
//     rep(i,N) q[i] = i;
//     mx = query();
// 
//     x = 0;
//     y = N - 1;
//     while(x < y){
//       z = (x + y) / 2;
//       sz = 0;
//       rep(i,x,z+1) q[sz++] = i;
//       if(query() == mx) y = z; else x = z + 1;
//     }
// 
//     ress = X;
//     rep(i,X) res[i] = mx;
//     rep(i,X) rep(j,As[i]) if(A[i][j]==x){
//       rep(k,N) ok[k] = 1;
//       rep(j,As[i]) ok[A[i][j]] = 0;
//       sz = 0;
//       rep(k,N) if(ok[k]) q[sz++] = k;
//       res[i] = query();
//       break;
//     }
//     answer();
//   }
// }