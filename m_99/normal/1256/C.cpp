#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000000

int main(){
	
		
	int n,m,d;
	cin>>n>>m>>d;
	vector<int> c(m);
	rep(i,m)cin>>c[i];
	
	vector<int> ans(n,-1);
	vector<int> pre(m+1,d-1);
	
	int sum = 0;
	rep(i,m){
		sum += c[i];
	}
	rep(i,m+1)sum += pre[i];
	
	if(sum < n){
		cout<<"NO"<<endl;
		return 0;
	}
	
	rep(i,m+1){
		while(pre[i]>0&&sum!=n){
			sum--;
			pre[i]--;
		}
	}
	int pos = 0;
	rep(i,m){
		rep(j,pre[i])pos++;
		rep(j,c[i]){
			ans[pos] = i;
			pos++;
		}
	}
	cout<<"YES"<<endl;
	rep(i,n){
		if(i!=0)cout<<' ';
		cout<<ans[i]+1;
	}
	cout<<endl;
		
		
	
	
	return 0;
}