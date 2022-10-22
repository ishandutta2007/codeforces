#include <bits/stdc++.h>
using namespace std;
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 1000000000000000000

int main(){

	int t;
	cin>>t;
	
	for(int _=0;_<t;_++){
		int n;
		cin>>n;
		
		vector<int> l(n),r(n);
		map<int,int> mp;
		for(int i=0;i<n;i++){
			scanf("%d %d",&l[i],&r[i]);
			l[i]*=2;
			r[i]*=2;
			mp[l[i]]=0;
			mp[l[i]-1] = 0;
			mp[l[i]+1] = 0;
			mp[r[i]] = 0;
			mp[r[i]-1] = 0;
			mp[r[i]+1] = 0;
		}
		
		int now = 0;
		for(auto &a:mp){
			a.second = now;
			now ++;
		}
		
		vector<long long> imos(now,0);
		for(int i=0;i<n;i++){
			l[i] = mp[l[i]];
			r[i] = mp[r[i]];
			imos[l[i]]++;
			imos[r[i]+1]--;
		}
		
		for(int i=1;i<now;i++)imos[i] += imos[i-1];
		
		int ans = 0;
		bool f = false;
		for(int i=0;i<now;i++){
			if(imos[i]==0){
				f = false;
			}
			else{
				if(!f){
					f = true;
					ans ++;
				}
			}
		}
		
		int last = -1;
		vector<int> l0,r0,l1,r1;
		
		for(int i=0;i<now;i++){
			if(imos[i] == 0){
				if(last==0)continue;
				last = 0;
				l0.push_back(i);
			}
			else{
				if(last==0){
					r0.push_back(i-1);
					last = -1;
				}
			}
		}
		
		last = -1;
		for(int i=0;i<now;i++){
			if(imos[i] == 1){
				if(last==1)continue;
				last = 1;
				l1.push_back(i);
			}
			else{
				if(last==1){
					r1.push_back(i-1);
					last = -1;
				}
			}
		}
		
		int maxi = -5;
		
		for(int i=0;i<n;i++){
			int x = distance(upper_bound(l1.begin(),l1.end(),r[i]),l1.end());
			int y = distance(r1.begin(),lower_bound(r1.begin(),r1.end(),l[i]));
			int z = l1.size()-x-y;
			bool f1 = binary_search(l1.begin(),l1.end(),l[i]);
			bool f2 = binary_search(r1.begin(),r1.end(),r[i]);
			
			bool ff1 = binary_search(r0.begin(),r0.end(),l[i]-1);
			bool ff2 = binary_search(l0.begin(),l0.end(),r[i]+1);
			if(f1&&f2){
				if(ff1&&ff2)z-=2;
				else if(ff1^ff2)z--;
			}
			else if(f1){
				if(ff1)z--;
			}
			else if(f2){
				if(ff2)z--;
			}
			
			maxi = max(maxi,z);
		}
		
		cout<<ans+maxi<<endl;
		
	}
	
	
		
		
	
	return 0;
}