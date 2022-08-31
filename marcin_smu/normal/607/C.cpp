#include <bits/stdc++.h>

using namespace std;
#define MP make_pair
#define PB push_back
#define LL long long
#define int LL
#define FI first
#define SE second
#define R(i,n) for(int i=0;i<n;i++)
#define F(i,a,b) for(int i=a;i<b;i++)
#define FD(i,n) for(int i=n-1;i>=0;i--)
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())
#define PII pair<int,int>
#define VI vector<int>
template<class C> void mini(C&a4, C b4){a4=min(a4,b4);}
template<class C> void maxi(C&a4, C b4){a4=max(a4,b4);}

template<class TH> void _dbg(const char *sdbg, TH h){cerr<<sdbg<<"="<<h<<"\n";}
template<class TH, class... TA> void _dbg(const char *sdbg, TH h, TA... a){
  while(*sdbg!=',')cerr<<*sdbg++;cerr<<"="<<h<<","; _dbg(sdbg+1,a...);
}

#ifdef LOCAL
#define debug(...) _dbg(#__VA_ARGS__, __VA_ARGS__)
#define debugv(C) {for(auto&c:C)cerr<<c<<",";cerr<<endl;}
#else
#define debug(...) (__VA_ARGS__)
#define debugv(C) {}
#define cerr if(0) cout
#endif
#define MAX 2000001
int n;
char t[300];
string z,z2;
int kmp[MAX];
#undef int
int main(){
#define int LL
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout<<fixed<<setprecision(11);
  t['S'] = 'N';
  t['N'] = 'S';
  t['E'] = 'W';
  t['W'] = 'E';
  cin >> n >> z >> z2;
  reverse(ALL(z));
  z+=z2;
  R(i,n-1)z[i] = t[z[i]]; 
  int t = 0;
  F(i,1,SZ(z)){
    while(t && z[t] != z[i]) t = kmp[t-1];
    kmp[i] = t += z[t] == z[i];
  }
  if(t)
    cout << "NO\n";
  else
    cout << "YES\n";
 
  
  
  
}