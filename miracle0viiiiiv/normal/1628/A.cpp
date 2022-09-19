#include <bits/stdc++.h>
using namespace std;
const int M=1e9+7;
int n,a[200010],c[200010],d[200010];
void solve(){
	cin>>n;for(int i=0;i<n;i++)cin>>a[i];
	for(int i=0;i<n;i++)c[a[i]]++;
	int r=n;for(int i=0;i<n;i++)if(c[i]==0)r=min(r,i);
	vector<int>ans;
	for(int i=0;i<n;i++){
		ans.push_back(r);
		int j=i,t=0;
		for(;t<r;j++){
			if(a[j]<r&&d[a[j]]==0)t++;d[a[j]]++;
		}
		for(int k=i;k<j;k++){
			d[a[k]]--,c[a[k]]--;
			if(c[a[k]]==0)r=min(r,a[k]);
		}
		if(i==j)c[a[i]]--;
		i=max(j-1,i);
	}
	cout<<ans.size()<<'\n';
	for(int i=0;i<ans.size();i++)cout<<ans[i]<<' ';cout<<'\n';
}
int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	int t;cin>>t;
	while(t--)solve();
	return 0;
}