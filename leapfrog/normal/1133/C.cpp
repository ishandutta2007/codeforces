#include<bits/stdc++.h>
using namespace std;
int n,a[200005],ans=-1;multiset<int>s;
int main()
{
	scanf("%d",&n),s.clear();
	for(int i=1;i<=n;i++) scanf("%d",a+i);
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		while(!s.empty()&&*s.begin()<a[i]-5) s.erase(s.begin());
		s.insert(a[i]),ans=max(ans,(int)s.size());
	}
	return printf("%d\n",ans),0;
}