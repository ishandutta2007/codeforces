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

vector<ll> a;

vector<ll> res;

void op(ll k){
	res.pb(k);
	reverse(a.begin(),a.begin()+k);
}

void solve(ll n){
	if(n==1)return;
	ll pos=-1;
	fore(i,0,n){
		if(a[i]==n){
			pos=i;
		}
	}
	assert(pos!=-1);
	op(pos+1);
	pos=-1;
	fore(i,0,n){
		if(a[i]==n-1){
			pos=i;
		}
	}
	assert(pos!=-1);
	op(pos);
	op(n);
	pos=-1;
	fore(i,0,n){
		if(a[i]==n){
			pos=i;
		}
	}
	assert(pos!=-1);
	op(pos+1);
	op(n);
	solve(n-2);
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		a.clear();
		a.resize(n);
		fore(i,0,n)cin>>a[i];
		ll br=0;
		fore(i,0,n){
			if(!((i+a[i])&1))br++;
		}
		if(br){
			cout<<"-1\n";
			continue;
		}
		res.clear();
		solve(n);
		cout<<SZ(res)<<"\n";
		for(auto i:res)cout<<i<<" ";
		cout<<"\n";
	}
	
	return 0;
}