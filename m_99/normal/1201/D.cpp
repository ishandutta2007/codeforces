#include <bits/stdc++.h>
using namespace std;
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x))%modulo)
#define Inf 1000000000000


int main(){
	
	int n,m,k,q;
	cin>>n>>m>>k>>q;
	
	vector<vector<long long>> treasure(n,vector<long long>(0));
	int maxi = 0;
	for(int i=0;i<k;i++){
		int y,x;
		cin>>y>>x;
		maxi = max(y,maxi);
		y--;x--;
		treasure[y].push_back(x);
	}
	
	vector<long long> b(q);
	for(int i=0;i<q;i++){
		cin>>b[i];
		b[i]--;
	}
	
	b.push_back(Inf);b.push_back(-Inf);
	
	n = maxi;
	
	for(int i=0;i<n;i++){
		sort(treasure[i].begin(),treasure[i].end());
	}
	
	sort(b.begin(),b.end());
	
	vector<vector<long long>> way(n,vector<long long>(4,-1));
	for(int i=0;i<n;i++){
		if(treasure[i].size()==0)continue;
		long long left = treasure[i][0];
		long long right = treasure[i][treasure[i].size()-1];
		
		auto it1 = lower_bound(b.begin(),b.end(),left);
		auto it2 = lower_bound(b.begin(),b.end(),right);
		it1--;it2--;
		way[i][0] = *it1;
		way[i][1] = *(it1+1);
		way[i][2] = *it2;
		way[i][3] = *(it2+1);
		
		//cout<<i<<':'<<way[i][0]<<','<<way[i][1]<<','<<way[i][2]<<','<<way[i][3]<<endl;
	}
	
	vector<vector<long long>> dp(n,vector<long long>(4,Inf));
	
	long long a = 0;
	if(treasure[0].size()!=0)a=treasure[0][treasure[0].size()-1];
	
	if(n==1){
		cout<<a<<endl;
		return 0;
	}
	vector<long long> pos(4);
	for(int i=0;i<4;i++){
		if(treasure[0].size()==0){
			dp[0][i]=b[1]+1;
			pos[i]=b[1];
		}
		else{
			dp[0][i] = abs(a)+abs(a-way[0][i])+1;
			pos[i] = way[0][i];
		}
	}
	
	for(int i=1;i<n-1;i++){
		for(int j=0;j<4;j++){
			if(treasure[i].size()==0){
				dp[i][j] = dp[i-1][j]+1;
			}
			else{
				for(int k=0;k<4;k++){
					long long from = pos[k];
					long long to = way[i][j];
					long long right = treasure[i][treasure[i].size()-1];
					long long left = treasure[i][0];
					long long x = min(abs(from-right)+abs(right-left)+abs(left-to),abs(from-left)+abs(left-right)+abs(right-to));
					dp[i][j] = min(dp[i][j],dp[i-1][k]+x+1);
					dp[i][j] = min(dp[i][j],Inf);
				}
			}
		}
		if(treasure[i].size()!=0){
			for(int j=0;j<4;j++){
				pos[j] = way[i][j];
			}
		}
	}

	long long ans = Inf;
	
	for(int i=0;i<4;i++){
		long long from = pos[i];
		long long right = treasure[n-1][treasure[n-1].size()-1];
		long long left = treasure[n-1][0];
		long long x = min(abs(from-right)+abs(right-left),abs(from-left)+abs(left-right));
		ans = min(ans,dp[n-2][i] + x);
	}
	/*
	for(int i=0;i<n-1;i++){
		for(int j=0;j<4;j++){
			cout<<dp[i][j]<<',';
		}
		cout<<endl;
	}
*/
	
	cout<<ans<<endl;
	
	
	
	
			
			
	
	
	return 0;
}