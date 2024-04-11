#include <bits/stdc++.h>
#define F first
#define S second
#define X real()
#define Y imag()
using namespace std;
typedef long long ll;
typedef long double ld;
ll m1=1e9+7;
ll m2=1e9+9;

ll k1=53;
ll k2=83;

pair<ll, ll> ha[1010101];

int c[1010101];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n,m;
	cin>>n>>m;
	ll hh1=131237;
	ll hh2=547857;
	ll p1=48291;
	ll p2=84933;
	for (int i=0;i<n;i++){
		int g;
		cin>>g;
		set<int> id;
		for (int j=0;j<g;j++){
			int a;
			cin>>a;
			c[a]++;
			id.insert(a);
		}
		map<int, vector<int> > h;
		for (int a:id){
			h[c[a]].push_back(a);
		}
		for (auto t:h){
			hh1*=k1;
			hh2*=k1;
			hh1%=m1;
			hh2%=m2;
			p1*=k2;
			p1%=m1;
			p2*=k2;
			p2%=m2;
			for (int a:t.S){
				ha[a].F*=hh1;
				ha[a].F+=p1;
				ha[a].F%=m1;
				ha[a].S*=hh2;
				ha[a].S+=p2;
				ha[a].S%=m2;
			}
		}
		for (int a:id){
			c[a]=0;
		}
	}
	vector<pair<ll, ll> > hs;
	for (int i=1;i<=m;i++){
		hs.push_back(ha[i]);
	}
	sort(hs.begin(), hs.end());
	ll ke=1;
	ll cc=0;
	ll v=1;
	for (int i=0;i<(int)hs.size();i++){
		cc++;
		ke*=cc;
		ke%=m1;
		if (i+1==(int)hs.size()||hs[i]!=hs[i+1]){
			v*=ke;
			v%=m1;
			cc=0;
			ke=1;
		}
	}
	cout<<v<<endl;
}