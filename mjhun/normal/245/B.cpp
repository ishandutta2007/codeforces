#include <iostream>
#include <string>
using namespace std;

int main(){
	string s;
	int x;
	getline(cin,s);
	x=s.find('p',0);
	s.insert(x+1,"://");
	x=s.find("ru",x+5);
	s.insert(x,".");
	if(x+3<s.size())
		s.insert(x+3,"/");
	cout<<s<<endl;
	return 0;
}