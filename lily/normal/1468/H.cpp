//#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>

#define rep(i,l,r) for(int i=l;i<=r;++i)
#define repdo(i,l,r) for(int i=l;i>=r;--i)
#define il inline

using namespace std;
typedef long long ll;
typedef double db;
//-------------------------------------------
const int nsz=5e5+50;
int t;
int n,k,m,val[nsz];
int main(){
	cin>>t;
	rep(cs,1,t){
		cin>>n>>k>>m;
		rep(i,1,m)cin>>val[i];
		if((n-m)%(k-1)){
			cout<<"NO\n";
			continue;
		}
		rep(i,1,m){
			if(val[i]-i>=k/2&&n-val[i]-m+i>=k/2){cout<<"YES\n";goto out;}
		}
		cout<<"NO\n";
		out:;
	}
}