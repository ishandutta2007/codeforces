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

#define MAX 501
int n,m;
int res[MAX];
int t[MAX][MAX];
vector<int> d[MAX];
void dfs(int a,int b){
  if(res[a])return;
  res[a] = b;
  for(int ak:d[a]){
    dfs(ak,-b);
  }
}
#undef int
int main(){
#define int LL
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout<<fixed<<setprecision(11);
  
  cin >> n >> m;
//   if(m == n *(n-1) /2){
//     cout << "Yes\n";
//     R(i,n){
//       cout << "a";
//     }
//     cout << "\n";
//   }
  R(i,m){
    int a,b;
    cin >> a >> b;
    a--;b--;
    t[a][b] = t[b][a] = 1;
  }
  R(i,n)R(j,n)if(i!=j){
    if(t[i][j] == 0){
      d[i].PB(j);
    }
  }
  
  R(i,n)if(SZ(d[i]))dfs(i,1);
  
  
  R(i,n)R(j,n){
    if(i == j)continue;
    if((t[i][j] == 0) ^ (res[i] * res[j] == -1)){
      cout << "No\n";
      return 0;
    }
  }
  cout << "Yes\n";
  R(i,n){
    cout << char('b' + res[i]);
  }
  cout << "\n";
}