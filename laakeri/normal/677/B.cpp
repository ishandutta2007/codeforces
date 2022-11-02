#include <bits/stdc++.h>
#define F first
#define S second
#define X real()
#define Y imag()
using namespace std;
typedef long long ll;
typedef long double ld;

ll a[101010];

int main() {
	ios_base::sync_with_stdio();
	cin.tie(0);
	int n;
	cin>>n;
	ll k,h;
	cin>>h>>k;
	for (int i=0;i<n;i++){
		cin>>a[i];
	}
	ll v=0;
	ll u=0;
	for (int i=0;i<n;i++){
		if (h-u<a[i]){
			ll mi=0;
			ll ma=1e9;
			ll f=1e9;
			while (mi<=ma){
				ll mid=(mi+ma)/2;
				if (h-u+mid*k>=a[i]){
					f=mid;
					ma=mid-1;
				}
				else{
					mi=mid+1;
				}
			}
			v+=f;
			u=max(0ll, u-f*k);
		}
		u+=a[i];
	}
	
	ll mi=0;
	ll ma=1e9;
	ll f=1e9;
	while (mi<=ma){
		ll mid=(mi+ma)/2;
		if (h-u+mid*k>=h){
			f=mid;
			ma=mid-1;
		}
		else{
			mi=mid+1;
		}
	}
	v+=f;
	cout<<v<<endl;
}