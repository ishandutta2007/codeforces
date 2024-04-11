#include<bits/stdc++.h>
using namespace std;
int a,b;
bool work()
{
	int a,b;
	string s;
	cin>>a>>b>>s;
	int cnt=0,ret=0,len;
	for(int x=0;x<s.size();x++)
	if(s[x]!='X')
	{
		int y=x;
		while(s[y]=='.'&&y<s.size())y++;
		if(y-x>=b&&y-x<a)return false;
		if(y-x>=2*b)cnt++,len=y-x;
		if(y-x>=a&&y-x<2*b)ret++;
		x=y-1;
	}
	if(cnt>1)return false;
	if(!cnt)return (ret&1);
	for(int x=1;x<=len-a+1;x++)
	if((!(len-x-a+1>=2*b||x-1>=2*b||(x-1>=b&&x-1<a)||(len-x-a+1>=b&&len-x-a+1<a)))&&((ret+(x-1>=a&&x-1<2*b)+(len-x-a+1>=a&&len-x-a+1<2*b))%2==0))return true;
	return false;
}
int main()
{
	int t;
	cin>>t;
	while (t--)
	if(work())cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
}