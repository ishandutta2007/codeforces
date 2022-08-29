#pragma GCC optimize ("Ofast")
#include<bits/stdc++.h>
using namespace std;
void *wmem;
char memarr[96000000];
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
inline void rd(string &x){
  char *buf = (char *)wmem;
  rd(buf);
  x = buf;
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
inline void wt_L(unsigned x){
  int s=0;
  char f[10];
  while(x){
    f[s++]=x%10;
    x/=10;
  }
  if(!s){
    f[s++]=0;
  }
  while(s--){
    putchar(f[s]+'0');
  }
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
inline void wt_L(unsigned long long x){
  int s=0;
  char f[21];
  while(x){
    f[s++]=x%10;
    x/=10;
  }
  if(!s){
    f[s++]=0;
  }
  while(s--){
    putchar(f[s]+'0');
  }
}
inline void wt_L(double x){
  printf("%.15f",x);
}
inline void wt_L(const char c[]){
  int i=0;
  for(i=0;c[i]!='\0';i++){
    putchar(c[i]);
  }
}
inline void wt_L(string &x){
  int i=0;
  for(i=0;x[i]!='\0';i++){
    putchar(x[i]);
  }
}
int N;
int M;
string S[100];
string rs[100];
int use[100];
int arr1[100];
int arr2[100];
int sz1;
int sz2;
int main(){
  int i;
  wmem = memarr;
  string res;
  rd(N);
  rd(M);
  {
    int Lj4PdHRW;
    for(Lj4PdHRW=(0);Lj4PdHRW<(N);Lj4PdHRW++){
      rd(S[Lj4PdHRW]);
    }
  }
  for(i=(0);i<(N);i++){
    use[i] = 0;
    rs[i] = S[i];
    reverse(rs[i].begin(), rs[i].end());
  }
  sz1 = sz2 = 0;
  for(i=(0);i<(N);i++){
    int j;
    for(j=(i+1);j<(N);j++){
      if(!use[i] && !use[j] && S[i]==rs[j]){
        use[i] = use[j] = 1;
        arr1[sz1++] = i;
        arr2[sz2++] = j;
      }
    }
  }
  for(i=(0);i<(N);i++){
    if(!use[i] && S[i]==rs[i]){
      arr1[sz1++] = i;
      break;
    }
  }
  for(i=(0);i<(sz1);i++){
    res += S[arr1[i]];
  }
  for(i=(sz2)-1;i>=(0);i--){
    res += S[arr2[i]];
  }
  wt_L((int)res.size());
  wt_L('\n');
  wt_L(res);
  wt_L('\n');
  return 0;
}
// cLay varsion 20200214-1

// --- original code ---
// //no-unlocked
// int N, M;
// string S[100], rs[100];
// int use[100];
// int arr1[100], arr2[100], sz1, sz2;
// {
//     string res;
//     rd(N,M,S(N));
//     rep(i,N){
//       use[i] = 0;
//       rs[i] = S[i];
//       reverse(rs[i].begin(), rs[i].end());
//     }
// 
//     sz1 = sz2 = 0;
//     rep(i,N) rep(j,i+1,N) if(!use[i] && !use[j] && S[i]==rs[j]){
//       use[i] = use[j] = 1;
//       arr1[sz1++] = i;
//       arr2[sz2++] = j;
//     }
//     rep(i,N) if(!use[i] && S[i]==rs[i]){
//       arr1[sz1++] = i;
//       break;
//     }
//     rep(i,sz1) res += S[arr1[i]];
//     rrep(i,sz2) res += S[arr2[i]];
//     wt((int)res.size());
//     wt(res);
// }