#include<iostream>
#include<string>

using namespace std;

int main(){
	int d[3]={0,0,0};
	char c;
	string s;
	string aux="";
	cin>>s;
	for(int i=0;i<s.size();i++)
		if(s[i]!='+')
			d[s[i]-'1']++;
	while(d[0]-->0)aux+= "1+"; 
	while(d[1]-->0)aux+= "2+"; 
	while(d[2]-->0)aux+= "3+";
	cout<<aux.substr(0,aux.size()-1);
	return 0;
}