#include <iostream>
#include <algorithm>
#include <vector>
#include <stdio.h>
#include <math.h>
using namespace std;
struct query{
	int L,R,i;
	query(int LL,int RR,int ii)
	{
		L=LL;
		R=RR;
		i=ii;
	}
};
int arr[200005],bs;
vector<query> q;
long long a[200005],c[1000005];
bool cmp(query a,query b)
{
	if (a.L/bs!=b.L/bs)
	return a.L/bs<b.L/bs;
	return a.R<b.R;
}
int main()
{
	int n,m,ql,qr;
	scanf("%d%d",&n,&m);
	for (int i=0;i<n;i++)
	scanf("%d",&arr[i]);
	for (int i=0;i<m;i++)
	{
		scanf("%d%d",&ql,&qr);
		q.push_back(query(ql,qr,i));
	}
	bs=sqrt(n);
	sort(q.begin(),q.end(),cmp);
	int l,r,cl=0,cr=0;
	long long ans=0;
	for (int i=0;i<m;i++)
	{
		l=q[i].L-1;
		r=q[i].R-1;
		while (cl<l)
		{
			ans-=arr[cl]*(2LL*c[arr[cl]]-1LL);
			c[arr[cl]]--;
			cl++;
		}
		while (cl>l)
		{
			cl--;
			ans+=arr[cl]*(2LL*c[arr[cl]]+1LL);
			c[arr[cl]]++;
		}
		while (cr<=r)
		{
			ans+=arr[cr]*(2LL*c[arr[cr]]+1LL);
			c[arr[cr]]++;
			cr++;
		}
		while (cr>r+1)
		{
			cr--;
			ans-=arr[cr]*(2LL*c[arr[cr]]-1LL);
			c[arr[cr]]--;
		}
		a[q[i].i]=ans;
	}
	for (int i=0;i<m;i++)
	printf("%I64d\n",a[i]);
}