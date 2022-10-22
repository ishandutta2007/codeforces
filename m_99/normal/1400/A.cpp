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
		string s;
		cin>>s;
		
		string ans = "";
		for(int i=0;i<s.size();i+=2)ans += s[i];
		cout<<ans<<endl;
	}
	
	return 0;
}