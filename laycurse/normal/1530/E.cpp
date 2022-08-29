#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include<bits/stdc++.h>
using namespace std;
inline int my_getchar(){
  static char buf[1048576];
  static int s = 1048576;
  static int e = 1048576;
  if(s == e && e == 1048576){
    e = fread(buf, 1, 1048576, stdin);
    s = 0;
  }
  if(s == e){
    return EOF;
  }
  return buf[s++];
}
inline void rd(int &x){
  int k;
  int m=0;
  x=0;
  for(;;){
    k = my_getchar();
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
    k = my_getchar();
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
    i = my_getchar();
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
    i = my_getchar();
    if(i!=' '&&i!='\n'&&i!='\r'&&i!='\t'&&i!=EOF){
      break;
    }
  }
  c[sz++] = i;
  for(;;){
    i = my_getchar();
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
inline void my_putchar(const int k){
  putchar(k);
}
inline void wt_L(char a){
  my_putchar(a);
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
    my_putchar('-');
  }
  while(s--){
    my_putchar(f[s]+'0');
  }
}
inline void wt_L(const char c[]){
  int i=0;
  for(i=0;c[i]!='\0';i++){
    my_putchar(c[i]);
  }
}
inline void wt_L(string &x){
  int i=0;
  for(i=0;x[i]!='\0';i++){
    my_putchar(x[i]);
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
int hist[26];
int f(string s){
  int i;
  int res = 0;
  for(i=(1);i<(s.size());i++){
    if(s.substr(0,i) == s.substr(s.size()-i)){
      res = i;
    }
  }
  return res;
}
int main(){
  int Q5VJL1cS;
  int e98WHCEY = rd_int();
  for(Q5VJL1cS=(0);Q5VJL1cS<(e98WHCEY);Q5VJL1cS++){
    int m;
    int i;
    int j;
    int k;
    int r;
    N = rd(S);
    if(0){
      int opt = 1073709056;
      int now;
      string res;
      string tmp;
      puts("---");
      sort(S,S+N);
      do{
        tmp = S;
        now = 0;
        for(i=(1);i<(tmp.size()+1);i++){
          chmax(now, f(tmp.substr(0,i)));
        }
        if(now < opt || (now == opt && tmp < res)){
          res = tmp;
          opt= now;
        }
      }
      while(next_permutation(S,S+N));
      wt_L(opt);
      wt_L('\n');
      wt_L(res);
      wt_L('\n');
    }
    sort(S,S+N);
    if(S[0]==S[N-1]){
      wt_L(S);
      wt_L('\n');
      continue;
    }
    for(i=(0);i<(26);i++){
      hist[i] = 0;
    }
    for(i=(0);i<(N);i++){
      hist[S[i]-'a']++;
    }
    for(i=(0);i<(26);i++){
      if(hist[i]==1){
        break;
      }
    }
    if(i < 26){
      for(k=(0);k<(N);k++){
        if(S[k] == 'a'+i){
          S[k] = 'a' - 1;
        }
      }
      sort(S,S+N);
      for(k=(0);k<(N);k++){
        if(S[k] == 'a'-1){
          S[k] = 'a' + i;
        }
      }
      wt_L(S);
      wt_L('\n');
      continue;
    }
    for(i=(0);i<(26);i++){
      if(hist[i]){
        break;
      }
    }
    if(hist[i] + hist[i]-2 <= N){
      k = 0;
      S[k++] = 'a' + i;
      hist[i]--;
      S[k++] = 'a' + i;
      hist[i]--;
      for(j=(i+1);j<(26);j++){
        while(hist[j]){
          S[k++] = 'a' + j;
          hist[j]--;
          if(hist[i]){
            S[k++] = 'a' + i;
            hist[i]--;
          }
        }
      }
      wt_L(S);
      wt_L('\n');
      continue;
    }
    for(j=(i+1);j<(26);j++){
      if(hist[j]){
        break;
      }
    }
    k = 0;
    S[k++] = 'a' + i;
    hist[i]--;
    S[k++] = 'a' + j;
    hist[j]--;
    for(m=(j+1);m<(26);m++){
      if(hist[m]){
        break;
      }
    }
    if(m < 26){
      while(hist[i]){
        S[k++] = 'a' + i;
        hist[i]--;
      }
      S[k++] = 'a' + m;
      hist[m]--;
      for(i=(0);i<(26);i++){
        while(hist[i]){
          S[k++] = 'a' + i;
          hist[i]--;
        }
      }
    }
    else{
      while(hist[j]){
        S[k++] = 'a' + j;
        hist[j]--;
      }
      for(i=(0);i<(26);i++){
        while(hist[i]){
          S[k++] = 'a' + i;
          hist[i]--;
        }
      }
    }
    wt_L(S);
    wt_L('\n');
  }
  return 0;
}
// cLay version 20210717-1 [beta]

// --- original code ---
// //no-unlocked
// int N;
// char S[1d5+2];
// int hist[26];
// 
// int f(string s){
//   int i, res = 0;
//   rep(i,1,s.size()){
//     if(s.substr(0,i) == s.substr(s.size()-i)) res = i;
//   }
//   return res;
// }
// 
// {
//   REP(rd_int()){
//     int i, j, k, r;
//     rd(S@N);
// 
//     if(0){
//       int opt = int_inf, now;
//       string res, tmp;
//       puts("---");
//       sort(S,S+N);
//       do{
//         tmp = S;
//         now = 0;
//         rep(i,1,tmp.size()+1) now >?= f(tmp.substr(0,i));
//         if(now < opt || (now == opt && tmp < res)) res = tmp, opt= now;
//       }while(next_permutation(S,S+N));
//       wt(opt);
//       wt(res);
//     }
// 
//     sort(S,S+N);
//     if(S[0]==S[N-1]) wt(S), continue;
//     rep(i,26) hist[i] = 0;
//     rep(i,N) hist[S[i]-'a']++;
//     rep(i,26) if(hist[i]==1) break;
//     if(i < 26){
//       rep(k,N) if(S[k] == 'a'+i) S[k] = 'a' - 1;
//       sort(S,S+N);
//       rep(k,N) if(S[k] == 'a'-1) S[k] = 'a' + i;
//       wt(S);
//       continue;
//     }
//     rep(i,26) if(hist[i]) break;
//     if(hist[i] + hist[i]-2 <= N){
//       k = 0;
//       S[k++] = 'a' + i, hist[i]--;
//       S[k++] = 'a' + i, hist[i]--;
//       rep(j,i+1,26) while(hist[j]){
//         S[k++] = 'a' + j, hist[j]--;
//         if(hist[i]) S[k++] = 'a' + i, hist[i]--;
//       }
//       wt(S);
//       continue;
//     }
//     rep(j,i+1,26) if(hist[j]) break;
//     k = 0;
//     S[k++] = 'a' + i, hist[i]--;
//     S[k++] = 'a' + j, hist[j]--;
// 
//     rep(m,j+1,26) if(hist[m]) break;
//     if(m < 26){
//       while(hist[i]) S[k++] = 'a' + i, hist[i]--;
//       S[k++] = 'a' + m, hist[m]--;
//       rep(i,26) while(hist[i]) S[k++] = 'a' + i, hist[i]--;
//     } else {
//       while(hist[j]) S[k++] = 'a' + j, hist[j]--;
//       rep(i,26) while(hist[i]) S[k++] = 'a' + i, hist[i]--;
//     }
//     wt(S);
//   }
// }