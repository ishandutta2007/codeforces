#include <iostream>
#include <map>
#include <string>
using namespace std;
map<string,int> un;
int main(){
	int n;
	string s;
	cin>>n;
	while(n--){
		cin>>s;
		if(un[s]==0)
			cout<<"OK"<<endl;
		else
			cout<<s<<un[s]<<endl;
		un[s]++;
	}
	return 0;
}