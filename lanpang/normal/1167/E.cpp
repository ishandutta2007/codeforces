#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn = 1e6+10;
const LL mod = 1e9+7;
const double eps = 1e-9;

int n , m , a[maxn] , ma[maxn] , mi[maxn] , trma[maxn*4] , trmi[maxn*4];
vector<int> v[maxn];
LL ans;

void putin(int num , int l , int r , int x , int y)
{
	if (l == r)
	{
		if (y) trma[num] = trmi[num] = y;
		else
		{
			trma[num] = 0;
			trmi[num] = m+1;
		}
		return;
	}
	if (x <= (l+r)/2) putin(num*2,l,(l+r)/2,x,y);
	else putin(num*2+1,(l+r)/2+1,r,x,y);
	trma[num] = max(trma[num*2],trma[num*2+1]);
	trmi[num] = min(trmi[num*2],trmi[num*2+1]);
}

int getma(int num , int l , int r , int x , int y)
{
	if (x > r || l > y) return 0;
	if (x <= l && r <= y) return trma[num];
	if (y <= (l+r)/2) return getma(num*2,l,(l+r)/2,x,y);
	if (x >= (l+r)/2+1) return getma(num*2+1,(l+r)/2+1,r,x,y);
	return max(getma(num*2,l,(l+r)/2,x,y),getma(num*2+1,(l+r)/2+1,r,x,y));
}

int getmi(int num , int l , int r , int x , int y)
{
	if (x > r || l > y) return m+1;
	if (x <= l && r <= y) return trmi[num];
	if (y <= (l+r)/2) return getmi(num*2,l,(l+r)/2,x,y);
	if (x >= (l+r)/2+1) return getmi(num*2+1,(l+r)/2+1,r,x,y);
	return min(getmi(num*2,l,(l+r)/2,x,y),getmi(num*2+1,(l+r)/2+1,r,x,y));
}

void era(int &x)
{
	x++;
	for (auto i: v[x])
		putin(1,1,n,i,0);
}

void ins(int &x , int y)
{
	for (auto i: v[x])
		putin(1,1,n,i,x);
	x += y;
}

bool chk(int x)
{
	if (v[x].size() == 0) return 1;
	int lef = getma(1,1,n,1,mi[x]-1) , rig = getmi(1,1,n,ma[x]+1,n);
	int midma = getma(1,1,n,mi[x],ma[x]) , midmi = getmi(1,1,n,mi[x],ma[x]);
	if (lef < x && midma == x && midmi == x && rig > x) return 1;
	return 0;
}

int main()
{
	int i , j , l , r;
	cin >> n >> m;
	for (i = 1 ; i <= m ; i++)
		mi[i] = n+1;
	for (i = 1 ; i <= n*4 ; i++)
		trmi[i] = m+1;
	for (i = 1 ; i <= n ; i++)
	{
		scanf("%d",&a[i]);
		v[a[i]].push_back(i);
		ma[a[i]] = max(i,ma[a[i]]);
		mi[a[i]] = min(i,mi[a[i]]);
	}
	l = 1;
	r = m;
	ins(r,-1);
	while (r >= 1 && chk(r+1)) ins(r,-1);
	era(r);
	ans += m-r+1;
	while (l <= m)
	{
		ins(l,1);
		while (r <= m && (r < l || !chk(l-1))) era(r);
		if (r > m) break;
		ans += m-r+1;
	}
	cout << ans << "\n";
	return 0;
}