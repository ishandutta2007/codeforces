#include <iostream>
#include <vector>
#include <stack>
using namespace std;
vector<int> v[2][300005];
int n,arr[300005],l[300005],r[300005],mx[300005],occ[300005],tree[300005];
void update(int idx,int val)
{
	while (idx<=n)
	{
		tree[idx]+=val;
		idx+=(idx&(-idx));
	}
}
int query(int idx)
{
	int ans=0;
	while (idx)
	{
		ans+=tree[idx];
		idx-=(idx&(-idx));
	}
	return ans;
}
int main()
{
	scanf("%d",&n);
	for (int i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
		occ[i+1]=n;
	}
	stack<int> s1,s2;
	s1.push(-1);
	for (int i=0;i<n;i++)
	{
		while (s1.size()!=1 && arr[s1.top()]<arr[i])
		s1.pop();
		l[i]=s1.top()+1;
		s1.push(i);
	}
	s2.push(n);
	mx[n]=n;
	long long ans=0;
	for (int i=n-1;i>=0;i--)
	{
		while (s2.size()!=1 && arr[s2.top()]<arr[i])
		s2.pop();
		r[i]=s2.top()-1;
		mx[i]=min(mx[i+1],occ[arr[i]]-1);
		occ[arr[i]]=i;
		s2.push(i);
		int ll=max(l[i],i-arr[i]+1),rr=min(r[i]-arr[i]+1,i);
		if (ll<=rr)
		{
			v[0][ll].push_back(arr[i]);
			v[1][rr].push_back(arr[i]);
		}
		for (int j:v[1][i])
		update(j,1);
		ans+=query(mx[i]-i+1);
		for (int j:v[0][i])
		update(j,-1);
	}
	printf("%I64d",ans);
}