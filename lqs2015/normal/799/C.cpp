#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int bit[111111],n,co,di,x,y,mxa,mxb,ans;
vector<pair<int,int> > c,d;
char ch;
void change(int cost,int beau)
{
	int i=cost;
	while(i<=100000)
	{
		bit[i]=max(bit[i],beau);
		i+=i&-i;
	}
}
int get(int cost)
{
	int i=cost,res=0;
	while(i>=1)
	{
		res=max(res,bit[i]);
		i-=i&-i;
	}
	return res;
}
int main()
{
	scanf("%d%d%d",&n,&co,&di);
	for (int i=1;i<=n;i++)
	{
		scanf("%d %d %c",&x,&y,&ch);
		if (ch=='C') 
		{
			if (y<=co) mxa=max(mxa,x);
			c.push_back(make_pair(y,x)); 
		}
		else
		{
			if (y<=di) mxb=max(mxb,x);
			d.push_back(make_pair(y,x));
		}
	}
	if (mxa && mxb) ans=mxa+mxb;
	sort(c.begin(),c.end());
	sort(d.begin(),d.end());
	for (int i=0;i<c.size();i++)
	{
		int xx=get(co-c[i].first);
		change(c[i].first,c[i].second);
		if (xx) ans=max(ans,c[i].second+xx);
	}
	for (int i=1;i<=100000;i++) bit[i]=0;
	for (int i=0;i<d.size();i++)
	{
		int xx=get(di-d[i].first);
		change(d[i].first,d[i].second);
		if (xx) ans=max(ans,d[i].second+xx);
	}
	printf("%d\n",ans);
	return 0;
}