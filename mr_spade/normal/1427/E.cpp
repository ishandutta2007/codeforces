#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<vector>
#define int long long
using std::random_shuffle;
using std::vector;
const int N=100;
int cnt,a[N];
vector<int> V;
inline void init()
{
	memset(a,0,sizeof(a));cnt=0;
	return;
}
inline int expand(int x)
{
	register int i;
	for(i=49;i>=0;i--)
		if(x>>i&1)
		{
			if(!a[i])
				return a[i]=x,1;
			V.push_back(a[i]);
			V.push_back(-2);
			V.push_back(x);
			V.push_back(-3);
			x^=a[i];
		}
	return 0;
}
inline int rand1()
{
	int res=0,x,y;
	register int i;
	for(x=0,i=40;i>=0;i--)
		if(a[i]&&(rand()&1))
		{
			V.push_back(a[i]);
			V.push_back(-2);
			V.push_back(x);
			V.push_back(-3);
			x^=a[i];
		}
	res+=x;
	for(y=0,i=40;i>=0;i--)
		if(a[i]&&(rand()&1))
		{
			V.push_back(a[i]);
			V.push_back(-2);
			V.push_back(y);
			V.push_back(-3);
			y^=a[i];
		}
	res+=y;
	V.push_back(x);
	V.push_back(-1);
	V.push_back(y);
	V.push_back(-3);
	return res;
}
inline bool check(int x)
{
	register int i;
	init();V.clear();
	expand(x);
	V.push_back(x);
	V.push_back(-2);
	V.push_back(x);
	V.push_back(-3);
	for(i=2;!a[0]&&i<=1000;i++)
	{
		V.push_back((i-1)*x);
		V.push_back(-1);
		V.push_back(x);
		V.push_back(-3);
		expand(i*x);
		expand(rand1());
	}
	printf("%d\n",(int)V.size()/4);
	for(int x:V)
		switch(x)
		{
			case -1:printf(" + ");break;
			case -2:printf(" ^ ");break;
			case -3:printf("\n");break;
			default:printf("%lld",x);break;
		}
	for(int x:V)
		if(x>(1e14))
			return 0;
//	if(!a[0])
//	{
//		for(i=1001;i<=2000;i++)
//			expand(i*x),expand(rand1());
//	}
	return a[0];
}
signed main()
{
	int x;
	scanf("%lld",&x);
	check(x);
	return 0;
}