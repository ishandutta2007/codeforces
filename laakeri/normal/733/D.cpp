#include <bits/stdc++.h>
#define F first
#define S second
#define X real()
#define Y imag()
using namespace std;
typedef long long ll;
typedef long double ld;

map<pair<ll, ll>, vector<pair<ll, int> > > lol;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin>>n;
	ll v=0;
	int va=1;
	int vb=1;
	for (int i=0;i<n;i++){
		ll a,b,c;
		cin>>a>>b>>c;
		lol[{a, b}].push_back({c, i+1});
		lol[{b, a}].push_back({c, i+1});
		lol[{a, c}].push_back({b, i+1});
		lol[{c, a}].push_back({b, i+1});
		lol[{b, c}].push_back({a, i+1});
		lol[{c, b}].push_back({a, i+1});
		if (min(a, min(b, c))>v){
			v=min(a, min(b, c));
			va=i+1;
			vb=i+1;
		}
	}
	for (auto t:lol){
		sort(t.S.begin(), t.S.end());
		t.S.erase(unique(t.S.begin(), t.S.end()), t.S.end());
		if ((int)t.S.size()>=2){
			ll a=t.F.F;
			ll b=t.F.S;
			ll c=t.S[(int)t.S.size()-2].F+t.S.back().F;
			if (min(a, min(b, c))>v){
				v=min(a, min(b, c));
				va=t.S[(int)t.S.size()-2].S;
				vb=t.S.back().S;
			}
		}
	}
	if (va==vb){
		cout<<1<<endl<<va<<endl;
	}
	else{
		cout<<2<<endl<<va<<" "<<vb<<endl;
	}
}