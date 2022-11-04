#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn = 1e6+10;
const LL mod = 1e9+7;

int n , b[maxn];
LL a[maxn] , tr[maxn*4] , lz[maxn*4];

void build(int num , int l , int r)
{
	if (l == r)
	{
		tr[num] = a[l];
		return;
	}
	int mid = (l+r)/2;
	build(num*2,l,mid);
	build(num*2+1,mid+1,r);
	tr[num] = min(tr[num*2],tr[num*2+1]);
}

void putin(int num , int l , int r , int x , int y , LL z)
{
	if (l > y || x > r) return;
	if (x <= l && r <= y)
	{
		lz[num] += z;
		return;
	}
	int mid = (l+r)/2;
	putin(num*2,l,mid,x,y,z);
	putin(num*2+1,mid+1,r,x,y,z);
	tr[num] = min(tr[num*2]+lz[num*2],tr[num*2+1]+lz[num*2+1]);
}

int getout(int num , int l , int r , LL bf)
{
	if (l == r) return l;
	bf += lz[num];
	int mid = (l+r)/2;
	if (tr[num*2+1]+lz[num*2+1]+bf == 0) return getout(num*2+1,mid+1,r,bf);
	else return getout(num*2,l,mid,bf);
}

int main()
{
	int i , j;
	cin >> n;
	for (i = 1 ; i <= n ; i++)
		scanf("%I64d",&a[i]);
	build(1,1,n);
	for (i = 1 ; i <= n ; i++)
	{
		j = getout(1,1,n,0);
		b[j] = i;
		putin(1,1,n,j+1,n,-i);
		putin(1,1,n,j,j,(LL)n*n);
	}
	for (i = 1 ; i <= n ; i++)
		printf("%d ",b[i]);
	printf("\n");
	return 0;
}