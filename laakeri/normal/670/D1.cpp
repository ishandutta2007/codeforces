#include <bits/stdc++.h>
#define F first
#define S second
#define X real()
#define Y imag()
using namespace std;
typedef long long ll;
typedef long double ld;

ll a[101010];
ll b[101010];
ll n,k;

int test(ll x){
	ll ne=0;
	for (int i=0;i<n;i++){
		ne+=max(0ll, a[i]*x-b[i]);
		if (ne>k) return 0;
	}
	return 1;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>k;
	for (int i=0;i<n;i++){
		cin>>a[i];
	}
	for (int i=0;i<n;i++){
		cin>>b[i];
	}
	ll mi=0;
	ll ma=2e9;
	ll v=0;
	while (mi<=ma){
		ll mid=(mi+ma)/2;
		if (test(mid)){
			v=mid;
			mi=mid+1;
		}
		else{
			ma=mid-1;
		}
	}
	cout<<v<<endl;
}