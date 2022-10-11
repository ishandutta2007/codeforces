#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define MX 3000000
long long cnt[MX+5],ans[MX+5];
int main()
{
	int n;
	scanf("%d",&n);
	vector<long long> v;
	for (int i=0;i<n;i++)
	{
		int a;
		scanf("%d",&a);
		v.push_back(a);
		cnt[a]++;
	}
	int r=v.size()-1;
	sort(v.begin(),v.end());
	for (int l=0;l<v.size();l++)
	{
		while (r>=0 && v[l]*v[r]>MX)
		r--;
		ans[MX]+=v.size()-r-1;
		ans[MX]-=(r<l);
	}
	for (int i=1;i<=MX;i++)
	{
		for (int j=i;j<=MX;j+=i)
		{
			if (j/i==i)
			ans[j]+=cnt[i]*(cnt[i]-1);
			else
			ans[j]+=cnt[i]*cnt[j/i];
		}
	}
	for (int i=MX;i>=0;i--)
	ans[i]+=ans[i+1];
	int q;
	scanf("%d",&q);
	while (q--)
	{
		int a;
		scanf("%d",&a);
		printf("%I64d\n",ans[a]);
	}
}