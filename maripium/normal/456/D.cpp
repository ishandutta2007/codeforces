#include<bits/stdc++.h>
using namespace std;
const int	MAXN=1e5+5;
struct	trie	{
	int child[26],nchild;
	bool have[26],win,lose;
}	a[8*MAXN];
int n,q,cnt=0;
void update(string s,int pos,int pre)	{
	int x=s[pos]-'a';
	if(a[pre].have[x]==0)	{
		a[pre].have[x]=1;
		a[pre].win=false;
		a[pre].lose=false;
		a[pre].nchild++;
		a[pre].child[x]=++cnt;
	}
	if(pos==s.size()-1)	return;
	update(s,pos+1,a[pre].child[x]);
}
void dfs(int pre)	{
	if(a[pre].nchild==0)	{
		a[pre].win=false;
		a[pre].lose=true;
		return;
	}
	for(int i=0;i<26;++i)
		if(a[pre].have[i]==1)	{
			int v=a[pre].child[i];
			dfs(v);
			if(a[v].win==false)	a[pre].win=true;
			if(a[v].lose==false)	a[pre].lose=true;	
		}
}
int main()	{
	ios_base::sync_with_stdio(0);	cin.tie(0);
	cin>>n>>q;
	while(n--)	{
		string s;	cin>>s;	update(s,0,0);
	}
	dfs(0);
	if(a[0].win && (a[0].lose || q%2==1))	cout<<"First";
	else	cout<<"Second";
}