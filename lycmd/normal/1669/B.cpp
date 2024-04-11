#include<bits/stdc++.h>
using namespace std;
int const N=200010;
int t,n,a[N],cnt[N];
int main(){
	ios::sync_with_stdio(0);
	for(cin>>t;t--;){
		cin>>n;
		int ans=-1;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			if(++cnt[a[i]]>2)ans=a[i];
		}
		cout<<ans<<"\n";
		for(int i=1;i<=n;i++)
			cnt[a[i]]--;
	}
	return 0;
}