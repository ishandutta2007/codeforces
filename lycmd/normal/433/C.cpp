#include<bits/stdc++.h>
#define int long long
using namespace std;
int const N=100010;
int n,m,sum,ans,a[N];
vector<int>p[N];
signed main(){
	ios::sync_with_stdio(0);
	cin>>m>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<n;i++){
		if(a[i]==a[i+1])
			continue;
		sum+=abs(a[i]-a[i+1]);
		p[a[i]].push_back(a[i+1]);
		p[a[i+1]].push_back(a[i]);
	}
	ans=sum;
	for(int i=1;i<=m;i++){
		if(p[i].empty())
			continue;
		sort(p[i].begin(),p[i].end());
		int mid=p[i][p[i].size()/2],t=sum;
		for(int j:p[i])
			t-=abs(j-i)-abs(j-mid);
		ans=min(ans,t);
	}
	cout<<ans<<"\n";
}