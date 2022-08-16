#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

const int MaxN=100010;

int n;
int a[MaxN],used[MaxN];

vector<int> v,tmp;

vector<vector<int> > list[4];

struct node
{
	int a[5],b[5];
}get;

vector<node> ans;

void init()
{
	cin>>n;
	for (int i=1;i<=n;++i)
		scanf("%d",&a[i]);
	for (int i=1;i<=n;++i)
	{
		if (used[i]) continue;
		v.clear();
		for (int x=i;!used[x];x=a[x])
		{
			v.push_back(x);
			used[x]=1;
		}
		for (int i=0;i<v.size();i+=4)
		{
			int len=min(v.size()-i,5u);
			if (len==1) break;
			tmp.clear();
			for (int j=0;j<len;++j)
				tmp.push_back(v[i+j]);
			if (len==2)
				list[2].push_back(tmp);
			else if (len==3)
				list[3].push_back(tmp);
			else
			{
				get.a[4]=get.b[4]=0;
				for (int j=0;j<len;++j)
				{
					get.a[j]=tmp[j];
					get.b[j]=tmp[(j+1)%len];
				}
				ans.push_back(get);
				if (len==5) v[i+4]=v[i];
			}
		}
	}
}

void work()
{
	while (!list[2].empty()&&!list[3].empty())
	{
		get.a[0]=get.b[1]=(*list[2].rbegin())[0];
		get.a[1]=get.b[0]=(*list[2].rbegin())[1];
		get.a[2]=get.b[4]=(*list[3].rbegin())[0];
		get.a[3]=get.b[2]=(*list[3].rbegin())[1];
		get.a[4]=get.b[3]=(*list[3].rbegin())[2];
		ans.push_back(get);
		list[2].pop_back();
		list[3].pop_back();
	}
	while (!list[2].empty())
	{
		for (int i=0;i<5;++i)
			get.a[i]=get.b[i]=0;
		get.a[0]=get.b[1]=(*list[2].rbegin())[0];
		get.a[1]=get.b[0]=(*list[2].rbegin())[1];
		list[2].pop_back();
		if (!list[2].empty())
		{
			get.a[2]=get.b[3]=(*list[2].rbegin())[0];
			get.a[3]=get.b[2]=(*list[2].rbegin())[1];
			list[2].pop_back();
		}
		ans.push_back(get);
	}
	while (list[3].size()>=3)
	{
		get.a[0]=get.b[2]=(*list[3].rbegin())[0];
		get.a[1]=get.b[0]=(*list[3].rbegin())[1];
		get.a[2]=get.b[1]=(*list[3].rbegin())[2];
		list[3].pop_back();
		get.a[3]=get.b[4]=(*list[3].rbegin())[0];
		get.a[4]=get.b[3]=(*list[3].rbegin())[1];
		(*list[3].rbegin())[1]=(*list[3].rbegin())[0];
		ans.push_back(get);
		get.a[3]=get.b[4]=(*list[3].rbegin())[1];
		get.a[4]=get.b[3]=(*list[3].rbegin())[2];
		list[3].pop_back();
		get.a[0]=get.b[2]=(*list[3].rbegin())[0];
		get.a[1]=get.b[0]=(*list[3].rbegin())[1];
		get.a[2]=get.b[1]=(*list[3].rbegin())[2];
		list[3].pop_back();
		ans.push_back(get);
	}
	while (!list[3].empty())
	{
		for (int i=0;i<5;++i)
			get.a[i]=get.b[i]=0;
		get.a[0]=get.b[2]=(*list[3].rbegin())[0];
		get.a[1]=get.b[0]=(*list[3].rbegin())[1];
		get.a[2]=get.b[1]=(*list[3].rbegin())[2];
		list[3].pop_back();
		ans.push_back(get);
	}
	cout<<ans.size()<<endl;
	for (int i=0;i<ans.size();++i)
	{
		int k=0;
		for (;ans[i].a[k];++k)
			if (k==5) break;
		printf("%d\n",k);
		for (int j=0;j<k;++j)
		{
			if (j) putchar(' ');
			printf("%d",ans[i].a[j]);
		}
		puts("");
		for (int j=0;j<k;++j)
		{
			if (j) putchar(' ');
			printf("%d",ans[i].b[j]);
		}
		puts("");
	}
}

int main()
{
	init();
	work();
	return 0;
}