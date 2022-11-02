#include<cstdio>
#include<string>
#include<iostream>
#include<map>
using namespace std;
const int N=200002;
string s[N];
map<string,bool>a;
int n,i;
int main(){
	scanf("%d",&n);
	for(i=n;i;i--)
		cin>>s[i];
	for(i=1;i<=n;i++)
		if(!a[s[i]])
			cout<<s[i]<<endl,
			a[s[i]]=1;
}