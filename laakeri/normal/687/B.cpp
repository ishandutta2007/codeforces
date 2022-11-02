#include <bits/stdc++.h>
#define F first
#define S second
#define X real()
#define Y imag()
using namespace std;
typedef long long ll;
typedef long double ld;

ll dv[1010101];

int has[1010101];
int ma[1010101];
int h[1010101];

void add(ll x, int t){
	while (x>1){
		has[dv[x]]+=t;
		x/=dv[x];
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	for (ll i=2;i<=1000000;i++){
		if (dv[i]==0){
			for (ll j=1;j*i<=1000000;j++){
				dv[i*j]=i;
			}
		}
	}
	ll n,k;
	cin>>n>>k;
	add(k, 1);
	for (int i=0;i<n;i++){
		ll x;
		cin>>x;
		h[x]=1;
	}
	for (int i=2;i<=1000000;i++){
		if (h[i]){
			int ed=0;
			int c=0;
			int x=i;
			while (x>1){
				if (dv[x]!=ed){
					c=0;
				}
				c++;
				ma[dv[x]]=max(ma[dv[x]], c);
				ed=dv[x];
				x/=dv[x];
			}
		}
	}
	for (int i=2;i<=1000000;i++){
		if (has[i]>ma[i]){
			cout<<"No\n";
			return 0;
		}
	}
	cout<<"Yes"<<endl;
}