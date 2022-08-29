#pragma GCC optimize ("Ofast")
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
  int i, sz=0;
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
char S;
char res[11];
int main(){
  int Lj4PdHRW, i, j, k;
  rd(N);
  for(Lj4PdHRW=0;Lj4PdHRW<(N);Lj4PdHRW++){
    rd(S);
    if(S=='L'){
      for(i=0;i<(10);i++){
        if(res[i]==0){
          res[i]=1;
          break;
        }
      }
    }
    else if(S=='R'){
      for(i=0;i<(10);i++){
        if(res[9-i]==0){
          res[9-i]=1;
          break;
        }
      }
    }
    else{
      res[S-'0'] = 0;
    }
  }
  for(i=0;i<(10);i++){
    res[i] += '0';
  }
  wt_L(res);
  wt_L('\n');
  return 0;
}
// cLay varsion 20190820-1

// --- original code ---
// //no-unlocked
// int N; char S;
// char res[11];
// {
//   int i, j, k;
// 
//   rd(N);
//   rep(N){
//     rd(S);
//     if(S=='L'){
//       rep(i,10) if(res[i]==0){ res[i]=1; break; }
//     } else if(S=='R'){
//       rep(i,10) if(res[9-i]==0){ res[9-i]=1; break; }
//     } else {
//       res[S-'0'] = 0;
//     }
//   }
// 
//   rep(i,10) res[i] += '0';
//   wt(res);
// }