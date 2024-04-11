#include <bits/stdc++.h>
using namespace std;
#define modulo 100000
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 1000000000

int main(){
	
	int n;
	cin>>n;
	
	vector<int> x(n);
	
	for(int i=0;i<n;i++)scanf("%d",&x[i]);
	
	x.push_back(-100);
	sort(x.begin(),x.end());
	
	vector<int> dp(n+1,Inf);
	
	dp[0] = 0;
	for(int i=1;i<=n;i++){
		int ind = distance(x.begin(),lower_bound(x.begin(),x.end(),x[i]-2));
		ind--;
		dp[i] = dp[ind]+1;
	}
	
	cout<<dp.back()<<' ';
	set<int> S;
	for(int i=1;i<=n;i++){
		if(x[i-1]<x[i]-1)x[i]--;
		else if(x[i-1]>=x[i]){
			x[i]++;
		}
		//cout<<x[i]<<endl;
		S.insert(x[i]);
	}
	
	cout<<S.size()<<endl;
	
	
	
	
    return 0;
}