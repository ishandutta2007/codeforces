#include <bits/stdc++.h>
using namespace std;
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 10000000000000000



int main(){
	
	int n;
	cin>>n;
	
	vector<vector<int>> ans(n,vector<int>(n,0));
	int now = 1;
	
	
	int l = 1;
	int r = n*n;
	
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(j<n/2){
				ans[i][j] = l;
				l++;
			}
			else{
				if(n%2==1&&j==n/2)continue;
				ans[i][j]=r;
				r--;
			}
		}
	}
	
	if(n%2==1){
		for(int i=0;i<n;i++){
			ans[i][n/2]=l;
			l++;
		}
	}
	
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(j!=0)cout<<' ';
			cout<<ans[i][j];
		}
		cout<<endl;
	}
	
    return 0;
}