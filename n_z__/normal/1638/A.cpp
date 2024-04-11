#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int a[n+1],plc[n+1];
		for(int i=1;i<=n;i++){
			cin>>a[i];
			plc[a[i]]=i;
		}
		for(int i=1;i<=n;i++){
			if(a[i]!=i){
				int l=i,r=plc[i];
				while(l<r){
					swap(a[l],a[r]);
					l++;
					r--;
				}
				break;
			}
		}
		for(int i=1;i<=n;i++){
			cout<<a[i]<<" ";
		}
		cout<<endl;
	}
}