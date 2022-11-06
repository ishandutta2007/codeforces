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

vector<ll> v;

ll solve(ll l, ll r, ll k){
	//cout<<l<<" "<<r<<" "<<k<<"\n";
	if(k==0)return 0;
	ll ch=-1;
	fore(i,l,r-1){
		if((v[i]&k)!=(v[i+1]&k)){
			ch=i+1; break;
		}
	}
	if(ch==-1)return solve(l,r,k>>1);
	return min(solve(l,ch,k>>1)+(r-ch-1),solve(ch,r,k>>1)+(ch-l-1));
}

int main(){FIN;
	ll n; cin>>n;
	v.resize(n);
	fore(i,0,n)cin>>v[i];
	sort(ALL(v));
	cout<<solve(0,n,(1ll<<29))<<"\n";
	return 0;
}