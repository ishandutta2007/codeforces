#include <iostream>
#include <vector>
using namespace std;
int cnt[105];
vector<int> v;
int main()
{
	int n;
	scanf("%d",&n);
	while (n--)
	{
		int a;
		scanf("%d",&a);
		if (!cnt[a])
		v.push_back(a);
		cnt[a]++;
	}
	if (v.size()!=2)
	printf("NO");
	else if (cnt[v[0]]!=cnt[v[1]])
	printf("NO");
	else
	printf("YES\n%d %d",v[0],v[1]);
}