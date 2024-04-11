#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
	int t;
	cin>>t;
	while(t--){
		int n,k;
		cin>>n>>k;
		if(k>(n+1)/2){
			cout<<"-1"<<endl;
			continue;
		}
		char c[n+1][n+1];
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				c[i][j]='.';
			}
		}
		for(int i=1;i<=k;i++){
			c[i*2-1][i*2-1]='R';
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				cout<<c[i][j];
			}
			cout<<endl;
		}
	} 
}