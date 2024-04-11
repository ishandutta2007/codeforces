#include <bits/stdc++.h>
using namespace std;
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 1000000000

int main(){
	
	int t;
	cin>>t;
	
	for(int i=0;i<t;i++){
		int n;
		cin>>n;
		
		long long T,a,b;
		cin>>T>>a>>b;
		
		map<long long,priority_queue<long long>> mp;

		
		long long sum = 0;
		
		vector<int> x(n);
		for(int j=0;j<n;j++)cin>>x[j];
		
		for(int j=0;j<n;j++){
			long long t;
			cin>>t;
			t--;
			if(x[j]==0){
				mp[t].push(a);
				sum+=a;
			}
			else{
				mp[t].push(b);
				sum+=b;
			}
		}
		
		
		
		int a_cnt = 0;
		int b_cnt = 0;
		int ans = 0;
		if(T >= sum)ans = n;
		for(auto it = mp.rbegin();it!=mp.rend();it++){
			long long t = (*it).first;
			while((*it).second.size()!=0){
				n--;
				if(a==(*it).second.top())a_cnt++;
				else b_cnt++;
				sum -= (*it).second.top();
				(*it).second.pop();
			}
			if(sum<=t){
				long long S = t-sum;
				long long x = n;
				x += min((long long)a_cnt,S/a);
				S -= min((long long)a_cnt,S/a) * a;
				x += min((long long)b_cnt,S/b);
				ans = max((long long)ans,x);
			}
		}
		
		cout<<ans<<endl;
		
		
	}
	
	
    return 0;
}