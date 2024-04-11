#include<bits/stdc++.h>
using namespace std;
void *wmem;
template<class T1, class T2> void sortA_L(int N, T1 a[], T2 b[], void *mem = wmem){
  int i;
  pair<T1, T2> *arr=(pair<T1, T2> *) mem;
  for(i=0;i<N;i++){
    arr[i].first = a[i];
    arr[i].second = b[i];
  }
  sort(arr, arr+N);
  for(i=0;i<N;i++){
    a[i] = arr[i].first;
    b[i] = arr[i].second;
  }
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
inline void wt_L(const char c[]){
  int i=0;
  for(i=0;c[i]!='\0';i++){
    putchar(c[i]);
  }
}
template<class S, class T> inline S min_L(S a,T b){
  return a<=b?a:b;
}
char memarr[96000000];
int N;
int S[300000];
int T[300000];
int ind[300000];
int ps;
int pp[300000];
int pv[300000];
int ns;
int np[300000];
int nv[300000];
int ress;
int resI[1500000];
int resJ[1500000];
int resD[1500000];
int main(){
  int i, j, k;
  wmem = memarr;
  rd(N);
  {
    int Lj4PdHRW;
    for(Lj4PdHRW=0;Lj4PdHRW<N;Lj4PdHRW++){
      rd(S[Lj4PdHRW]);
    }
  }
  {
    int KL2GvlyY;
    for(KL2GvlyY=0;KL2GvlyY<N;KL2GvlyY++){
      rd(T[KL2GvlyY]);
    }
  }
  for(i=0;i<N;i++){
    ind[i] = i+1;
  }
  sortA_L(N,S,ind);
  sort(T,T+N);
  for(i=0;i<N;i++){
    if(S[i] < T[i]){
      pp[ps] = i;
      pv[ps++] = T[i] - S[i];
    }
    else if(S[i] > T[i]){
      np[ns] = i;
      nv[ns++] = S[i] - T[i];
    }
  }
  while(ps && ns){
    if(pp[ps-1] > np[ns-1]){
      break;
    }
    k =min_L(pv[ps-1], nv[ns-1]);
    resI[ress] = ind[pp[ps-1]];
    resJ[ress] = ind[np[ns-1]];
    resD[ress] = k;
    ress++;
    pv[ps-1] -= k;
    nv[ns-1] -= k;
    if(pv[ps-1]==0){
      ps--;
    }
    if(nv[ns-1]==0){
      ns--;
    }
  }
  if(ps || ns){
    wt_L("NO");
    wt_L('\n');
  }
  else{
    wt_L("YES");
    wt_L('\n');
    wt_L(ress);
    wt_L('\n');
    for(i=0;i<ress;i++){
      wt_L(resI[i]);
      wt_L(' ');
      wt_L(resJ[i]);
      wt_L(' ');
      wt_L(resD[i]);
      wt_L('\n');
    }
  }
  return 0;
}
// cLay varsion 20190601-1

// --- original code ---
// //no-unlocked
// int N, S[3d5], T[3d5], ind[3d5];
// 
// int ps, pp[3d5], pv[3d5];
// int ns, np[3d5], nv[3d5];
// 
// int ress, resI[15d5], resJ[15d5], resD[15d5];
// {
//   int i, j, k;
// 
//   rd(N,S(N),T(N));
//   rep(i,N) ind[i] = i+1;
//   sortA(N,S,ind);
//   sort(T,T+N);
// 
//   rep(i,N){
//     if(S[i] < T[i]){
//       pp[ps] = i;
//       pv[ps++] = T[i] - S[i];
//     } else if(S[i] > T[i]){
//       np[ns] = i;
//       nv[ns++] = S[i] - T[i];
//     }
//   }
// 
//   while(ps && ns){
//     if(pp[ps-1] > np[ns-1]) break;
// 
//     k = min(pv[ps-1], nv[ns-1]);
//     resI[ress] = ind[pp[ps-1]];
//     resJ[ress] = ind[np[ns-1]];
//     resD[ress] = k;
//     ress++;
// 
//     pv[ps-1] -= k;
//     nv[ns-1] -= k;
//     if(pv[ps-1]==0) ps--;
//     if(nv[ns-1]==0) ns--;
//   }
// 
//   if(ps || ns){
//     wt("NO");
//   } else {
//     wt("YES");
//     wt(ress);
//     rep(i,ress) wt(resI[i], resJ[i], resD[i]);
//   }
// }