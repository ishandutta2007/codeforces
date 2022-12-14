#include<iostream>
#include<map>
#include<string>
#include<algorithm>
using namespace std;
map<string,int> mp[55];
string name;
int n,k;
int score[11]={-1,25,18,15,12,10,8,6,4,2,1};
string NAME[1111],NAM[1111];
int t;
bool cmp1(string i,string j)
{
	for (int k=0;k<=50;k++)
	{
		if (mp[k][i]!=mp[k][j]) return mp[k][i]>mp[k][j];
	}
	return i>j;
}
bool cmp2(string i,string j)
{
	if (mp[1][i]!=mp[1][j]) return mp[1][i]>mp[1][j];
	if (mp[0][i]!=mp[0][j]) return mp[0][i]>mp[0][j];
	for (int k=2;k<=50;k++)
	{
		if (mp[k][i]!=mp[k][j]) return mp[k][i]>mp[k][j];
	}
	return i>j;
}
bool fiod(string &s)
{
	for (int i=1;i<=t;i++)
	{
		if (NAME[i]==s) return 1;
	}
	return 0;
}
int main()
{
	cin>>n;
	for (int i=1;i<=n;i++)
	{
		cin>>k;
		for (int j=1;j<=k;j++)
		{
			cin>>name;
			if (!fiod(name)) NAME[++t]=name;
			if (j<=10)
			{
				mp[0][name]+=score[j];
			}
			mp[j][name]++;
		}
	}
	for (int i=1;i<=t;i++)
	{
		NAM[i]=NAME[i];
	}
	sort(NAME+1,NAME+t+1,cmp1);
	sort(NAM+1,NAM+t+1,cmp2);
	cout<<NAME[1]<<endl<<NAM[1]<<endl;
	return 0;
}