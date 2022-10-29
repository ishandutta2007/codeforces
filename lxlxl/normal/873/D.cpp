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

const int maxn = 110000;

int n,k;
int a[maxn];

void merge(const int l,const int r,int &kk)
{
	if(l+1==r) { a[l]++; return; }
	if(l==r) return;
	if(!k)
	{
		for(int i=l;i<r;i++) a[i]=i-l+1;
		return;
	}
	
	k-=2;
	int mid=l+r>>1;
	merge(l,mid,kk);
	merge(mid,r,kk);
	for(int i=l;i<mid;i++) a[i]+=r-mid;
	return;
}

int main()
{
	scanf("%d%d",&n,&k);
	k--; merge(0,n,k);
	if(k) return puts("-1"),0;
	for(int i=0;i<n;i++) printf("%d ",a[i]);
	
	return 0;
}