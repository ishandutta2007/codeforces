#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> ii;
#define fore(i,a,b) for(int i=a,ggdem=b;i<ggdem;i++)
#define FIN ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define pb push_back
#define SZ(a) ((int)(a).size())
#define ALL(a) a.begin(),a.end()
#define fst first
#define snd second

const ll INF=1e15;
ll n;
vector<vector<ll>>v={{-INF,-INF,-1},{INF,INF,-1}};
ii res[256];

ll get(ll s,ll d) {
	fore(i,0,SZ(v)) {
		if(v[i][1]>=s) {
			if(s+d-1<v[i][0])return s;
			else break;
		}
	}
	s=1;
	fore(i,0,SZ(v)) {
		if(v[i][1]>=s) {
			if(s+d-1<v[i][0])return s;
			else s=v[i][1]+1;
		}
	}
	assert(0);
	return -1;
}

int main() {FIN;
	cin>>n;
	fore(i,0,n) {
		ll s,d;cin>>s>>d;
		ll st=get(s,d);
		v.pb({st,st+d-1,i});
		sort(v.begin(),v.end());
	}
	fore(i,1,SZ(v)-1)res[v[i][2]]={v[i][0],v[i][1]};
	fore(i,0,n)cout<<res[i].fst<<" "<<res[i].snd<<"\n";
}