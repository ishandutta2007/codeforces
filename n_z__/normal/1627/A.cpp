#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
	int t;
	cin>>t;
	while(t--){
		int n,m,r,c;
		cin>>n>>m>>r>>c;
		char C[n+1][m+1];
		int you=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				cin>>C[i][j];
				if(C[i][j]=='B'){
					you=1;
				}
			}
		}
		if(!you){
			cout<<-1<<endl;
			continue;
		}
		if(C[r][c]=='B'){
			cout<<0<<endl;
			continue;
		}
		you=0;
		for(int i=1;i<=n;i++){
			if(C[i][c]=='B'){
				you=1;
			}
		}
		for(int j=1;j<=m;j++){
			if(C[r][j]=='B'){
				you=1;
			}
		}
		if(you){
			cout<<1;
		}
		else{
			cout<<2;
		}
		cout<<endl;
	}
	return 0;
}