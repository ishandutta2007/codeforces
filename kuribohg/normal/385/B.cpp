#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
using namespace std;
string str;
int len;
int pos[10001],tot;
int ans;
bool used[6001][6001];
int main()
{
	cin>>str;
	len=str.length();
	for(int i=0;i<=len-4;i++)
		if(str.substr(i,4)=="bear") pos[++tot]=i,i+=3;
	pos[0]=-1;
	for(int i=1;i<=tot;i++)
		ans+=(pos[i]-pos[i-1])*(len-pos[i]-3);
	cout<<ans<<endl;
	return 0;
}