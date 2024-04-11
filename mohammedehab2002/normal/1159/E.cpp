#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;
int nex[500005],p[500005],ch[500005];
pair<int,int> arr[500005];
int main()
{
	int t;
	scanf("%d",&t);
	while (t--)
	{
		int n;
		scanf("%d",&n);
		for (int i=1;i<=n;i++)
		{
			scanf("%d",&nex[i]);
			arr[i]={nex[i],-i};
			p[i]=-1;
		}
		int cur=n;
		sort(arr+1,arr+n+1);
		for (int i=n;cur;i--)
		{
			int idx=-arr[i].second;
			if (p[idx]!=-1)
			continue;
			if (nex[idx]!=-1 && nex[idx]!=n+1 && nex[nex[idx]]==-1 && p[nex[idx]]==-1)
			p[nex[idx]]=cur--;
			p[idx]=cur--;
		}
		stack<int> st;
		st.push(n+1);
		bool ok=1;
		for (int i=n;i>0;i--)
		{
			while (st.size()!=1 && p[i]>p[st.top()])
			st.pop();
			ok&=(nex[i]==-1 || nex[i]==st.top());
			st.push(i);
		}
		if (!ok)
		{
			printf("-1\n");
			continue;
		}
		for (int i=1;i<=n;i++)
		printf("%d%c",p[i]," \n"[i==n]);
	}
}