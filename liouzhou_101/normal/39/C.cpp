#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

const int MaxN=4010;

int n;
int x[MaxN],y[MaxN];
vector<int> p,v[MaxN];

void init()
{
	cin>>n;
	for (int i=1;i<=n;++i)
	{
		int c,r;
		cin>>c>>r;
		p.push_back(x[i]=c-r);
		p.push_back(y[i]=c+r);
	}
	sort(p.begin(),p.end());
	p.erase(unique(p.begin(),p.end()),p.end());
	for (int i=1;i<=n;++i)
	{
		x[i]=lower_bound(p.begin(),p.end(),x[i])-p.begin();
		y[i]=lower_bound(p.begin(),p.end(),y[i])-p.begin();
		v[x[i]].push_back(i);
	}
}

int F[MaxN][MaxN];

void print(int L,int R)
{
	if (!F[L][R]) return;
	int flag=0;
	for (vector<int>::iterator it=v[L].begin();it!=v[L].end();++it)
		if (y[*it]==R)
		{
			cout<<*it<<" ";
			flag=1;
			break;
		}
	for (vector<int>::iterator it=v[L].begin();it!=v[L].end();++it)
	{
		if (y[*it]>=R) continue;
		if (F[L][R]-flag==F[L][y[*it]]+F[y[*it]][R])
		{
			print(L,y[*it]);
			print(y[*it],R);
			return;
		}
	}
	print(L+1,R);
}

void work()
{
	int m=p.size();
	for (int k=1;k<m;++k)
		for (int i=0;i<m;++i)
		{
			int j=i+k;
			if (j>=m) continue;
			F[i][j]=F[i+1][j];
			int flag=0;
			for (vector<int>::iterator it=v[i].begin();it!=v[i].end();++it)
			{
				if (y[*it]==j) flag=1;
				if (y[*it]>=j) continue;
				F[i][j]=max(F[i][j],F[i][y[*it]]+F[y[*it]][j]);
			}
			if (flag) ++F[i][j];
		}
	cout<<F[0][m-1]<<endl;
	print(0,m-1);
}

int main()
{
	init();
	work();
	return 0;
}