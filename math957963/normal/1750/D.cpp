#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define N 200010
#define MOD 998244353
#define INF (ll)1e+18
#define ll long long
#define rep(i, n) for(int i = 0; i < n; ++i)
#define rep2(i, a, b) for(int i = a; i <= b; ++i)
#define rep3(i, a, b) for(int i = a; i >= b; --i)
#define eb emplace_back
#define pb push_back
#define all(c) (c).begin(), (c).end()
#define vi vector<int>
#define pii pair<int,int>
#define pll pair<ll,ll>
struct Setup_io {
	Setup_io() {
		ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
		cout << fixed << setprecision(15);
	}
} setup_io;

vector<int>p;
vector<int>q;

void make_p(void){
  bool used[31623];
  int k=31623;
  int x;
  rep(i,k)used[i]=false;
  rep2(i,2,k){
    if(!used[i]){
      p.pb(i);
      q.pb(i*i);
      x=2*i;
      while(x<k){
        used[x]=true;
        x+=i;
      }
    }
  }
  return;
}

ll count(int k,int m){
  int sz=p.size();
  vector<int>a;
  int x,y,z;
  rep(i,sz){
    if(k<q[i])break;
    if(k%p[i]==0){
      a.pb(p[i]);
      while((k%p[i]==0))k/=p[i];
    }
  }
  if(k>1)a.pb(k);
  ll ret=0;
  sz=a.size(); 
  rep(i,(1<<sz)){
    x=i;
    y=0;
    z=1;
    rep(j,sz){
      if(x&1){
        y++;
        z*=a[j];
      }
      x=(x>>1);
    }
    if(y%2==0)ret+=(m/z);
    else ret-=(m/z);
  }
  return ret;
}


int main() {
  int t,n,m,x,pre;
  ll ans;
  make_p();
  cin>>t;
  rep(tt,t){
    cin>>n>>m;
    cin>>pre;
    ans=1;
    rep(i,n-1){
      cin>>x;
      if(ans!=0){
        if(pre%x!=0)ans=0;
        if(ans!=0){
          //cout<<ans<<endl;
          //cout<<count(pre/x,m/x)<<endl;
          ans=(ans*count(pre/x,m/x))%MOD;
        }     
      }
      pre=x;
    }
    cout<<ans<<"\n";
  }
    
	return 0;
}