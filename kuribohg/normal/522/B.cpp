#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<set>
using namespace std;
typedef long long LL;
const int MAXN=200010;
multiset<int> S;
multiset<int>::iterator it;
int n,w[MAXN],h[MAXN];
LL sum,ans[MAXN];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d%d",&w[i],&h[i]),sum+=w[i],S.insert(h[i]);
	for(int i=1;i<=n;i++)
	{
		sum-=w[i];
		it=S.find(h[i]);
		S.erase(it);
		ans[i]=(*S.rbegin())*sum;
		S.insert(h[i]);
		sum+=w[i];
	}
	for(int i=1;i<=n;i++) printf("%I64d ",ans[i]);
	return 0;
}