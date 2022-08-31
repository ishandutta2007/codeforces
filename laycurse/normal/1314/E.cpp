#pragma GCC optimize ("Ofast")
#include<bits/stdc++.h>
using namespace std;
#define MD (998244353U)
struct Modint{
  unsigned val;
  Modint(){
    val=0;
  }
  Modint(int a){
    val = ord(a);
  }
  Modint(unsigned a){
    val = ord(a);
  }
  Modint(long long a){
    val = ord(a);
  }
  Modint(unsigned long long a){
    val = ord(a);
  }
  inline unsigned ord(unsigned a){
    return a%MD;
  }
  inline unsigned ord(int a){
    a %= (int)MD;
    if(a < 0){
      a += MD;
    }
    return a;
  }
  inline unsigned ord(unsigned long long a){
    return a%MD;
  }
  inline unsigned ord(long long a){
    a %= (int)MD;
    if(a < 0){
      a += MD;
    }
    return a;
  }
  inline unsigned get(){
    return val;
  }
  inline Modint &operator+=(Modint a){
    val += a.val;
    if(val >= MD){
      val -= MD;
    }
    return *this;
  }
  inline Modint &operator-=(Modint a){
    if(val < a.val){
      val = val + MD - a.val;
    }
    else{
      val -= a.val;
    }
    return *this;
  }
  inline Modint &operator*=(Modint a){
    val = ((unsigned long long)val*a.val)%MD;
    return *this;
  }
  inline Modint &operator/=(Modint a){
    return *this *= a.inverse();
  }
  inline Modint operator+(Modint a){
    return Modint(*this)+=a;
  }
  inline Modint operator-(Modint a){
    return Modint(*this)-=a;
  }
  inline Modint operator*(Modint a){
    return Modint(*this)*=a;
  }
  inline Modint operator/(Modint a){
    return Modint(*this)/=a;
  }
  inline Modint operator+(int a){
    return Modint(*this)+=Modint(a);
  }
  inline Modint operator-(int a){
    return Modint(*this)-=Modint(a);
  }
  inline Modint operator*(int a){
    return Modint(*this)*=Modint(a);
  }
  inline Modint operator/(int a){
    return Modint(*this)/=Modint(a);
  }
  inline Modint operator+(long long a){
    return Modint(*this)+=Modint(a);
  }
  inline Modint operator-(long long a){
    return Modint(*this)-=Modint(a);
  }
  inline Modint operator*(long long a){
    return Modint(*this)*=Modint(a);
  }
  inline Modint operator/(long long a){
    return Modint(*this)/=Modint(a);
  }
  inline Modint operator-(void){
    Modint res;
    if(val){
      res.val=MD-val;
    }
    else{
      res.val=0;
    }
    return res;
  }
  inline operator bool(void){
    return val!=0;
  }
  inline operator int(void){
    return get();
  }
  inline operator long long(void){
    return get();
  }
  inline Modint inverse(){
    int a = val;
    int b = MD;
    int u = 1;
    int v = 0;
    int t;
    Modint res;
    while(b){
      t = a / b;
      a -= t * b;
      swap(a, b);
      u -= t * v;
      swap(u, v);
    }
    if(u < 0){
      u += MD;
    }
    res.val = u;
    return res;
  }
  inline Modint pw(unsigned long long b){
    Modint a(*this);
    Modint res;
    res.val = 1;
    while(b){
      if(b&1){
        res *= a;
      }
      b >>= 1;
      a *= a;
    }
    return res;
  }
  inline bool operator==(int a){
    return ord(a)==val;
  }
  inline bool operator!=(int a){
    return ord(a)!=val;
  }
}
;
inline Modint operator+(int a, Modint b){
  return Modint(a)+=b;
}
inline Modint operator-(int a, Modint b){
  return Modint(a)-=b;
}
inline Modint operator*(int a, Modint b){
  return Modint(a)*=b;
}
inline Modint operator/(int a, Modint b){
  return Modint(a)/=b;
}
inline Modint operator+(long long a, Modint b){
  return Modint(a)+=b;
}
inline Modint operator-(long long a, Modint b){
  return Modint(a)-=b;
}
inline Modint operator*(long long a, Modint b){
  return Modint(a)*=b;
}
inline Modint operator/(long long a, Modint b){
  return Modint(a)/=b;
}
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
inline void wt_L(Modint x){
  int i;
  i = (int)x;
  wt_L(i);
}
int N;
int K;
Modint dp[2222][2222];
int vis[2222][2222];
vector<vector<int>> now;
vector<vector<int>> nx;
Modint solve2(int l, int r){
  int i;
  int c = 0;
  Modint res = 0;
  if(vis[l][r]){
    return dp[l][r];
  }
  if(r != N){
    res += 1;
  }
  for(i=(1);i<(l+1);i++){
    c += i;
    if(c > r){
      break;
    }
    res += solve2(i,r-c);
  }
  vis[l][r] = 1;
  return dp[l][r] = res;
}
int a[100000];
int as;
int solve3(vector<int> &v){
  int k;
  int fg;
  long long s;
  if(v.size()){
    int i;
    s = as = 0;
    for(i=(v.size())-1;i>=(0);i--){
      int cTE1_r3A;
      for(cTE1_r3A=(0);cTE1_r3A<(v[i]);cTE1_r3A++){
        a[as++] = v.size() - i;
      }
    }
    for(i=(as)-1;i>=(0);i--){
      s += a[i] * (as - i);
    }
    if(s > N){
      return 0;
    }
    now.push_back(v);
  }
  k = 1;
  if(v.size()){
    k = v.back();
  }
  do{
    v.push_back(k);
    fg = solve3(v);
    v.pop_back();
    k++;
  }
  while(fg);
  return 1;
}
vector<int> evolution(vector<int> v){
  int i;
  int j;
  int N = v.size();
  vector<int> res;
  for(i=(0);i<(N);i++){
    j = 1;
    while(i + 1 < v.size() && v[i+1] == v[i]){
      i++;
      j++;
    }
    res.push_back(j);
  }
  sort(res.begin(), res.end());
  return res;
}
int main(){
  int iMWUTgY_;
  vector<int> emp;
  Modint res = 0;
  rd(N);
  rd(K);
  if(K==1){
    int i;
    for(i=(1);i<(2222);i++){
      int j;
      dp[i][i] = 1;
      for(j=(i)-1;j>=(1);j--){
        dp[i][j] = dp[i][j+1];
        if(i-j >= 1){
          dp[i][j] += dp[i-j][j];
        }
      }
    }
    for(i=(1);i<(N+1);i++){
      res += dp[i][1];
    }
    wt_L(res);
    wt_L('\n');
    return 0;
  }
  if(K==2){
    res = solve2(N,N);
    wt_L(res);
    wt_L('\n');
    return 0;
  }
  solve3(emp);
  for(iMWUTgY_=(0);iMWUTgY_<(K-3);iMWUTgY_++){
    int i;
    nx.clear();
    for(i=(0);i<(now.size());i++){
      nx.push_back(evolution(now[i]));
    }
    sort(nx.begin(), nx.end());
    now.clear();
    for(i=(0);i<(nx.size());i++){
      if(i==0 || nx[i]!=nx[i-1]){
        now.push_back(nx[i]);
      }
    }
  }
  res = (int)now.size();
  wt_L(res);
  wt_L('\n');
  return 0;
}
// cLay varsion 20200217-1

