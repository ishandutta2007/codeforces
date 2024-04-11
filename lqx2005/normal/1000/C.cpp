#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=1000000;
const int inf=10000000000000;
int n;
int l[maxn+5],r[maxn+5],L[maxn+5],R[maxn+5];
vector<int> un;
int c[maxn+5],sum[maxn+5],info[maxn+5];
signed main()
{
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld%lld",&l[i],&r[i]);
		un.push_back(l[i]);
		un.push_back(r[i]);
	} 
	un.push_back(-inf);
	sort(un.begin(),un.end());
	un.erase(unique(un.begin(),un.end()),un.end());
	for(int i=1;i<=n;i++)
	{
		int pos1=lower_bound(un.begin(),un.end(),l[i])-un.begin();
		int pos2=lower_bound(un.begin(),un.end(),r[i])-un.begin();
		sum[pos1+1]++;
		sum[pos2+1]--;
		info[pos1]++;
		info[pos2+1]--;
	}
	for(int i=1;i<=un.size();i++) sum[i]+=sum[i-1],info[i]+=info[i-1];
	for(int i=2;i<un.size();i++) c[sum[i]]+=un[i]-un[i-1]-1;
	for(int i=1;i<un.size();i++) c[info[i]]++;
	for(int i=1;i<=n;i++) printf("%lld ",c[i]);
	printf("\n");
	return 0;
}