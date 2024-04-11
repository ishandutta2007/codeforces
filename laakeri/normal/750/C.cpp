#include <bits/stdc++.h>
#define F first
#define S second
#define X real()
#define Y imag()
using namespace std;
typedef long long ll;
typedef long double ld;

int n;
ll c[202020];
int d[202020];

int ok(ll x){
	for (int i=0;i<n;i++){
		if (d[i]==1&&x<1900){
			return -1;
		}
		if (d[i]==2&&x>=1900){
			return 1;
		}
		x+=c[i];
	}
	return 0;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	for (int i=0;i<n;i++){
		cin>>c[i]>>d[i];
	}
	int f=0;
	ll inf=1e10;
	ll mi=-inf;
	ll ma=inf;
	ll v=0;
	while (mi<=ma){
		ll mid=(mi+ma)/2;
		int o=ok(mid);
		if (o==0){
			f=1;
			v=mid;
			mi=mid+1;
		}
		else if(o==-1){
			mi=mid+1;
		}
		else{
			ma=mid-1;
		}
	}
	if (f==0){
		cout<<"Impossible"<<endl;
	}
	else if(v==inf){
		cout<<"Infinity"<<endl;
	}
	else {
		for (int i=0;i<n;i++){
			v+=c[i];
		}
		cout<<v<<endl;
	}
}