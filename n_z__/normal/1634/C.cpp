#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
	int t;
	cin>>t;
	while(t--){
		int n,m;
		cin>>n>>m;
		if(m!=1&&n%2==1){
			cout<<"NO"<<endl;
			continue;
		}
		int a[n+1][m+1];
		int cnt=0;
		for(int i=1;i<=m;i++){
			for(int j=1;j<=n;j++){
				cnt++;
				a[j][i]=cnt;
			}
		} 
		cout<<"YES"<<endl;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				cout<<a[i][j]<<" ";
			}
			cout<<endl;
		}
	}
	return 0;
}