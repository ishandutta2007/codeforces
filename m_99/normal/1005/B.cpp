#include <bits/stdc++.h>
using namespace std;




int main(){
	string s,t;
	cin>>s>>t;
	int ans = 0;
	if(s.size()>t.size()){
		ans+=s.size()-t.size();
		s=s.substr(s.size()-t.size());
	}
	else if(s.size()<t.size()){
		ans+=t.size()-s.size();
		t=t.substr(t.size()-s.size());
	}
	for(int i=0;i<s.size();i++){
		int x = s.size()-1-i;
		if(s[x]!=t[x]){
			ans+=(s.size()-i)*2;
			break;
		}
	}
	
	cout<<ans<<endl;
	
	return 0;
}