#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
	int t;
    cin>>t;
    while(t--){
    	int n;
    	cin>>n;
    	int a[n+1],b[n+1],maxv1=0,maxv2=0;
    	for(int i=1;i<=n;i++){
    		cin>>a[i];
		}
		for(int i=1;i<=n;i++){
			cin>>b[i];
		}
		for(int i=1;i<=n;i++){
			maxv1=max(maxv1,min(a[i],b[i]));
			maxv2=max(maxv2,max(a[i],b[i]));
		}
		cout<<maxv1*maxv2<<endl;
	}
    return 0;
}