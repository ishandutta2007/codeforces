#include<bits/stdc++.h>
#define int long long
using namespace std;
int k[4],t[4],a[4][100001];
signed main(){
	int n;
	cin>>k[1]>>k[2]>>k[3]>>t[1]>>t[2]>>t[3]>>n;
	int ans=0;
	for(int x=1;x<=n;x++){
		int y,z;
		cin>>y;
		z=y;
		for(int o=1;o<=3;o++)
		a[o][x%k[o]]=max(a[o][x%k[o]],z)+t[o],z=a[o][x%k[o]];
		ans=max(ans,z-y);
	}
	cout<<ans<<endl;
}