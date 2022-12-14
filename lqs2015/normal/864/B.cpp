#include<iostream>
#include<string>
#include<cstring>
using namespace std;
string s;
int mx,cnt,n;
bool used[33];
int main()
{
	cin>>n>>s;
	for (int i=0;i<n;i++)
	{
		if (s[i]>='A' && s[i]<='Z')
		{
			mx=max(mx,cnt);
			memset(used,0,sizeof(used));
			cnt=0;
		}
		else 
		{
			if (!used[s[i]-'a']) cnt++;
			used[s[i]-'a']=1;
		}
	}
	mx=max(mx,cnt);
	cout<<mx<<endl;
	return 0;
}