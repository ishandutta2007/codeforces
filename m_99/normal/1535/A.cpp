#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000001

int main(){
	
	int t;
	cin>>t;
	
	rep(_,t){
		vector<int> x(4);
		rep(i,4)cin>>x[i];
		
		int X = min(max(x[0],x[1]),max(x[2],x[3]));
		sort(x.rbegin(),x.rend());
		if(x[1]==X)cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
		
		
		
	}
	
	return 0;
}