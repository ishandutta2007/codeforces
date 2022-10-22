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
		
		int n,m;
		cin>>n>>m;
		
		if(m<n){
			cout<<"NO"<<endl;
			continue;
		}
		vector<int> ans(n,1);
		m -= n;
		
		if(n%2==1)ans.back() += m;
		else{
			
			if(m%2==0){
				ans[n-1] += m/2;
				ans[n-2] += m/2;
			}
			else{
				cout<<"NO"<<endl;
				continue;
			}
			
		}
		
		cout<<"YES"<<endl;
		rep(i,n){
			if(i!=0)cout<<' ';
			cout<<ans[i];
		}
		cout<<endl;
		
	}
	
    return 0;
}