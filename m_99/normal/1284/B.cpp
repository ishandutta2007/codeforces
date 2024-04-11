#include <bits/stdc++.h>
using namespace std;
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 1000000000

int main(){
	
	int n;
	cin>>n;
	
	vector<vector<int>> a(n,vector<int>());
	
	for(int i=0;i<n;i++){
		int l;
		scanf("%d",&l);
		for(int j=0;j<l;j++){
			int x;
			scanf("%d",&x);
			a[i].push_back(x);
		}
	}
	
	vector<int> mini,maxi;
	
	long long ans = 0;
	long long cnt = 0;
	for(int i=0;i<n;i++){
		int m = a[i][0];
		for(int j=0;j<a[i].size();j++){
			if(m < a[i][j]){
				ans += (long long)n;
				cnt ++;
				m = -1;
				break;
			}
			m = a[i][j];
		}
		if(m==-1)continue;
		mini.push_back(m);
		maxi.push_back(a[i][0]);
	}
	
	sort(mini.begin(),mini.end());
	
	for(int i=0;i<maxi.size();i++){
		int num = distance(mini.begin(),lower_bound(mini.begin(),mini.end(),maxi[i]));
		ans += (long long) num+cnt;
	}
	
	cout<<ans<<endl;
	
		
	
    return 0;
}