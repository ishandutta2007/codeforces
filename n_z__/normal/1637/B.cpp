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
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		int mex[n+1],sum=0;
		for(int i=1;i<=n;i++){
			sum+=i*(n-i+1);
			if(!a[i]) mex[i]=1;
			else mex[i]=0;
			sum+=mex[i]*i*(n-i+1);
		}
		cout<<sum<<endl;
	}
	return 0;
}