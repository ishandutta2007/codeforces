#include <bits/stdc++.h>
using namespace std;
int main(){
	string s;
	cin>>s;
	for(int i=0;i<5;i++){
		string go;
		cin>>go;
		if(go[0]==s[0]||go[1]==s[1]){
			cout<<"YES\n";
			return 0;
		}
	}
	cout<<"NO\n";
	return 0;
}