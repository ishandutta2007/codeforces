#include <bits/stdc++.h>
using namespace std;
#define modulo 998244353
#define mod(mod_x) ((((long long)mod_x)+modulo)%modulo)
#define Inf 1000000000000


int main() {
	
	int n,k;
	cin>>n>>k;
	
	vector<string> S(n);
	
	for(int i=0;i<n;i++){
		cin>>S[i];
	}
	
	vector<vector<int>> ans(n,vector<int>(n,0));
	
	for(int i=0;i<n;i++){
		for(int j=0;j<n+1-k;j++){
			bool f = true;
			for(int a=0;a<k;a++){
				if(S[i][j+a]=='#'){
					f=false;
					break;
				}				
			}
			if(!f)continue;
			for(int a=0;a<k;a++){
				ans[i][j+a]++;				
			}
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n+1-k;j++){
			bool f = true;
			for(int a=0;a<k;a++){
				if(S[j+a][i]=='#'){
					f=false;
					break;
				}				
			}
			if(!f)continue;
			for(int a=0;a<k;a++){
				ans[j+a][i]++;				
			}
		}
	}
	
	int maxi = -1;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			maxi = max(maxi,ans[i][j]);
		}
	}
	
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(maxi == ans[i][j]){
				cout<<i+1<<' '<<j+1<<endl;
				return 0;
			}
		}
	}
	
	
	
    return 0;
}