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
template<class S, class T> inline int arrcmp(int As, S A[], int Bs, T B[]){
  int i;
  for(i=0;;i++){
    if(i==As && As==Bs){
      break;
    }
    if(i==As){
      return -1;
    }
    if(i==Bs){
      return 1;
    }
    if(A[i] < B[i]){
      return -1;
    }
    if(A[i] > B[i]){
      return 1;
    }
  }
  return 0;
}
char P[102];
char H[102];
char tmp[102];
int PS;
int HS;
int x;
int y;
int main(){
  int Lj4PdHRW;
  int KL2GvlyY = rd_int();
  for(Lj4PdHRW=(0);Lj4PdHRW<(KL2GvlyY);Lj4PdHRW++){
    PS = rd(P);
    HS = rd(H);
    sort(P,P+PS);
    for(x=(0);x<(HS+1);x++){
      int i;
      y = HS - x - PS;
      if(y < 0){
        break;
      }
      for(i=(0);i<(PS);i++){
        tmp[i] = H[i+x];
      }
      sort(tmp,tmp+PS);
      if(arrcmp(PS,P,PS,tmp)==0){
        wt_L("YES");
        wt_L('\n');
        goto Q5VJL1cS;
      }
    }
    wt_L("NO");
    wt_L('\n');
    Q5VJL1cS:;
  }
  return 0;
}
// cLay varsion 20191214-1

// --- original code ---
// //no-unlocked
// char P[102], H[102], tmp[102];
// int PS, HS, x, y;
// 
// {
//   REP(rd_int()){
//     rd(P@PS,H@HS);
//     sort(P,P+PS);
//     rep(x,HS+1){
//       y = HS - x - PS;
//       if(y < 0) break;
//       rep(i,PS) tmp[i] = H[i+x];
//       sort(tmp,tmp+PS);
//       if(arrcmp(PS,P,PS,tmp)==0) wt("YES"), break_continue;
//     }
//     wt("NO");
//   }
// }