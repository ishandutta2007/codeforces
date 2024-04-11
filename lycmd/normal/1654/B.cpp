#include<bits/stdc++.h>
using namespace std;
int const N=233333;
int t,pos[33];
string s;
int main(){
	ios::sync_with_stdio(0);
	for(cin>>t;t--;){
		cin>>s;
		memset(pos,0,sizeof pos);
		for(int i=0;i<s.size();i++)
			pos[s[i]-96]=i;
		for(int i=0;i<s.size();i++)
			if(pos[s[i]-96]==i){
				cout<<s.substr(i)<<"\n";
				break;
			}
	}
	return 0;
}