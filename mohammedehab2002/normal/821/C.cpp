#include <iostream>
#include <string.h>
#include <set>
using namespace std;
char tmp[7];
set<int> s;
bool ch[300005];
int main()
{
	int n,ans=0,d=1;
	cin >> n;
	bool so=1;
	n*=2;
	while (n--)
	{
		scanf("%s",tmp);
		if (tmp[0]=='a')
		{
			int a;
			scanf("%d",&a);
			if (s.size()>0)
			{
				if (a>*(s.begin()))
				ch[*(s.begin())]=1,so=0;
			}
			s.insert(a);
		}
		else
		{
			if (ch[*(s.begin())] && !so)
			ans++,so=1;
			s.erase(s.begin());
		}
	}
	printf("%d",ans);
}