#include<bits/stdc++.h>
using namespace std;
string s;
int cnt;
int main(){
	ios::sync_with_stdio(0);
	cin>>s,s+=s+s;
	for(int i=0;i<s.size()/3;i++)
		if(s[i]^s[i+1])
			cnt+=s[i]^s[i+2]||s[i]^s[i+3],i+=s[i]!=s[i+3];
	cout<<cnt<<"\n";
}