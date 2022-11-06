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
	ll n; cin>>n;
	vector<pair<ll,ll>> v;
	ll a,b;
	fore(i,0,n){
		cin>>a>>b;
		v.pb({a,b});
	}
	sort(ALL(v));
	reverse(ALL(v));
	pair<ll,ll> tel[2]={{-1,-1},{-1,-1}};
	while(SZ(v)){
		if(tel[0].fst==-1){
			tel[0]=v.back(); v.pop_back();
		}else if(tel[1].fst==-1){
			tel[1]=v.back(); v.pop_back();
		}else{
			if(tel[0].snd>tel[1].snd)swap(tel[0],tel[1]);
			b=v.back().fst;
			if(b>tel[0].snd){
				tel[0]=v.back(); v.pop_back();
			}else{
				//cout<<b<<" "<<tel[0].snd; break;
				break;
			}
		}
	}
	if(SZ(v)){
		cout<<"NO";
	}else{
		cout<<"YES";
	}
	
	return 0;
}