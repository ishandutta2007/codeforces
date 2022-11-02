#include <bits/stdc++.h>
#define F first
#define S second
#define X real()
#define Y imag()
using namespace std;
typedef long long ll;
typedef long double ld;

const ll mod=998244353;

vector<int> g[202020];

ll p[202020];

ll dfs(int x, int pa){
  ll cvs=1;
  ll cs=0;
  for (int nx:g[x]){
    if (nx!=pa){
      cvs*=dfs(nx, x);
      cvs%=mod;
      cs++;
    }
  }
  ll t=(cvs*p[cs+1-(x==1)])%mod;
  //cout<<x<<" "<<t<<endl;
  return t;
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  p[0]=1;
  for (ll i=1;i<=200000;i++){
    p[i]=(p[i-1]*i)%mod;
  }
  int n;
  cin>>n;
  for (int i=0;i<n-1;i++){
    int a,b;
    cin>>a>>b;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  cout<<(dfs(1, 0)*(ll)n)%mod<<endl;
}