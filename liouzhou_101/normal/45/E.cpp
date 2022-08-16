#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
#include<string>

using namespace std;

int n;
vector<string> v[26],w[26];
int get[26],used[26];
vector<int> p[26];

int main()
{
	cin>>n;
	for (int i=1;i<=n;++i)
	{
		string s;
		cin>>s;
		v[s[0]-'A'].push_back(s);
	}
	for (int i=1;i<=n;++i)
	{
		string s;
		cin>>s;
		w[s[0]-'A'].push_back(s);
	}
	for (int i=0;i<26;++i)
	{
		sort(v[i].begin(),v[i].end());
		sort(w[i].begin(),w[i].end());
	}
	for (int i=0;i<26;++i)
	{
		get[i]=min(v[i].size(),w[i].size());
		for (int j=0;j<get[i];++j)
			p[i].push_back(i);
	}
	for (int i=0;i<26;++i)
		for (int j=get[i];j<w[i].size();++j)
			for (int k=0;k<26;++k)
				if (p[k].size()<v[k].size())
				{
					p[k].push_back(i);
					break;
				}
	for (int i=0,flag=0;i<26;++i)
	{
		sort(p[i].begin(),p[i].end());
		for (int j=0;j<p[i].size();++j)
		{
			if (flag) cout<<", ";
			flag=1;
			cout<<v[i][j]<<" "<<w[p[i][j]][used[p[i][j]]++];
		}
	}
	cout<<endl;
	return 0;
}