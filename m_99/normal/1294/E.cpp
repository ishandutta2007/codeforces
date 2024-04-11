#include <bits/stdc++.h>
using namespace std;
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 1000000000

int calc(vector<int> &A,vector<int> &B){
	map<int,int> mp;
	for(int i=0;i<B.size();i++)mp[B[i]] = i;
	
	vector<int> cnt(A.size(),A.size());
	for(int i=0;i<A.size();i++){
		cnt[i] +=i;
	}
	
	for(int i=0;i<A.size();i++){
		if(!mp.count(A[i]))continue;
		int x = i-mp[A[i]];
		if(x<0)x += A.size();
		cnt[x]--;
	}
	
	int ret = Inf;
	for(int i=0;i<cnt.size();i++)ret= min(cnt[i],ret);
	return ret;
}

int main(){

	int n,m;
	cin>>n>>m;
	
	vector<vector<int>> a(n,vector<int> (m));
	
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			scanf("%d",&a[i][j]);
		}
	}
	
	int ans = 0;
	
	for(int i=0;i<m;i++){
		vector<int> A,B;
		for(int j=0;j<n;j++){
			A.push_back(a[j][i]);
			B.push_back(m*j+1+i);
		}
		
		ans += calc(A,B);
	}
	
	cout<<ans<<endl;
	
	return 0;
}