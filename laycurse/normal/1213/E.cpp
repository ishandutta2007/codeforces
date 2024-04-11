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
char S[4];
char T[4];
char res[300002];
int ress;
int is_ok(void){
  int i;
  for(i=(1);i<(3*N);i++){
    if(res[i-1]==S[0] && res[i]==S[1]){
      return 0;
    }
    if(res[i-1]==T[0] && res[i]==T[1]){
      return 0;
    }
  }
  return 1;
}
int main(){
  int i, ind[3], k;
  rd(N);
  rd(S);
  rd(T);
  wt_L("YES");
  wt_L('\n');
  for(i=0;i<(3);i++){
    ind[i] = i;
  }
  do{
    ress = 0;
    for(k=0;k<(3);k++){
      for(i=0;i<(N);i++){
        res[ress++] = 'a' + ind[k];
      }
    }
    if(is_ok()){
      wt_L(res);
      wt_L('\n');
      return 0;
    }
  }
  while(next_permutation(ind,ind+3));
  do{
    ress = 0;
    for(i=0;i<(N);i++){
      for(k=0;k<(3);k++){
        res[ress++] = 'a' + ind[k];
      }
    }
    if(is_ok()){
      wt_L(res);
      wt_L('\n');
      return 0;
    }
  }
  while(next_permutation(ind,ind+3));
  return 0;
}
// cLay varsion 20190830-1

// --- original code ---
// //no-unlocked
// int N;
// char S[4], T[4];
// 
// char res[300002]; int ress;
// 
// int is_ok(void){
//   rep(i,1,3N){
//     if(res[i-1]==S[0] && res[i]==S[1]) return 0;
//     if(res[i-1]==T[0] && res[i]==T[1]) return 0;
//   }
//   return 1;
// }
// 
// {
//   int i, k;
//   int ind[3];
// 
//   rd(N,S,T);
//   wt("YES");
// 
//   rep(i,3) ind[i] = i;
//   do{
//     ress = 0;
//     rep(k,3) rep(i,N) res[ress++] = 'a' + ind[k];
//     if(is_ok()) wt(res), return 0;
//   }while(next_permutation(ind,ind+3));
// 
//   do{
//     ress = 0;
//     rep(i,N) rep(k,3) res[ress++] = 'a' + ind[k];
//     if(is_ok()) wt(res), return 0;
//   }while(next_permutation(ind,ind+3));
// 
// }