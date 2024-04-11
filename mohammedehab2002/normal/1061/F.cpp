#include <iostream>
#include <random>
#include <chrono>
using namespace std;
int n,k;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rnd()
{
	return uniform_int_distribution<int>(1,n)(rng);
}
bool ask(int a,int b,int c)
{
	printf("? %d %d %d\n",a,b,c);
	fflush(stdout);
	string ans;
	cin >> ans;
	return (ans=="Yes");
}
int main()
{
	scanf("%d%d",&n,&k);
	int h=0,cn=n;
	while (cn)
	{
		cn/=k;
		h++;
	}
	while (1)
	{
		int a=rnd(),b=rnd();
		if (a==b)
		continue;
		vector<int> path;
		for (int i=1;i<=n;i++)
		{
			if (ask(a,i,b))
			path.push_back(i);
		}
		if (path.size()==2*h-1)
		{
			for (int i:path)
			{
				int cnt=0;
				for (int j:path)
				cnt+=ask(a,j,i);
				if (cnt==h)
				{
					printf("! %d\n",i);
					fflush(stdout);
					return 0;
				}
			}
		}
	}
}