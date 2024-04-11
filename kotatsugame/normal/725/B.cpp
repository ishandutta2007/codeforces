#include<iostream>
#include<string>
#include<sstream>
using namespace std;
int main()
{
	string sint,s;
	cin>>s;
	sint=s.substr(0,s.length()-1);
	stringstream ss;
	ss<<sint;
	__int64 n,sum;
	ss>>n;
	if(n%4==1||n%4==3)sum=n/4*16;
	else sum=(n-1)/4*16+7;
	if(s[s.length()-1]=='f')sum++;
	else if(s[s.length()-1]=='e')sum+=2;
	else if(s[s.length()-1]=='d')sum+=3;
	else if(s[s.length()-1]=='a')sum+=4;
	else if(s[s.length()-1]=='b')sum+=5;
	else sum+=6;
	cout<<sum<<endl;
	return 0;
}