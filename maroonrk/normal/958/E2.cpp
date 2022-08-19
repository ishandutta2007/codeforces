#include <bits/stdc++.h>
#define rep(i,N) for(int i=0;i<(int)(N);i++)
#define rep1(i,N) for(int i=1;i<=(int)(N);i++)
#define show(x) cout<< #x<< " "<<(x)<<endl;
#define all(c) c.begin(),c.end()
#define chmax(x,y) x = max(x,y)
#define fs first
#define sc second
#define pb push_back

using namespace std;
using ll = long long;

using P = pair<ll,ll>;
set<P> svi,siv;
ll solve(vector<ll> v,int K){
	int N = v.size();
	ll inf = 1e18;
	rep(i,N){
		svi.insert(P(v[i],i+1));
		siv.insert(P(i+1,v[i]));
	}
	svi.insert(P(inf,0));
	siv.insert(P(0,inf));
	svi.insert(P(inf,N+1));
	siv.insert(P(N+1,inf));

	ll ans = 0;
	rep(k,K){
		P p = *svi.begin();
		ll v = p.fs;
		int i = p.sc;
		ans += v;
		siv.erase(P(i,v));
		svi.erase(P(v,i));
		auto it = siv.lower_bound(P(i,0));
		P r = *it;
		it--;
		P l = *it;
		ll nv = l.sc + r.sc - v;

		siv.erase(l);
		siv.erase(r);
		svi.erase(P(l.sc,l.fs));
		svi.erase(P(r.sc,r.fs));

		svi.insert(P(nv,i));
		siv.insert(P(i,nv));
	}
	return ans;
}

int main(){
	int K;
	int N;
	vector<ll> a;
	cin>>K>>N;
	a.resize(N);
	rep(i,N) cin>>a[i];
	sort(all(a));
	vector<ll> b;
	rep(i,N-1){
		b.pb(a[i+1]-a[i]);
	}
	cout<<solve(b,K)<<endl;
}