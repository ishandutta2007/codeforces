#include<cstdio>
#include<string>
#include<iostream>
using std::cin;
using std::cout;
using std::string;
string pw,t;
bool book[2][2];
int n;
signed main()
{
	int i,j;
	cin>>pw;
	scanf("%d",&n);
	while(n--)
	{
		cin>>t;
		if(t.find(pw,0)!=string::npos)
		{
			puts("YES");
			return 0;
		}
		if(*t.begin()==pw[0])
			book[0][0]=1;
		if(*t.begin()==pw[1])
			book[1][0]=1;
		if(t[t.size()-1]==pw[0])
			book[0][1]=1;
		if(t[t.size()-1]==pw[1])
			book[1][1]=1;
	}
	if(book[0][1]&&book[1][0])
	{
		puts("YES");
		return 0;
	}
	puts("NO");
	return 0;
}