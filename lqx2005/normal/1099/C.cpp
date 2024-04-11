#include<bits/stdc++.h>
using namespace std;
const int N=200;
const int INF=200000;
struct node
{
	char w;
	int flag;
};
vector<node> v;
vector<char> t;
string s;
int vis[N+5];
int slen,n;
int main()
{
	cin>>s;
	slen=s.length();
	for(int i=0;i<slen-1;i++)
	{
		if(s[i]<'a'||s[i]>'z') continue;
		if(s[i+1]=='*') v.push_back(node{s[i],-1});
		else if(s[i+1]=='?') v.push_back(node{s[i],1});
		else v.push_back(node{s[i],0});
	}
	if(s[slen-1]>='a'&&s[slen-1]<='z') v.push_back(node{s[slen-1],0});
	cin>>n;
	int check=0;
	for(int i=0;i<v.size();i++) 
	{
		if(!v[i].flag)
		{
			vis[i]=1;
			t.push_back(v[i].w);
		}
		else if(v[i].flag==1) check++;
		else check+=INF;
	}
	for(int i=1;i<v.size();i++) vis[i]+=vis[i-1];
	if(t.size()>n||t.size()+check<n)
	{
		printf("Impossible\n");
		return 0;
	}
	int len=n-t.size();
	t.clear();
	for(int i=0;i<v.size();i++)
	{
		if(v[i].flag==1)
		{
			if(len<=0) continue;
			t.push_back(v[i].w);
			len--;
		}
		else if(v[i].flag==-1)
		{
			if(len<=0) continue;
			while(len--) t.push_back(v[i].w);
			len=0;
		}
		else t.push_back(v[i].w);
	}
	for(int i=0;i<t.size();i++) cout<<t[i];
	cout<<endl;
	return 0;
}