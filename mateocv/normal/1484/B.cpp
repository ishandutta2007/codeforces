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

ll INF=1e18;

vector<ll> gen(ll n, ll m, ll s, ll c){
	vector<ll> res={s%m};
	while(SZ(res)<n)res.pb((res.back()+c)%m);
	return res;
}

bool ism(vector<ll> v){
	ll tot[3]={0,0,0};
	fore(i,0,SZ(v)-1){
		if(v[i]>v[i+1])tot[0]++;
		if(v[i]==v[i+1])tot[1]++;
		if(v[i]<v[i+1])tot[2]++;
	}
	fore(k,0,3)if(tot[k]==SZ(v)-1)return 1;
	return 0;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		vector<ll> a(n);
		fore(i,0,n)cin>>a[i];
		if(ism(a)){
			if(SZ(a)==1){
				cout<<"0\n";
			}else{
				ll d=a[1]-a[0];
				if(a==gen(n,INF,a[0],d)){
					cout<<"0\n";
				}else{
					cout<<"-1\n";
				}
			}
		}else{
			ll d=-1;
			fore(i,0,SZ(a)-1){
				if(a[i]<=a[i+1])d=a[i+1]-a[i];
			}
			ll m=-1;
			fore(i,0,SZ(a)-1){
				if(a[i]>=a[i+1])m=a[i]+d-a[i+1];
			}
			if(m<=0||d>=m){
				cout<<"-1\n";
				continue;
			}
			if(a==gen(n,m,a[0],d)){
				cout<<m<<" "<<d<<"\n";
			}else{
				cout<<"-1\n";
			}
		}
	}
	
	return 0;
}