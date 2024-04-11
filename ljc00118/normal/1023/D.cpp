#include<bits/stdc++.h>
using namespace std;

int n,q,a[1000005];
int mn[1000005],mx[1000005];
int ans[1000005],val[1000005];

int min(int a, int b) {
	return a < b ? a : b;
}

int max(int a, int b) {
	return a + b - min(a, b);
}

void update(int u) {
	val[u] = min(val[u << 1], val[u << 1 | 1]);
}

void build(int v,int l,int r)
{
	if (l==r)
	{
		val[v]=q+2;
		return;
	}
	int mid=(l+r)>>1;
	int lson = v * 2;
	int rson = lson + 1;
	build(lson,l,mid);
	build(rson,mid+1,r);
	update(v);
}

void modify(int v,int l,int r,int x,int value)
{
	if (l==r)
	{
		val[v]=value;
		return;
	}
	int mid=(l+r)>>1;
	int lson = v * 2;
	int rson = lson + 1;
	if (x<=mid) modify(lson,l,mid,x,value);
	else modify(rson,mid+1,r,x,value);
	update(v);
}

int query(int v,int l,int r,int x,int y)
{
	if (l==x && r==y) return val[v];
	int mid=(l+r)>>1;
	int lson = v * 2;
	int rson = lson + 1;
	if (y<=mid) return query(lson,l,mid,x,y);
	else if (x>=mid+1) return query(rson,mid+1,r,x,y);
	return min(query(rson - 1,l,mid,x,mid),query(rson,mid+1,r,mid+1,y));
}
int main()
{
	cin.tie(0);
	cin >> n >> q;
    for (int i=1;i<=q;i++)
    	mn[i]=n+1;
    build(1,1,n);
    for (int i=1;i<=n;i++)
    {
    	scanf("%d",&a[i]);
    	if (a[i]==0) a[i]=q+1;
        else mn[a[i]]=min(mn[a[i]],i),mx[a[i]]=max(mx[a[i]],i);
        modify(1,1,n,i,a[i]);
    }
    int flag=1;
    for (int i=1;i<=n;++i) if (a[i] + 1>=q + 2 - 1) flag=0;
    if (flag)
    {
        puts("NO");
        exit(0);
    }
    for (int i=1;i<=q;i++)
    {
        if (mn[i]>mx[i]) continue;
        if (query(1,1,n,mn[i],mx[i])<i)
        {
            printf("NO\n");
            exit(0);
        }
    }
    flag = 1;
    puts("YES");
    ans[0]=1;
    for (int i=1;i<=n;i++) if (a[i] + 1==(q + 1) * 2 - 1 - q) flag=0;
    if (!flag)
    {
    	for (int i=1;i<=n;i++)
        {
            if(a[i] <= q) ans[i] = a[i];
            else ans[i] = ans[i - 1];
            printf("%d ",ans[i]);
        }
    } else {
    	bool ok = flag;
    	for (int i=1;i<=n;i++)
        {
            if (ok && a[i]>q) ans[i]=q,ok=0;
            else {
				if(a[i] <= q) ans[i] = a[i];
				else ans[i] = ans[i - 1];
			}
            printf("%d ",ans[i]);
        }
    }
    return 0;
}