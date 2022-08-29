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
template<class S, class T> inline S chmin(S &a, T b){
  if(a>b){
    a=b;
  }
  return a;
}
int N;
char S[300002];
int sz;
int lis[300002];
int main(){
  int i, m;
  int k;
  int mn;
  int y;
  int f;
  int cnt;
  int res;
  int res1;
  int res2;
  int ini;
  rd(N);
  rd(S);
  k = mn = 0;
  for(i=(0);i<(N);i++){
    if(S[i]=='('){
      k++;
    }
    else{
      k--;
    }
    chmin(mn, k);
  }
  if(k){
    wt_L(0);
    wt_L('\n');
    wt_L(1);
    wt_L(' ');
    wt_L(1);
    wt_L('\n');
    return 0;
  }
  k = 0;
  res = res1 = res2 = 0;
  for(i=(0);i<(N);i++){
    if(S[i]=='('){
      k++;
    }
    else{
      k--;
    }
    if(k==mn){
      res++;
      lis[sz++] = i;
    }
  }
  ini = res;
  for(m=(0);m<(sz);m++){
    k = 0;
    if(m==sz-1){
      y =lis[0] + N;
    }
    else{
      y =lis[m+1];
    }
    f = -1;
    for(i=(lis[m]+1);i<(y);i++){
      if(S[i%N]=='('){
        k++;
      }
      else{
        k--;
      }
      if(k<2){
        f=-1;
        cnt=0;
      }
      if(k==2 && f==-1){
        f = i;
      }
      if(k==2){
        cnt++;
      }
      if(k==2 && ini+cnt > res){
        res = ini+cnt;
        res1 = f%N;
        res2 = (i+1)%N;
      }
    }
  }
  for(m=(0);m<(sz);m++){
    k = 0;
    if(m==sz-1){
      y =lis[0] + N;
    }
    else{
      y =lis[m+1];
    }
    cnt = 0;
    for(i=(lis[m]+1);i<(y);i++){
      if(S[i%N]=='('){
        k++;
      }
      else{
        k--;
      }
      if(k==1){
        cnt++;
      }
    }
    if(cnt > res){
      res = cnt;
      res1 = (lis[m]+1) % N;
      res2 = y % N;
    }
  }
  wt_L(res);
  wt_L('\n');
  wt_L(res1+1);
  wt_L(' ');
  wt_L(res2+1);
  wt_L('\n');
  return 0;
}
// cLay varsion 20191102-1

// --- original code ---
// //no-unlocked
// int N;
// char S[300002];
// 
// int sz, lis[300002];
// 
// {
//   int k, mn, y, f, cnt;
//   int res, res1, res2, ini;
//   rd(N,S);
// 
//   k = mn = 0;
//   rep(i,N){
//     if[S[i]=='(', k++, k--];
//     mn <?= k;
//   }
//   if(k){
//     wt(0);
//     wt(1,1);
//     return 0;
//   }
// 
//   k = 0;
//   res = res1 = res2 = 0;
//   rep(i,N){
//     if[S[i]=='(', k++, k--];
//     if(k==mn) res++, lis[sz++] = i;
//   }
//   ini = res;
// 
//   rep(m,sz){
//     k = 0;
//     y = if[m==sz-1, lis[0] + N, lis[m+1]];
//     f = -1;
//     rep(i,lis[m]+1,y){
//       if[S[i%N]=='(', k++, k--];
//       if(k<2) f=-1, cnt=0;
//       if(k==2 && f==-1) f = i;
//       if(k==2) cnt++;
//       if(k==2 && ini+cnt > res){
//         res = ini+cnt;
//         res1 = f%N;
//         res2 = (i+1)%N;
//       }
//     }
//   }
// 
//   rep(m,sz){
//     k = 0;
//     y = if[m==sz-1, lis[0] + N, lis[m+1]];
//     cnt = 0;
//     rep(i,lis[m]+1,y){
//       if[S[i%N]=='(', k++, k--];
//       if(k==1) cnt++;
//     }
//     if(cnt > res){
//       res = cnt;
//       res1 = (lis[m]+1) % N;
//       res2 = y % N;
//     }
//   }
// 
//   wt(res);
//   wt(res1+1,res2+1);
// }