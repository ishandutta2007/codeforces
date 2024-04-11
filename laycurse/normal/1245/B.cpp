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
int A;
int B;
int C;
char S[102];
char res[102];
int main(){
  int Lj4PdHRW;
  int win;
  int KL2GvlyY = rd_int();
  for(Lj4PdHRW=(0);Lj4PdHRW<(KL2GvlyY);Lj4PdHRW++){
    int i;
    rd(N);
    rd(A);
    rd(B);
    rd(C);
    rd(S);
    for(i=(0);i<(N);i++){
      res[i] = 0;
    }
    win = 0;
    for(i=(0);i<(N);i++){
      if(S[i]=='S' && A > 0){
        res[i] = 'R';
        A--;
        win++;
      }
      if(S[i]=='R' && B > 0){
        res[i] = 'P';
        B--;
        win++;
      }
      if(S[i]=='P' && C > 0){
        res[i] = 'S';
        C--;
        win++;
      }
    }
    for(i=(0);i<(N);i++){
      if(res[i]==0){
        if(A > 0){
          A--;
          res[i] = 'R';
          continue;
        }
        if(B > 0){
          B--;
          res[i] = 'P';
          continue;
        }
        if(C > 0){
          C--;
          res[i] = 'S';
          continue;
        }
      }
    }
    res[N] = '\0';
    if(2* win >= N){
      wt_L("YES");
      wt_L('\n');
      wt_L(res);
      wt_L('\n');
    }
    else{
      wt_L("NO");
      wt_L('\n');
    }
  }
  return 0;
}
// cLay varsion 20191027-1

// --- original code ---
// //no-unlocked
// int N, A, B, C;
// char S[102];
// char res[102];
// {
//   int win;
//   REP(rd_int()){
//     rd(N,A,B,C,S);
//     rep(i,N) res[i] = 0;
//     win = 0;
//     rep(i,N){
//       if(S[i]=='S' && A > 0) res[i] = 'R', A--, win++;
//       if(S[i]=='R' && B > 0) res[i] = 'P', B--, win++;
//       if(S[i]=='P' && C > 0) res[i] = 'S', C--, win++;
//     }
//     rep(i,N) if(res[i]==0){
//       if(A > 0) A--, res[i] = 'R', continue;
//       if(B > 0) B--, res[i] = 'P', continue;
//       if(C > 0) C--, res[i] = 'S', continue;
//     }
//     res[N] = '\0';
//     if[2 win >= N, wtLn("YES", res), wt("NO")];
// 
//   }
// }