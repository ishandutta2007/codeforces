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

vector<pair<ll,ll>> v;

vector<ll> pref={0};

void push(ll val){
	ll hay=1;
	while(SZ(v)&&v.back().fst<=val){
		hay+=v.back().snd;
		v.pop_back();
		pref.pop_back();
	}
	v.pb({val,hay});
	pref.pb(pref.back()+v.back().fst*v.back().snd);
}

void pop(ll val){
	assert(v.back().fst==val);
	auto b=v.back();
	v.pop_back();
	pref.pop_back();
	b.snd--;
	if(b.snd){
		v.pb(b);
		pref.pb(pref.back()+v.back().fst*v.back().snd);
	}
}

int main(){FIN;
	ll n; cin>>n;
	cin>>s;
	ll res=0,va=0;
	fore(i,0,n){
	/*	cout<<"v:\n";
		for(auto i:v)cout<<i.fst<<" "<<i.snd<<"\n";
		cout<<"pref:\n";
		for(auto i:pref)cout<<i<<" "; cout<<"\n\n";*/
		if(s[i]=='0'){
			fore(i,0,va+1){
				push(va-i);
			}
			va=0;
		}else{
			va++;
			push(va);
			pop(va);
			res+=va*(va+1)/2;
		}
		res+=pref.back();
	}
	cout<<res<<"\n";
	
	return 0;
}