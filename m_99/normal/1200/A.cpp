#include <bits/stdc++.h>
using namespace std;
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x))%modulo)
#define Inf 10000000000000000


int main(){
	
	int n;
	cin>>n;
	
	string s;
	cin>>s;
	
	string ans = "0000000000";
	
	for(int i=0;i<s.size();i++){
		if(s[i]<='9'&&s[i]>='0'){
			ans[s[i]-'0']='0';
		}
		else{
			if(s[i]=='L'){
				for(int j=0;j<10;j++){
					if(ans[j]=='0'){
						ans[j]='1';
						break;
					}
				}
			}
			else{
				for(int j=9;j>=0;j--){
					if(ans[j]=='0'){
						ans[j] = '1';
						break;
					}
				}
			}
		}
		
	}
	
	cout<<ans<<endl;
	
		
	
	return 0;
}