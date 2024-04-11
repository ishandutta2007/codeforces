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
template<class S, class T> inline S chmax(S &a, T b){
  if(a<b){
    a=b;
  }
  return a;
}
int N;
char S[100000+2];
int cnt1[26];
long long cnt[26][26];
int main(){
  int i;
  long long res = 0;
  N = rd(S);
  for(i=(0);i<(N);i++){
    S[i] -= 'a';
  }
  for(i=(0);i<(N);i++){
    int j;
    for(j=(0);j<(26);j++){
      cnt[j][S[i]] += cnt1[j];
    }
    cnt1[S[i]]++;
  }
  for(i=(0);i<(26);i++){
    chmax(res, cnt1[i]);
  }
  for(i=(0);i<(26);i++){
    int j;
    for(j=(0);j<(26);j++){
      chmax(res, cnt[i][j]);
    }
  }
  wt_L(res);
  wt_L('\n');
  return 0;
}
// cLay varsion 20200217-1

// --- original code ---
// //no-unlocked
// int N;
// char S[1d5+2];
// 
// int cnt1[26];
// ll cnt[26][26];
// {
//   ll res = 0;
//   rd(S@N);
//   rep(i,N) S[i] -= 'a';
// 
//   rep(i,N){
//     rep(j,26) cnt[j][S[i]] += cnt1[j];
//     cnt1[S[i]]++;
//   }
// 
//   rep(i,26) res >?= cnt1[i];
//   rep(i,26) rep(j,26) res >?= cnt[i][j];
//   wt(res);
// }