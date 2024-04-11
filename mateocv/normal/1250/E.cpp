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

ll a[200005];
pair<ll,pair<ll,ll>> b[200005];
ll m,n,k,t; 

struct disjoint_intervals {
	set<pair<int,int> > s;
	void insert(pair<int,int> v){
		if(v.fst>=v.snd) return;
		auto at=s.lower_bound(v);auto it=at;
		if(at!=s.begin()&&(--at)->snd>=v.fst)v.fst=at->fst,--it;
		for(;it!=s.end()&&it->fst<=v.snd;s.erase(it++))
			v.snd=max(v.snd,it->snd);
		s.insert(v);
	}
};

bool can(ll mid){
	if(mid>=m)return true;
	ll ss=a[mid];
	//ll maxi=0;
	/*fore(i,0,k){
		if(b[i].fst>s)maxi=max(maxi,b[i].snd);
	}*/
	//cout<<"Tarda "<<n+1+2*maxi<<"\n";
	disjoint_intervals d;
	fore(i,0,k){
		if(b[i].fst>ss)d.insert({b[i].snd.fst,b[i].snd.snd+1});
	}
	ll tot=0;
	for(auto i:d.s){
		tot+=2*(i.snd-i.fst);
	}
	//cout<<"Tarda "<<n+1+tot<<"\n";
	return n+1+tot<=t;
}

int main(){FIN;
	cin>>m>>n>>k>>t;
	fore(i,0,m)cin>>a[i];
	sort(a,a+m);
	fore(i,0,k)cin>>b[i].snd.fst>>b[i].snd.snd>>b[i].fst;
	sort(b,b+k);
	ll l=0,r=m;
	while(l <= r) {
		ll mid = (l+r)/2;
		if (can (mid)) r=mid-1;
	  	else l=mid+1;
	  	//cout<<l<<" "<<r<<"\n";
	}
	assert(m-l>=0);
	cout<<m-l;
	return 0;
}