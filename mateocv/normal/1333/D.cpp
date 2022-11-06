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

string s;

vector<ll> mov(){
	ll sk=0;
	vector<ll> res;
	fore(i,0,SZ(s)-1){
		if(sk){
			sk--; continue;
		}
		if(s[i]=='R'&&s[i+1]=='L'){
			swap(s[i],s[i+1]);
			res.pb(i); sk++;
		}
	}
	return res;
}

int main(){FIN;
	ll n,k; cin>>n>>k;
	cin>>s;
	vector<vector<ll>> res;
	fore(i,0,n*n){
		auto v=mov();
		if(SZ(v)==0)break;
		res.pb(v);
	}
	if(SZ(res)>k){
		cout<<-1;
		return 0;
	}
	vector<vector<ll>> resf;
	reverse(ALL(res));
	ll ex=k-SZ(res);
	while(ex>0){
		if(SZ(res)==0){
			cout<<-1;
			return 0;
		}
		if(SZ(res.back())==1){
			resf.pb(res.back());
			res.pop_back();
		}else{
			ll b=res.back().back();
			res[SZ(res)-1].pop_back();
			resf.pb({b});
			ex--;
		}
	}
	while(SZ(res)){
		resf.pb(res.back());
		res.pop_back();
	}
	assert(SZ(resf)==k);
	for(auto i:resf){
		cout<<SZ(i)<<" ";
		for(auto j:i)cout<<j+1<<" ";
		cout<<"\n";
	}
	
	return 0;
}