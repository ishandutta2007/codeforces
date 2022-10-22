#include <bits/stdc++.h>
using namespace std;
int n, t;
pair<pair<int,int>, pair<int,long long int> > d[300000];
int a[300000];
long long int c[1000002];
long long int sum;
int h;
int l;
int r;
bool by_block(pair<pair<int,int>,pair<int,long long int> > x,pair<pair<int,int>,pair<int,long long int> > y)
{
	if(x.first.first/h==y.first.first/h) return x.first.second<y.first.second;
	else return x.first.first<y.first.first;
}
bool by_index(pair<pair<int,int>,pair<int,long long int> > x,pair<pair<int,int>,pair<int,long long int> > y)
{
	return x.second.first<y.second.first;
}
int main()
{
	scanf("%d %d",&n,&t);
	h=sqrt(n);
	for(int i=0;i<n;i++) scanf("%d",&a[i+1]);
	for(int i=0;i<t;i++)
	{
		scanf("%d %d",&l,&r);
		d[i]=make_pair(make_pair(l,r),make_pair(i,0));
	}
	sort(d,d+t,by_block);
	int cl=0;
	int cr=0;
	int k;
	for(int i=0;i<t;i++)
	{
		l=d[i].first.first;
		r=d[i].first.second;
		while(cr<r)
		{
			cr++;
			k=a[cr];
			sum-=c[k]*c[k]*k;
			c[k]++;
			sum+=c[k]*c[k]*k;
		}
		while(cl<l)
		{
			k=a[cl];
			sum-=c[k]*c[k]*k;
			c[k]--;
			sum+=c[k]*c[k]*k;
			cl++;
		}
		while(cr>r)
		{
			k=a[cr];
			sum-=c[k]*c[k]*k;
			c[k]--;
			sum+=c[k]*c[k]*k;
			cr--;
		}
		while(cl>l)
		{
			cl--;
			k=a[cl];
			sum-=c[k]*c[k]*k;
			c[k]++;
			sum+=c[k]*c[k]*k;
		}
		d[i]=make_pair(make_pair(l,r),make_pair(d[i].second.first,sum));
	}
	sort(d,d+t,by_index);
	for(int i=0;i<t;i++) printf("%I64d\n",d[i].second.second);
	return 0;
}