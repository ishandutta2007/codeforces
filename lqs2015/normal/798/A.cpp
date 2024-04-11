#include<iostream>
#include<string>
using namespace std;
string s;
int cnt;
int main()
{
	cin>>s;
	int n=s.size();
	for (int i=0;i<n/2;i++)
	{
		if (s[i]!=s[n-1-i]) cnt++;
	}
	if (cnt>1 || (!cnt && n%2==0)) cout<<"NO"<<endl;
	else cout<<"YES"<<endl;
	return 0;
 }