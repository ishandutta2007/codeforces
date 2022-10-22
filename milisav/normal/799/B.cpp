#include <bits\stdc++.h>
using namespace std;
priority_queue<int,vector<int>, greater<int> > q[6];
int p[200000],a[200000],b[200000];
int n,m;
int o[6];
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%d",&p[i]);
	for(int i=0;i<n;i++) scanf("%d",&a[i]);
	for(int i=0;i<n;i++) scanf("%d",&b[i]);
	for(int i=0;i<n;i++)
	{
		if(a[i]==b[i] && a[i]==1) q[0].push(p[i]);
		else
		{
			if(a[i]==b[i] && a[i]==2) q[1].push(p[i]);
			else
			{
				if(a[i]==b[i] && a[i]==3) q[2].push(p[i]);
				else q[a[i]+b[i]].push(p[i]);
			}
		}
	}
	scanf("%d",&m);
	int c,d,e,f;
	for(int i=0;i<m;i++)
	{
		scanf("%d",&c);
		for(int j=0;j<6;j++) o[j]=-1;
		c--;
		if(q[c].size()>0) o[c]=q[c].top();
		//cout<<"?"<<endl;
		c++;
		if(c==1)
		{
			if(q[3].size()>0) o[3]=q[3].top();
			if(q[4].size()>0) o[4]=q[4].top();
		}
		if(c==2)
		{
			if(q[3].size()>0) o[3]=q[3].top();
			if(q[5].size()>0) o[5]=q[5].top();
		}
		if(c==3)
		{
			if(q[4].size()>0) o[4]=q[4].top();
			if(q[5].size()>0) o[5]=q[5].top();
		}
		//cout<<"?"<<endl;
		e=0;
		for(int j=1;j<6;j++)
		{
			if(o[j]!=-1 && (o[e]==-1 || o[e]>o[j])) e=j;
		}
		printf("%d ",o[e]);
		if(o[e]!=-1) q[e].pop();
	}
	return 0;
}