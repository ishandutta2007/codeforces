#include <bits/stdc++.h>
using namespace std;
#define modulo 998244353
#define mod(mod_x) ((mod_x)%modulo)
#define Inf 1000000001

int main(){
	
	int n;
	cin>>n;
	
	string s;
	cin>>s;
	
	int ans = 0;
	
	for(int i=0;i<n;i+=2){
		if(s[i]!=s[i+1])continue;
		if(s[i]=='a'){
			ans++;
			s[i]='b';
		}
		else{
			ans++;
			s[i]='a';
		}
	}
	
	cout<<ans<<endl;
	cout<<s<<endl;
	
    return 0;
}