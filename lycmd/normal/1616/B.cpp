#include<bits/stdc++.h>
using namespace std;
int t,n;
string s;
int main(){
	ios::sync_with_stdio(0);
	for(cin>>t;t--;){
		cin>>n>>s;
		int i=0,flg=0;
		for(;i<n-1&&(s[i]>s[i+1]||(s[i]==s[i+1]&&flg));i++)
			if(s[i]>s[i+1])flg=1;
		string t=s.substr(0,i+1);
		cout<<t;
		reverse(t.begin(),t.end());
		cout<<t<<"\n";
	}
	return 0;
}