#include<cstdio>
#include<map>
#define int long long
using std::pair;
using std::make_pair;
using std::map;
inline int read()
{
	int res=0;
	char x;
	while((x=getchar())<'0'||x>'9');
	for(;x>='0'&&x<='9';x=getchar())
		res=res*10+x-'0';
	return res;
}
inline int gcd(int x,int y)
{
	return x?gcd(y%x,x):y;
}
const int N=1e6+5;
int m;
int a,b,c;
pair<int,int> x[N];
map<pair<int,int>,int> M;
signed main()
{
	int g;
	register int i;
	m=read();
	for(i=1;i<=m;i++)
	{
		a=read();b=read();c=read();
		g=gcd(a+b,c);
		x[i]=make_pair((a+b)/g,c/g);
		M[x[i]]++;
	}
	for(i=1;i<=m;i++)
		printf("%lld ",M[x[i]]);
	putchar('\n');
	return 0;
}