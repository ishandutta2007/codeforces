#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
	int t;
	cin>>t;
	while(t--){
		int n,x,k;
		cin>>n>>x>>k;
		int a[n+1],sum=0;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			sum+=a[i];
		} 
		x+=sum;
		if(x%2==k%2){
			cout<<"Alice";
		}
		else{
			cout<<"Bob";
		}
		cout<<endl;
	}
	return 0;
}