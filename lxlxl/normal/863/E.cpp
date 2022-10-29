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

const int maxn = 210000;

int n;
struct node
{
	int l,r,i;
}a[maxn];
inline bool cmp(const node x,const node y){return x.l==y.l?x.r>y.r:x.l<y.l;}

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d%d",&a[i].l,&a[i].r),a[i].i=i;
	sort(a+1,a+n+1,cmp);
	
	int ans=-1;
	int lar=a[1].r;
	int j=2;
	for(int i=2;i<=n;i++)
	{
		if(lar>=a[i].r) { ans=a[i].i; break; }
		if(a[i].l<=lar) a[i].l=lar+1;
		j=max(j,i+1);
		for(;j<=n&&a[j].l<=a[i].l;j++)
			if(a[j].r>=a[i].r) { ans=a[i].i; break; }
		j--;
		if(ans!=-1) break;
		lar=max(lar,a[i].r);
	}
	printf("%d\n",ans);
	
	return 0;
}