#include <iostream>
#include <stack>
using namespace std;
int arr[1000005];
int main()
{
	int n,q,cur=0,f=0;
	scanf("%d%d",&n,&q);
	stack<int> s;
	while (q--)
	{
		int t;
		scanf("%d",&t);
		if (t==1)
		{
			int x;
			scanf("%d",&x);
			cur=(cur+x+n)%n;
		}
		else
		{
			if (!s.empty() && s.top()==cur%2)
			s.pop();
			else
			{
				s.push(cur%2);
				if (s.size()==1)
				f=cur%2;
			}
		}
	}
	for (int i=0;i<n;i++)
	{
		int idx=i+cur;
		if (i%2!=f)
		idx-=s.size()%n;
		else
		idx+=s.size()%n;
		while (idx<0)
		idx+=n;
		arr[idx%n]=i+1;
	}
	for (int i=0;i<n;i++)
	printf("%d ",arr[i]);
}