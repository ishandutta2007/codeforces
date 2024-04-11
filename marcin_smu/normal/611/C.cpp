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
int n,m,q;
string z[MAX];
int res1[MAX][MAX];
int res2[MAX][MAX];
int get1(int i,int j,int ii,int jj){
  i--;j--;
  return res1[ii][jj] - res1[i][jj] - res1[ii][j] + res1[i][j];
}
int get2(int i,int j,int ii,int jj){
  i--;j--;
  return res2[ii][jj] - res2[i][jj] - res2[ii][j] + res2[i][j];
}
#undef int
int main(){
#define int LL
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout<<fixed<<setprecision(11);
  cin >> n >> m;
  R(i,n)cin >> z[i];
  R(i,n)R(j,m-1){
    res1[i+1][j+1] = res1[i+1][j] + res1[i][j+1] - res1[i][j];  
    if(z[i][j]=='.' && z[i][j+1] == '.'){
      res1[i+1][j+1] ++;
    }
  }
  R(i,n-1)R(j,m){
    res2[i+1][j+1] = res2[i+1][j] + res2[i][j+1] - res2[i][j];  
    if(z[i][j]=='.' && z[i+1][j] == '.'){
      res2[i+1][j+1]++;
    }
  }
  cin >> q;
  while(q--){
    int r1,c1,r2,c2;
    cin >> r1 >> c1 >> r2 >> c2;
    cout << get1(r1,c1,r2,c2-1) + get2(r1,c1,r2-1,c2) << "\n";
  }
}