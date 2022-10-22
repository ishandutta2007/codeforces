#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000000000000


int main(){
	
	int _t;
	cin>>_t;
	
	rep(_,_t){
		int n;
		string s;
		scanf("%d",&n);
		cin>>s;
		
		vector<int> cntR(n,1),cntL(n,1);
		rep(i,n){
			if(i!=0){
				if(s[i-1]!=s[i])cntL[i] += cntL[i-1];
			}
			
		}
		for(int i=n-1;i>=0;i--){
			if(i!=n-1){
				if(s[i]!=s[i+1])cntR[i] += cntR[i+1];
			}
		}
		
		rep(i,n+1){
			int ans = 1;
			if(i!=n){
				if(s[i]=='R')ans += cntR[i];
			}
			if(i!=0){
				if(s[i-1]=='L')ans += cntL[i-1];
			}
			if(i!=0)printf(" ");
			printf("%d",ans);
		}
		printf("\n");
		
		
	}
	
    return 0;
}