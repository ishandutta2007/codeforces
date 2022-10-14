#include<bits/stdc++.h>
using namespace std;
int const N=2333333;
int n,ans,a[N],cnt[N];
int main(){
	ios::sync_with_stdio(0);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i],cnt[a[i]]++;
	for(int i=0;i<N-1;i++)
		ans+=cnt[i]%2,cnt[i+1]+=cnt[i]/2;
	cout<<ans<<"\n";
	return 0;
}