#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 1000000000
string s;

int get(int l,int r){
	if(l>r)return 0;
	if(l==r)return 1;
	if(r-l==1){
		if(s[l]==s[r])return 1;
		return 2;
	}
	static vector dp(505,vector<int>(505,-1));
	if(dp[l][r]!=-1)return dp[l][r];
	
	int ret = Inf;
	
	
	
	for(int i=l+1;i<r;i++){
		ret = min(ret,get(l,i)+get(i,r)-1);
	}
	
	if(s[l]==s[r]){
		ret = min(ret,get(l+1,r-1)+1);
	}
	
	dp[l][r] = ret;
	return ret;
	
}

int main(){
	int n;
	scanf("%d",&n);
	
	cin>>s;
	
	{
		string t = "";
		rep(i,n){
			if(t.size()==0 || t.back()!=s[i])t += s[i];
		}
		swap(s,t);
	}
	
	cout<<get(0,s.size()-1)<<endl;
	
	return 0;
}