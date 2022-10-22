#include <bits/stdc++.h>
using namespace std;
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 100000000



int main(){
    
	int n,k;
	cin>>n>>k;
	
	map<vector<pair<int,int>>,long long> mp;
	
	for(int i=0;i<n;i++){
		vector<pair<int,int>> v(0);
		int a;
		scanf("%d",&a);
		for(long long j=2;j*j<=a;j++){
			if(a%j!=0)continue;
			int cnt = 0;
			while(a%j==0){
				cnt++;
				a/=j;
			}
			cnt%=k;
			if(cnt!=0)v.emplace_back(j,cnt);
		}
		if(a!=1)v.emplace_back(a,1);
		sort(v.begin(),v.end());
		mp[v]++;
	}

	long long ans = 0;
	while(mp.size()!=0){
		auto it = mp.begin();
		vector<pair<int,int>> V1 = (*it).first;
		vector<pair<int,int>> V2 = V1;
		for(int i=0;i<V1.size();i++){
			V2[i].second = k-V1[i].second;
		}
		
		long long a = mp[V1];
		
		if(V1==V2){
			ans += (a * (a-1))/2;
			mp.erase(it);
		}
		else{
			ans += a * mp[V2];
			mp.erase(V1);
			mp.erase(V2);
		}
	}
	
	cout<<ans<<endl;
		
		
	
    return 0;
}