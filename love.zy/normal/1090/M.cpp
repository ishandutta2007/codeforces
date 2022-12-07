#include<bits/stdc++.h>
#define maxn 100005
using namespace std;
int n,k;
int a[maxn];
vector<int> v;
int main()
{
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;++i)scanf("%d",&a[i]);
	v.push_back(1);
	for(int i=2;i<=n;++i)if(a[i]==a[i-1])
	{
		v.push_back(i);
	}
	v.push_back(n+1);
	int ans=0;
	for(int i=0;i<v.size()-1;++i)ans=max(ans,v[i+1]-v[i]);
	printf("%d\n",ans);
	return 0;
}