#include<bits/stdc++.h>
using namespace std;
int t;
string s;
int main(){
	ios::sync_with_stdio(0);
	cin>>t;
	while(t--){
		cin>>s;
		int p=0,mn=255;
		for(int i=0;i<s.size();i++)
			if(s[i]<mn)mn=s[i],p=i;
		cout<<(char)mn<<" ";
		for(int i=0;i<s.size();i++)
			if(i!=p)cout<<s[i];
		cout<<"\n";
	}
	return 0;
}