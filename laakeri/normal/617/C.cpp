#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef long double ld;

ll sq(ll x){
	return x*x;
}

ll suma[2020];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin>>n;
	ll x1,y1,x2,y2;
	cin>>x1>>y1>>x2>>y2;
	vector<pair<ll, ll> > lol(n);
	ll v=4e18;
	for (int i=0;i<n;i++){
		ll x,y;
		cin>>x>>y;
		lol[i]={sq(x1-x)+sq(y1-y), (sq(x2-x)+sq(y2-y))};
	}
	for (int i=0;i<n;i++){
		ll r1=lol[i].F;
		ll r2=0;
		for (int ii=0;ii<n;ii++){
			if (lol[ii].F>r1){
				r2=max(r2, lol[ii].S);
			}
		}
		v=min(v, r1+r2);
	}
	for (int i=0;i<n;i++){
		ll r2=lol[i].S;
		ll r1=0;
		for (int ii=0;ii<n;ii++){
			if (lol[ii].S>r2){
				r1=max(r1, lol[ii].F);
			}
		}
		v=min(v, r1+r2);
	}
	cout<<v<<endl;
}