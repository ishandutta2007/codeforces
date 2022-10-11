#include <map>
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
int arr[100005],n,bs,a[100005],c[100005],ori[100005];
pair<int,int> tmp[100005];
vector<query> q;
bool cmp(query a,query b)
{
	if (a.L/bs!=b.L/bs)
	return a.L/bs<b.L/bs;
	return a.R<b.R;
}
void compress()
{
	sort(tmp,tmp+n);
	for (int i=0;i<n;i++)
	{
		int t=arr[tmp[i].second];
		if (i && tmp[i].first==tmp[i-1].first)
		arr[tmp[i].second]=arr[tmp[i-1].second];
		else
		arr[tmp[i].second]=i;
		ori[arr[tmp[i].second]]=t;
	}
}
int main()
{
	int m,ql,qr;
	scanf("%d%d",&n,&m);
	for (int i=0;i<n;i++)
	scanf("%d",&arr[i]),tmp[i]=make_pair(arr[i],i);
	compress();
	for (int i=0;i<m;i++)
	{
		scanf("%d%d",&ql,&qr);
		q.push_back(query(ql,qr,i));
	}
	bs=sqrt(n);
	sort(q.begin(),q.end(),cmp);
	int l,r,cl=0,cr=0,ans=0;
	for (int i=0;i<m;i++)
	{
		l=q[i].L-1;
		r=q[i].R-1;
		while (cl<l)
		{
			c[arr[cl]]--;
			ans+=(c[arr[cl]]==ori[arr[cl]]);
			ans-=(c[arr[cl]]==(ori[arr[cl]]-1));
			cl++;
		}
		while (cl>l)
		{
			cl--;
			c[arr[cl]]++;
			ans+=(c[arr[cl]]==ori[arr[cl]]);
			ans-=(c[arr[cl]]==(ori[arr[cl]]+1));
		}
		while (cr<=r)
		{
			c[arr[cr]]++;
			ans+=(c[arr[cr]]==ori[arr[cr]]);
			ans-=(c[arr[cr]]==(ori[arr[cr]]+1));
			cr++;
		}
		while (cr>r+1)
		{
			cr--;
			c[arr[cr]]--;
			ans+=(c[arr[cr]]==ori[arr[cr]]);
			ans-=(c[arr[cr]]==(ori[arr[cr]]-1));
		}
		a[q[i].i]=ans;
	}
	for (int i=0;i<m;i++)
	printf("%d\n",a[i]);
}