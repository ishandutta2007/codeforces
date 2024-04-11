#include <bits/stdc++.h>
using namespace std;
#define N 500005
#define ll long long
int n,a[N],st[N];ll ans;priority_queue<int,vector<int>,greater<int>> q;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i) scanf("%d",&a[i]),ans+=a[i];sort(a+1,a+n+1);
	for(int i=n,t,t1,t2,w;i;i=t)
	{
		t=i;while(a[t]==a[i]) --t;t1=i-t;t2=min(t1,n-i-(int)q.size()*2);
		for(int j=1;j<=t2;++j) st[++st[0]]=a[i];t1-=t2;
		for(int j=1;j<=t1;j+=2) if(!q.empty())
		{
			w=q.top();q.pop();
			if(w<a[i]) {st[++st[0]]=a[i];if(j<t1) st[++st[0]]=a[i];}
			else {st[++st[0]]=w;if(j<t1 && a[i]*2>w) st[++st[0]]=a[i]*2-w;}
		}while(st[0]) q.push(st[st[0]--]);
	}while(!q.empty()) ans-=q.top(),q.pop();printf("%lld\n",ans);return 0;
}