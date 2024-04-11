#include<bits/stdc++.h>
using namespace std;

bool DEBUG=false;

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

const int MAXN=5003;
const ll MOD=998244353;
int n,a[MAXN],same[MAXN],dp[MAXN][MAXN],f[MAXN],dp_c[MAXN][MAXN],prod[MAXN];
int add(ll a,ll b) {return (a+b)%MOD;}
int sub(ll a,ll b) {return (((a-b)%MOD)+MOD)%MOD;}
int mul(ll a,ll b) {return (a*b)%MOD;}
int qpow(ll b,ll e) {
  ll res=1;
  while(e) {
    if(e&1)res=mul(res,b);
    b=mul(b,b);
    e>>=1;
  }
  return res;
}
int divi(ll a,ll b) {return mul(a,qpow(b,MOD-2));}
int c(int n,int k) {
  assert(k<=n);
  if(n==k)return 1;
  if(k==0)return 1;
  int &res=dp_c[n][k];
  if(res!=-1)return res;
  res=add(c(n-1,k-1),c(n-1,k));
  return res;
}
int brute() {
  ll res=0;
  vector<vector<int>>tot;
  do {
    ll cur=1;
    fore(i,0,n) {
      if(i&1) {
        if(i && a[i-1]>=a[i])cur=0;
        if(i+1<n && a[i+1]>=a[i])cur=0;
      } else {
        if(i && a[i-1]<=a[i])cur=0;
        if(i+1<n && a[i+1]<=a[i])cur=0;
      }
    }
    for(int i=1;i<n;i+=2) {
      if(i+2<n && a[i+2]<=a[i])cur=0;
    }
    if(DEBUG && cur) {
      vector<int>v;
      fore(i,0,n)v.pb(a[i]);
      tot.pb(v);
    }
    res+=cur;
  } while(next_permutation(a,a+n));
  if(DEBUG) {
    assert(res==SZ(tot));
    fore(i,0,res) {
      fore(j,0,n)cout<<tot[i][j]<<" \n"[j==n-1];
    }
  }
  return res;
}

int solve(int i,int j) {
    if(i<0)return divi(f[j+1],prod[j]);
    assert(0<=j && ((i&1)==((n-1)&1)));
    if(dp[i][j] != -1)return dp[i][j];
    int have=j-i-1;
    if(DEBUG)cout<<i<<" "<<j<<" : have: "<<have<<endl;
    assert(have>=0);
    int res=0;
    if(same[j]) {
      // cout<<i<<" "<<j<<" : "<<same[j]<<" "<<have<<endl;
      // No ponerlo
      if(same[j]+1<=have)res=add(res,mul(c(have,same[j]+1),solve(i,j-same[j]-1)));
      // Ponerlo
      if(same[j]<=have)res=add(res,mul(c(have,same[j]),solve(i-2,j-same[j]-1)));
      // int val=mul(c(have,same[j]),solve(i-2,j-same[j]));

    } else {
      // No ponerlo
      if(have)res=add(res,mul(have,solve(i,j-1)));
      // ponerlo
      res=add(res,solve(i-2,j-1));
    }
    if(DEBUG)cout<<i<<" "<<j<<" : "<<res<<endl;
    return dp[i][j]=res;
}

int solve() {
  cin>>n;
  fore(i,0,n)cin>>a[i];
  if(n<=8)return brute();
  if(a[n-1]==a[n-2] || a[n-2] == a[n-3])return 0;
  fore(i,0,n+1)same[i]=0;
  fore(i,1,n)if(a[i]==a[i-1])same[i]=same[i-1]+1;
  ll p=1;
  fore(i,0,n){
    if(same[i] && !same[i+1])p=mul(p,f[same[i]+1]);
    prod[i]=p;
  }
  fore(i,0,n+1)fore(j,0,n+1)dp[i][j]=-1;
  return solve(n-5,n-3);
}

int main() {FIN;
  memset(dp_c,-1,sizeof(dp_c));
  // fore(i,0,10)fore(j,0,i+1)cout<<i<<" "<<j<<" ::: "<<c(i,j)<<endl;
  f[0]=f[1]=1;
  fore(i,2,MAXN)f[i]=mul(f[i-1],i);
  int q;cin>>q;
  while(q--){
    if(DEBUG)cout<<"Start test case"<<endl;
    cout<<solve()<<"\n";
  }
}