#include<iostream>
#include<string>
#include<cstring>
#include<vector>
using namespace std;
long long has[5555][5555],sz,p,ans[5555],hash1,hash2;
vector<long long> deg[5555];
string s;
int main()
{
	cin>>s;
	for (int i=0;i<s.size();i++)
	{
		has[i][i]=s[i]-'a';
		for (int j=i+1;j<s.size();j++)
		{
			has[i][j]=has[i][j-1]*31+(s[j]-'a');
		}
	}
	for (int i=0;i<s.size();i++)
	{
		for (int j=i;j<s.size();j++) deg[j].clear();
		hash1=hash2=0;p=1;
		for (int j=i;j<s.size();j++)
		{
			hash1=hash1*31+(s[j]-'a');
			hash2=hash2+p*(s[j]-'a');
			sz=(j-i+1)/2;
			if (sz && has[i][i+sz-1]==has[j-sz+1][j])
			{
				for (int k=0;k<deg[i+sz-1].size();k++)
				{
					deg[j].push_back(deg[i+sz-1][k]+1);
					ans[deg[i+sz-1][k]+1]++;
				}
			} 
			if (hash1==hash2) 
			{
				deg[j].push_back(1);
				ans[1]++; 
			}
			p*=31;
		}
	}
	for (int i=1;i<=s.size();i++) cout<<ans[i]<<" ";
	cout<<endl;
	return 0;
}