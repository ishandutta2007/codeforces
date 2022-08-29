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
template<class S, class T> inline S chmax(S &a, T b){
  if(a<b){
    a=b;
  }
  return a;
}
void solve(vector<int> a, vector<int> b){
  map<vector<int>,int> d;
  queue<vector<int>> q;
  int mx = -1;
  d[a] = 0;
  q.push(a);
  while(q.size()){
    int i;
    vector<int> x;
    int dd;
    x = q.front();
    q.pop();
    dd = d[x];
    chmax(mx, dd);
    for(i=(0);i<(x.size());i++){
      int j;
      for(j=(i+1);j<(x.size());j++){
        swap(x[i], x[j]);
        if(d.count(x)==0){
          d[x] = dd+1;
          q.push(x);
        }
        swap(x[i], x[j]);
      }
    }
  }
  int ok = 0;
  for(auto [x,dd] : d){
    if(dd == mx){
      if(b==x){
        ok = 1;
      }
    }
  }
  if(!ok){
    wt_L("DAME");
    wt_L('\n');
    exit(0);
  }
}
int main(){
  int OA9NF42T;
  int ATMZloZo = rd_int();
  for(OA9NF42T=(0);OA9NF42T<(ATMZloZo);OA9NF42T++){
    int i;
    int N;
    rd(N);
    int A[N];
    {
      int QBN4sCMC;
      for(QBN4sCMC=(0);QBN4sCMC<(N);QBN4sCMC++){
        rd(A[QBN4sCMC]);A[QBN4sCMC] += (-1);
      }
    }
    int vis[N] = {};
    vector<long long> ind[N];
    for(i=(0);i<(N);i++){
      ind[vis[A[i]]].push_back((long long)A[i]*1000000000 + i);
      vis[A[i]]++;
    }
    for(i=(0);i<(N);i++){
      int j;
      sort(ind[i].begin(), ind[i].end());
      for(j=(0);j<(ind[i].size());j++){
        vis[j] = A[ind[i][j]%1000000000];
      }
      for(j=(0);j<(ind[i].size());j++){
        A[ind[i][j]%1000000000] = vis[(j+1)%ind[i].size()];
      }
    }
    {
      int ZcmRJqJU;
      if(N==0){
        wt_L('\n');
      }
      else{
        for(ZcmRJqJU=(0);ZcmRJqJU<(N-1);ZcmRJqJU++){
          wt_L(A[ZcmRJqJU]+1);
          wt_L(' ');
        }
        wt_L(A[ZcmRJqJU]+1);
        wt_L('\n');
      }
    }
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
// cLay version 20220312-1 [+beta]

// --- original code ---
// //no-unlocked
// void solve(VI a, VI b){
//   map<VI,int> d;
//   queue<VI> q;
//   int mx = -1;
//   d[a] = 0;
//   q.push(a);
//   while(q.size()){
//     VI x;
//     int dd;
//     x = q.front(); q.pop();
//     dd = d[x];
//     mx >?= dd;
//     rep(i,x.size()) rep(j,i+1,x.size()){
//       swap(x[i], x[j]);
//       if(d.count(x)==0){
//         d[x] = dd+1;
//         q.push(x);
//       }
//       swap(x[i], x[j]);
//     }
//   }
//   int ok = 0;
//   for(auto [x,dd] : d) if(dd == mx){
// //    wt(dd,":",x);
//     if(b==x) ok = 1;
//   }
//   if(!ok) wt("DAME"), exit(0);
// }
// 
// {
//   // for(;;){
//   //   int N, A[100], vis[100] = {};
//   //   vector<ll> ind[100];
//   //   VI a, b;
//   //   N = rand()%6+1;
//   //   rep(i,N) A[i] = rand()%N;
// 
//   //   rep(i,N) a.push_back(A[i]);
//   //   rep(i,N){
//   //     ind[vis[A[i]]].push_back((ll)A[i]*1d9 + i);
//   //     vis[A[i]]++;
//   //   }
//   //   rep(i,N){
//   //     sort(ind[i].begin(), ind[i].end());
//   //     rep(j,ind[i].size()) vis[j] = A[ind[i][j]%1d9];
//   //     rep(j,ind[i].size()) A[ind[i][j]%1d9] = vis[(j+1)%ind[i].size()];
//   //   }
//   //   rep(i,N) b.push_back(A[i]);
//   //   puts("");
//   //   wt(a,":",b);
//   //   solve(a,b);
//   // }
// 
//   REP(rd_int()){
//     int @N, @A--[N], vis[N] = {};
//     vector<ll> ind[N];
//     rep(i,N){
//       ind[vis[A[i]]].push_back((ll)A[i]*1d9 + i);
//       vis[A[i]]++;
//     }
//     rep(i,N){
//       sort(ind[i].begin(), ind[i].end());
//       rep(j,ind[i].size()) vis[j] = A[ind[i][j]%1d9];
//       rep(j,ind[i].size()) A[ind[i][j]%1d9] = vis[(j+1)%ind[i].size()];
//     }
//     wt(A(N)+1);
//   }
// }