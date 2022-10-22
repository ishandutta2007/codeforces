#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf32 1000000001
#define Inf64 4000000000000000001

string s;
int dp[2005][2005];

int get(int l,int r){
	if(r-l==2){
		if(s[l]==s[r-1])return 0;
		else return 1;
	}
	
	if(dp[l][r]!=-5)return dp[l][r];
	
	char c = min(s[l],s[r-1]);
	int ret = -1;
	if(true){
		
		int tt =1;
		char c = s[l];
		{
			int rr = get(l+2,r);
			char d = s[l+1];
			if(rr!=0)tt = min(tt,rr);
			else{
				if(c==d)tt = min(tt,0);
				if(c>d)tt = min(tt,-1);
			}
		}
		
		{
			int rr = get(l+1,r-1);
			char d = s[r-1];
			if(rr!=0)tt = min(tt,rr);
			else{
				if(c==d)tt = min(tt,0);
				if(c>d)tt = min(tt,-1);
			}
		}
	
		ret = max(ret,tt);
		
	}
	if(true){
		int tt =1;
		char c = s[r-1];
		{
			int rr = get(l,r-2);
			char d = s[r-2];
			if(rr!=0)tt = min(tt,rr);
			else{
				if(c==d)tt = min(tt,0);
				if(c>d)tt = min(tt,-1);
			}
		}
		
		{
			int rr = get(l+1,r-1);
			char d = s[l];
			if(rr!=0)tt = min(tt,rr);
			else{
				if(c==d)tt = min(tt,0);
				if(c>d)tt = min(tt,-1);
			}
		}
	
		ret = max(ret,tt);
	}
	dp[l][r] = ret;
	return ret;
	
}

int main(){
	
	int _t;
	cin>>_t;
	
	rep(_,_t){
		
		cin>>s;
		
		int n = s.size();
		rep(i,n+5){
			rep(j,n+5){
				dp[i][j] = -5;
			}
		}
		
		int ans = get(0,n);
		if(ans==0)cout<<"Draw"<<endl;
		if(ans==1)cout<<"Alice"<<endl;
		if(ans==-1)cout<<"Bob"<<endl;
	}
	
    return 0;
}