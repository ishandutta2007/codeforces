#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000001

int main(){
	
	vector<long long> sum(10000001,0);
	vector<long long> ps;
	
	for(long long i=2;i<sum.size();i++){
		if(sum[i]==0){
			sum[i] = i;
			ps.push_back(i);
		}
		rep(j,ps.size()){
			if(ps[j]*i>=sum.size())break;
			if(ps[j]>sum[i])break;
			sum[ps[j]*i] = ps[j];
		}
	}
	//cout<<sum[18]<<endl;
	vector<long long> ans(10000001,1);
	sum[1] = 1;
	for(long long i=2;i<sum.size();i++){
		if(sum[i]==i){
			sum[i] = i+1;
			ans[i] = i+1;
		}
		else{
			long long temp = sum[i/sum[i]];
			if((i/sum[i])%sum[i]!=0){
				ans[i] = sum[i]+1;
				sum[i] = temp * ans[i];
			}
			else{
				temp /= ans[i/sum[i]];
				ans[i] = ans[i/sum[i]] * sum[i] + 1;
				temp *= ans[i];
				sum[i] = temp;
			}
		}
		
	}
	
	ans.assign(10000001,-1);
	for(int i=1;i<sum.size();i++){
		if(sum[i]<sum.size() && ans[sum[i]]==-1)ans[sum[i]] = i;
	}
	
	int _t;
	cin>>_t;
	
	rep(_,_t){
		
		int c;
		cin>>c;
		
		cout<<ans[c]<<endl;
	}
	
	return 0;
}