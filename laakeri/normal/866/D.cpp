#include <bits/stdc++.h>
#define F first
#define S second
#define X real()
#define Y imag()
using namespace std;
typedef long long ll;
typedef long double ld;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	ll pf=0;
	int n;
	cin>>n;
	multiset<ll> h;
	for (int i=0;i<n;i++){
		ll a;
		cin>>a;
		if (h.size()==0){
			h.insert(a);
		}
		else{
			ll t=(*h.begin());
			h.erase(h.begin());
			ll pr=max(0ll, a-t);
			pf+=pr;
			h.insert(t+pr);
			h.insert(a);
		}
	}
	cout<<pf<<endl;
}