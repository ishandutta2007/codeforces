#include<iostream>
#include<cstdio>
#include<string>
using namespace std;

string s,ans;

int main(){
	getline(cin, s);
	int n = s.size();
	
	for(int i = 0; i < n;){
		while(i < n && s[i] == ' ') ++i;
		if(i == n) break;
		
		if(s[i] == ',')
			ans += ", ", ++i;
		else if(isdigit(s[i])){
			if(isdigit(ans[ans.size() - 1])) ans += ' ';
			while(i < n && isdigit(s[i])) ans += s[i++];
		}
		else if(s[i] == '.'){
			if(!ans.empty() && ans[ans.size() - 1] != ' ') ans += ' ';
			ans += "...";
			i += 3;
		}
	}
	if(ans[ans.size() - 1] == ' ') ans = ans.substr(0, ans.size() - 1);
	
	cout << ans;
	return 0;
}
//CF81B