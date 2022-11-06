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

ll ask(ll x, ll y){
	cout<<"? "<<x+1<<" "<<y+1<<endl;
	string resp; cin>>resp;
	if(resp=="Yes")return 1;
	return 0;
}

int main(){FIN;
	ll n; cin>>n;
	vector<pair<ll,ll>> a(n);
	fore(i,0,n)cin>>a[i].fst,a[i].snd=i;
	vector<pair<ll,pair<ll,ll>>> v;
	sort(ALL(a));
	fore(i,0,n){
		fore(j,i+1,n){
			v.pb({a[j].fst-a[i].fst,{a[j].snd,a[i].snd}});
		}
	}
	sort(ALL(v));
	reverse(ALL(v));
	for(auto i:v){
		ll r=ask(i.snd.fst,i.snd.snd);
		if(r==1){
			cout<<"! "<<i.snd.fst+1<<" "<<i.snd.snd+1<<endl;
			return 0;
		}
	}
	cout<<"! 0 0"<<endl;
	return 0;
}