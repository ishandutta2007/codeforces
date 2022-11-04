#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn = 12e5+10;
const LL mod = 1e9+7;

int n , tr[maxn];
struct mmp{
	int x , i;
	bool operator < (const mmp &op) const{
		return x < op.x;
	} 
}a[maxn];
vector<mmp> v;

void build(int num , int l , int r)
{
	tr[num] = n*3+1;
	if (l == r) return;
	int mid = (l+r)/2;
	build(num*2,l,mid);
	build(num*2+1,mid+1,r);
}

void putin(int num , int l , int r , int x , int y)
{
	if (l == r)
	{
		tr[num] = y;
		return;
	}
	int mid = (l+r)/2;
	if (x <= mid) putin(num*2,l,mid,x,y);
	else putin(num*2+1,mid+1,r,x,y);
	tr[num] = min(tr[num*2],tr[num*2+1]);
}

int getout(int num , int l , int r , int x , int y)
{
	if (x > r || l > y) return n*3+1;
	if (x <= l && r <= y) return tr[num];
	int mid = (l+r)/2;
	if (y <= mid) return getout(num*2,l,mid,x,y);
	else if (x >= mid+1) return getout(num*2+1,mid+1,r,x,y);
	else return min(getout(num*2,l,mid,x,y),getout(num*2+1,mid+1,r,x,y));
}

int main()
{
	int i , j;
	cin >> n;
	for (i = 1 ; i <= n ; i++)
	{
		scanf("%d",&a[i]);
		a[i].i = i;
		a[n+i] = a[i];
		a[n+i].i += n;
		a[n*2+i] = a[n+i];
		a[n*2+i].i += n;
	}
	sort(a+1,a+n*3+1);
	build(1,1,n*3);
	j = 1;
	for (i = 1 ; i <= n*3 ; i++)
	{
		while (j <= i && a[j].x*2 < a[i].x)
		{
			putin(1,1,n*3,a[j].i,a[j].i);
			j++;
		}
		if (a[i].i <= n*2) v.push_back({a[i].i,getout(1,1,n*3,a[i].i,a[i].i+n-1)});
	}
	build(1,1,n*2);
	for (auto i: v)
		putin(1,1,n*2,i.x,i.i);
	for (i = 1 ; i <= n ; i++)
	{
		j = getout(1,1,n*2,i,i+n-1);
		if (j >= n*3+1) printf("-1 ");
		else printf("%d ",j-i);
	}
	cout << "\n";
	return 0;
}