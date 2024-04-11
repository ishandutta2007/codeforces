#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
	int t;
    cin>>t;
    while(t--){
    	int n;
    	cin>>n;
    	int a[n+1],cnt=0;
    	for(int i=1;i<=n;i++){
    		cin>>a[i];
		}
		for(int i=n;i>=1;i--){
			if(a[i]!=a[n]){
				cnt++;
				i-=(n-i);
				i++;
			}
		}
		cout<<cnt<<endl;
	}
    return 0;
}