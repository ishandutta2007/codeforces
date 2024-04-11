#include<bits/stdc++.h>
using namespace std;
int main(){
	string s;
	cin>>s;
	if(s.find("AB")!=-1){
		string t=s;
		t.replace(s.find("AB"),2,".");
		if(t.find("BA")!=-1)return puts("YES")*0;
	}
	if(s.find("BA")!=-1){
		string t=s;
		t.replace(s.find("BA"), 2,".");
		if(t.find("AB")!=-1)return puts("YES")*0;
	}
	cout<<"NO"<<endl;
}