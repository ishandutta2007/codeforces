#include <bits/stdc++.h>
#define F first
#define S second
#define X real()
#define Y imag()
using namespace std;
typedef long long ll;
typedef long double ld;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	ll k;
	cin>>n>>k;
	map<ll, int> ss;
	ss[0]=1;
	ll su=0;
	ll v=0;
	const ll inf=2e14;
	for (int i=0;i<n;i++){
		ll a;
		cin>>a;
		su+=a;
		
		if (k==1){
			v+=(ll)ss[su-1];
		}
		else if(k==-1){
			v+=(ll)ss[su-1];
			v+=(ll)ss[su+1];
		}
		else{
			for (ll x=1;x<=inf;x*=k){
				v+=(ll)ss[su-x];
			}
		}
		
		ss[su]++;
	}
	cout<<v<<endl;
}