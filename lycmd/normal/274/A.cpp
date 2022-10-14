#include<bits/stdc++.h>
using namespace std;
int const N=233333,M=1000000010;
int n,k,ans,a[N];
map<int,int>cnt;
int main(){
	ios::sync_with_stdio(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)
		if(!cnt[a[i]]){
			ans++;
			if(1ll*a[i]*k<M)
				cnt[a[i]*k]++;
		}else cnt[a[i]]--;
	cout<<ans<<"\n";
}