#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

const int MaxN=1<<19;

int n;
int x[MaxN],y[MaxN],h[MaxN],s[MaxN];
vector<int> p;
int v[MaxN<<1];
vector<pair<int,int> > ans;

void add(int k,int L,int R,int x,int y,int h)
{
	if (L==x&&R==y)
	{
		v[k]=max(v[k],h);
		return;
	}
	int mid=(L+R)>>1;
	if (y<=mid)
		add(k<<1,L,mid,x,y,h);
	else if (x>mid)
		add(k<<1|1,mid+1,R,x,y,h);
	else
	{
		add(k<<1,L,mid,x,mid,h);
		add(k<<1|1,mid+1,R,mid+1,y,h);
	}
}

int get(int x)
{
	int h=0;
	for (int k=x+MaxN-1;k;k>>=1)
		h=max(h,v[k]);
	return h;
}

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	cin>>n;
	for (int i=1;i<=n;++i)
	{
		scanf("%d%d%d",&h[i],&x[i],&y[i]);
		p.push_back(x[i]-1);
		p.push_back(x[i]);
		p.push_back(y[i]);
		p.push_back(--y[i]);
	}
	sort(p.begin(),p.end());
	p.erase(unique(p.begin(),p.end()),p.end());
	for (int i=1;i<=n;++i)
	{
		x[i]=lower_bound(p.begin(),p.end(),x[i])-p.begin()+1;
		y[i]=lower_bound(p.begin(),p.end(),y[i])-p.begin()+1;
		add(1,1,MaxN,x[i],y[i],h[i]);
	}
	for (int i=1;i<p.size();++i)
	{
		s[i+1]=get(i+1);
		if (s[i]!=s[i+1])
		{
			ans.push_back(make_pair(p[i],s[i]));
			ans.push_back(make_pair(p[i],s[i+1]));
		}
	}
	cout<<ans.size()<<endl;
	for (int i=0;i<ans.size();++i)
		printf("%d %d\n",ans[i].first,ans[i].second);
	return 0;
}