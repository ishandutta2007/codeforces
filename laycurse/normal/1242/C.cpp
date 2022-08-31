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
inline void wt_L(const char c[]){
  int i=0;
  for(i=0;c[i]!='\0';i++){
    putchar(c[i]);
  }
}
int K;
int N[15];
long long A[15][5000];
long long ss[15];
map<long long,int> box;
int ok[32768];
int val[32768][15];
int go[32768][15];
int tval[15];
int tgo[15];
int main(){
  int i;
  int j;
  int k;
  int bt;
  int all;
  int c;
  int cn;
  int dm;
  long long sm = 0;
  long long v;
  long long nx;
  rd(K);
  for(i=(0);i<(K);i++){
    rd(N[i]);
    {
      int Q5VJL1cS;
      for(Q5VJL1cS=(0);Q5VJL1cS<(N[i]);Q5VJL1cS++){
        rd(A[i][Q5VJL1cS]);
      }
    }
  }
  for(i=(0);i<(K);i++){
    for(j=(0);j<(N[i]);j++){
      box[A[i][j]] = i;
    }
  }
  for(i=(0);i<(K);i++){
    for(j=(0);j<(N[i]);j++){
      ss[i] += A[i][j];
    }
  }
  {
    int a2conNHc;
    long long hCmBdyQB;
    if(K==0){
      hCmBdyQB = 0;
    }
    else{
      hCmBdyQB = ss[0];
      for(a2conNHc=(1);a2conNHc<(K);a2conNHc++){
        hCmBdyQB += ss[a2conNHc];
      }
    }
    sm =hCmBdyQB;
  }
  if(sm % K){
    wt_L("No");
    wt_L('\n');
    return 0;
  }
  sm /= K;
  for(i=(0);i<(K);i++){
    for(j=(0);j<(N[i]);j++){
      int m;
      c = i;
      bt =(1<<(i));
      v = A[i][j];
      dm = 0;
      for(;;){
        nx = sm - ss[c] + v;
        if(box.count(nx)==0){
          dm = 1;
          break;
        }
        cn = box[nx];
        tval[c] = v;
        tgo[cn] = c;
        if(cn == i){
          if(nx != A[i][j]){
            dm = 1;
          }
          break;
        }
        if(((bt) &(1<<(cn)))){
          dm = 1;
          break;
        }
        v = nx;
        c = cn;
        bt |=(1<<(c));
      }
      if(dm){
        continue;
      }
      if(ok[bt]){
        continue;
      }
      ok[bt] = 1;
      for(m=(0);m<(K);m++){
        val[bt][m] = tval[m];
        go[bt][m] = tgo[m];
      }
    }
  }
  for(i=(0);i<(1<<K);i++){
    if(!ok[i]){
      for(j=((i-1)&i);j;j=((j-1)&i)){
        int x;
        k = i^j;
        if(!ok[j] || !ok[k]){
          continue;
        }
        ok[i] = 1;
        for(x=(0);x<(K);x++){
          if(((i) &(1<<(x)))){
            if(((j) &(1<<(x)))){
              val[i][x] = val[j][x];
              go[i][x] = go[j][x];
            }
            if(((k) &(1<<(x)))){
              val[i][x] = val[k][x];
              go[i][x] = go[k][x];
            }
          }
        }
        break;
      }
    }
  }
  all = (1<<K) - 1;
  if(!ok[all]){
    wt_L("No");
    wt_L('\n');
    return 0;
  }
  wt_L("Yes");
  wt_L('\n');
  for(i=(0);i<(K);i++){
    wt_L(val[all][i]);
    wt_L(' ');
    wt_L(go[all][i]+1);
    wt_L('\n');
  }
  return 0;
}
// cLay varsion 20191110-1

// --- original code ---
// //no-unlocked
// int K;
// int N[15]; ll A[15][5000], ss[15];
// 
// map<ll,int> box;
// int ok[32768], val[32768][15], go[32768][15];
// int tval[15], tgo[15];
// 
// {
//   int i, j, k, bt, all, c, cn, dm;
//   ll sm = 0, v, nx;
//   rd(K);
//   rep(i,K) rd(N[i], A[i](N[i]));
//   rep(i,K) rep(j,N[i]) box[A[i][j]] = i;
//   rep(i,K) rep(j,N[i]) ss[i] += A[i][j];
// 
//   sm = sum(ss(K));
//   if(sm % K) wt("No"), return 0;
//   sm /= K;
// 
//   rep(i,K) rep(j,N[i]){
//     c = i;
//     bt = BIT_ith(i);
//     v = A[i][j];
//     dm = 0;
//     for(;;){
//       nx = sm - ss[c] + v;
//       if(box.count(nx)==0) dm = 1, break;
//       cn = box[nx];
//       tval[c] = v;
//       tgo[cn] = c;
//       if(cn == i){
//         if(nx != A[i][j]) dm = 1;
//         break;
//       }
//       if(BIT_ith(bt, cn)) dm = 1, break;
//       v = nx;
//       c = cn;
//       bt |= BIT_ith(c);
//     }
//     if(dm) continue;
// 
//     if(ok[bt]) continue;
//     ok[bt] = 1;
//     rep(m,K) val[bt][m] = tval[m], go[bt][m] = tgo[m];
//   }
// 
//   rep(i,1<<K) if(!ok[i]){
//     for(j=((i-1)&i);j;j=((j-1)&i)){
//       k = i^j;
//       if(!ok[j] || !ok[k]) continue;
//       ok[i] = 1;
//       rep(x,K) if(BIT_ith(i,x)){
//         if(BIT_ith(j,x)) val[i][x] = val[j][x], go[i][x] = go[j][x];
//         if(BIT_ith(k,x)) val[i][x] = val[k][x], go[i][x] = go[k][x];
//       }
//       break;
//     }
//   }
// 
//   all = (1<<K) - 1;
// 
//   if(!ok[all]) wt("No"), return 0;
//   wt("Yes");
//   rep(i,K) wt(val[all][i], go[all][i]+1);
// }