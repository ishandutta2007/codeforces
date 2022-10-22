#include <bits/stdc++.h>
using namespace std;
int n;
int p;
char c[2];
pair<int,int> a[400000];
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d %s",&p,c);
		if(c[0]=='G') a[i]=make_pair(p,0);
		if(c[0]=='R') a[i]=make_pair(p,1);
		if(c[0]=='B') a[i]=make_pair(p,-1);
	}
	int j,k;
	long long int q;
	bool r,b;
	long long int s=0;
	long long int t;
	long long int g;
	long long int p1,p2;
	int i=0;
	while(i<n && a[i].second!=0) i++;
	if(i==n)
	{
		i=0;
		p1=-1;
		q=-1;
		p2=-1;
		t=-1;
		j=0;
		r=false;
		b=false;
		while(j<n)
		{
			g=a[j].first;
			if(a[j].second==1) 
			{
				if(p1==-1) q=g;
				p1=max(g,p1);
			}
			if(a[j].second==-1)
			{
				if(p2==-1) t=g;
				p2=max(g,p2);
			}
			j++;
		}
		printf("%lld",p1-q+p2-t);
		return 0;
	}
	else
	{
		q=a[i].first;
		p1=q;
		p2=q;
		j=0;
		while(j<i)
		{
			g=a[j].first;
			if(a[j].second==1) p1=min(g,p1);
			if(a[j].second==-1) p2=min(g,p2);
			j++;
		}
		s+=(q-p1);
		s+=(q-p2);
	}
	while(i<n)
	{
		if(a[i].second==0)
		{
			r=false;
			b=false;
			j=i+1;
			q=a[i].first;
			while(j<n && a[j].second!=0)
			{
				if(a[j].second==1) r=true;
				if(a[j].second==-1) b=true;
				j++;
			}
			if(j==n)
			{
				p1=q;
				p2=q;
				k=i+1;
				while(k<j)
				{
					g=a[k].first;
					if(a[k].second==1) p1=max(g,p1);
					if(a[k].second==-1) p2=max(g,p2);
					k++;
				}
				s+=(p1-q);
				s+=(p2-q);
			}
			else
			{
				t=a[j].first;
				p1=2*t-2*q;
				//cout<<p1<<endl;
				p2=t-q; //Neka je ovo povezivanje preko jednih
				k=i+1;
				long long int f1=0,f2=0;
				long long int h1=q,h2=q;
				while(k<j)
				{
					g=a[k].first;
					if(a[k].second==1)
					{
						f1=max(f1,g-h1);
						h1=g;
					}
					if(a[k].second==-1)
					{
						f2=max(f2,g-h2);
						h2=g;
					}
					k++;
				}
				f1=max(f1,t-h1);
				f2=max(f2,t-h2);
				p2=min(p1,p2*3-f1-f2);
				s+=p2;
			}
			i=j-1;
		}
		i++;
	}
	printf("%lld",s);
	return 0;
}