// --- original code ---
// //no-unlocked
// #define MD 998244353
// 
// int N, K;
// 
// Modint dp[2222][2222];
// int vis[2222][2222];
// 
// vector<vector<int>> now;
// vector<vector<int>> nx;
// 
// Modint solve2(int l, int r){
//   int i, c = 0;
//   Modint res = 0;
//   if(vis[l][r]) return dp[l][r];
// 
//   if(r != N) res += 1;
//   rep(i,1,l+1){
//     c += i;
//     if(c > r) break;
//     res += solve2(i,r-c);
//   }
// 
//   vis[l][r] = 1;
//   return dp[l][r] = res;
// }
// 
// int a[1d5], as;
// int solve3(vector<int> &v){
//   int k, fg;
//   ll s;
// 
//   if(v.size()){
//     s = as = 0;
//     rrep(i,v.size()) rep(v[i]) a[as++] = v.size() - i;
//     rrep(i,as) s += a[i] * (as - i);
//     //wt(v(v.size()),":",s,N);
//     if(s > N) return 0;
//     now.push_back(v);
//   }
// 
//   k = 1;
//   if(v.size()) k = v.back();
// 
//   do{
//     v.push_back(k);
//     fg = solve3(v);
//     v.pop_back();
//     k++;
//   } while(fg);
// 
//   return 1;
// }
// 
// vector<int> evolution(vector<int> v){
//   int i, j, N = v.size();
//   vector<int> res;
// 
//   rep(i,N){
//     j = 1;
//     while(i + 1 < v.size() && v[i+1] == v[i]) i++, j++;
//     res.push_back(j);
//   }
//   sort(res.begin(), res.end());
//   return res;
// }
// 
// 
// {
//   vector<int> emp;
//   Modint res = 0;
//   rd(N,K);
// 
//   if(K==1){
//     rep(i,1,2222){
//       dp[i][i] = 1;
//       rrep(j,1,i){
//         dp[i][j] = dp[i][j+1];
//         if(i-j >= 1) dp[i][j] += dp[i-j][j];
//       }
//     }
//     rep(i,1,N+1) res += dp[i][1];
//     wt(res);
//     return 0;
//   }
// 
//   if(K==2){
//     res = solve2(N,N);
//     wt(res);
//     return 0;
//   }
// 
//   solve3(emp);
//   rep(K-3){
//     nx.clear();
//     rep(i,now.size()) nx.push_back(evolution(now[i]));
//     sort(nx.begin(), nx.end());
//     now.clear();
//     rep(i,nx.size()) if(i==0 || nx[i]!=nx[i-1]) now.push_back(nx[i]);
//   }
//   res = (int)now.size();
//   wt(res);
// }