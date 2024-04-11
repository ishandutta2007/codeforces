#include <bits/stdc++.h>
using namespace std;
int main(){
	string s;
	cin>>s;
	string hello="hello";
	int cnt=0;
	for(int i=0;i<s.length();i++){
		if(s[i]==hello[cnt])cnt++;
		if(cnt==5)break;
	}
	cout<<(cnt==5?"YES\n":"NO\n");
}