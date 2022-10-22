#include<cstdio>
#include<algorithm>
#include<iostream>
using namespace std;
typedef long long ll;
int main(){
	int _; cin>>_;
	while(_--){
		ll a,b,x,y;
		scanf("%lld%lld%lld%lld",&x,&y,&a,&b);
		if(x>y) swap(x,y);
		ll ans=b*x+a*(y-x);
		cout<<min(y*b+(y-x)*a,min(ans,(x+y)*a))<<endl;
	}
	return 0;
}