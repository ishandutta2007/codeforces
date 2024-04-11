#include<iostream>
#include<string>
using namespace std;
int k,ans,cnt;
bool used[33];
string s;
int main()
{
	cin>>s>>k;
	if (k>s.size()) 
	{
		cout<<"impossible"<<endl;
		return 0;
	}
	for (int i=0;i<s.size();i++)
	{
		if (!used[s[i]-'a'])
		{
			cnt++;
			used[s[i]-'a']=1;
		}
	}
	cout<<max(0,k-cnt)<<endl;
	return 0;
}