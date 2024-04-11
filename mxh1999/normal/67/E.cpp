//This is meng meng da mjy>_<
#include <map>
#include <queue>
#include <cmath>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define INF 1000000007
typedef long long ll;
using namespace std;

void read(int &digit)
{
	digit=0;
	char c;
	for (c=getchar();(c<'0' || c>'9') && c!='-';c=getchar());
	bool type=false;
	if (c=='-')
		type=true,c=getchar();
	for (;c>='0' && c<='9';digit=digit*10+c-'0',c=getchar());
	if (type==true)
		digit=-digit;
}

#define maxn 1010
struct Point
{
	int x,y;
}	a[maxn];
int n,m,y00;
ll mjyl,mjyr;
int main()
{
	read(n);
	for (int i=1;i<=n;i++)	read(a[i].x),read(a[i].y);
	y00=a[1].y;mjyl=a[1].x,mjyr=a[2].x;
	if (mjyl>mjyr)	swap(mjyl,mjyr);
	for (int i=2;i<=n;i++)
	{
		int _a=a[i].x,_b=a[i].y;
		int _c=a[i%n+1].x,_d=a[i%n+1].y;
		if (_b==_d && _b==y00)	continue;
		if (_b==_d && ((_b<y00)^(_a>_c)))
		{
			printf("0\n");return 0;
		}
		if (_b==_d)	continue;
		double q=y00-_b;
		q*=_c-_a;
		q/=(_d-_b);
		q+=_a;
		if (_d-_b>0)
		{
			ll ql=floor(q+0.99);
			mjyl=max(mjyl,ql);
		}	else
		{
			ll ql=floor(q+1e-6);
			mjyr=min(mjyr,ql);
		}
	}
	if (mjyl<=mjyr)	cout<<mjyr-mjyl+1<<endl;else printf("0\n");
	return 0;
}