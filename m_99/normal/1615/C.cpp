#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define Inf 1000000000001
int main(){
	

	int _t;
	cin>>_t;
	
	rep(_,_t){
		
		int n;
		cin>>n;
		string a,b;
		cin>>a>>b;
		
		vector pos(2,vector<int>());
		rep(i,n){
			if(a[i]=='1')pos[0].push_back(i);
			if(b[i]=='1')pos[1].push_back(i);
		}
		
		long long ans = Inf;
		
		if(pos[0].size()==pos[1].size()){
			long long S = 0LL;
			rep(i,n){
				if(a[i]=='0'&&b[i]=='1')S += 2;
			}
			ans = S;
		}
		
		if(pos[1].size()>0){
			long long temp = pos[1].size();
			temp = n-temp;
			temp++;
			if(temp==pos[0].size()){
				vector<long long> S(n+1,0);
				rep(i,n){
					if(a[i]==b[i])S[i+1] = 1;
					S[i+1] += S[i];
				}
				
				rep(i,n){
					if(a[i]=='1'){
						
						long long t = 0;
						if(a[i]!=b[i])t++;
						t += S[i];
						t += S.back() - S[i+1];
						ans = min(ans,t+1);
					}
				}
				
			}
		}
		if(ans==Inf)ans = -1;
		cout<<ans<<endl;
	}
	
	return 0;
}