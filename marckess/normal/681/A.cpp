#include<iostream>
#include<string>
#include<vector>

using namespace std;

int main(){
	int n;
	string s;
	int a;
	int b;
	cin>>n;
	bool f = false;
	while(n-->0){
		cin>>s>>a>>b;
		if(a>=2400 && b>a)
			f = true;
	}
	if(f)
		cout<<"YES";
	else
		cout<<"NO";
}