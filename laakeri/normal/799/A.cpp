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
	ll n,t,k,d;
	cin>>n>>t>>k>>d;
	ll t1=(n/k)*t;
	if (n%k>0) t1+=t;
	
	ll t2=t1-1;
	ll c=(t2/t)*k+((t2-d)/t)*k;
	if (c>=n){
		cout<<"YES"<<endl;
	}
	else{
		cout<<"NO"<<endl;
	}
}