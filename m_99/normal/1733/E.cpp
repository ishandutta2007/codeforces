#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf32 1000000001
#define Inf64 4000000000000000001


int main(){
	
	int _t;
	cin>>_t;
	
	rep(_,_t){
		
		long long t,x,y;
		cin>>t>>x>>y;
		
		t -= x+y;
		if(t<0){
			cout<<"NO"<<endl;
			continue;
		}
		
		vector dp(120,vector<long long>(120,0));
		dp[0][0] = t;
		rep(i,120){
			rep(j,120){
				if(j!=119){
					dp[i][j+1] += (dp[i][j]+1)/2;
				}
				if(i!=119){
					dp[i+1][j] += dp[i][j]/2;
				}
			}
		}
		bool f = false;
		int cx = 0,cy = 0;
		while(cx!=120&&cy!=120){
			if(cx==x&&cy==y){
				f = true;
				break;
			}
			if(dp[cx][cy]&1){
				cx++;
			}
			else cy++;
		}
		cout<<(f?"YES":"NO")<<endl;
	}
	
	return 0;
}