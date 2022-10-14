#include<bits/stdc++.h>
using namespace std;
string s,ans,sna;
int main(){
	ios::sync_with_stdio(0);
	cin>>s;
	int l=0,r=s.size()-1;
	while(l<r){
		if(s[l]==s[r])
			ans.push_back(s[l]),sna.push_back(s[r]),l++,r--;
		else if(s[l]==s[r-1])r--;
		else l++;
		if(l==r)ans.push_back(s[l]);
	}
	reverse(sna.begin(),sna.end());
	ans+=sna;
	if(ans.size()>=s.size()/2)
		cout<<ans;
	else cout<<"IMPOSSIBLE\n";
}//