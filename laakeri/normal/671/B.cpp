#include <bits/stdc++.h>
#define F first
#define S second
#define X real()
#define Y imag()
using namespace std;
typedef long long ll;
typedef long double ld;

ll c[505050];
int n;
ll k;

int cr(ll x){
	ll s=0;
	for (int i=0;i<n;i++){
		if (c[i]>x) s+=c[i]-x;
	}
	if (s>k){
		return 0;
	}
	return 1;
}

int cp(ll x){
	ll s=0;
	for (int i=0;i<n;i++){
		if (c[i]<x) s+=x-c[i];
	}
	if (s>k){
		return 0;
	}
	return 1;
}

int main(){
	int kkk;
	scanf("%d %d", &n, &kkk);
	k=kkk;
	ll su=0;
	for (int i=0;i<n;i++){
		int ccc;
		scanf("%d", &ccc);
		c[i]=ccc;
		su+=c[i];
	}
	ll mi=0;
	ll ma=1e9;
	ll r=1e9;
	while (mi<=ma){
		ll mid=(mi+ma)/2;
		if (cr(mid)){
			r=mid;
			ma=mid-1;
		}
		else{
			mi=mid+1;
		}
	}
	mi=0;
	ma=1e9;
	ll p=0;
	while (mi<=ma){
		ll mid=(mi+ma)/2;
		if (cp(mid)){
			p=mid;
			mi=mid+1;
		}
		else{
			ma=mid-1;
		}
	}
	if (p>=r){
		if (su%(ll)n==0){
			cout<<0<<endl;
		}
		else{
			cout<<1<<endl;
		}
	}
	else{
		cout<<r-p<<endl;
	}
}