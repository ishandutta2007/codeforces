#include<bits/stdc++.h>
#define int long long
const int N=1000005;
using namespace std;

int n,a[N],b[N],c[N];

bool chk(int mid){
	for(int i=1;i<=n;i++)b[i]=a[i];
	for(int i=n;i>=1;i--){
		if(b[i]<mid)return 0;
		int k=(b[i]-mid)/3;
		k=min(k,a[i]/3);
		if(i>2)b[i-1]+=k,b[i-2]+=2*k; 
	}
	return 1;
}

void solve(){
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	int l=1,r=1e9,ans=1;
	while(l<=r){
		int mid=l+r>>1;
		if(chk(mid))ans=mid,l=mid+1;
		else r=mid-1;
	}
	cout<<ans<<endl;
}

main(){
	int _T=1;cin>>_T;
	while(_T--)solve();
}