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
#define inf 1e9
using namespace std;

const int maxn = 310000;
const int maxd = 40;

struct Tree
{
	int sum[maxn*maxd],son[maxn*maxd][2],root,cnt;
	void ins(int c)
	{
		int p=root;
		for(int i=29;i>=0;i--)
		{
			int w=c>>i&1;
			if(!son[p][w]) son[p][w]=++cnt;
			p=son[p][w];
			sum[p]++;
		}
	}
	int query(int c)
	{
		int p=root,re=0;
		for(int i=29;i>=0;i--)
		{
			int w=c>>i&1;
			if(sum[son[p][w]]) p=son[p][w];
			else p=son[p][!w],re|=1<<i;
			sum[p]--;
		}
		return re;
	}
}tr;
int n;
int A[maxn],B[maxn];

int main()
{
	//freopen("tmp.in","r",stdin);
	//freopen("tmp.out","w",stdout);
	
	tr.root=tr.cnt=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&A[i]);
	for(int i=1;i<=n;i++) scanf("%d",&B[i]),tr.ins(B[i]);
	
	for(int i=1;i<=n;i++)
	{
		printf("%d",tr.query(A[i]));
		if(i!=n) putchar(' ');
	}
	
	return 0;
}