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
inline int rd_int(void){
  int x;
  rd(x);
  return x;
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
int N;
int A;
int B;
int V;
vector<int> in[100000];
int ot[100000];
int main(){
  int Lj4PdHRW, Q5VJL1cS;
  int i;
  int k;
  long long res = 0;
  rd(N);
  int KL2GvlyY = rd_int();
  for(Lj4PdHRW=(0);Lj4PdHRW<(KL2GvlyY);Lj4PdHRW++){
    rd(A);A += (-1);
    rd(B);B += (-1);
    if(A > B){
      swap(A, B);
    }
    ;
    in[A].push_back(B);
    ot[B]++;
  }
  for(i=(0);i<(N);i++){
    res += (long long)in[i].size() * ot[i];
  }
  wt_L(res);
  wt_L('\n');
  int e98WHCEY = rd_int();
  for(Q5VJL1cS=(0);Q5VJL1cS<(e98WHCEY);Q5VJL1cS++){
    rd(V);V += (-1);
    res -= (long long)in[V].size() * ot[V];
    for(k=(0);k<(in[V].size());k++){
      i = in[V][k];
      ot[i]--;
      res -= in[i].size();
      res += ot[i];
      ot[V]++;
      in[i].push_back(V);
    }
    in[V].clear();
    wt_L(res);
    wt_L('\n');
  }
  return 0;
}
// cLay varsion 20190925-1

// --- original code ---
// //no-unlocked
// int N, A, B, V;
// vector<int> in[1d5];
// int ot[1d5];
// 
// {
//   int i, k;
//   ll res = 0;
//   
//   rd(N);
//   REP(rd_int()){
//     rd(A--,B--);
//     sortE(A,B);
//     in[A].push_back(B);
//     ot[B]++;
//   }
// 
//   rep(i,N) res += (ll)in[i].size() * ot[i];
//   wt(res);
// 
//   REP(rd_int()){
//     rd(V--);
//     res -= (ll)in[V].size() * ot[V];
//     rep(k,in[V].size()){
//       i = in[V][k];
//       ot[i]--;
//       res -= in[i].size();
//       res += ot[i];
//       ot[V]++;
//       in[i].push_back(V);
//     }
//     in[V].clear();
//     wt(res);
//   }
// }