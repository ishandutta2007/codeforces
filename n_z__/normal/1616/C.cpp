#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int a[2*n+1];
		for(int i=1;i<=n;i++){
			cin>>a[i];
		} 
		for(int i=n+1;i<=2*n;i++){
			a[i]=-1e14;
		}
		int minv=n-1;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n-i;j++){
				for(int k=-100;k<=100;k++){
					int need=a[i]+k,sum=1;
					for(int l=i+j;l<=n;l+=j){
						if(a[l]==need){
							sum++;
						}
						need+=k; 
					}
					minv=min(minv,n-sum);
				}
			}
		}
		cout<<minv<<endl;
	} 
}