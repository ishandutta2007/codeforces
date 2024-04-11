#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include<bits/stdc++.h>
using namespace std;
void*wmem;
char memarr[96000000];
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
inline void rd(string &x){
  char*buf = (char *)wmem;
  rd(buf);
  x = buf;
}
inline int rd_int(void){
  int x;
  rd(x);
  return x;
}
struct MY_WRITER{
  char buf[1048576];
  int s;
  int e;
  MY_WRITER(){
    s = 0;
    e = 1048576;
  }
  ~MY_WRITER(){
    if(s){
      fwrite(buf, 1, s, stdout);
    }
  }
}
;
MY_WRITER MY_WRITER_VAR;
void my_putchar(int a){
  if(MY_WRITER_VAR.s == MY_WRITER_VAR.e){
    fwrite(MY_WRITER_VAR.buf, 1, MY_WRITER_VAR.s, stdout);
    MY_WRITER_VAR.s = 0;
  }
  MY_WRITER_VAR.buf[MY_WRITER_VAR.s++] = a;
}
template<class T> inline void wt_L(vector<T> x);
template<class T> inline void wt_L(set<T> x);
template<class T> inline void wt_L(multiset<T> x);
template<class T1, class T2> inline void wt_L(pair<T1,T2> x);
inline void wt_L(char a){
  my_putchar(a);
}
inline void wt_L(const char c[]){
  int i=0;
  for(i=0;c[i]!='\0';i++){
    my_putchar(c[i]);
  }
}
template<class T> inline int isPalindrome(const int N, const T A[]){
  int i = 0;
  int j = N-1;
  while(i < j){
    if(A[i] != A[j]){
      return 0;
    }
    ;
    i++;
    j--;
  }
  return 1;
}
int main(){
  int Nzj9Y0kE;
  wmem = memarr;
  int bkxOPzPX = rd_int();
  for(Nzj9Y0kE=(0);Nzj9Y0kE<(bkxOPzPX);Nzj9Y0kE++){
    int i;
    int N;
    rd(N);
    string S[N];
    {
      int om7Ebh6q;
      for(om7Ebh6q=(0);om7Ebh6q<(N);om7Ebh6q++){
        rd(S[om7Ebh6q]);
      }
    }
    string tmp;
    int len;
    set<string> st;
    for(i=(0);i<(N);i++){
      if(isPalindrome(S[i].size(), S[i].c_str())){
        wt_L("YES");
        wt_L('\n');
        goto WKqLrJHZ;
      }
    }
    for(i=(0);i<(N);i++){
      len = S[i].size();
      tmp = "";
      tmp += S[i][len-1];
      tmp += S[i][len-2];
      if(st.count(tmp)){
        wt_L("YES");
        wt_L('\n');
        goto WKqLrJHZ;
      }
      if(len==2){
        int j;
        for(j=('a');j<('z'+1);j++){
          if(st.count( tmp + char(j) )){
            wt_L("YES");
            wt_L('\n');
            goto WKqLrJHZ;
          }
        }
      }
      else{
        tmp += S[i][0];
        if(st.count(tmp)){
          wt_L("YES");
          wt_L('\n');
          goto WKqLrJHZ;
        }
      }
      st.insert(S[i]);
    }
    wt_L("NO");
    wt_L('\n');
    WKqLrJHZ:;
  }
  return 0;
}
template<class T> inline void wt_L(vector<T> x){
  int fg = 0;
  for(auto a : x){
    if(fg){
      my_putchar(' ');
    }
    fg = 1;
    wt_L(a);
  }
}
template<class T> inline void wt_L(set<T> x){
  int fg = 0;
  for(auto a : x){
    if(fg){
      my_putchar(' ');
    }
    fg = 1;
    wt_L(a);
  }
}
template<class T> inline void wt_L(multiset<T> x){
  int fg = 0;
  for(auto a : x){
    if(fg){
      my_putchar(' ');
    }
    fg = 1;
    wt_L(a);
  }
}
template<class T1, class T2> inline void wt_L(pair<T1,T2> x){
  wt_L(x.first);
  my_putchar(' ');
  wt_L(x.second);
}
// cLay version 20220116-1 [+beta]

// --- original code ---
// //no-unlocked
// REP(rd_int()){
//   int @N; string @S[N], tmp; int len;
//   set<string> st;
//   rep(i,N) if(isPalindrome(S[i].size(), S[i].c_str())) wt("YES"), break_continue;
// 
//   rep(i,N){
//     len = S[i].size();
//     tmp = "";
//     tmp += S[i][len-1];
//     tmp += S[i][len-2];
//     if(st.count(tmp)) wt("YES"), break_continue;
//     if(len==2){
//       rep(j,'a','z'+1) if(st.count( tmp + char(j) )) wt("YES"), break_break_continue;
//     } else {
//       tmp += S[i][0];
//       if(st.count(tmp)) wt("YES"), break_continue;
//     }
//     st.insert(S[i]);
//   }
// 
//   wt("NO");
// }