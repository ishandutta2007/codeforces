#pragma GCC optimize ("Ofast")
#include<bits/stdc++.h>
using namespace std;
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
template<class S, class T> inline S chmax(S &a, T b){
  if(a<b){
    a=b;
  }
  return a;
}
char S[200002];
char T[200002];
int Slen;
int Tlen;
int dp1[200001];
int dp2[200001];
int main(){
  int i, j, res=0;
  Slen = rd(S);
  Tlen = rd(T);
  j = 0;
  for(i=0;i<(Slen);i++){
    if(j < Tlen && S[i] == T[j]){
      j++;
    }
    dp1[i] = j;
  }
  j = 0;
  for(i=Slen-1;i>=0;i--){
    if(j < Tlen && S[i] == T[Tlen-1-j]){
      j++;
    }
    dp2[i] = j;
  }
  j = 0;
  while(j+1 <= Slen && dp2[j+1] >= Tlen){
    j++;
  }
  chmax(res, j);
  for(i=0;i<(Slen);i++){
    while(j+1 <= Slen && dp1[i] + dp2[j+1] >= Tlen){
      j++;
    }
    chmax(res, j - i - 1);
  }
  wt_L(res);
  wt_L('\n');
  return 0;
}
// cLay varsion 20190820-1

// --- original code ---
// //no-unlocked
// char S[200002], T[200002];
// int Slen, Tlen;
// 
// int dp1[200001], dp2[200001];
// 
// {
//   int i, j, res = 0;
//   rd(S@Slen, T@Tlen);
// 
//   j = 0;
//   rep(i,Slen){
//     if(j < Tlen && S[i] == T[j]) j++;
//     dp1[i] = j;
//   }
// 
//   j = 0;
//   for(i=Slen-1;i>=0;i--){
//     if(j < Tlen && S[i] == T[Tlen-1-j]) j++;
//     dp2[i] = j;
//   }
// 
//   j = 0;
//   while(j+1 <= Slen && dp2[j+1] >= Tlen) j++;
//   res >?= j;
//   
//   rep(i,Slen){
//     while(j+1 <= Slen && dp1[i] + dp2[j+1] >= Tlen) j++;
//     res >?= j - i - 1;
//   }
// 
//   wt(res);
// }