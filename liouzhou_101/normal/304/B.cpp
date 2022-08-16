#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<ctime>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<sstream>
#include<bitset>
#include<vector>
#include<string>
#include<set>
#include<map>
#include<queue>
#include<iomanip>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef double ld;
typedef pair<int,int> pii;
typedef pair<ld,ld> pdd;
typedef pair<ll,ll> pll;

#define X first
#define Y second

int days[]={0,31,28,31,30,31,30,31,31,30,31,30,31};

pair<pii,int> date(int a,int b,int c)
{
	return pair<pii,int>(pii(a,b),c);
}

bool leap(int a)
{
	return a%4==0&&a%100!=0||a%400==0;
}

int main()
{
	int y1,m1,d1,y2,m2,d2;
	scanf("%d:%d:%d%d:%d:%d",&y1,&m1,&d1,&y2,&m2,&d2);
	if (date(y1,m1,d1)>date(y2,m2,d2))
	{
		swap(y1,y2);
		swap(m1,m2);
		swap(d1,d2);
	}
	int ans=0;
	while (date(y1,m1,d1)!=date(y2,m2,d2))
	{
		ans++;
		if (leap(y1)) days[2]=29; else days[2]=28;
		++d1;
		if (d1>days[m1])
		{
			++m1;
			d1=1;
			if (m1>12)
			{
				++y1;
				m1=1;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}