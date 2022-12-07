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

int a[maxn],b[maxn];
int i,j,k,l,m,n,ma,mi;

int abs(int x)
{
	return x<0?-x:x;
}

int main()
{
	scan2(n,m);
	for(i=1;i<=n;i++)scan(a[i]);
	for(i=1;i<=m;i++)scan(b[i]);
	sort(a+1,a+n+1);sort(b+1,b+m+1);
	k=1;ma=0;
	for(i=1;i<=n;i++)
	{
		while(b[k]<=a[i] && b[k+1]<=a[i] && k<m)k++;
		if(a[i]>b[m])mi=a[i]-b[m];else if(a[i]<b[1])mi=abs(a[i]-b[1]);else mi=min(abs(a[i]-b[k]),abs(a[i]-b[k+1]));
		ma=max(ma,mi);
	}
	printf("%d",ma);
    return 0;
}