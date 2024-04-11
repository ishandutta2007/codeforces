//#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>

#define rep(i,l,r) for(int i=l;i<=r;++i)
#define repdo(i,l,r) for(int i=l;i>=r;--i)
#define il inline

using namespace std;
typedef long long ll;
typedef double db;
//-------------------------------------------
const int nsz=1e5+50;
ll n,dx1,dx2,dy1,dy2;

int main(){
	ios::sync_with_stdio(0),cin.tie(0);
	cin>>n>>dx1>>dy1>>dx2>>dy2;
	if(dx1*dy2-dy1*dx2==0){
		cout<<"NO\n";
		return 0;
	}
	ll ans=0;
	ans=abs(dx1*dy2-dy1*dx2);
	if(ans!=n){
		cout<<"NO\n";
		return 0;
	}
	cout<<"YES\n";
	while(dx2){
		dy1-=dx1/dx2*dy2;
		dx1%=dx2;
		swap(dx1,dx2);
		swap(dy1,dy2);
	}
	rep(i,0,abs(dx1)-1)rep(j,0,abs(dy2)-1)cout<<i<<' '<<j<<'\n';
}