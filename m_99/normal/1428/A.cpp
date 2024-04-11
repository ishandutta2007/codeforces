#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000001

int main(){	
	
	int t;
	cin>>t;
	
	rep(_,t){
		
		long long x1,y1,x2,y2;
		cin>>x1>>y1>>x2>>y2;
		long long ans = abs(x1-x2)+abs(y1-y2);
		if(x1==x2||y1==y2){
		}
		else{
			ans += 2;
		}
		
		cout<<ans<<endl;
			
		
	}
	
    return 0;
}