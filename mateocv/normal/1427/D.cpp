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

vector<vector<ll>> res;
vector<ll> prov;

ll a[60];

vector<vector<ll>> vv;

void apl(vector<ll> v){
	/*cout<<"apl ";
	for(auto i:v)cout<<i<<" ";
	cout<<":\n";*/
	vv.clear();
	ll va=0;
	vector<ll> vva;
	for(auto i:v){
		vva.clear();
		fore(j,0,i){
			vva.pb(a[va]);
			va++;
		}
		vv.pb(vva);
	}
	reverse(ALL(vv));
/*	for(auto i:vv){
		for(auto j:i)cout<<j<<" ";
		cout<<"\n";
	}*/
	va=0;
	for(auto i:vv){
		fore(j,0,SZ(i)){
			a[va]=i[j];
			va++;
		}
	}
}

int main(){FIN;
	ll n; cin>>n;
	fore(i,0,n)cin>>a[i],a[i]--;
	fore(i,0,n-1){
		ll ub=-1;
		fore(j,0,n){
			if(a[j]==i){
				ub=j;
				break;
			}
		}
		assert(ub!=-1);
		if(i&1){
			prov.clear();
			fore(j,0,i)prov.pb(1);
			prov.pb(ub-i+1);
			if(prov.back()==0)prov.pop_back();
			prov.pb(n-ub-1);
			if(prov.back()==0)prov.pop_back();
			if(SZ(prov)>1)res.pb(prov);
			apl(prov);
		}else{
			prov.clear();
			prov.pb(ub);
			if(prov.back()==0)prov.pop_back();
			prov.pb(n-i-ub);
			if(prov.back()==0)prov.pop_back();
			fore(j,0,i)prov.pb(1);
			if(SZ(prov)>1)res.pb(prov);
		/*	cout<<"Antes:\n";
			fore(i,0,n)cout<<a[i]<<" "; cout<<"\n";*/
			apl(prov);
		/*	cout<<"Desp:\n";
			fore(i,0,n)cout<<a[i]<<" "; cout<<"\n";*/
		}
	}
	if(a[0]!=0){
		prov.clear();
		fore(i,0,n)prov.pb(1);
		res.pb(prov);
	}
	assert(SZ(res)<=n);
	cout<<SZ(res)<<"\n";
	for(auto i:res){
		cout<<SZ(i)<<" ";
		for(auto j:i)cout<<j<<" ";
		cout<<"\n";
	}
	
	return 0;
}