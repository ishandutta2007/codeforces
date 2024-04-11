#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue>
#include <stack>
#include <set>

using namespace std;

int main(){
	int n,m;
	cin >> n >> m;
	int a[20][105]={};
	vector<string> s(n);
	for(int i=0;i<n;i++){
		cin >> s[i];
	}
	vector<int> left(20,100000);
	int right[20]={};
	int count[20]={};
	int co =0;
	int mx=-1;
	for(int i=n-1;i>=0;i--){
		for(int j=0;j<m+2;j++){
			if(s[i][j]=='1'){
				a[n-1-i][j]=1;
				count[n-1-i]+=1;
				co +=1;
				left[n-1-i] = min(left[n-1-i],j);
				right[n-1-i] = max(right[n-1-i],j);
				mx = max(mx,n-1-i);
			}
		}
	}
	if(co==0){
		cout << 0 << endl;
		return 0;
	}
	if(mx==0){
		cout << right[0] << endl;
		return 0;
	}
	int dp[20][2]={};
	if(count[0]==0){
		dp[0][0]=0;
		dp[0][1]=m+1;
	}else{
		dp[0][0] = 2*right[0];
		dp[0][1] = m+1;
	}
	for(int i=1;i<mx;i++){
		if(count[i]==0){
			dp[i][0] = dp[i-1][0]+1;
			dp[i][1] = dp[i-1][1]+1;
		}else{
			dp[i][0] = min(dp[i-1][0]+1+2*right[i],dp[i-1][1]+1+m+1);
			dp[i][1] = min(dp[i-1][0]+1+m+1,dp[i-1][1]+1+2*(m+1-left[i]));
		}
	}
	cout << min(dp[mx-1][0]+1+right[mx],dp[mx-1][1]+1+m+1-left[mx]) << endl;
	return 0;
}