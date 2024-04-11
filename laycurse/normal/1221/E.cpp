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
template<class S, class T> inline S chmax(S &a, T b){
  if(a<b){
    a=b;
  }
  return a;
}
int N;
int A;
int B;
char S[300003];
int sz;
int len[300000];
int mx;
int cnt;
int fg[3];
int main(){
  int Lj4PdHRW;
  int i;
  int j;
  int k;
  int KL2GvlyY = rd_int();
  for(Lj4PdHRW=(0);Lj4PdHRW<(KL2GvlyY);Lj4PdHRW++){
    rd(A);
    rd(B);
    N = rd(S);
    S[N++] = 'X';
    mx = 0;
    sz = 0;
    k = -1;
    for(i=(0);i<(N);i++){
      if(S[i]=='X'){
        chmax(mx, i-k-1);
        len[sz++] = i-k-1;
        k = i;
      }
    }
    fg[0] = fg[1] = fg[2] = 0;
    for(i=(0);i<(mx-A+1);i++){
      j = mx - i - A;
      if(B <= i  &&  i < A || i >= 2*B){
        continue;
      }
      if(B <= j  &&  j < A || j >= 2*B){
        continue;
      }
      if(i>=A){
        if(j>=A){
          fg[1+1] = 1;
        }
        else{
          fg[1+0] = 1;
        }
      }
      else{
        if(j>=A){
          fg[0+1] = 1;
        }
        else{
          fg[0+0] = 1;
        }
      }
    }
    cnt = 0;
    for(i=(0);i<(sz);i++){
      if(len[i] == mx){
        mx = -1;
        continue;
      }
      if(B <= len[i]  &&  len[i] < A || len[i] >= 2*B){
        cnt = -1;
        break;
      }
      if(len[i] >= A){
        cnt++;
      }
    }
    if(cnt==-1){
      wt_L("NO");
      wt_L('\n');
      continue;
    }
    for(i=(0);i<(3);i++){
      if(fg[i] && (cnt+i)%2 == 0){
        break;
      }
    }
    if(i==3){
      wt_L("NO");
      wt_L('\n');
    }
    else{
      wt_L("YES");
      wt_L('\n');
    }
  }
  return 0;
}
// cLay varsion 20190921-1

// --- original code ---
// //no-unlocked
// int N, A, B;
// char S[300003];
// 
// int sz, len[3d5], mx, cnt;
// int fg[3];
// {
//   int i, j, k;
//   REP(rd_int()){
//     rd(A,B,S@N);
//     S[N++] = 'X';
// 
//     mx = 0;
//     sz = 0;
//     k = -1;
//     rep(i,N) if(S[i]=='X'){
//       mx >?= i-k-1;
//       len[sz++] = i-k-1;
//       k = i;
//     }
// 
//     fg[0] = fg[1] = fg[2] = 0;
//     rep(i,mx-A+1){
//       j = mx - i - A;
//       if(B <= i < A || i >= 2B) continue;
//       if(B <= j < A || j >= 2B) continue;
//       fg[ if[i>=A,1,0] + if[j>=A,1,0] ] = 1;
//     }
// 
//     cnt = 0;
//     rep(i,sz){
//       if(len[i] == mx) mx = -1, continue;
//       if(B <= len[i] < A || len[i] >= 2B) cnt = -1, break;
//       if(len[i] >= A) cnt++;
//     }
// 
//     if(cnt==-1) wt("NO"), continue;
//     rep(i,3) if(fg[i] && (cnt+i)%2 == 0) break;
//     wt( if[i==3, "NO", "YES"] );
//   }
// }