#include <iostream>
#include <stdlib.h>
#include <vector>
using namespace std;
vector<string> v[11];
int main()
{
	int n,m,cnt=0;
	scanf("%d%d",&n,&m);
	v[0].push_back("");
	long long ans=0;
	for (int i=2;i<13;i+=2)
	{
		for (char x='0';x<='9';x++)
		{
			for (int k=0;k<v[i-2].size();k++)
			{
				v[i].push_back(x+v[i-2][k]+x);
				if (x!='0')
				{
					ans=(ans+atoll(v[i].back().c_str()))%m;
					n--;
				}
				if (!n)
				{
					printf("%I64d",ans);
					return 0;
				}
			}
		}
	}
}