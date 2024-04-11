#include <iostream>
#include <vector>
using namespace std;
vector<pair<int,int> > v;
int main()
{
	int k;
	scanf("%d",&k);
	if (k%2)
	{
		printf("YES\n");
		for (int i=2;i<=k;i++)
		{
			v.push_back({1,i});
			for (int j=k+1;j<2*k;j++)
			v.push_back({i,j});
		}
		for (int i=k+1;i<2*k;i+=2)
		v.push_back({i,i+1});
		printf("%d %d\n",4*k-2,2*v.size()+1);
		printf("1 %d\n",2*k);
		for (auto p:v)
		printf("%d %d\n%d %d\n",p.first,p.second,p.first+2*k-1,p.second+2*k-1);
	}
	else
	printf("NO");
}