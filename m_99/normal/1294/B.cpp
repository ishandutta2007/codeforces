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
		
		vector<pair<int,int>> p(n+1,make_pair(0,0));
		for(int i=0;i<n;i++)cin>>p[i+1].first>>p[i+1].second;
		sort(p.begin(),p.end());
		
		string ans = "";
		bool f = true;
		for(int i=1;i<=n;i++){
			int a = p[i].first - p[i-1].first;
			int b = p[i].second - p[i-1].second;
			
			if(a<0||b<0){
				f = false;
				break;
			}
			for(int j=0;j<a;j++)ans += 'R';
			for(int j=0;j<b;j++)ans += 'U';
		}
		
		if(f){
			cout<<"YES"<<endl;
			cout<<ans<<endl;
		}
		else{
			cout<<"NO"<<endl;
		}
		
	}
	
	return 0;
}