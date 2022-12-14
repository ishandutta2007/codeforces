#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<algorithm>
using namespace std;
vector<string> anss;
int ans;
int combit(int n)
{
	int k=0;
	while(n)
	{
		k+=(n%2);
		n/=2;
	}
	return k;
}
map<string,int> mp;
int n,m;
string s,x,y,name[1111];
bool g[111][111],flag;
int main()
{
	cin>>n>>m;
	for (int i=0;i<n;i++)
	{
		cin>>s;
		name[i]=s;
		mp[s]=i;
	}
	for (int i=1;i<=m;i++)
	{
		cin>>x>>y;
		g[mp[x]][mp[y]]=g[mp[y]][mp[x]]=1;
	}
	for (int state=0;state<(1<<n);state++)
	{
		if (combit(ans)>=combit(state)) continue;
		flag=0;
		for (int i=0;i<n;i++)
		{
			for (int j=i+1;j<n;j++)
			{
				if ((state&(1<<i)) && (state&(1<<j)) && g[i][j])
				flag=1;
			}
		}
		if (!flag) ans=state;
	}
	for (int i=0;i<n;i++)
	{
		if (ans&(1<<i)) anss.push_back(name[i]);
	}
	sort(anss.begin(),anss.end());
	cout<<anss.size()<<endl;
	for (int i=0;i<anss.size();i++)
	{
		cout<<anss[i]<<endl;
	}
	return 0;
}