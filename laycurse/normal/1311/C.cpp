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
inline void rd(char &c){
  int i;
  for(;;){
    i = getchar();
    if(i!=' '&&i!='\n'&&i!='\r'&&i!='\t'&&i!=EOF){
      break;
    }
  }
  c = i;
}
inline int rd(char c[]){
  int i;
  int sz = 0;
  for(;;){
    i = getchar();
    if(i!=' '&&i!='\n'&&i!='\r'&&i!='\t'&&i!=EOF){
      break;
    }
  }
  c[sz++] = i;
  for(;;){
    i = getchar();
    if(i==' '||i=='\n'||i=='\r'||i=='\t'||i==EOF){
      break;
    }
    c[sz++] = i;
  }
  c[sz]='\0';
  return sz;
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
int M;
char S[200000+2];
int arr[200000];
long long s;
long long res[26];
int main(){
  int Lj4PdHRW;
  int KL2GvlyY = rd_int();
  for(Lj4PdHRW=(0);Lj4PdHRW<(KL2GvlyY);Lj4PdHRW++){
    int KrdatlYV, i;
    rd(N);
    rd(M);
    rd(S);
    for(i=(0);i<(N);i++){
      S[i] -= 'a';
    }
    for(i=(0);i<(N);i++){
      arr[i] = 0;
    }
    for(i=(0);i<(26);i++){
      res[i] = 0;
    }
    for(KrdatlYV=(0);KrdatlYV<(M);KrdatlYV++){
      arr[rd_int()-1]++;
    }
    s = 1;
    for(i=(N)-1;i>=(0);i--){
      s += arr[i];
      res[S[i]] += s;
    }
    {
      int V9aVTaxx;
      if(26==0){
        putchar('\n');
      }
      else{
        for(V9aVTaxx=(0);V9aVTaxx<(26-1);V9aVTaxx++){
          wt_L(res[V9aVTaxx]);
          wt_L(' ');
        }
        wt_L(res[V9aVTaxx]);
        wt_L('\n');
      }
    }
  }
  return 0;
}
// cLay varsion 20200217-1

// --- original code ---
// //no-unlocked
// int N, M;
// char S[2d5+2];
// 
// int arr[2d5];
// ll s, res[26];
// {
//   REP(rd_int()){
//     rd(N,M,S);
//     rep(i,N) S[i] -= 'a';
//     rep(i,N) arr[i] = 0;
//     rep(i,26) res[i] = 0;
//     rep(M) arr[rd_int()-1]++;
//     s = 1;
//     rrep(i,N){
//       s += arr[i];
//       res[S[i]] += s;
//     }
//     wt(res(26));
//   }
// }