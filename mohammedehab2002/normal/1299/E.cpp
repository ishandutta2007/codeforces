#include <bits/stdc++.h>
using namespace std;
int n,mod[6][805],ans[805],inv[805];
int query(vector<int> v)
{
	printf("? %d",v.size());
	for (int i:v)
	printf(" %d",i);
	printf("\n");
	fflush(stdout);
	int ans;
	scanf("%d",&ans);
	return ans;
}
void put(int i,int val)
{
	ans[i]=val;
	inv[val]=i;
}
void go(int a,int m)
{
	for (int i=1;i<=n;i++)
	{
		if (!ans[i])
		{
			vector<int> v;
			for (int j=1;j<=m;j++)
			v.push_back(inv[j]);
			if (a<3)
			{
				mod[a][i]=mod[a-1][i];
				v.pop_back();
				for (int j=n;j>n-(1<<(a+1));j--)
				{
					if (j%(1<<(a+1))==(1<<a))
					v.push_back(inv[j]);
				}
			}
			for (int j=0;j<m-1;j++)
			{
				if ((a<3 && (j+1)%(1<<a)!=mod[a-1][i]) || (j+1)%m==mod[a][i])
				continue;
				v[j]=i;
				if (query(v))
				{
					mod[a][i]=(j+1)%m;
					break;
				}
				v[j]=inv[j+1];
			}
		}
	}
}
int main()
{
	scanf("%d",&n);
	for (int i=2;i<=n;i++)
	mod[0][i]=(mod[0][i-1]^!query({i-1,i}));
	vector<int> cur;
	for (int i=1;i<=n;i++)
	cur.push_back(i);
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
	for (int i=1;i<=min(8,n/2);i++)
	{
		vector<int> tmp,perm;
		for (int j=1;j<=n;j++)
		perm.push_back(j);
		shuffle(perm.begin(),perm.end(),rng);
		for (int j:perm)
		{
			if (tmp.size()==2)
			break;
			auto it=find(cur.begin(),cur.end(),j);
			if (it==cur.end())
			continue;
			cur.erase(it);
			if (query(cur))
			tmp.push_back(j);
			cur.push_back(j);
		}
		for (int j:tmp)
		{
			if (mod[0][j]==i%2)
			put(j,i);
			else
			put(j,n-i+1);
			cur.erase(find(cur.begin(),cur.end(),j));
		}
	}
	if (n>16)
	{
		go(1,4);
		go(2,8);
		go(3,3);
		go(4,5);
		go(5,7);
		for (int i=1;i<=n;i++)
		{
			if (!ans[i])
			{
				
				for (int j=1;j<=n;j++)
				{
					if (j%8==mod[2][i] && j%3==mod[3][i] && j%5==mod[4][i] && j%7==mod[5][i])
					ans[i]=j;
				}
			}
		}
	}
	if (ans[1]>n/2)
	{
		for (int i=1;i<=n;i++)
		ans[i]=n-ans[i]+1;
	}
	printf("!");
	for (int i=1;i<=n;i++)
	printf(" %d",ans[i]);
	printf("\n");
	fflush(stdout);
}