#include<set>
#include<map>
#include<deque>
#include<queue>
#include<stack>
#include<cmath>
#include<ctime>
#include<bitset>
#include<string>
#include<vector>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<climits>
#include<complex>
#include<iostream>
#include<algorithm>
#define ll long long
using namespace std;

const int maxn = 110000;

int n; ll s;
int a[maxn];
int c[maxn];

int ret;
ll res;
ll judge(const int x)
{
	int tot=0;
	for(int i=1;i<=n;i++) if((ll)i*x+a[i]<=s) c[++tot]=i*x+a[i];
	if(tot<x) return s+1;
	sort(c+1,c+tot+1);
	ll re=0;
	for(int i=1;i<=x;i++) re+=(ll)c[i];
	return re;
}
void solve()
{
	int l=1,r=n;
	while(l<=r)
	{
		int mid=l+r>>1;
		ll tmp=judge(mid);
		if(tmp<=s) res=tmp,l=mid+1;
		else r=mid-1;
	}
	ret=l-1;
}

int main()
{
	//freopen("tmp.in","r",stdin);
	//freopen("tmp.out","w",stdout);
	
	scanf("%d%I64d",&n,&s);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	
	ret=0; res=0;
	solve();
	printf("%d %I64d\n",ret,res);
	
	return 0;
}