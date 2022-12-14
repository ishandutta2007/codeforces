#include<bits/stdc++.h>
#define Accepted 0
using namespace std;
const int maxn=1e9;
string s;
char c[11];
int l1,r1,l2,r2,mid1,mid2,l,r,mid;
bool ask(int x,int y)
{
	printf("? %d %d\n",x,y);
	fflush(stdout);
	scanf("%s",c);
	return (c[0]=='x');
}
int main()
{
	while(cin>>s)
	{
		if (s=="end") break;
		if (ask(0,1))
		{
			printf("! 1\n");
			fflush(stdout);
			continue;
		}
		l=2;r=1e9;
		while(l<r)
		{
			mid=min((l-1)*2,(l+r)>>1);
			if (ask(l-1,mid)) r=mid;
			else l=mid+1;
		}
		printf("! %d\n",l);
		fflush(stdout);
	}	
	return Accepted;
}