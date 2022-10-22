#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000000000000000

	

int main(){
	
	int n;
	vector<pair<long long,int>> a;
	
	cin>>n;
	
	a.resize(n);
	rep(i,n){
		scanf("%lld",&a[i].first);
		a[i].second = i;
	}
	
	sort(a.begin(),a.end());
	
	vector<long long> dp(n+1,Inf);
	dp[0] = 0;
	vector<int> pre(n+1,-1);
	rep(i,n){
		for(int j=3;j<=5;j++){
			if(i-j+1<0)continue;
			long long nv = dp[i+1-j] + a[i].first-a[i-j+1].first;
		//	cout<<nv<<endl;
			if(nv<dp[i+1]){
				dp[i+1] = nv;
				pre[i+1] = j;
			}
		}
	}
	//cout<<'a'<<endl;
	/*
	rep(i,n+1){
		cout<<pre[i]<<',';
	}
	cout<<endl;
	*/
	int cur = n;
	vector<int> color(n,-1);
	int t = 0;
	while(cur!=0){
		//cout<<cur<<endl;
		rep(i,pre[cur]){
			color[cur - 1 - i] = t;
		}
		t++;
		cur -= pre[cur];
	}
	
	vector<int> ans(n);
	rep(i,n){
		ans[a[i].second] = color[i]+1;
	}
	
	cout<<dp.back()<<' '<<t<<endl;;
	
	rep(i,n){
		if(i!=0)printf(" ");
		printf("%d",ans[i]);
	}
	cout<<endl;
	
	return 0;
}