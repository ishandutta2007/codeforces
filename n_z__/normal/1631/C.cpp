#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
	int t;
    cin>>t;
    while(t--){
    	int n,k;
    	cin>>n>>k;
    	if(n==4&&k==3){
    		cout<<-1<<endl;
    		continue;
		}
		if(k==0){
			for(int i=0;i<n/2;i++){
				cout<<i<<" "<<n-i-1<<endl;
			}
		}
		else if(k!=n-1){
			cout<<0<<" "<<n-k-1<<endl;
			cout<<k<<" "<<n-1<<endl;
			for(int i=0;i<n/2;i++){
				if(i!=0&&i!=n-k-1&&i!=k){
					cout<<i<<" "<<n-i-1<<endl;
				}
			}
		}
		else{
			cout<<0<<" "<<1<<endl;
			cout<<n/2-1<<" "<<n-1<<endl;
			cout<<n/2<<" "<<n-2<<endl;
			for(int i=2;i<n/2-1;i++){
				cout<<i<<" "<<n-i-1<<endl;
			}
		}
	}
    return 0;
}