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

ll ask(vector<ll> v){
	cout<<"? ";
	for(auto i:v)cout<<i+1<<" ";
	cout<<endl;
	ll resp; cin>>resp;
	resp--;
	return resp;
}

int main(){FIN;
	ll n; cin>>n;
	ll ul=-1;
	vector<ll> z(n),res(n);
	for(ll i=n-1;i>=0;i--){
		auto v=z;
		v[n-1]=i;
		ll br=0;
		if(ask(v)!=-1){
			ul=n-1-i;
			br++; break;
		}
		if(!br)ul=n-1;
	}
	res[n-1]=ul;
	assert(ul!=-1);
	fore(i,0,n){
		if(i!=ul){
			vector<ll> v(n);
			if(i<ul){
				fore(j,0,n-1)v[j]=ul-i;
			}else{
				v[n-1]=i-ul;
			}
			auto a=ask(v);
			assert(a!=-1);
			res[a]=i;
		}
	}
	cout<<"! ";
	for(auto i:res)cout<<i+1<<" ";
	cout<<"\n";
	
	return 0;
}