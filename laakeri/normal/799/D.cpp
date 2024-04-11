#include <bits/stdc++.h>
#define F first
#define S second
#define X real()
#define Y imag()
using namespace std;
typedef long long ll;
typedef long double ld;

const int inf=1e9;

int cnt[101010];

vector<ll> szs;

ll a,b;

int ans=inf;

int ok(ll w, ll h){
	if (a<=w&&b<=h) return 1;
	if (a<=h&&b<=w) return 1;
	return 0;
}

void go(ll w, ll h, int i, int c){
	if (ok(w, h)) {
		ans=min(ans, c);
		return;
	}
	if (i>=(int)szs.size()) return;
	
	ll nw=w;
	ll tx=szs[i];
	for (int t1=0;t1<=cnt[szs[i]];t1++){
		ll nh=h;
		for (int t2=0;t2+t1<=cnt[szs[i]];t2++){
			if (ok(nw, nh)){
				go(nw, nh, i+1, c+t1+t2);
				break;
			}
			else{
				if (t1+t2==cnt[szs[i]]){
					go(nw, nh, i+1, c+t1+t2);
				}
			}
			if (nh>a&&nh>b) break;
			nh*=tx;
		}
		if (nw>a&&nw>b) break;
		nw*=tx;
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	ll w,h;
	cin>>a>>b>>w>>h;
	if (a<=w&&b<=h) ans=0;
	if (a<=h&&b<=w) ans=0;
	
	int n;
	cin>>n;
	
	for (int i=0;i<n;i++){
		ll s;
		cin>>s;
		cnt[s]++;
		szs.push_back(s);
	}
	sort(szs.rbegin(), szs.rend());
	szs.erase(unique(szs.begin(), szs.end()), szs.end());
	
	go(w, h, 0, 0);
	
	if (ans>=inf){
		cout<<-1<<endl;
	}
	else{
		cout<<ans<<endl;
	}
}