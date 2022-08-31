#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int n;
int c[100];
int a[100][100];
vector<int> p;
vector<pair<pair<int,int>,pair<int,int> > > ans;

int main()
{
	cin>>n;
	for (int i=1;i<=n;++i)
		cin>>c[i];
	for (int i=1;i<=n;++i)
		for (int j=1;j<=c[i];++j)
		{
			cin>>a[i][j];
			p.push_back(a[i][j]);
		}
	sort(p.begin(),p.end());
	int k=0;
	for (int i=1;i<=n;++i)
		for (int j=1;j<=c[i];++j)
		{
			if (p[k]!=a[i][j])
			{
				for (int ii=1;ii<=n;++ii)
					for (int jj=1;jj<=c[ii];++jj)
						if (a[ii][jj]==p[k])
						{
							ans.push_back(make_pair(make_pair(i,j),make_pair(ii,jj)));
							swap(a[i][j],a[ii][jj]);
							break;
						}
			}
			++k;
		}
	cout<<ans.size()<<endl;
	for (int i=0;i<ans.size();++i)
		printf("%d %d %d %d\n",ans[i].first.first,ans[i].first.second,ans[i].second.first,ans[i].second.second);
	return 0;
}