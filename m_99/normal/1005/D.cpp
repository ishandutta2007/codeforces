#include <bits/stdc++.h>
using namespace std;


int main(){
	string s;
	cin>>s;
	int ans = 0;
	int mod = 0;
	bool flag = false;
	for(int i=0;i<s.size();i++){
		int x = s[i]-'0';
		if(x%3==0){
			ans++;
			mod=0;
			flag=false;
			continue;
		}
		if(flag){
			ans++;
			flag=false;
			mod=0;
			continue;
		}
		if(mod!=0)flag=true;
		mod=(mod+x)%3;
		if(mod==0){
			flag=false;
			ans++;
		}
	}
	
	cout<<ans<<endl;
	
	
	return 0;
}