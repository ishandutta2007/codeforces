#include<bits/stdc++.h>
using namespace std;
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
inline void wt_L(long long x){
  char f[20];
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
char S[1000001];
int N;
int cnt[1000001];
int main(){
  int i, j, k;
  long long res=0;
  N = rd(S);
  k = 0;
  for(i=0;i<N;i++){
    if(S[i]=='v'){
      if(S[i+1]=='v'){
        S[k++] = 'w';
      }
    }
    else{
      S[k++] = S[i];
    }
  }
  N = k;
  for(i=0;i<N;i++){
    if(S[i]=='w'){
      cnt[i+1] = cnt[i]+1;
    }
    else{
      cnt[i+1] = cnt[i];
    }
  }
  for(i=0;i<N;i++){
    if(S[i]=='o'){
      res += (long long)cnt[i] * (cnt[N] - cnt[i]);
    }
  }
  wt_L(res);
  wt_L('\n');
  return 0;
}
// cLay varsion 20190721-1

// --- original code ---
// //no-unlocked
// char S[1000001]; int N;
// 
// int cnt[1000001];
// {
//   int i, j, k;
//   ll res = 0;
//   rd(S@N);
// 
//   k = 0;
//   rep(i,N){
//     if(S[i]=='v'){
//       if(S[i+1]=='v') S[k++] = 'w';
//     } else {
//       S[k++] = S[i];
//     }
//   }
//   N = k;
// 
//   rep(i,N) cnt[i+1] = cnt[i] if[S[i]=='w', +1];
// 
//   rep(i,N) if(S[i]=='o'){
//     res += (ll)cnt[i] * (cnt[N] - cnt[i]);
//   }
// 
//   wt(res);
// }