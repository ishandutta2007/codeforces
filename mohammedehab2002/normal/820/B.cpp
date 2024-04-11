#include <iostream>
#include <math.h>
using namespace std;
pair<long long,long long> l,an,cur;
int main()
{
	long long n,a,ans;
	cin >> n >> a;
	an=make_pair(180,n);
	l=make_pair(1000,1);
	cur=make_pair(180*(n-2),n);
	for (int i=3;i<=n;i++)
	{
		pair<long long,long long> d=make_pair(abs(cur.first-a*cur.second),cur.second);
		if (d.first*l.second<l.first*d.second)
		{
			l=d;
			ans=i;
		}
		cur.first-=an.first;
	}
	cout << 1 << ' ' << 2 << ' ' << ans;
}