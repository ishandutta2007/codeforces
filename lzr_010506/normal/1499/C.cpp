#include<bits/stdc++.h>
using namespace std;
int a[100010];
vector<long long> v1, v2;
priority_queue<int, vector<int>, greater<int> > q;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		int i;
		for(i=1; i<=n; i++) scanf("%d",&a[i]);
		long long sum = 0;
		for(i=1; i<=n; i+=2)
		{
			sum += (long long)a[i];
			q.push(a[i]);
			long long tem = (long long)q.top() * (long long)(n - (i + 1) / 2) + sum;
			v1.push_back(tem);
		}
		sum = 0;
		while(q.size()) q.pop();
		for(i=2; i<=n; i+=2)
		{
			sum += (long long)a[i];
			q.push(a[i]);
			long long tem = (long long)q.top() * (long long)(n - (i / 2)) + sum;
			v2.push_back(tem);
		}
		long long ans = 1e18 + 10;
		// for(i=0; i<v1.size(); i++) cout << v1[i] << " ";
		// cout << endl;
		// for(i=0; i<v2.size(); i++) cout << v2[i] << " ";
		// 	cout << endl;
		for(i=2; i<=n; i++)
		{
			if((i + 1) / 2 - 1 >= v1.size() || (i / 2 - 1 >= v2.size())) continue;
			ans = min(v1[(i + 1) / 2 - 1] + v2[i / 2 - 1], ans);
		}
		printf("%lld\n",ans);
		while(q.size()) q.pop();
		v1.clear();
		v2.clear();
	}
	return 0;
}