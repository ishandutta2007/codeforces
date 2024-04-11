#include<iostream>
#include<string>
using namespace std;
long long x,y,xx[111],yy[111],a,b;
string s;
bool check(long long a,long long b)
{
	if (a*b<0) return 0;
	if (!b)
	{
		if (!a) return 1;
		return 0;
	}
	if (a%b==0) return 1;
	return 0;
}
int main()
{
	cin>>a>>b>>s;
	for (long long i=0;i<s.size();i++)
	{
		if (s[i]=='U') y++;
		else if (s[i]=='D') y--;
		else if (s[i]=='L') x--;
		else x++;
		xx[i]=x;yy[i]=y;
	}
	if (check(a,x) && check(b,y))
	{
		if ((x==0 || y==0) || (a/x==b/y)) 
		{
			cout<<"Yes"<<endl;
			return 0;
		}
	}
	for (long long i=0;i<s.size();i++)
	{
		if (check(a-xx[i],x) && check(b-yy[i],y))
		{
			if ((x==0 || y==0) || ((a-xx[i])/x==(b-yy[i])/y)) 
			{
				cout<<"Yes"<<endl;
				return 0;
			}
		}
	}
	cout<<"No"<<endl;
	return 0;
}