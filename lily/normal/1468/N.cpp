//#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>

#define rep(i,l,r) for(int i=l;i<=r;++i)
#define repdo(i,l,r) for(int i=l;i>=r;--i)
#define il inline

using namespace std;
typedef long long ll;
typedef double db;
//-------------------------------------------
const int nsz=5050;
ll t,c1,c2,c3,a1,a2,a3,a4,a5;
int main(){
	cin>>t;
	rep(i,1,t){
		cin>>c1>>c2>>c3;
		cin>>a1>>a2>>a3>>a4>>a5;
		if(c1<a1||c2<a2||c3<a3){
			cout<<"NO\n";
			continue;
		}
		c1-=a1,c2-=a2,c3-=a3;
		a4=max(0ll,a4-c1);
		a5=max(0ll,a5-c2);
		cout<<(a4+a5<=c3?"YES":"NO")<<'\n';
	}
}