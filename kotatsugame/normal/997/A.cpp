#include<iostream>
#include<algorithm>
using namespace std;
string s;
long long x,y;
int n;
main()
{
	cin>>n>>x>>y>>s;
	long long cnt=0,cnt1=0;
	for(int i=0;i<s.size();i++)
	{
		cnt+=s[i]=='0'&&(i==0||s[i-1]=='1');
		cnt1+=s[i]=='1'&&(i==0||s[i-1]=='0');
	}
	long long ans=cnt*y;
	for(int i=0;i<cnt;i++)ans=min(ans,i*x+(cnt-i)*y);
	for(int i=0;i<cnt1;i++)ans=min(ans,i*x+(cnt1-i)*y+y);
	cout<<ans<<endl;
}