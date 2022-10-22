#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define Inf 1000000001


int main(){
	
	int _t;
	cin>>_t;
	
	rep(_,_t){
		
		int n;
		cin>>n;
		
		vector<long long> ans(1,1);
		rep(i,n-1){
			ans.push_back(ans.back() * 3);
			if(ans.back()>=Inf){
				break;
			}
		}
		
		if(ans.back()>=Inf)cout<<"NO"<<endl;
		else{
			cout<<"YES"<<endl;
			rep(i,n){
				if(i!=0)cout<<' ';
				cout<<ans[i];
			}
			cout<<endl;
		}
		
	}
	
	return 0;
}