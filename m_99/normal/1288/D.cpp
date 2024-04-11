#include <bits/stdc++.h>
using namespace std;
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 1000000000000000000



int main(){

	int n,m;
	cin>>n>>m;
	
	vector<vector<int>> a(n,vector<int>(m));
	
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			scanf("%d",&a[i][j]);
		}
	}
	
	int ok = 0,ng = 1000000001;
	
	while(ng-ok>1){
		int mid = (ok+ng)/2;
		set<int> S;
		for(int i=0;i<n;i++){
			int x = 0;
			for(int j=0;j<m;j++){
				if(mid <= a[i][j])x |= 1<<j;
			}
			S.insert(x);
		}
		bool f = false;
		for(auto x:S){
			for(auto y:S){
				if((x|y) == (1<<(m))-1){
					f = true; 
					goto L;
				}
			}
		}
		
		L:
		if(f)ok = mid;
		else ng = mid;
	}

	map<int,int> mp;
	for(int i=0;i<n;i++){
		int x = 0;
		for(int j=0;j<m;j++){
			if(ok <= a[i][j])x |= 1<<j;
		}
		mp[x] = i+1;
	}
	
	for(auto x:mp){
		for(auto y:mp){
			if((x.first|y.first) == (1<<(m))-1){
				cout<<x.second<<' '<<y.second<<endl;
				return 0;
			}
		}
	}
	return 0;
}