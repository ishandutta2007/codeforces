#include<bits/stdc++.h>
using namespace std;
int s[1000005],lft,rht;
bool c[1000005];
char mp[2][1000005];
int main(){
	int n,m;
	cin>>n>>m;
	for(int x=1;x<=n;x++)
	{
		cin>>mp[x&1]+1;
		for(int y=1;y<=m;y++)
		c[y]|=(mp[x&1][y]=='X'&&mp[!(x&1)][y+1]=='X');
	}
	for(int x=1;x<=m;x++)
	s[x]=s[x-1]+c[x];
	int q;
	cin>>q;
	while(q--)
	{
		int l,r;
		cin>>l>>r;
		if(l==r)cout<<"yes"<<endl;
		else if(s[r-1]-s[l-1]>0)cout<<"no"<<endl;
		else cout<<"yes"<<endl;
	}
}