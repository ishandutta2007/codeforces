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

const int MAXN=100005;

ll a[MAXN];

vector<vector<pair<ll,ll>>> v;

int main(){FIN;
	ll n; cin>>n;
	fore(i,0,n)cin>>a[i];
	pair<ll,ll> ul={-1,0};
	vector<pair<ll,ll>> vp;
	fore(i,0,n){
		if(a[i]==ul.fst)ul.snd++;
		else{
			if(ul.fst!=-1)vp.pb(ul);
			ul.fst=a[i];
			ul.snd=1;
		}
	}
	vp.pb(ul);
	ll res=0;
	for(auto i:vp){
		if(i.snd==1)res++;
		else res+=2;
	}
	vector<pair<ll,ll>> va;
	for(auto i:vp){
		if(i.snd>=2){
			if(SZ(va))v.pb(va);
			va.clear();
			va.pb(i);
		}else{
			va.pb(i);
		}
	}
	v.pb(va);
	fore(i,0,SZ(v)-1){
		ll ult=v[i][0].fst;
		if(v[i][0].snd==1)ult=-1;
		ll br=0;
		fore(j,1,SZ(v[i])-1){
			if(v[i][j].fst!=ult&&v[i][j+1].fst!=ult)br++;
		}
		if(ult==v[i+1][0].fst&&!br)res--;
	}
	cout<<res<<"\n";
	
	return 0;
}