#include<bits/stdc++.h>
#define Accepted 0
using namespace std;
int n,cnt,len,l,r;
string s;
bool f;
int main()
{
	cin>>s;
	n=s.size();
	for (int i=0;i<n;i++)
	{
		if (s[i]=='a') cnt++;
	}
	if ((n-cnt)&1)
	{
		printf(":(\n");
		return 0;
	}
	len=(n-cnt)/2+cnt;
	l=0;r=len;
	while(l<len)
	{
		while(l<len && s[l]=='a') l++;
		if (l>=len && r<n) 
		{
			f=1;
			break;
		}
		if (r>=n && l<len) 
		{
			f=1;
			break;
		}
		if (l>=len) break;
		if (s[r]=='a') 
		{
			f=1;
			break;
		}
		if (s[l]!=s[r]) 
		{
			f=1;
			break;
		}
		l++;r++;
	}
	if (f) printf(":(\n");
	else 
	{
		for (int i=0;i<len;i++) printf("%c",s[i]);
		printf("\n");
	}
	return Accepted;
}