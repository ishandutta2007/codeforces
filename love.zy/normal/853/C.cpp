#include<bits/stdc++.h>
using namespace std;
#define MAXN 200001
#define MAXBIT 20
typedef long long LL;
struct Tree{
	int num, childL, childR;
}tree[MAXN * MAXBIT + 1];
int root[MAXN];
int cnt, maxValue;
void insert(int& i, int l, int r, int value)
{
	tree[++cnt] = tree[i];
	tree[i = cnt].num++;
	int mid = (unsigned int)(l + r) >> 1;
	if (l == mid)return;
	if (value < mid)insert(tree[i].childL, l, mid, value);
	else insert(tree[i].childR, mid, r, value);
}
int rnk(int i, int j, int value)
{
	int ret = 0;
	for (int t = maxValue >> 1; t; t >>= 1){
		if (value & t){
			ret += tree[tree[j].childL].num - tree[tree[i].childL].num;
			i = tree[i].childR; j = tree[j].childR;
		}
		else{ i = tree[i].childL; j = tree[j].childL; }
	}
	return ret;
}
void build(int a[],int n)
{
	root[0] = 0; cnt = 0;
	for (maxValue = 1; maxValue <= n+1; maxValue <<= 1);
	for (int i = 1; i <= n; i++){
		root[i] = root[i - 1];
		insert(root[i], 0, maxValue, a[i]);
	}
}
int a[200001];
int n,q;
int query(int x,int y,int xx,int yy)
{
    if(x>x || y>yy || x>n || y>n || x<=0 || y<=0 || xx>n || yy>n || xx<=0 || yy<=0)return 0;
	int ans=rnk(root[x-1],root[xx],yy+1)-rnk(root[x-1],root[xx],y);
    return ans;
}

int main()
{
    scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	build(a,n);
    while(q--)
    {
        LL ans=0;
        int u,d,l,r;
        scanf("%d%d%d%d",&u,&l,&d,&r);
        LL p=query(u,l,d,r);
        LL q=n-p;
        ans+=p*q;
        ans+=1ll*p*(p-1)>>1;
        LL sum=1ll*q*(q-1)>>1;
        LL t=query(1,1,u-1,n);
        sum-=1ll*t*(t-1)>>1;
        t=query(d+1,1,n,n);
        sum-=1ll*t*(t-1)>>1;
        t=query(1,1,n,l-1);
        sum-=1ll*t*(t-1)>>1;
        t=query(1,r+1,n,n);
        sum-=1ll*t*(t-1)>>1;
        t=query(1,1,u-1,l-1);
        sum+=1ll*t*(t-1)>>1;
        t=query(d+1,1,n,l-1);
        sum+=1ll*t*(t-1)>>1;
        t=query(1,r+1,u-1,n);
        sum+=1ll*t*(t-1)>>1;
        t=query(d+1,r+1,n,n);
        sum+=1ll*t*(t-1)>>1;
        printf("%lld\n",ans+sum);
    }
    return 0;
}