#include<iostream>
#include<string>
#include<queue>
using namespace std;
int u[11],cnt[11];
string s;
bool f[11];
queue<int> q;
int main()
{
	cin>>s;
	for (int i=0;i<=3;i++) u[i]=-1;
	for (int i=0;i<=3;i++)
	{
		f[i]=0;
		for (int j=i;j<s.size();j+=4)
		{
			if (s[j]!='!') 
			{
				if (s[j]=='R') u[1]=i;
				else if (s[j]=='B') u[2]=i;
				else if (s[j]=='Y') u[3]=i;
				else u[4]=i;
				f[i]=1;
			}
			else cnt[i]++;
		}
		if (!f[i]) q.push(i); 
	}
	for (int i=1;i<=4;i++) 
	{
		if (u[i]==-1)
		{
			int x=q.front();
			q.pop();
			u[i]=x;
		}
	}
	for (int i=1;i<=4;i++)
	{
		if (i-1) cout<<" ";
		cout<<cnt[u[i]];
	}
	cout<<endl;
	return 0;
}