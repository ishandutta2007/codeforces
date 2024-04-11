#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<string>
using namespace std;
string a,b;
string work(string str)
{
	int len=str.size();
	if(len&1) return str;
	string str1=str.substr(0,len>>1);
	string str2=str.substr(len>>1,len>>1);
	str1=work(str1),str2=work(str2);
	return min(str1+str2,str2+str1);
}
int main()
{
	cin>>a>>b;
	if(work(a)==work(b)) puts("YES");
	else puts("NO");
	return 0;
}