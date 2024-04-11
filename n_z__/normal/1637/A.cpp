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
		int ok=0;
		for(int i=1;i<n;i++){
			if(a[i]>a[i+1]){
				ok=1;
			}
		}
		if(ok){
			cout<<"YES";
		}
		else{
			cout<<"NO";
		}
		cout<<endl;
	}
	return 0;
}