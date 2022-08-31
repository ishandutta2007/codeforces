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
int N;
char S[200000+1];
int res[200000];
int main(){
  int Lj4PdHRW;
  int KL2GvlyY = rd_int();
  for(Lj4PdHRW=(0);Lj4PdHRW<(KL2GvlyY);Lj4PdHRW++){
    int i;
    int j;
    int k;
    rd(N);
    rd(S);
    j = N;
    k = 1;
    while(j){
      int m;
      i = j-1;
      while(i > 0 && S[i-1]=='<'){
        i--;
      }
      for(m=(i);m<(j);m++){
        res[m] = k++;
      }
      j = i;
    }
    {
      int KrdatlYV;
      if(N==0){
        putchar('\n');
      }
      else{
        for(KrdatlYV=(0);KrdatlYV<(N-1);KrdatlYV++){
          wt_L(res[KrdatlYV]);
          wt_L(' ');
        }
        wt_L(res[KrdatlYV]);
        wt_L('\n');
      }
    }
    j = 0;
    k = 1;
    while(j < N){
      int m;
      i = j + 1;
      while(i < N && S[i-1]=='>'){
        i++;
      }
      for(m=(i)-1;m>=(j);m--){
        res[m] = k++;
      }
      j = i;
    }
    {
      int jbtyPBGc;
      if(N==0){
        putchar('\n');
      }
      else{
        for(jbtyPBGc=(0);jbtyPBGc<(N-1);jbtyPBGc++){
          wt_L(res[jbtyPBGc]);
          wt_L(' ');
        }
        wt_L(res[jbtyPBGc]);
        wt_L('\n');
      }
    }
  }
  return 0;
}
// cLay varsion 20200214-1

// --- original code ---
// //no-unlocked
// int N;
// char S[2d5+1];
// int res[2d5];
// {
//   REP(rd_int()){
//     int i, j, k;
//     rd(N,S);
// 
//     j = N;
//     k = 1;
//     while(j){
//       i = j-1;
//       while(i > 0 && S[i-1]=='<') i--;
//       rep(m,i,j) res[m] = k++;
//       j = i;
//     }
//     wt(res(N));
// 
//     j = 0;
//     k = 1;
//     while(j < N){
//       i = j + 1;
//       while(i < N && S[i-1]=='>') i++;
//       rrep(m,j,i) res[m] = k++;
//       j = i;
//     }
//     wt(res(N));
//   }
// }