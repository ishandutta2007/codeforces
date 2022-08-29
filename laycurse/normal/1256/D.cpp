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
long long K;
char S[1000002];
char res[1000002];
int ress;
int main(){
  int Lj4PdHRW;
  int one;
  int KL2GvlyY = rd_int();
  for(Lj4PdHRW=(0);Lj4PdHRW<(KL2GvlyY);Lj4PdHRW++){
    int i, tU__gIr_;
    rd(N);
    rd(K);
    rd(S);
    one = ress = 0;
    for(i=(0);i<(N);i++){
      if(K==0){
        res[ress++] = S[i];
        continue;
      }
      if(S[i]=='1'){
        one++;
        continue;
      }
      if(K > one){
        res[ress++] = S[i];
        K -= one;
      }
      else{
        int FmcKpFmN, t_ynMSdg;
        for(FmcKpFmN=(0);FmcKpFmN<(one-K);FmcKpFmN++){
          res[ress++] = '1';
        }
        res[ress++] = '0';
        for(t_ynMSdg=(0);t_ynMSdg<(K);t_ynMSdg++){
          res[ress++] = '1';
        }
        K = 0;
        one = 0;
      }
    }
    for(tU__gIr_=(0);tU__gIr_<(one);tU__gIr_++){
      res[ress++] = '1';
    }
    res[ress] = '\0';
    wt_L(res);
    wt_L('\n');
  }
  return 0;
}
// cLay varsion 20191110-1

// --- original code ---
// //no-unlocked
// int N; ll K;
// char S[1000002];
// char res[1000002]; int ress;
// {
//   int one;
//   REP(rd_int()){
//     rd(N,K,S);
//     one = ress = 0;
//     rep(i,N){
//       if(K==0) res[ress++] = S[i], continue;
//       if(S[i]=='1') one++, continue;
//       if(K > one){
//         res[ress++] = S[i];
//         K -= one;
//       } else {
//         rep(one-K) res[ress++] = '1';
//         res[ress++] = '0';
//         rep(K) res[ress++] = '1';
//         K = 0;
//         one = 0;
//       }
//     }
//     rep(one) res[ress++] = '1';
//     res[ress] = '\0';
//     wt(res);
//   }
// }