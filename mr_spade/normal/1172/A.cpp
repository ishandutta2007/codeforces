#include<cstdio>
#include<cstdlib>
#include<set>
#include<queue>
using std::max;
using std::min;
using std::multiset;
using std::deque;
const int N=2e5+5;
int n,pos,ans;
int a[N],b[N];
multiset<int> s;
deque<int> t;
inline void redo()
{
	int ans=0;
	register int i;
	for(i=1;i<=n;i++)
		if(b[i])
			ans=max(ans,i-b[i]+1);
	printf("%d\n",ans+n);
	exit(0);
	return;
}
signed main()
{
	int x;
	register int i,j;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(i=1;i<=n;i++)
		scanf("%d",&b[i]);
	for(i=1;i<=n;i++)
		s.insert(a[i]);
	for(i=1;i<=n;i++)
		t.push_back(b[i]);
	for(i=1;i<=n;i++)
		if(b[i]==1)
		{
			for(j=i;j<=n;j++)
				if(b[j]!=j-i+1)
					goto end;
			pos=n-i+1;
		}
	end:;
	if(!pos)
		redo();
	for(i=pos+1;i<=n;i++)
	{
		if(s.find(i)==s.end())
			redo();
		s.erase(i);
		x=t.front();t.pop_front();
		s.insert(x);
	}
	printf("%d\n",n-pos);
	return 0;
}