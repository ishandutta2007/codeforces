#include <bits/stdc++.h>
#define int long long
using namespace std;
int dpp[100000+2][2][2];
int mex(vector<int>& arr){
	
	if(find(arr.begin(),arr.end(),0)==arr.end()){
		return 0;
	}	
	if(find(arr.begin(),arr.end(),1)==arr.end()){
		return 1;
	}
	return 2;
}
int dp(int ind,int f0,int f1,string& s1,string& s2){
	if(ind==s1.size()){
		if(f0==0&&f1==0){
			return 0;
		}
		return -1000000;
	}
	int ans=dpp[ind][f0][f1];
	if(ans!=-1){
		return ans;
	}
	vector<int> c1;
	if(f0==1){
		c1.push_back(0);
	}
	if(f1==1){
		c1.push_back(1);
	}
	c1.push_back(s1[ind]-'0');
	c1.push_back(s2[ind]-'0');
	ans=max(ans,mex(c1)+dp(ind+1,0,0,s1,s2));
	int ff0=f0;
	int ff1=f1;
	if(s1[ind]=='0'){
		ff0=1;
	}
	else{
		ff1=1;
	}
	if(s2[ind]=='0'){
		ff0==1;
	}
	else{
		ff1=1;
	}
	return dpp[ind][f0][f1]=max(ans,dp(ind+1,ff0,ff1,s1,s2));
}
void solve(){
	int n;
	cin>>n;
	string s1;
	string s2;
	cin>>s1>>s2;
	
	for(int i=0;i<n;i++){
		for(int j=0;j<2;j++){
			for(int k=0;k<2;k++){
				dpp[i][j][k]=-1;
			}
		}
	}
	cout<<dp(0,0,0,s1,s2)<<'\n';		
}

signed main() {
	ios_base::sync_with_stdio(false);
	cout.tie(0);
	cin.tie(NULL);
    int t=1;
	cin>>t;
	while(t--){
		solve();
	}
}