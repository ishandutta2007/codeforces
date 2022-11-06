#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+5;
int n,k,ans;
int p[N],a[N],b[N];
deque<int> Q;
signed main()
{
	int x;
	register int i;
	cin>>n;
	for(i=1;i<=n;i++)
		p[i]=i,cin>>a[i]>>b[i];
	sort(p+1,p+n+1,[](int x,int y)->bool
	{
		return b[x]<b[y];
	});
	for(i=1;i<=n;i++)
		Q.push_back(p[i]);
	while(!Q.empty())
	{
		if(k<b[Q.front()])
		{
			x=min(a[Q.back()],b[Q.front()]-k);
			k+=x;ans+=2*x;
			if(!(a[Q.back()]-=x))
				Q.pop_back();
		}
		else
			k+=a[Q.front()],ans+=a[Q.front()],Q.pop_front();
	}
	cout<<ans<<endl;
	return 0;
}