#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define pll pair<ll,ll>
void solve(){
	//fuck
	long double N,R;
	cin>>N>>R;
	long double cosine=cos(2*3.1415925358979/N);
	long double x=sqrt((1-cosine)/2);
	long double rad=R*x/(1-x);
	cout<<fixed<<setprecision(12)<<rad<<"\n";
}
	
int main(){
	ll T=1;
	//cin>>T;
	while(T--)solve();
}