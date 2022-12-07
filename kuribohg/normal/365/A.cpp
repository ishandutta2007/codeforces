#include<iostream>
#include<string>
#include<cstring>
using namespace std;
bool used[10];
int n,k,len,ans;
string str;
void check()
{
	for(int i=0;i<=k;i++)
		if(!used[i]) return;
	ans++;
}
int main()
{
	cin>>n>>k;
	for(int p=1;p<=n;p++)
	{
		cin>>str;
		len=str.length();
		for(int i=0;i<len;i++)
			used[str[i]-'0']=true;
		check();
		memset(used,0,sizeof(used));
	}
	cout<<ans<<endl;
	return 0;
}