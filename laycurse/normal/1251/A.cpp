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
inline void wt_L(const char c[]){
  int i=0;
  for(i=0;c[i]!='\0';i++){
    putchar(c[i]);
  }
}
int N;
char S[502];
int ok[26];
int ress;
char res[27];
int main(){
  int Lj4PdHRW;
  int KL2GvlyY = rd_int();
  for(Lj4PdHRW=(0);Lj4PdHRW<(KL2GvlyY);Lj4PdHRW++){
    int i;
    N = rd(S);
    for(i=(0);i<(N);i++){
      S[i] -= 'a';
    }
    for(i=(0);i<(26);i++){
      ok[i] = 0;
    }
    while(N){
      if(N >= 2 && S[N-1] == S[N-2]){
        N-=2;
        continue;
      }
      ok[S[--N]] = 1;
    }
    ress = 0;
    for(i=(0);i<(26);i++){
      if(ok[i]){
        res[ress++] = 'a' + i;
      }
    }
    res[ress] = '\0';
    wt_L(res);
    wt_L('\n');
  }
  return 0;
}
// cLay varsion 20191108-1

// --- original code ---
// //no-unlocked
// int N;
// char S[502];
// int ok[26];
// int ress; char res[27];
// {
//   REP(rd_int()){
//     rd(S@N);
//     rep(i,N) S[i] -= 'a';
//     rep(i,26) ok[i] = 0;
//     while(N){
//       if(N >= 2 && S[N-1] == S[N-2]) N-=2, continue;
//       ok[S[--N]] = 1;
//     }
//     ress = 0;
//     rep(i,26) if(ok[i]) res[ress++] = 'a' + i;
//     res[ress] = '\0';
//     wt(res);
//   }
// }