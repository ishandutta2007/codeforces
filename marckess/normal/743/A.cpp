#include<iostream>
#include<string>

using namespace std;

int main(){
	int n;
	int a;
	int b;
	string s;
	char id1;
	char id2;
	char aux;
	cin>>n>>a>>b>>s;
	id1 = s[a-1];
	id2 = s[b-1];
	if(id1==id2)
		cout<<0;
	else
		cout<<1;
}