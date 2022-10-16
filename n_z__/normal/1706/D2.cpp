#include<bits/stdc++.h>
using namespace std;
signed main(){
	int t;
	cin>>t;
	while(t--)
	{
		int n,k;
		cin>>n>>k;
		vector<int>a(n+1);
		for(int x=1;x<=n;x++)
		cin>>a[x];
		vector<int>b(100001);
		for(int x=0;x<=a[1];x++)
		b[x]=-1;
		for(int x=1;x<=n;x++)
		for(int y=a[x],l=1,r=0;l<=y;l=r+1)
		r=y/(y/l),b[l]=max(b[l],y/min(y/l,k));
		int ans=100001;
		for(int x=1;x<=a[1];x++)
		b[x]=max(b[x],b[x-1]),ans=min(ans,b[x]-x);
		cout<<ans<<endl;
	}
}