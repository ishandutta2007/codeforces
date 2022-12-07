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
  
#define LL __int64
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
 
const int maxn=2100005;
const LL mod=51123987;
char s1[maxn],s2[2*maxn];
LL p[2*maxn],st[maxn],en[maxn];
int i,j,k,l,m,n,mx,id;

int main()
{
	scanf("%d\n",&n);
	gets(s1);
	s2[0]='$';k=0;
	for(i=0;i<n;i++)
	{
		s2[++k]='#';
		s2[++k]=s1[i];
	}
	s2[++k]='#';s2[++k]='\0';
	mx=0;id=0;
	for(i=1;s2[i]!='\0';i++)
	{
		p[i]=mx>i?min(p[2*id-i],mx-i):1;
		while(s2[i+p[i]]==s2[i-p[i]])p[i]++;
		if(i+p[i]>mx)mx=i+p[i],id=i;
	}
	LL tot=0;
	for(i=1;s2[i]!='\0';i++)p[i]--;
	for(i=1;s2[i]!='\0';i++)
	{
		if(i&1 && p[i]<=0)continue;
		tot+=(p[i]+1LL)/2LL;
	}
	if(tot%2LL==0)tot=((tot/2LL)%mod)*((tot-1LL)%mod);else tot=((tot-1LL)/2LL%mod)*(tot%mod);
	tot%=mod;
	for(i=1;s2[i]!='\0';i++)
	{
		if(i&1 && p[i]<=0)continue;
		LL mid=i/2;
		LL lo=(p[i]+1)/2;
		if(i&1)
		{
			st[mid-lo+1]++;
			st[mid+1]--;
			en[mid+1]++;
			en[mid+lo+1]--;
		}else
		{
			st[mid-lo+1]++;
			st[mid+1]--;
			en[mid]++;
			en[mid+lo]--;
		}
	}
	st[1]%=mod;en[1]%=mod;
	for(i=1;i<=n;i++)
	{
		st[i]=(st[i]+st[i-1])%mod;
		en[i]=(en[i]+en[i-1])%mod;
	}
	LL ans=0;
	for(i=2;i<=n;i++)
	{
		en[i]=(en[i]+en[i-1])%mod;
		ans=(ans+(en[i-1]*st[i])%mod)%mod;
	}
	printf("%I64d",(tot+mod-ans)%mod);
	return 0;
}