#include<cstdio>
#include<cstring>
#include<iostream>
#include<string>

using namespace std;

const int MaxN=110;

int n;
string s;

long long F[MaxN][2];

long long solve(int flag)
{
	memset(F,0,sizeof(F));
	F[0][flag]=1;
	for (int i=1;i<=n;++i)
	{
		if (s[i]=='B')
			F[i][1]=F[i-1][1];
		else
		{
			F[i][0]=F[i-1][0]+F[i-1][1];
			if (s[i-1]=='B')
				F[i][1]=F[i-2][0]+F[i-2][1];
		}
	}
	return F[n][flag];
}

int main()
{
	string t;
	cin>>t;
	n=t.length();
	int pos=-1;
	for (int i=0;i<n;++i)
		if (t[i]=='B') pos=i;
	if (pos==-1)
	{
		puts("1");
		return 0;
	}
	s+='B';
	for (int i=pos;i<n;++i)
		s+=t[i];
	for (int i=0;i<pos;++i)
		s+=t[i];
	s+='B';
	cout<<solve(0)+solve(1)<<endl;
	return 0;
}