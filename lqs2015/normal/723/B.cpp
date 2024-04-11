#include<iostream>
#include<string>
using namespace std;
int mx,cnt,n,t,len;
string s;
int main()
{
	cin>>n;
	cin>>s;
	for (int i=0;i<s.size();i++)
	{
		char c=s[i];
		if (c=='(') 
		{
			t++;
			if (len) 
			{
				mx=max(mx,len);
				len=0;
			}
		}
		else if (c==')') 
		{
			t--;
			if (len) 
			{
				cnt++;
				len=0;
			}
		}
		else if (c=='_')
		{
			if (!len) continue;
			if (t) cnt++;
			else mx=max(mx,len);
			len=0;
		}
		else len++;
	}
	if (len) mx=max(mx,len);
	cout<<mx<<" "<<cnt<<endl;
	return 0;
}