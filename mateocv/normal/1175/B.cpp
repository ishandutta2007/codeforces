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

int main(){FIN;
	ll l; cin>>l;
	ll res=0;
	ll maxn=(((1ll<<30)-1)*2+1)*2+1;
	string s;
	vector<pair<ll,ll>> v;
	 	while(l--){
		cin>>s;
		if(s=="add"){
			if(SZ(v)==0){
				res++;
				if(res>maxn){
					cout<<"OVERFLOW!!!"; return 0;
				}
			}else{
				v[SZ(v)-1].snd++;
				if(v[SZ(v)-1].snd>maxn){
					cout<<"OVERFLOW!!!"; return 0;
				}
			}
		}else if(s=="end"){
			pair<ll,ll> b=v.back(); v.pop_back();
			if(SZ(v)==0){
				res+=b.fst*b.snd;
				if(res>maxn){
					cout<<"OVERFLOW!!!"; return 0;
				}	
			}else
			if(v.back().snd+b.fst*b.snd<=maxn)v[SZ(v)-1].snd+=b.fst*b.snd;
			else{
				cout<<"OVERFLOW!!!"; return 0;
			}
		}else if(s=="for"){
			ll n; cin>>n;
			v.pb({n,0});
		}
	}
	cout<<res;
	
	return 0;
}