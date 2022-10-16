#include<bits/stdc++.h>
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
		int maxv=0,cnt=0;
		for(int i=1;i<=n;i++){
			maxv=max(maxv,a[i]);
			if(maxv==i){
				cnt++;
			}
		}
		cout<<cnt<<endl;
	}
}