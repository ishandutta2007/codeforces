#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int a[n+1];
		int you[300];
		for(int i=0;i<=299;i++){
			you[i]=0;
		}
		for(int i=1;i<=n;i++){
			cin>>a[i];
			you[llabs(a[i])]++;
		}
		int sum=0;
		for(int i=1;i<=299;i++){
			sum+=min(you[i],2ll);
		}
		sum+=(you[0]>=1);
		cout<<sum<<endl;
	} 
}