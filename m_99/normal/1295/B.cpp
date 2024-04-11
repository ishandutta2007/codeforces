#include <bits/stdc++.h>
using namespace std;
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 1000000000

int main(){

	int t;
	cin>>t;
	
	for(int _=0;_<t;_++){
		int n;
		cin>>n;
		
		long long x;
		cin>>x;
		
		string S;
		cin>>S;
		
		int sum = 0;
		map<int,int> mp;
		for(int i=0;i<S.size();i++){
			if((S[i]=='0') ^ (x<0))sum++;
			else sum--;
			mp[sum] ++;
		}
		if(x<0)x *= -1;
		
		if(sum==0 && mp.count(x)){
			cout<<-1<<endl;
			continue;
		}
		
		if(sum == 0 && !mp.count(x)){
			cout<<0<<endl;
			continue;
		}
		
		long long ans = 0;
		if(x==0)ans ++;
		
		if(x>=1000000){
			if(sum<0){
				cout<<0<<endl;
				continue;
			}
			else{
				int k = (x-1000000);
				x -= (k / sum) * sum;
			}
		}
		
		while(true){
			if(mp.count(x))ans += mp[x];
			x -= sum;
			if(sum > 0 &&mp.upper_bound(x) == mp.begin())break;
			if(sum <= 0 && mp.lower_bound(x)==mp.end())break;
		}
		
		cout<<ans<<endl;
	}
	
	return 0;
}