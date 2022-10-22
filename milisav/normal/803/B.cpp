#include <bits\stdc++.h>
using namespace std;
int a[300000];
int b[300000];
int n;
void bfs()
{
	vector<int> q;
	for(int i=0;i<n;i++)
	{
		b[i]=n+5;
		if(a[i]==0)
		{
			q.push_back(i);
			b[i]=0;
		}
	}
	int ind=0;
	int t;
	while(ind<q.size())
	{
		t=q[ind];
		if(t>0 && b[t-1]>b[t]+1)
		{
			b[t-1]=b[t]+1;
			q.push_back(t-1);
		}
		if(t<n-1 && b[t+1]>b[t]+1)
		{
			b[t+1]=b[t]+1;
			q.push_back(t+1);
		}
		ind++;
	}
}
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%d",&a[i]);
	bfs();
	for(int i=0;i<n;i++) printf("%d ",b[i]);
	return 0;
}