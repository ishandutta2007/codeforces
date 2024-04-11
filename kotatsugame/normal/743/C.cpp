#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<string>
#include<sstream>
#include<iomanip>
#include<utility>
#include<cmath>
#include<set>
#include<list>
#include<queue>
#include<stack>
#include<map>
#include<cstring>
using namespace std;
typedef long long int ll;
ll x,y,z;
ll n;
bool IDE(int limit)
{
	ll b,c,d;
	for(b=1;b<=limit;b++)
	{
		for(c=1;c<=limit;c++)
		{
			x=n/2+b;
			for(d=1;d<=c*(2*x-n);d++)
			{
				if(2*c*(2*x-n)-d>0&&(2*c*n*x)%d==0&&(2*c*n*x)%(2*c*(2*x-n)-d)==0)
				{
					y=(2*c*n*x)/d;
					z=(2*c*n*x)/(2*c*(2*x-n)-d);
					if(x==y||y==z||z==x)continue;
					return true;
				}
			}
		}
	}
	return false;
}

int main()
{
	cin>>n;
	if(n==1)
	{
		cout<<-1<<endl;
		return 0;
	}
	for(int limit=1;limit<100;limit++)
	{
		if(IDE(limit))
		{
			cout<<x<<" "<<y<<" "<<z<<endl;
			return 0;
		}
	}
	return 0;
}