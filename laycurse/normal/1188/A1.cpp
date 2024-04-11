#include<bits/stdc++.h>
using namespace std;
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
inline void wt_L(const char c[]){
  int i=0;
  for(i=0;c[i]!='\0';i++){
    putchar(c[i]);
  }
}
int N;
int deg[100000];
int main(){
  int Lj4PdHRW, i, j, k;
  rd(N);
  for(Lj4PdHRW=0;Lj4PdHRW<N-1;Lj4PdHRW++){
    rd(i);i += (-1);
    rd(j);j += (-1);
    deg[i]++;
    deg[j]++;
  }
  for(i=0;i<N;i++){
    if(deg[i]==2){
      break;
    }
  }
  if(i==N){
    wt_L("YES");
    wt_L('\n');
  }
  else{
    wt_L("NO");
    wt_L('\n');
  }
  return 0;
}
// cLay varsion 20190706-1 [beta]

// --- original code ---
// //no-unlocked
// int N, deg[1d5];
// {
//   int i, j, k;
//   rd(N);
//   rep(N-1){
//     rd(i--,j--);
//     deg[i]++;
//     deg[j]++;
//   }
//   rep(i,N) if(deg[i]==2) break;
//   wt( if[i==N, "YES", "NO"] );
// }