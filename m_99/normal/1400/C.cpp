#include <bits/stdc++.h>
using namespace std;
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 1000000000

int main(){
	
	int t;
	cin>>t;
	
	for(int _=0;_<t;_++){
		
		string s;
		cin>>s;
		int x;
		cin>>x;
		string ans(s.size(),'1');
		for(int i=0;i<s.size();i++){
			if(s[i]=='1')continue;
			if(i-x>=0)ans[i-x]='0';
			if(i+x<s.size())ans[i+x]='0';
		}
		
		bool f = true;
		for(int i=0;i<s.size();i++){
			if(s[i]=='0')continue;
			if(i-x>=0&&ans[i-x]=='1')continue;
			if(i+x<s.size()&&ans[i+x]=='1')continue;
			f=false;
			break;
		}
		
		if(f)cout<<ans<<endl;
		else cout<<-1<<endl;
	}
	
	return 0;
}