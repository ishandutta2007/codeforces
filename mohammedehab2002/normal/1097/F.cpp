#include <iostream>
#include <bitset>
#include <vector>
using namespace std;
#define MX 7000
bitset<MX+5> s[100005],d[MX+5],m[MX+5];
vector<int> v[MX+5];
bool sq[MX+5];
int main()
{
	for (int i=2;i<=MX;i++)
	{
		for (int j=i*i;j<=MX;j+=i*i)
		sq[j]=1;
	}
	for (int i=1;i<=MX;i++)
	{
		for (int j=1;i*j<=MX;j++)
		{
			v[i*j].push_back(i);
			if (!sq[j])
			m[i][i*j]=1;
		}
		for (int j:v[i])
		d[i][j]=1;
	}
	int n,q;
	scanf("%d%d",&n,&q);
	while (q--)
	{
		int t,x,y;
		scanf("%d%d%d",&t,&x,&y);
		if (t==1)
		s[x]=d[y];
		else if (t==4)
		printf("%d",(s[x]&m[y]).count()%2);
		else
		{
			int z;
			scanf("%d",&z);
			if (t==2)
			s[x]=(s[y]^s[z]);
			else
			s[x]=(s[y]&s[z]);
		}
	}
}