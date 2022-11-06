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
typedef int ll;

ll INF=1e9;

int main(){FIN;
	ll n,k; cin>>n>>k;
	vector<pair<ll,pair<ll,ll>>> a;
	fore(i,0,n){
		fore(j,0,n){
			ll x; cin>>x;
			a.pb({x,{i,j}});
		}
	}
	sort(ALL(a));
	reverse(ALL(a));
	vector<string> res(n);
	fore(i,0,n)res[i].resize(n);
	ll sr[2]={INF,-INF};
	ll rr[2]={INF,-INF};
	for(auto i:a){
		auto x=i.snd.fst,y=i.snd.snd;
		auto s=x+y,r=x-y;
		//cout<<sr[0]<<" "<<sr[1]<<" "<<rr[0]<<" "<<rr[1]<<"\n";
		if(sr[0]<s-k||sr[1]>s+k||rr[0]<r-k||rr[1]>r+k){
			res[x][y]='G';
		}else{
			res[x][y]='M';
			sr[0]=min(sr[0],s);
			sr[1]=max(sr[1],s);
			rr[0]=min(rr[0],r);
			rr[1]=max(rr[1],r);
		}
	}
	for(auto i:res)cout<<i<<"\n";
	
	return 0;
}