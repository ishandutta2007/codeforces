#include <bits/stdc++.h>
using namespace std;
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 1000000000000

int main(){

	int t;
	cin>>t;
	
	for(int _=0;_<t;_++){
		int n;
		cin>>n;
		
		map<int,int> mp;
		for(int i=2;i*i<=n;i++){
			while(n%i==0){
				mp[i] ++;
				n/=i;
			}
		}
		
		if(n!=1)mp[n] ++;
		
		int a = 1,b = 1,c = 1;
		
		if(mp.size()>=3){
			int now = 0;
			for(auto x:mp){
				for(int i=0;i<x.second;i++){
					if(now%3==0)a *= x.first;
					else if(now%3==1)b*=x.first;
					else c *= x.first;
				}
				now++;
			}
			cout<<"YES"<<endl;
			cout<<a<<' '<<b<<' '<<c<<endl;
		}
		else if(mp.size()==2){
			int now = 0;
			for(auto x:mp){
				if(now==0)a *= x.first;
				else b *= x.first;
				for(int i=0;i<x.second-1;i++){
					c *= x.first;
				}
				now++;
			}
			if(a==b||b==c||c==a||c==1)cout<<"NO"<<endl;
			else{
				cout<<"YES"<<endl;
				cout<<a<<' '<<b<<' '<<c<<endl;
			}
		}
		else{
			int now = (*(mp.begin())).first;
			int cnt = (*(mp.begin())).second;
			if(cnt<6){
				cout<<"NO"<<endl;
				continue;
			}
			a = now;
			b = now*now;
			cnt-=3;
			for(int i=0;i<cnt;i++)c*=now;
			cout<<"YES"<<endl;
			cout<<a<<' '<<b<<' '<<c<<endl;
		}
		
	}
	
	return 0;
}