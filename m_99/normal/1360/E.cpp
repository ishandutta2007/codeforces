#include <bits/stdc++.h>
using namespace std;
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 1000000001

int main(){
	
	int t;
	cin>>t;
	
	for(int _=0;_<t;_++){
		int n;
		scanf("%d",&n);
		vector<string> s(n);
		for(int i=0;i<n;i++)cin>>s[i];
		
		vector<vector<bool>> ok(n,vector<bool>(n,false));
		
		for(int i=n-1;i>=0;i--){
			for(int j=n-1;j>=0;j--){
				if(s[i][j]=='0')continue;
				if(i==n-1||j==n-1){
					ok[i][j]=true;
					continue;
				}
				if(ok[i+1][j]||ok[i][j+1])ok[i][j]=true;
			}
		}
		bool f = true;
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(s[i][j]=='1'&&!ok[i][j]){
					f=false;
					break;
				}
			}
		}
		if(f)cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
		
	}
	
	return 0;	
}