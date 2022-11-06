#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;

const ll MOD=1000000007;

ll be(ll b, ll e, ll mod){
  ll r=1;
  while(e)if(e&1)r=(r*b)%mod,e^=1; else b=(b*b)%mod,e/=2;
  return r;
}

int main(){FIN;
	ll n,m; cin>>n>>m;
	ll a[n],b[m];
	fore(i,0,n)cin>>a[i];
	fore(i,0,m)cin>>b[i];
	char t[n][m];
	fore(i,0,n){
		fore(j,0,m){
			t[i][j]='.';
		}
	}
	fore(i,0,n){
		fore(j,0,a[i]){
			t[i][j]='1';
		}
		if(a[i]<m)t[i][a[i]]='0';
	}
	fore(j,0,m){
		fore(i,0,b[j]){
			if(t[i][j]=='0'){
				cout<<0; return 0;
			}
			t[i][j]='1';
		}
		if(b[j]<n){
			if(t[b[j]][j]=='1'){
				cout<<0; return 0;
			}
			t[b[j]][j]='0';	
		}
	}
	ll cont=0;
	fore(i,0,n){
		fore(j,0,m){
			if(t[i][j]=='.')cont++;
		}
	}
	cout<<be(2,cont,MOD);
	return 0;
}