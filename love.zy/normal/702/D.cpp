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

LL d,k,a,b,t;
LL t1,t2,ans,dis;

int main()
{
	scanf("%lld%lld%lld%lld%lld",&d,&k,&a,&b,&t);
	if(d<=k){printf("%lld",a*d);return 0;}
	ans+=a*k;
	d-=k;
	t1=d/k;t2=d%k;
	if(t+k*a<b*k)ans+=t1*(t+a*k);else ans+=t1*k*b;
	if(t2*b<t+t2*a)ans+=t2*b;else ans+=t+t2*a;
	printf("%lld",ans);
    return 0;
}