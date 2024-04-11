#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<string>
using namespace std;
const int MAXN=5000010;
int n,r,c,now,next[MAXN],res[MAXN],tmp[MAXN],len[MAXN],tot,sub;
string str[MAXN];
void qpow(int x)
{
	if(x==1)
	{
		for(int i=1;i<=n+1;i++)
			res[i]=next[i];
		return;
	}
	qpow(x>>1);
	for(int i=1;i<=n+1;i++) res[i]=res[res[i]];
	if(x&1)
	{
		for(int i=1;i<=n+1;i++)
			res[i]=next[res[i]];
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin>>n>>r>>c;
	for(int i=1;i<=n;i++) cin>>str[i];
	for(int i=1;i<=n;i++) len[i]=str[i].length();
	now=0,tot=-1;
	for(int i=1;i<=n;i++)
	{
		if(now<i-1) tot=-1,now=i-1;
		while(now+1<=n&&tot+len[now+1]+1<=c)
			now++,tot+=len[now]+1;
		next[i]=now+1;
		tot-=len[i]+1;
	}
	next[n+1]=n+1;
	qpow(r);
	for(int i=1;i<=n;i++)
		if(res[i]-i>res[sub]-sub) sub=i;
	tot=0;
	for(int i=sub;i<res[sub];i++)
	{
		if(i==sub) cout<<str[i],tot=len[i];
		else
		{
			if(tot+len[i]+1<=c) cout<<" ",tot++;
			else cout<<endl,tot=0;
			tot+=len[i];
			cout<<str[i];
		}
	}
	cout<<endl;
	return 0;
}