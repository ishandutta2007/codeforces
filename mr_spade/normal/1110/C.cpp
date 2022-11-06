#include<cstdio>
#include<algorithm>
#include<map>
using std::map;
using std::__gcd;
map<int,int> a;
inline int count(int x)
{
	int res=0;
	while(x)
		res++,x&=x-1;
	return res;
}
int n;
inline void solve()
{
	int _,x=0;
	register int i;
	scanf("%d",&n);
	if(a.find(n)!=a.end())
	{
		printf("%d\n",a[n]);
		return;
	}
	for(_=0;1<<_<=n;_++);
		for(i=0;i<_;i++)
			x|=1<<i;
		printf("%d\n",x);
	return;
}
signed main()
{
	
	int T;
	register int i;
	a[1]=0;
a[3]=1;
a[7]=1;
a[15]=5;
a[31]=1;
a[63]=21;
a[127]=1;
a[255]=85;
a[511]=73;
a[1023]=341;
a[2047]=89;
a[4095]=1365;
a[8191]=1;
a[16383]=5461;
a[32767]=4681;
a[65535]=21845;
a[131071]=1;
a[262143]=87381;
a[524287]=1;
a[1048575]=349525;
a[2097151]=299593;
a[4194303]=1398101;
a[8388607]=178481;
a[16777215]=5592405;
a[33554431]=1082401;
	scanf("%d",&T);
	while(T--)
		solve();
	return 0;
}