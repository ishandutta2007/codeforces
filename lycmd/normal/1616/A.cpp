#include<bits/stdc++.h>
using namespace std;
int const N=233;
int t,n,a[N];
map<int,int>cnt;
int main(){
	ios::sync_with_stdio(0);
	for(cin>>t;t--;){
		cin>>n,cnt.clear();
		for(int i=1;i<=n;i++)
			cin>>a[i],cnt[a[i]]++;
		int ans=cnt.size();
		for(auto i:cnt)
			if(!cnt[-i.first]&&i.second>1)
				ans++;
		cout<<ans<<"\n";
	}
	return 0;
}