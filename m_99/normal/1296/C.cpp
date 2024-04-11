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
		
		string S;
		cin>>S;
		
		map<pair<int,int>,int> mp;
		int y = 0,x = 0;
		mp[{y,x}]=0;

		
		int l = -1,r = 10000000;
		
		for(int i=0;i<n;i++){
			if(S[i]=='U')y--;
			if(S[i]=='D')y++;
			if(S[i]=='L')x--;
			if(S[i]=='R')x++;
			
			if(mp.count({y,x})){
				if(r-l > i - mp[{y,x}]){
					l = mp[{y,x}]+1,r = i+1;
				}
			}
			mp[{y,x}] = i+1;
		}
		if(l==-1)cout<<-1<<endl;
		else{
			cout<<l<<' '<<r<<endl;
		}
	}
	
    return 0;
}