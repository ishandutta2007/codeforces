#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<queue>
using namespace std;
int n,m,i,d,ans[200010];
struct data
{
	int val,num;
	bool operator<(const data &a) const {return val>a.val;}
}a[200010],t;
priority_queue<data>q;
int main()
{
	scanf("%d%d%d",&n,&m,&d);
	for (i=1;i<=n;i++) scanf("%d",&a[i].val),a[i].num=i;
	sort(a+1,a+n+1);
	t.num=1;t.val=a[n].val;ans[a[n].num]=1;int cnt=1;
	q.push(t);
	for (i=n-1;i>0;i--)
	{
		t=q.top();
		if (t.val+d<a[i].val) 
		{
			ans[a[i].num]=t.num;t.val=a[i].val;
			q.pop();q.push(t);
		}
		else
		{
			ans[a[i].num]=++cnt;
			t.num=cnt;t.val=a[i].val;
			q.push(t);
		}
	}
	cout<<cnt<<endl;
	for (i=1;i<=n;i++) cout<<ans[i]<<" ";
}