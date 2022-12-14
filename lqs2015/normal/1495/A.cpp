#include<bits/stdc++.h>
using namespace std;
vector<int> a,b;
int test,n,x,y;
double ans;
int main()
{
	scanf("%d",&test);
	while(test--)
	{
		scanf("%d",&n);a.clear();b.clear();
		for (int i=1;i<=2*n;i++)
		{
			scanf("%d%d",&x,&y);
			if (x==0) a.push_back(abs(y));
			else b.push_back(abs(x));
		}
		sort(a.begin(),a.end());
		sort(b.begin(),b.end());
		ans=0.00;
		for (int i=0;i<n;i++)
		{
			ans+=(double)sqrt((double)a[i]*(double)a[i]+(double)b[i]*(double)b[i]);
		}
		printf("%.9lf\n",ans);
	}
	return 0;
}