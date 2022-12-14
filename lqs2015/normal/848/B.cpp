#include<iostream>
#include<cstdio>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;
int n,W,H,tp,ww,k,sh,sz;
pair<int,int> fin[111111];
map<int,vector<pair<int,int> > > mph,mpz;
map<int,bool> used;
pair<int,int> ans[111111];
vector<pair<int,int> > h,z;
int main()
{
	scanf("%d%d%d",&n,&W,&H);
	for (int i=1;i<=n;i++)
	{
		scanf("%d%d%d",&tp,&k,&ww);
		if (tp==1)
		{
			mpz[ww-k].push_back(make_pair(k,i));
			fin[i]=make_pair(k,H);
		}
		else
		{
			mph[ww-k].push_back(make_pair(k,i));
			fin[i]=make_pair(W,k);
		}
	}
	for (map<int,vector<pair<int,int> > >::iterator it=mpz.begin();it!=mpz.end();it++)
	{
		z=it->second;
		if (mph.find(it->first)==mph.end()) h.clear();
		else h=mph[it->first];
		sh=h.size();sz=z.size();
		if (sz>sh)
		{
			sort(z.begin(),z.end());
			sort(h.begin(),h.end());
			reverse(h.begin(),h.end());
			for (int i=0;i<sh;i++)
			{
				ans[h[i].second]=fin[z[i].second];
			}
			for (int i=sh;i<sz;i++)
			{
				ans[z[i-sh].second]=fin[z[i].second];
			}
			for (int i=sz-sh;i<sz;i++)
			{
				ans[z[i].second]=fin[h[i-sz+sh].second];
			}
		}
		else
		{
			sort(z.begin(),z.end());
			sort(h.begin(),h.end());
			reverse(h.begin(),h.end());
			for (int i=0;i<sz;i++)
			{
				ans[h[i].second]=fin[z[i].second];
			}
			for (int i=sz;i<sh;i++)
			{
				ans[h[i].second]=fin[h[i-sz].second];
			}
			for (int i=0;i<sz;i++)
			{
				ans[z[i].second]=fin[h[i+sh-sz].second];
			}
		}
		used[it->first]=1;
	}
	for (map<int,vector<pair<int,int> > >::iterator it=mph.begin();it!=mph.end();it++)
	{
		if (used[it->first]) continue;
		h=it->second;
		sh=h.size();
		for (int i=0;i<sh;i++)
		{
			ans[h[i].second]=fin[h[i].second];
		}
	}
	for (int i=1;i<=n;i++)
	{
		printf("%d %d\n",ans[i].first,ans[i].second);
	}
	return 0;
}