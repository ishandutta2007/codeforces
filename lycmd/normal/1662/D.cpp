#include<bits/stdc++.h>
using namespace std;
int t;
string a,b;
string calc(string s){
	string t="";
	int cnt=0;
	for(char i:s)
		if(i=='B')cnt++;
		else if(!t.empty()&&i==t.back())t.pop_back();
		else t+=i;
	return t+string(cnt&1,'B');
}
int main(){
	ios::sync_with_stdio(0);
	for(cin>>t;t--;)
		cin>>a>>b,cout<<(calc(a)==calc(b)?"YES\n":"NO\n");
}