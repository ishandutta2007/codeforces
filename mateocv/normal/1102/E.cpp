#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ThxDem=b;i<ThxDem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;

map<ll,ll> m;
map<ll,ll> va;

ll be(ll b, ll e, ll mod){
  ll r=1;
  while(e)if(e&1)r=(r*b)%mod,e^=1; else b=(b*b)%mod,e/=2;
  return r;
}

int main(){FIN;
	ll n; cin>>n;
	ll a[n];
	fore(i,0,n)cin>>a[i];
	fore(i,0,n)m[a[i]]++;
	vector<ll>v;
	fore(i,0,n){
		va[a[i]]++;
		if(m[a[i]]>1){
			if(va[a[i]]==1)v.pb(a[i]);
			if(va[a[i]]==m[a[i]])v.pb(a[i]);
		}else{
			v.pb(-1);
		}
	}
	ll tot=0,res=0;
	va.clear();
	fore(i,0,SZ(v)){
		if(i>0&&tot==0&&v[i]==-1)res++;
		if(i>0&&tot==0&&v[i]!=-1){
			res++; tot++; va[v[i]]=1;
		}
		else if(tot==0&&v[i]==-1);
		else if(tot==0&&v[i]!=-1){
			tot++; va[v[i]]=1;
		}
		else if(v[i]!=-1){
			if(va.count(v[i])){
				tot--; va.erase(v[i]);
			}else{
				tot++; va[v[i]]=1; 
			}
		}
	}
	cout<<be(2,res,998244353);
	
	return 0;
}