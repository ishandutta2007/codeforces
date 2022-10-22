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
		
		int n;
		cin>>n;
		vector<int> d(n);
		rep(i,n)cin>>d[i];
		
		vector<int> ans;
		rep(i,n){
			if(i==0)ans.push_back(d[0]);
			else{
				if(d[i]!=0 && ans.back()-d[i]>=0){
					ans.clear();
					ans = vector<int>(1,-1);
					break;
				}
				ans.push_back(ans.back()+d[i]);
			}
		}
		rep(i,ans.size()){
			if(i!=0)cout<<' ';
			cout<<ans[i];
		}
		cout<<endl;
		
	}
	
	return 0;
}