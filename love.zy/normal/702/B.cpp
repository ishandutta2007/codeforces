#include <iostream>
#include <cstring>
#include <stack>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <queue>
#include <cstdio>
#include <cstdlib>
#include <climits>
#include <deque>
#include <bitset>
#include <algorithm>
  
using namespace std;
  
const double eps=1e-10;
const double pi=3.1415926535897932384626433832795;
const double eln=2.718281828459045235360287471352;
  
#define LL long long
#define IN freopen("in.txt", "r", stdin)
#define OUT freopen("out.txt", "w", stdout)
#define scan(x) scanf("%d", &x)
#define scan2(x, y) scanf("%d%d", &x, &y)
#define scan3(x, y, z) scanf("%d%d%d", &x, &y, &z)
#define sqr(x) (x) * (x)
#define pr(x) printf("Case %d: ",x)
#define prn(x) printf("Case %d:\n",x)
#define prr(x) printf("Case #%d: ",x)
#define prrn(x) printf("Case #%d:\n",x)
#define lc o << 1
#define rc o << 1 | 1
#define lowbit(x) (x&(-x))
#define min(x,y) ((x)<(y)?(x):(y))
#define max(x,y) ((x)>(y)?(x):(y))
  
const int maxn=100005;
int a[maxn];
struct sleepy
{
	LL num,sum;
	sleepy(LL num=0,LL sum=0):num(num),sum(sum){}
}b[maxn];
LL i,j,k,m,n;

LL find(LL x)
{
	LL l,r;
	l=1;r=m;
	while(r-l>1)
	{
		LL mid=(l+r)>>1;
		if(b[mid].num==x)return b[mid].sum;
		if(b[mid].num<x)l=mid;else r=mid;
	}
	if(b[l].num==x)return b[l].sum;
	if(b[r].num==x)return b[r].sum;
	return 0;
}

int main()
{
	scanf("%lld",&n);
	for(i=1;i<=n;i++)scanf("%d",&a[i]);
	sort(a+1,a+n+1);m=1;k=1;b[1].num=a[1];
	for(i=2;i<=n;i++)
	{
		if(a[i]==a[i-1])k++;else
		{
			b[m++].sum=k;
			k=1;b[m].num=a[i];
		}
	}
	b[m].sum=k;LL ans=0;
	for(i=1;i<=m;i++)
	{
		j=1;
		while((j<=b[i].num))j*=2;
		if(j==2*b[i].num)ans+=b[i].sum*(b[i].sum-1)/2;
		for(j*=2;j<=(b[i].num+b[m].num);j*=2)
			ans+=b[i].sum*find(j-b[i].num);
	}
	printf("%lld",ans);
    return 0;
}