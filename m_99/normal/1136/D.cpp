#include <bits/stdc++.h>
using namespace std;
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 1000000000



int main(){
	
	int n,m;
	cin>>n>>m;
	
	vector<int> p(n);
	
	map<int,int> mp;
	
	for(int i=0;i<n;i++){
		scanf("%d",&p[i]);
		mp[p[i]] = i;
	}
	
	vector<vector<int>> revE(n,vector<int>());
	
	vector<int> cnt(n,0);
	
	for(int i=0;i<m;i++){
		int a,b;
		scanf("%d %d",&a,&b);
		a = mp[a];
		b = mp[b];
		if(a>b)continue;
		cnt[a] ++;
		revE[b].push_back(a);
	}
	
	int ans = 0;
	int C = 1;
	
	for(int i=n-2;i>=0;i--){
		if(C == cnt[i]){
			ans ++;
			for(int j=0;j<revE[i].size();j++){
				cnt[revE[i][j]]--;
			}
		}
		else{
			C ++;
		}
	}
	
	cout<<ans<<endl;
	
    return 0;
}