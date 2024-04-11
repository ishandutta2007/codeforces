#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <vector>
#include <bitset>
#include <cmath>
#include <queue>
#include <stack>
#include <set>
#include <map>

using namespace std;

typedef long long LL;
typedef pair <int,int> II;
const int maxn = 1e4+10;
const int maxint = 0x3f3f3f3f;
const int mod = 1e9+7;

int n , q , cnt;
bitset <maxn> ans , push;
vector <int> tr[maxn*4];

void putin(int p , int l , int r , int x , int y , int z)
{
	if (x > r || l > y) return;
	if (x <= l && r <= y) tr[p].push_back(z);
	else
	{
		putin(p*2,l,(l+r)/2,x,y,z);
		putin(p*2+1,(l+r)/2+1,r,x,y,z);
	}
	return;
}

void solve(int p , int l , int r)
{
	bitset <maxn> ty = push;
	for (int i = 0 ; i < tr[p].size() ; i++)
		push |= push<<tr[p][i];
	if (l == r) ans |= push;
	else
	{
		solve(p*2,l,(l+r)/2);
		solve(p*2+1,(l+r)/2+1,r);
	}
	push = ty;
	return;
}

int main()
{
	int x , y , z , i;
	cin >> n >> q;
	for (i = 1 ; i <= q ; i++)
	{
		cin >> x >> y >> z;
		putin(1,1,n,x,y,z);
	}
	push[0] = 1;
	solve(1,1,n);
	for (i = 1 ; i <= n ; i++) 
		if (ans[i]) cnt++;
	cout << cnt << "\n";
	for (i = 1 ; i <= n ; i++)
		if (ans[i]) cout << i << " ";
	cout << "\n";
	return 0;
}