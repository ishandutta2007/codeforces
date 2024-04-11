#include<bits/stdc++.h>
using namespace std;
string s;
vector<pair<char,int> >ans; 
int main(){
	ios::sync_with_stdio(0);
	cin>>s,s="00"+s;
	for(int i=s.size()-1,p=0;~i;i--)
		if(p^s[i]&1)
			ans.push_back({(p=s[i-1]&1)?'-':'+',s.size()-i-1});
	cout<<ans.size()<<"\n";
	for(auto i:ans)
		cout<<i.first<<"2^"<<i.second<<"\n";
}