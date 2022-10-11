#include <iostream>
#include <stack>
using namespace std;
int arr[200005],b[200005][2],ans[200005];
int main()
{
	int n;
	scanf("%d",&n);
	for (int i=0;i<n;i++)
	scanf("%d",&arr[i]);
	stack<pair<int,int> > st;
	st.push({0,-1});
	for (int i=0;i<n;i++)
	{
		while (st.top().first>=arr[i])
		st.pop();
		b[i][0]=st.top().second;
		st.push({arr[i],i});
	}
	while (!st.empty())
	st.pop();
	st.push({0,n});
	for (int i=n-1;i>=0;i--)
	{
		while (st.top().first>=arr[i])
		st.pop();
		b[i][1]=st.top().second;
		st.push({arr[i],i});
	}
	for (int i=0;i<n;i++)
	ans[b[i][1]-b[i][0]-1]=max(ans[b[i][1]-b[i][0]-1],arr[i]);
	for (int i=n-1;i>=0;i--)
	ans[i]=max(ans[i],ans[i+1]);
	for (int i=1;i<=n;i++)
	printf("%d ",ans[i]);
}