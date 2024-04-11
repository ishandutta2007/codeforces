#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
#define fore(i,a,b) for(int i=a,ggdem=b;i<ggdem;i++)
#define FIN ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define SZ(a) ((int)(a).size())
#define ALL(a) a.begin(),a.end()
#define fst first
#define snd second
#define pb push_back
#define mset(a, b) memset(a, b, sizeof(a))


int main() {FIN;
  int n; cin >> n;
  ll c[n][n]; fore(i, 0, n) fore(j, 0, n) cin >> c[i][j];
  ll C[n][n];mset(C,0);
  fore(i, 0, n) {
    fore(j,0,n) C[i][i] += c[i][j];
    fore(j, i + 1, n) {
      C[i][j] = C[i][j-1];
      fore(l, i, j) C[i][j] -= c[l][j];
      fore(l, 0, i) C[i][j] += c[l][j];
      fore(l, j + 1, n) C[i][j] += c[l][j];
    }
  }

  ll dp[n][n][n]; mset(dp, 0);
  fore(d, 1, n) {
    int now = d, ant = d - 1;
    fore(i, 0, n) {
      fore(j, i, n) {
        if(i==j) {dp[i][j][now]=0;continue;}
        dp[i][j][now] = 2e18;
        fore(k, i, j + 1) {
          ll r = 0;
          if(i < k) r += C[i][k-1]+dp[i][k-1][ant];
          if(k < j) r += C[k+1][j]+dp[k+1][j][ant];
          dp[i][j][now]=min(dp[i][j][now],r);
        }
      }
    }
  }
  queue<pair<ii, ii>> rebuild; rebuild.push({{0,n-1},{n-1, -1}});
  int parr[n];
  while(!rebuild.empty()) {
    auto p = rebuild.front(); rebuild.pop();
    int i = p.fst.fst;
    int j = p.fst.snd;
    int now = p.snd.fst, ant = p.snd.fst - 1;
    int par = p.snd.snd;
    fore(k, i, j + 1) {
      ll r = 0;
      if(i < k) r += C[i][k-1]+dp[i][k-1][ant];
      if(k < j) r += C[k+1][j]+dp[k+1][j][ant];
      if(dp[i][j][now]==r){
        parr[k]=par;
        rebuild.push({{i,k-1},{ant,k}});
        rebuild.push({{k+1,j},{ant,k}});
        break;
      }
    }
  }
  fore(i,0,n)cout<<parr[i]+1<<" ";cout<<endl;
}