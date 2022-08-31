#include<cstdio>
#include<iostream>
#include<vector>

using namespace std;

const int MaxN=100010;

int n;
vector<int> v[MaxN];
int px[MaxN],py[MaxN],size[MaxN];
long double sx,sy,sumx[MaxN];
long double ans;

void solve(int x,int p)
{
	sumx[x]=px[x];
	for (vector<int>::iterator it=v[x].begin();it!=v[x].end();++it)
		if (*it!=p)
		{
			solve(*it,x);
			size[x]+=size[*it]+1;
			sumx[x]+=sumx[*it];
			ans-=py[*it]*sumx[*it]*(n-1-size[*it])+py[x]*(sx-sumx[*it])*(size[*it]+1);
		}
}

int main()
{
	cin>>n;
	for (int i=1;i<n;++i)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		v[x].push_back(y);
		v[y].push_back(x);
	}
	for (int i=1;i<=n;++i)
	{
		scanf("%d%d",&px[i],&py[i]);
		sx+=px[i];
		sy+=py[i];
	}
	ans=sx*sy*(n-1);
	solve(1,0);
	printf("%.12lf\n",(double)(ans/sx/sy));
	return 0;
}