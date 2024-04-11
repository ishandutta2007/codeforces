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

vector<ll> a,b;

vector<ll> h;

ll p,q;

bool solve(ll d){
	//cout<<"solve "<<d<<endl;
	h.clear();
	p=0;
	q=d;
	auto va=a,vb=b;
	priority_queue<ll> pa,pb;
	while(SZ(va)&&SZ(vb)&&max(va.back(),vb.back())>d){
		auto maxi=max(va.back(),vb.back());
		if(maxi==va.back()){
			if(SZ(pa)&&pa.top()>maxi)return 0;
			if(SZ(pa)&&pa.top()==maxi){
				pa.pop();
				va.pop_back();
				continue;
			}
			h.pb(maxi);
			va.pop_back();
			pb.push(maxi-d);
		}else{
			if(SZ(pb)&&pb.top()>maxi)return 0;
			if(SZ(pb)&&pb.top()==maxi){
				pb.pop();
				vb.pop_back();
				continue;
			}
			h.pb(d-maxi);
			vb.pop_back();
			pa.push(maxi-d);
		}
	}
	vector<ll> fa,fb;
	while(SZ(va)){
		auto i=va.back();
		va.pop_back();
		if(SZ(pa)&&pa.top()>i)return 0;
		else if(SZ(pa)&&pa.top()==i)pa.pop();
		else fa.pb(i);
	}
	while(SZ(vb)){
		auto i=vb.back();
		vb.pop_back();
		if(SZ(pb)&&pb.top()>i)return 0;
		else if(SZ(pb)&&pb.top()==i)pb.pop();
		else fb.pb(i);
	}
	if(SZ(pa)||SZ(pb))return 0;
	assert(SZ(fa)==SZ(fb));
	sort(ALL(fa));
	sort(ALL(fb));
	reverse(ALL(fb));
	fore(i,0,SZ(fa)){
		if(fa[i]+fb[i]!=d)return 0;
		h.pb(fa[i]);
	}
	ll mini=min(p,q);
	for(auto i:h)mini=min(mini,i);
	p-=mini;
	q-=mini;
	for(auto &i:h)i-=mini;
	return 1;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		a.clear(); a.resize(n);
		b.clear(); b.resize(n);
		fore(i,0,n)cin>>a[i];
		fore(i,0,n)cin>>b[i];
		sort(ALL(a));
		sort(ALL(b));
		vector<ll> v;
		fore(i,0,n)v.pb(abs(b.back()-a[i]));
		v.pb(b.back()+a[0]);
		ll br=0;
		for(auto i:v){
			if(solve(i)){
				cout<<"YES\n";
				for(auto i:h)cout<<i<<" ";
				cout<<"\n"<<p<<" "<<q<<"\n";
				br++; break;
			}
		}
		if(!br)cout<<"NO\n";
	}
	
	return 0;
}