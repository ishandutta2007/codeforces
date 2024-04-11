#include<bits/stdc++.h>
using namespace std;
#define int long long
main(){
	int n,c;
	cin>>n>>c;
	vector<int>p(n+1);
    int a[n+1];
	int sum=0;
	for(int x=1;x<=n;x++)
	cin>>p[x],sum+=p[x];
	for(int x=1;x<=n;x++)
	{
	    int y;
	    cin>>y;
	    a[x]=c*(n-x)+y-p[x];
	}
	sort(a+1,a+n+1);
	int ans=sum;
	for(int x=1;x<=n;x++)
	sum+=a[x]-c*(x-1),ans=min(ans,sum);
	cout<<ans<<endl;
}